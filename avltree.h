// avltree.h

#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <fstream>
#include "binarytree.h"

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void Inserted(std::string str);
    bool Search(std::string str) const;
    int CreateTree(const std::string& filename);
    bool Deletede(std::string str);
    void inOrder() const;
    void preOrder() const;
    void postOrder() const;
    std::string* Resize(std::string* old, unsigned oldsize, unsigned newsize);

private:
    struct Node {
        Node(std::string s, Node* l, Node* r);
        std::string word;
        int appear = 1;
        Node* leftChild;
        Node* rightChild;
        int height();
    };

    Node* Insert(Node* n, std::string word);
    Node* Deleted(Node* n, std::string word, bool& found);
    Node* BalanceNode(Node* n);
    Node* RightRotation(Node* n);
    Node* LeftRotation(Node* n);
    int nodeBalanceFactor(Node* n);
    void inOrder(Node* treeNode) const;
    void preOrder(Node* treeNode) const;
    void postOrder(Node* treeNode) const;
    Node* MinNode(Node* n) const;
    void Clear(Node* node);

    Node* root;
    int elements;
    std::string* p;
};

#endif // AVLTREE_H
