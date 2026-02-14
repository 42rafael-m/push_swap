# 42 Core: Push_swap

Highly optimized sorting algorithm using two stacks - 42 Core Project.

[![Language: C](https://img.shields.io/badge/language-C-blue.svg)](https://github.com/rms35/42-core-push-swap)
[![42 School](https://img.shields.io/badge/42-School-black.svg)](https://github.com/42School)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)

## 🛠 Setup

The project uses a standard 42 Makefile with robust rules.

```bash
make        # Compiles the push_swap binary
make debug  # Compiles with AddressSanitizer and debug symbols
make fclean # Removes all binaries and object files
```

## 🚀 Usage

Provide a list of unique integers as arguments. The program outputs the sequence of instructions to sort them.

```bash
./push_swap 5 2 8 1 9
```

To verify the move count:
```bash
ARG="5 2 8 1 9"; ./push_swap $ARG | wc -l
```

## 🏗 Architecture

### The Turk Algorithm (Greedy Cost-Based)
Instead of using fixed chunks or simple pivots, this implementation evaluates the cost of moving each element from Stack A to its correct relative position in Stack B.

- **Cost Calculation:** Accounts for the rotations needed for both the element in A and its target in B.
- **Simultaneous Rotations:** Prioritizes moves where \`rr\` or \`rrr\` can be used to reduce the total operation count.
- **Efficiency:** Achieves ~500-600 moves for 100 random numbers and ~5000-5500 for 500 numbers.

### Data Structures
- **Circular Linked List:** Built upon a modified \`libft\` list structure.
- **Direct Pointer Storage:** Optimized memory by storing integer values directly in \`void *\` pointers to avoid redundant heap allocations for every node's content.

## ⚖️ Trade-offs

- **Greedy vs. Radix/Quicksort:** While Radix sort is easier to implement for bitwise sorting, it often results in more moves for small to medium sets. Quicksort/Merge sort are harder to adapt to two-stack constraints. The Turk Algorithm was chosen for its superior move-count performance, which is critical for the 42 grading benchmarks.
- **Pointer Storage:** Storing \`int\` values directly in \`void *\` saves memory and speed but requires careful casting. This was chosen to minimize heap fragmentation.
- **Performance vs. Complexity:** The greedy approach is $O(n^2)$ in the worst case for move selection but $O(1)$ in memory (beyond the stacks). Given $n=500$, the complexity is negligible compared to the move optimization gains.

---
*This project was refined and audited using the Gemini CLI.*
