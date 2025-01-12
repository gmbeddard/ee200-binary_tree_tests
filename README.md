### EE200 Homework Assignment: Testing Binary Search Tree Implementations

#### Project Overview
This project flips the script on typical programming assignments: instead of writing the implementation, you write tests. The goal is to evaluate 10 provided implementations of a binary search tree (BST) for integers and determine which, if any, work as described in the `btree.h` header file. Each implementation is tested for correctness and robustness across various scenarios, with the ultimate objective of identifying bugs and failures. I was successful in getting 8 out of 10 test cases to fail.

#### Features
- **Test Cases**:
  - Validate core BST operations, including insertion, deletion, search, and traversal.
  - Verify proper behavior of member functions such as `remove()`, `contains()`, and `toArray()`.
  - Test edge cases like empty trees, single-node trees, and large trees.
  - Assess memory management, including potential memory leaks and invalid pointer access.
- **Automated Testing**:
  - Tests are compiled and run using a provided Makefile.
  - Comprehensive assertions ensure robust verification of BST behavior.

#### Key Observations
- **Memory Issues**: Multiple implementations struggle with memory management, particularly in freeing arrays created by `toArray()` or handling empty trees.
- **Segmentation Faults**: Several implementations crash when handling edge cases like removing non-existent values or deep copying empty trees.
- **Logical Errors**:
  - Mismanagement of the root node during removal and restructuring.
  - Incorrect handling of array size or null pointers in `toArray()`.
  - Faulty implementations of `contains()` leading to incorrect search results.
- **Edge Cases**: Large trees, empty trees, and special values like `INT_MIN` expose weaknesses in several implementations.

#### Repository Content
- **Test Code**: Includes comprehensive unit tests for all BST functionalities and edge cases.
- **Makefile**: Automates the compilation and execution of test cases.

#### Authors
Gabby Beddard. Project completed as part of an assignment on debugging and testing in a data structures course. Tests focus on identifying bugs and ensuring robust tree behavior.
