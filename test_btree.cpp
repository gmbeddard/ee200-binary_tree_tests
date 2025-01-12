#include <cstdio>
#include <assert.h>
#include "btree.h"
#include <climits>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <ctime>

void test_add() {
  BTree tree_add;
  tree_add.add(10);
  assert(tree_add.contains(10));
  assert(tree_add.size() == 1);

  // If the element already exists in the tree, it is ignored (a second copy
  // is not added).
  void add(int value);
  tree_add.add(10);
  assert(tree_add.size() == 1);
}

void test_add_weird() {
  BTree test_neg;
  test_neg.add(-1);
  assert(test_neg.contains(-1) == 1);
  assert(test_neg.size() == 1);

  // trying with int_max and int_min
  test_neg.add(INT_MAX);
  assert(test_neg.contains(INT_MAX) == 1);
  assert(test_neg.size() == 2);

}

void test_remove() {
  BTree remove_tree;
  remove_tree.add(1);
  assert(remove_tree.contains(1));
  assert(remove_tree.size() == 1);

  remove_tree.remove(1);
  assert(remove_tree.size() == 0);

  // next try removing a value that doesn't exist
  remove_tree.add(2);
  remove_tree.remove(1);  
  assert(remove_tree.contains(1) == 0);
  assert(remove_tree.size() == 1);
}

void test_contains() {
  BTree tree_contains;
  tree_contains.add(1);
  tree_contains.add(0);
  tree_contains.add(1000);

  // should pass
  assert(tree_contains.contains(1) == 1 && tree_contains.contains(0) == 1 && tree_contains.contains(1000) == 1);
  // should fail
  assert(tree_contains.contains(-3) == 0);
  assert(tree_contains.size() == 3);
  tree_contains.remove(0);
  assert(tree_contains.size() == 2);
}

void test_to_Array() {
  BTree array_tree;
  // assert(array_tree.toArray() == NULL);

  // array_tree.add(1);
  // array_tree.remove(1);
  // assert(array_tree.toArray() == NULL);

  array_tree.add(2);
  array_tree.add(1);
  array_tree.add(3);

  int* array = array_tree.toArray();
  assert(array != nullptr);

  assert(array[0] == 1);
  assert(array[1] == 2);
  assert(array[2] == 3);

  // // Print the array contents
  // printf("Array contents: ");
  // for (int i = 0; i < 3; i++) {
  //   printf("%d ", array[i]);
  // }
  // printf("\n");

  // delete
  delete[] array;

  printf("toArray deletion test passed (check with Valgrind for leaks).\n");
}

void test_deep_copy() {
  //BTree copy_tree;
  BTree orig_tree;

  // copy two "full" trees
  orig_tree.add(3);
  orig_tree.add(4);
  // assert(orig_tree.size() != copy_tree.size());

  BTree copy_tree = orig_tree;
  assert(orig_tree.size() == copy_tree.size());

  copy_tree.remove(3);
  assert(orig_tree.size() == 2 && copy_tree.size() == 1);
  
  orig_tree.add(2);
  assert(orig_tree.size() == 3 && copy_tree.size() == 1);

  copy_tree.remove(4);
  assert(orig_tree.size() == 3 && copy_tree.size() == 0);

  copy_tree.remove(1); // should do nothing
  assert(orig_tree.size() == 3 && copy_tree.size() == 0);

  // orig_tree = copy_tree;
  // assert(orig_tree.size() == 0 && copy_tree.size() == 0);
  
}

void test_destructor() {
  // use constructor
  {
  BTree* des = new BTree();
  des->add(10);
  des->add(1);
  des->add(2);
  delete des;  
  }
  printf("Destructor test passed (check Valgrind for leaks).\n");
}

void test_cons_dest() {
  BTree tree_cons;
  assert(tree_cons.size() == 0);
  int* array = tree_cons.toArray();
  assert(array == NULL);
  //printf("COnstructor works\n");
  delete[] array;

  tree_cons.add(1);
  tree_cons.add(2);
  tree_cons.add(3);
  assert(tree_cons.size() == 3);
  int* array2 = tree_cons.toArray();
  assert(array2 != NULL);
  delete[] array2;
}

