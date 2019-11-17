#include "BinaryTree.h"
template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(T x) {
    this->data = x;
    this->left = NULL;
    this->right = NULL;
}

template<typename T>
BinaryTreeNode<T>::~BinaryTreeNode() {
}

template<typename T>
T BinaryTreeNode<T>::getData() {
    return this->data;
}

template<typename T>
void BinaryTreeNode<T>::setData(T data) {
    this->data=data;
}

template<typename T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode* node) {
    this->left = node;
}

template<typename T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode* node) {
    this->right = node;
}

template<typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getLeftChild(BinaryTreeNode* node) {
    return this->left;

}

template<typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRightChild(BinaryTreeNode* node) {
    return this->right;
}

template<typename T>
BinaryTree<T>::BinaryTree(){
    this->root = NULL;
}

template<typename T>
BinaryTree<T>::~BinaryTree(){}

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::insertData(BinaryTreeNode<T>* cur, T data){
   
    if(cur==NULL){
        return new BinaryTreeNode<T>(data);
    }
    if(data<cur->data){
        cur->left = insertData(cur->left, data);
    }
    else if(data>cur->data){
        cur->right = insertData(cur->right, data);
    }
    return cur;
}

template<typename T>
vector<T> BinaryTree<T>::traversal(BinaryTreeNode<T>* r) {
    vector<T> res;
    if(r!=NULL){
        traversal(r->left);
        cout << r->data << "\n";
        res.push_back(r->data);
        traversal(r->right);
    }
    return res;
}

template class BinaryTreeNode<int>;
template class BinaryTree<int>;