// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>

class BST {
 private:
  struct Node {
    T val;
    Node *right;
    Node *left;
    int count;
};

Node *root;
Node *addNode(Node *root, T x) {
    if (root == nullptr) {
        root = new Node;
        root->val = x;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        if (root->val > x) root->left = addNode(root->left, x);
        if (root->val < x) root->right = addNode(root->right, x);
        if (root->val == x) (root->count)++;
    }
    return root;
  }

int value(Node* root, T x) {
    if (root == nullptr) {
      return 0;
    } else {
        if (root->val == x) return root->count;
        if (root->val > x) return searchValue(root->left, x);
        if (root->val < x) return searchValue(root->right, x);
    }
}

 public:
  BST() : root(nullptr) {}
  void add(T x) {
    root = addNode(root, x);
  }
};

#endif  // INCLUDE_BST_H_