void test_node() {
  BTree node_tree;

  node_tree.add(10);
  node_tree.add(5);
  node_tree.add(15);

  assert(node_tree.mRoot != nullptr);
  assert(node_tree.mRoot->value == 10);
  assert(node_tree.mSize == node_tree.size());
  assert(node_tree.mRoot->left != nullptr);
  assert(node_tree.mRoot->left->value == 5);
  assert(node_tree.mRoot->right != nullptr);
  assert(node_tree.mRoot->right->value == 15);
  assert(node_tree.mRoot->left->left == nullptr);
  assert(node_tree.mRoot->left->right == nullptr);
  assert(node_tree.mRoot->right->left == nullptr);
  assert(node_tree.mRoot->right->right == nullptr);
  assert(node_tree.mSize == node_tree.size());

  node_tree.add(3);
  assert(node_tree.mSize == node_tree.size());

  node_tree.add(7);
  node_tree.add(12);
  node_tree.add(20);

  assert(node_tree.mRoot->left->left->value == 3);
  assert(node_tree.mRoot->left->right->value == 7);
  assert(node_tree.mRoot->right->left->value == 12);
  assert(node_tree.mRoot->right->right->value == 20);
}

void test_duplicate_add() {
  BTree tree_dup;

  tree_dup.add(10);
  tree_dup.add(10);  
  assert(tree_dup.size() == 1);  // Size should remain 1
  assert(tree_dup.contains(10));  // Contains the single value

  tree_dup.add(5);
  tree_dup.add(5);  // Duplicate
  assert(tree_dup.size() == 2);  // Size should be 2
  assert(tree_dup.contains(5));
}

void test_repeated_add_remove() {
  BTree tree_repeat;

  for (int i = 0; i < 10000; i++) {
    tree_repeat.add(10);
    assert(tree_repeat.size() == 1);  // Size should stay 1
    assert(tree_repeat.contains(10));

    tree_repeat.remove(10);
    assert(tree_repeat.size() == 0);  // Size should return to 0
    assert(!tree_repeat.contains(10));
  }
}

void test_remove_root() {
  BTree tree_root;

  tree_root.add(10);
  tree_root.add(15);
  tree_root.add(5);

  tree_root.remove(10);  // Remove root
  assert(tree_root.size() == 2);  // Size should decrease
  assert(!tree_root.contains(10));  // Root should no longer exist
  tree_root.add(0);

  int* array = tree_root.toArray();
  assert(array[0] == 0);  // Check remaining nodes
  assert(array[1] == 5);
  assert(array[2] == 15);
  delete[] array;
}

void test_large_tree() {
  BTree large_tree;

  // Add a large number of elements
  for (int i = 0; i < 100; i++) {
    large_tree.add(i);
    assert(large_tree.size() == i + 1);  // Size should increase incrementally
  }

  // Check that all elements are present
  for (int i = 0; i < 100; i++) {
    assert(large_tree.contains(i));
  }

  // Remove all elements
  for (int i = 0; i < 100; i++) {
    large_tree.remove(i);
    assert(!large_tree.contains(i));  // Removed element should not exist
    assert(large_tree.size() == 99 - i);  // Size should decrease incrementally
  }
}

void test_remove_edge_cases() {
  BTree edge_tree;

  // Add elements
  edge_tree.add(10);
  edge_tree.add(5);
  edge_tree.add(15);
  edge_tree.add(12);  // Left child of right child
  edge_tree.add(18);  // Right child of right child

  edge_tree.remove(15);  // Node with two children
  assert(edge_tree.size() == 4);  // Size should decrease
  assert(!edge_tree.contains(15));
  assert(edge_tree.contains(12));  // Left child of removed node should remain
  assert(edge_tree.contains(18));  // Right child of removed node should remain

  edge_tree.remove(12);  // Node with one child
  assert(edge_tree.size() == 3);
  assert(!edge_tree.contains(12));

}

void test_even_larger_tree() {
  BTree large_tree;

  // Add a large number of elements
  for (int i = 0; i < 10000; i++) {
    large_tree.add(i);
    assert(large_tree.size() == i + 1);  // Size should increase incrementally
  }

  // Check that all elements are present
  for (int i = 0; i < 10000; i++) {
    assert(large_tree.contains(i));
  }

  // Remove all elements
  for (int i = 0; i < 10000; i++) {
    large_tree.remove(i);
    assert(!large_tree.contains(i));  // Removed element should not exist
    assert(large_tree.size() == 9999 - i);  // Size should decrease incrementally
  }
}

