# Agricultural Equipment Registry - Data Structures Lab

## Overview
This project is a C-based procedural program developed for a Data Structures and Algorithms laboratory. It implements a robust Agricultural Equipment Registry using various dynamic, Linked-List based Abstract Data Types (ADTs). 

The project strictly adheres to rigorous C programming standards, avoiding syntactic shortcuts to demonstrate a deep understanding of memory management, pointer arithmetic, and raw data structuring.

## Highlight
The codebase is heavily modularized into header and implementation files, driven by a centralized, interactive menu system in `main.c`.

## Implemented Data Structures
All structures store a highly detailed Custom Data Type (`AgriEquipment`) representing farm machinery.

1. **Stack (LIFO) -** Standard Push, Pop, Display, and Search.
2. **Simple Queue (FIFO) -** Standard Enqueue, Dequeue, Display, and Search.
3. **Double-Ended Queue (Deque) -** Supports O(1) insertion and deletion at both the Front and Rear.
4. **Circular Queue -** Implements a closed-loop linked list where the Rear node links back to the Front.
5. **Priority Queue (Dynamic) -** Features an advanced **Comparator Engine**. Users can dynamically choose the priority criteria at runtime:
   * By Price
   * By Last Inspection Year
   * By Brand (Alphabetical)
   * By Registration Number (Alphabetical)
   * Supports both Ascending and Descending sort orders.

## Core Features
* A single, powerful search algorithm capable of traversing any of the above data structures and querying against 7 different equipment parameters.
* **File I/O Management:** 
  * Save current data structures to disk.
  * Supports both Text mode (`*.txt`) and Binary mode (`*.bin`).
  * Custom file path reading directly from standard input.

## File Structure
* `equipment_ds.h` - Contains all structure definitions (CDTs and ADTs) and function prototypes.
* `equipment_ds.c` - Contains the implementation logic for all data structures, utilities, search, and file I/O operations.
* `main.c` - The entry point containing the comprehensive, nested interactive terminal menu.

## Compilation and Execution

To compile the program using GCC, run this command in your terminal:

```bash
gcc main.c equipment_ds.c -o run.exe