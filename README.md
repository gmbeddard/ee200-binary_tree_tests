EE 200 Homework 15

# Overview
This assignment is the reverse of most that you've written so far: I have written some implementations of a binary search tree (for integers), and you will write the tests.  Your job is to figure out which of the 10 implementations actually does what is described in the header file `btree.h`.  Bonus points will be awarded if you come up with a test that breaks all of them (i.e., you find a real bug in my code).

You can use the provided Makefile to compile your code and run all your tests.

# Problem
For each of the 10 implementations, write a 1-sentence description of what the implementation is doing wrong, or how you determined that it is broken.  Only one of them works completely. (Unless there are bugs in my code, in which case none of them work completely!)

1. For this one, I tested a combination of 6 + 7 failures. I tested that the remove() member function properly responds to removing a value that is not in the BST, and after that, I verified that the BST does indeed not have that value anymore using the contains() member function. This test case failed here. Memory leak on this as well. Also, seems like the toArray() member function does not put things in proper order here and delete[] array doesn't work properly. 

2.

3. Adding and removing values in my BST before calling toArray() member function throws a "bad_array_new_length" exception when asserting that the array is NULL. Perhaps it's not properly handling reducing the array size from 1 to 0. Or it bases the size of the array on the number of elements in it using a for loop and doesn't account for a NULL array? Memory leaks: doesn't properly free memory when delete[] array is called. Also it strangely makes the root node null and doesn't replace w a value when a value is added.

4. I used the copy constructor to make a deep copy in test_deep_copy() and, unfortunately, this caused a seg fault in Test 4. This suggests there's an issue with the implementation of btree4's copy constructor implementation, since it passes on the other tests (mostly). It seems like the assignment operator overload also does not work on this test! Struggles with freeing memory when delete[] array created from toArray() is called. 

5. This test failed test_remove_root(), in which I attempted to verify that the BST correctly handles restructuring after I remove the root value. It seems like this test fails at properly removing the root and doesn't get far enough to check the restructuring part, so I will make this more robust and report back. Either way, this is a failure. Struggles with freeing memory when delete[] array created from toArray() is called.

6. Seg fault - I tried removing a value that doesn't exist using the remove() member function. Instead of doing nothing, I got a seg fault. This suggests that this BST implementation does not, in fact, handle this properly. 

7. I tested the BST contains() member function by checking if it properly catches that the BST does not contain a value. I added and removed the value of 1 and then attempted to verify that value 1 was no longer contained in the BST. Obviously, it worked for all of the other test cases except this one! I also tested this by adding INT_MIN + 1 into the BST, and this implementation somehow verified that INT_MIN was in my BST when it wasn't supposed to be. Struggles with freeing memory when delete[] array created from toArray() is called.

8. This one failed my test_large_tree() test, in which I created a large bST from 0 to 1000 and then attempted to remove all of its elements. This one failed to verify that the tree had all elements present that were previously added. 

9.

10. This one seg faulted when I copied an empty tree and then casted it into an array. It returned a "free(): invalid pointer" error. If I then create two arrays of the original empty tree and compare the copied empty array to them, it causes the program to segfault, suggested that the copy constructor may not handle empty trees correctly in this one.

# Submission
You don't need to submit anything on Gradescope, just push your test code and your updated README to Github.

