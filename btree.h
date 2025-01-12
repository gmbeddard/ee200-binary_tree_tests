
/* BTree - Implements a binary search tree of integers */
class BTree
{
public:

  // Default constructor
  BTree();

  // Copy constructor, which makes a deep copy of the tree
  BTree(const BTree &other);

  // Destructor, which cleans up all memory
  ~BTree();

  // Adds an element to the tree
  // If the element already exists in the tree, it is ignored (a second copy
  // is not added).
  void add(int value);

  // Removes an element from the tree
  // If the element does not exist, this does nothing.
  void remove(int value);

  // Checks whether the tree contains a value
  bool contains(int value);

  // Returns the number of nodes in the tree
  int size(void);

  // Performs an inorder traversal of the tree and puts all of the values
  // into an array.  Note that you'll need to delete[] the array when you're
  // done with it.
  // If the tree is empty, returns NULL.
  int* toArray(void);

  // Assignment operator, which makes a deep copy of the tree
  const BTree& operator=(const BTree& other);

  class Node {
  public:
    Node(int val) {}
    int value;
    Node* left;
    Node* right;
  };

// Leave these public so you can examine the internals if you'd like
//private:
  Node* mRoot;
  int mSize;
};

