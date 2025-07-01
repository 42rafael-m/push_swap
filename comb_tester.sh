#!/usr/bin/env bash
# set -euo pipefail

# ---------------------------------------------------
# CONFIGURA AQUÍ TU “BENCHMARK” POR TAMAÑO DE STACK:
# ---------------------------------------------------
declare -A BENCH=(
  [2]=3
  [3]=5
  [4]=12
  [5]=12
  # …añade más según necesites…
)

TEST_FILE="tests.txt"
LOG_FILE="log.txt"

# Prepara log
: > "$LOG_FILE"   # trunca o crea

MAX=155
line_no=0
while IFS= read -r raw; do
  ((line_no++))
  [[ $line_no -gt $MAX ]] && break
  # Salta líneas vacías
  [[ -z "${raw//[[:space:]]/}" ]] && continue

  # Cuenta elementos (comillas dobles) y extrae args sin comillas
  size=$(( $(grep -o '"' <<<"$raw" | wc -l) / 2 ))
  args=()
  while read -r q; do
    args+=("${q//\"/}")
  done < <(grep -o '"[^"]*"' <<<"$raw")

  # Ejecuta push_swap y captura todas las líneas
  mapfile -t out < <(./push_swap "${args[@]}")

  # Inicializa defaults
  status="KO"
  n_ops=0
  sorted_series=""

  if (( ${#out[@]} > 0 )); then
    # Última línea es la serie resultante
    sorted_series="${out[-1]}"
    # Número de operaciones = total líneas - 1
    n_ops=$(( ${#out[@]} - 1 ))
    # Comprueba si está ordenada
    normalized=$(echo "$sorted_series" | xargs)
    sorted_normalized=$(echo "$sorted_series" | tr ' ' '\n' | sort -n | xargs)
    if [[ "$sorted_normalized" == "$normalized" ]]; then
       ok_sorted=true
    else
        ok_sorted=false
    fi

    # if [[ "$(tr ' ' '\n' <<<"$sorted_series" | sort -n | xargs)" == "$sorted_series" ]]; then
    #   ok_sorted=true
    # else
    #   ok_sorted=false
    # fi
    # Comprueba benchmark (0 = KO si no hay benchmark)
    bench=${BENCH[$size]:-0}
    if $ok_sorted && (( n_ops <= bench )); then
      status="OK"
    fi
  fi

  # Formatea las líneas con etiquetas
  line1="Elements: $size | Line: $line_no"
  line2="Status: $status | Operations: $n_ops"
  line3="Result: $sorted_series"

  # Escribe en log.txt
  {
    echo "$line1"
    echo "$line2"
    echo "$line3"
  } >> "$LOG_FILE"

  # Imprime en pantalla sólo los KO
  if [[ "$status" == "KO" ]]; then
    echo "$line1"
    echo "$line2"
    echo "$line3"
  fi

done < "$TEST_FILE"

