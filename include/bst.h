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

  int searchNode(Node* root, T x) {
      if (root == nullptr) {
          return 0;
      } else {
          if (root->value == x) return root->count;
          if (root->value > x) return searchNode(root->left, x);
          if (root->val < x) return searchNode(root->right, x);
      }
  }

  int height(Node* root) {
      if (root == nullptr)
        return 0;
      if (root->left == nullptr && root->right == nullptr) return 0;
      int rt = height(root->right), lt = height(root->left);
      if (rt > lt)
        return rt + 1;
      else
        return lt + 1;
  }
 public:
  BST():root(nullptr) {}
  void add(T val) {
      root = addNode(root, val);
  }
  int depth() {
      return height(root);
  }
  int search(T val) {
      return searchNode(root, val);
  }
};

#endif  // INCLUDE_BST_H_
