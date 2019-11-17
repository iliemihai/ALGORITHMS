#ifndef __BinaryTreeNode__H
#define __BinaryTreeNode__H

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
  BinaryTreeNode(T data);
  ~BinaryTreeNode();
  void setData(T data);
  T getData();
  void setLeftChild(BinaryTreeNode* node);
  void setRightChild(BinaryTreeNode* node);
  BinaryTreeNode* getLeftChild(BinaryTreeNode* node);
  BinaryTreeNode* getRightChild(BinaryTreeNode* node);
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;
  T data;
};

template<typename T>
class BinaryTree {
public:
  BinaryTree();
  ~BinaryTree();

  BinaryTreeNode<T>* insertData(BinaryTreeNode<T>* node, T Data);
  vector<T> traversal(BinaryTreeNode<T>* root);
  int size;
  BinaryTreeNode<T>* root;
};

#endif
