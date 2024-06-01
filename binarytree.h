#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();
    int CreateTree(const std::string& filename);
    bool Search(const std::string& str) const;
    void InOrder() const;
    void PreOrder() const;
    void PostOrder() const;

private:
    struct Node {
        Node(const std::string& s, Node* l = nullptr, Node* r = nullptr);
        std::string word;
        int appear;
        Node* leftChild;
        Node* rightChild;
    };

    Node* Insert(Node* n, const std::string& word);
    Node* Delete(Node* n, const std::string& word, bool& found);
    Node* MinNode(Node* n) const;
    void InOrder(Node* treeNode) const;
    void PreOrder(Node* treeNode) const;
    void PostOrder(Node* treeNode) const;
    std::string* Resize(std::string* old, unsigned oldsize, unsigned newsize);
    void Clear(Node* node); // Declaration of Clear method

    Node* root;
    std::string* pin;
};

#endif // BINARYTREE_H
