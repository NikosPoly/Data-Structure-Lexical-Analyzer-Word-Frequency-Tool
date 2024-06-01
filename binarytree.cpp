#include "binarytree.h"
#include <iostream>
#include <fstream>
#include <chrono>

// Constructor for BinaryTree::Node
BinaryTree::Node::Node(const std::string& s, Node* l, Node* r)
    : word(s), appear(1), leftChild(l), rightChild(r) {}

// BinaryTree constructor
BinaryTree::BinaryTree() : root(nullptr), pin(nullptr) {
    std::cout << "Create Binary Tree" << std::endl;
}

// CreateTree method
int BinaryTree::CreateTree(const std::string& filename) {
    int wordCount = 0;
    std::ifstream data(filename);
    if (!data) {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        return -1;
    }
    pin = new std::string[1];
    std::string s;
    while (data >> s) {
        root = Insert(root, s);
        wordCount++;
    }
    if (data.bad()) {
        std::cerr << "Error reading file: " << filename << std::endl;
        return -1;
    }
    return wordCount;
}

// Insert method
BinaryTree::Node* BinaryTree::Insert(Node* n, const std::string& word) {
    if (n == nullptr) {
        n = new Node(word);
        return n;
    } else if (word < n->word) {
        n->leftChild = Insert(n->leftChild, word);
    } else if (word > n->word) {
        n->rightChild = Insert(n->rightChild, word);
    } else {
        n->appear++;
    }
    return n;
}

// Delete method
BinaryTree::Node* BinaryTree::Delete(Node* n, const std::string& word, bool& found) {
    if (n == nullptr) {
        found = false;
        return nullptr;
    }

    if (word < n->word) {
        n->leftChild = Delete(n->leftChild, word, found);
    } else if (word > n->word) {
        n->rightChild = Delete(n->rightChild, word, found);
    } else {
        found = true;
        if (n->appear > 1) {
            n->appear--;
        } else {
            if (n->leftChild == nullptr) {
                Node* temp = n->rightChild;
                delete n;
                return temp;
            } else if (n->rightChild == nullptr) {
                Node* temp = n->leftChild;
                delete n;
                return temp;
            }

            Node* temp = MinNode(n->rightChild);
            n->word = temp->word;
            n->appear = temp->appear;
            n->rightChild = Delete(n->rightChild, temp->word, found);
        }
    }
    return n;
}

// Implementation of MinNode function
BinaryTree::Node* BinaryTree::MinNode(Node* n) const {
    Node* current = n;
    while (current && current->leftChild != nullptr) {
        current = current->leftChild;
    }
    return current;
}


// InOrder traversal
void BinaryTree::InOrder(Node* treeNode) const {
    if (treeNode == nullptr) {
        return;
    }
    InOrder(treeNode->leftChild);
    std::cout << treeNode->word << " ";
    InOrder(treeNode->rightChild);
}

// PreOrder traversal
void BinaryTree::PreOrder(Node* treeNode) const {
    if (treeNode == nullptr) {
        return;
    }
    std::cout << treeNode->word << " ";
    PreOrder(treeNode->leftChild);
    PreOrder(treeNode->rightChild);
}

// PostOrder traversal
void BinaryTree::PostOrder(Node* treeNode) const {
    if (treeNode == nullptr) {
        return;
    }
    PostOrder(treeNode->leftChild);
    PostOrder(treeNode->rightChild);
    std::cout << treeNode->word << " ";
}

// Search method
bool BinaryTree::Search(const std::string& str) const {
    Node* currentNode = root;
    while (currentNode != nullptr) {
        if (currentNode->word == str) {
            std::cout << "the word \"" << currentNode->word << "\" found " << currentNode->appear << " times in the tree."<<'\n';
            return true;
        }
        if (str < currentNode->word) {
            currentNode = currentNode->leftChild;
        } else {
            currentNode = currentNode->rightChild;
        }
    }
    std::cout << "This word does not exist in the tree." << std::endl;
    return false;
}

// Resize method
std::string* BinaryTree::Resize(std::string* old, unsigned oldsize, unsigned newsize) {
    std::string* tmp = new std::string[newsize];
    unsigned minSize = (oldsize < newsize) ? oldsize : newsize;
    for(unsigned i = 0; i < minSize; ++i) {
        tmp[i] = old[i];
    }
    delete[] old;
    return tmp;
}

// Destructor
BinaryTree::~BinaryTree() {
    Clear(root);
    std::cout << "Binary Tree Destructed" << std::endl;
}

// Clear method to delete all nodes
void BinaryTree::Clear(Node* node) {
    if (node != nullptr) {
        Clear(node->leftChild);
        Clear(node->rightChild);
        delete node;
    }
}
