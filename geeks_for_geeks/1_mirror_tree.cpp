#include "../lib/BinaryTree.h"
using namespace std;

template<typename T>
void mirror(BinaryTreeNode<T>* node){
    //it's a post order traversal and instead of printing current node,
    // just swap it's childrens
    if(node) {
        BinaryTreeNode<T>* left = node->left;
        BinaryTreeNode<T>* right = node->right;
        mirror(left);
        mirror(right);
        //swap
        BinaryTreeNode<T>* aux = left;
        left = right;
        right = aux;
    }
}

int main(int argc, char** argv)
{
    BinaryTree<int> bt;
    // Insert data
 
	bt.root = bt.insertData(bt.root, 10);
    bt.insertData(bt.root, 30);
    bt.insertData(bt.root, 20);
    bt.insertData(bt.root, 40);
    bt.insertData(bt.root, 70);
    bt.insertData(bt.root, 60);
    bt.insertData(bt.root, 80);
    cout << "BEFORE MIRRORING" << "\n";
	std::vector<int> traversal = bt.traversal(bt.root);
	for (auto node : traversal) {
		std::cout << node << " ";
	}
    mirror(bt.root);
    cout << "AFTER MIRRORING" << "\n";
	traversal = bt.traversal(bt.root);
	for (auto node : traversal) {
		std::cout << node << " ";
	}
}