void test_multiple_toArray() {
  BTree tree_multi_array;
  tree_multi_array.add(2);
  tree_multi_array.add(1);
  tree_multi_array.add(3);

  for (int i = 0; i < 10; i++) {
    int* array = tree_multi_array.toArray();
    assert(array != nullptr);
    assert(array[0] == 1);
    assert(array[1] == 2);
    assert(array[2] == 3);
    delete[] array;  // Ensure no memory leak occurs
  }
}

void test_destructor_empty() {
  BTree* tree = new BTree();  // Empty tree
  delete tree;                // Destructor should handle this without errors
}

void test_ops_on_empty_array() {
  BTree empty;
  int* array_empty = empty.toArray();
  int* array_empty2 = empty.toArray();
  // assert(array_empty == nullptr && array_empty2 == nullptr);
  // assert(array_empty == array_empty2);

  BTree copy = empty;
  int* array_copy = copy.toArray();
  assert(array_copy == nullptr);
  assert(array_copy == array_empty);
  assert(array_copy == array_empty2);
  assert(copy.mRoot == nullptr && empty.mRoot == nullptr);
  assert(copy.mRoot == empty.mRoot);
  copy.add(11111);

  delete[] array_empty;
  delete[] array_empty2;
  delete[] array_copy;
}

void test_ops_on_empty_array_test92() {
  BTree empty, empty2;
  empty.add(1);
  empty2 = empty;

  empty.add(2);

  int* array_empty = empty.toArray();
  int* array_empty2 = empty2.toArray();
  assert(array_empty != nullptr && array_empty2 != nullptr);
  assert(array_empty != array_empty2);
  assert(array_empty[1] == 2 && array_empty2[0] == 1);

  // BTree copy = empty;
  // copy.add(1);
  // copy.remove(1);
  // copy.remove(1);
  // empty.add(1);
  // empty.add(1);
  // empty.remove(1);
  // int* array_copy = copy.toArray();
  // assert(copy.size() == empty.size());
  // assert(array_copy == nullptr);
  // assert(array_copy == array_empty);
  // assert(array_copy == array_empty2);

  delete[] array_empty;
  delete[] array_empty2;
  // delete[] array_copy;
}

void test_remove_leaf() {
  BTree* leaf = new BTree();
  leaf->add(1);
  
  leaf->~BTree();
}

void test_direct_mSize_manipulation() {
  BTree tree, copy;

  // Add elements
  tree.add(42);
  tree.add(24);
  tree.add(66);
  int* array = tree.toArray();

  // Manually tamper with mSize
  tree.mSize = 999;
  assert(tree.size() == 999);  // If size() uses mSize directly, this will pass
  assert(tree.size() != (sizeof(array)/sizeof(array[0])));
  
  copy = tree;
  int* copy_array = copy.toArray();
  assert(copy.mSize == 999);
}


int main(int argc, char* argv[])
{
  // // test add
  // test_add();
  // // printf("Test add passed!\n");

  // // test remove 
  // test_remove();
  // // printf("Test remove passed!\n");

  // // test contains
  // test_contains();
  // //printf("Test contains passed!\n");

  // // test adds negative numbers
  // test_add_weird();
  // // printf("Test add weird passed!\n");

  // // test toArray
  // test_to_Array();
  // // printf("Test to array passed!\n");

  // test_deep_copy();
  // // printf("Test deep copy passed!\n");

  // test_destructor();
  // // printf("Test destructor passed!\n");

  // test_to_Array();
  
  // test_cons_dest();
  // // printf("test const des passed!\n");

  // test_node();
  // // printf("test node passed!\n");

  // test_duplicate_add();
  // // printf("test add duplicate passed!\n");

  // test_repeated_add_remove();
  // // printf("test repeated passed!\n");

  // test_remove_root();
  // // printf("test remove root passed!\n");

  // test_large_tree();
  // // printf("test large tree passed!\n");

  // test_even_larger_tree();
  // // printf("test larger tree passed!\n");

  // test_remove_edge_cases();
  // // printf("test remove edge cases passed!\n");

  // test_multiple_toArray();
  // // printf("test multiple toArray passed!\n");

  // test_destructor_empty();
  // // printf("test_destructor_empty passed (check Valgrind for leaks).\n");

  // test_ops_on_empty_array();
  // test_ops_on_empty_array();
  // test_remove_leaf();
  test_direct_mSize_manipulation();

  return 0;
}