// avltree.cpp

#include "avltree.h"

// Constructor
AVLTree::AVLTree() : root(nullptr), elements(0), p(nullptr) {
    std::cout << "AVL Tree Created" << std::endl;
}

// Node Constructor
AVLTree::Node::Node(std::string s, Node* l, Node* r) : word(s), leftChild(l), rightChild(r), appear(1) {}

// Method to calculate height of a node
int AVLTree::Node::height() {
    int h = 0;
    if (this != nullptr) {
        int leftHeight = (this->leftChild != nullptr) ? this->leftChild->height() : 0;
        int rightHeight = (this->rightChild != nullptr) ? this->rightChild->height() : 0;
        int maxHeight = (leftHeight > rightHeight) ? leftHeight : rightHeight;
        h = maxHeight + 1;
    }
    return h;
}

// Insert a node
void AVLTree::Inserted(std::string str) {
    root = Insert(root, str);
    elements++;
}

// Method to read a file and insert each string into the tree
int AVLTree::CreateTree(const std::string& filename) {
    int wordCount = 0;
    std::ifstream data(filename);
    if (!data) {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        return -1;
    }
    p = new std::string[1];
    std::string s;
    while (data >> s) {
        Inserted(s);
        wordCount++;
    }
    if (data.bad()) {
        std::cerr << "Error reading file: " << filename << std::endl;
        return -1;
    }
    return wordCount;
}

// Insert a node into the AVL tree
AVLTree::Node* AVLTree::Insert(Node* n, std::string word) {
    if (n == nullptr) {
        Node* n = new Node(word, nullptr, nullptr);
        return n;
    } else if (word < n->word) {
        n->leftChild = Insert(n->leftChild, word);
    } else if (word > n->word) {
        n->rightChild = Insert(n->rightChild, word);
    } else {
        n->appear++;
    }
    n = BalanceNode(n);
    return n;
}

// Method to delete a node
bool AVLTree::Deletede(std::string str) {
    bool found = false;
    root = Deleted(root, str, found);
    return found;
}

//This method find the node with the <<smaller(alphabet)>> string.
//This method is necessary in the method delete.
AVLTree::Node* AVLTree::MinNode(Node* n) const {
    Node* currentNode = n;
    if (currentNode != nullptr) {
        while (currentNode->leftChild != nullptr)
            currentNode = currentNode->leftChild;
        return currentNode;
    } else
        return n;
}

// Method to delete a node from the AVL tree
AVLTree::Node* AVLTree::Deleted(Node* n, std::string word, bool& found) {
    if (n == nullptr) {
        found = false;
        return nullptr;
    }

    if (word < n->word) {
        n->leftChild = Deleted(n->leftChild, word, found);
    } else if (word > n->word) {
        n->rightChild = Deleted(n->rightChild, word, found);
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
            n->rightChild = Deleted(n->rightChild, temp->word, found);
        }
    }
    return n;
}


// Method to search for a string in the AVL tree
bool AVLTree::Search(std::string str) const {
    Node* currentNode = root;
    while (currentNode != nullptr) {
        // If find the node, show the string and the number.
        if (currentNode->word == str) {
            std::cout << "the word \"" << currentNode->word << "\" found " << currentNode->appear << " times in the tree."<<'\n';
            return true;
        }
        if (str < currentNode->word)
            currentNode = currentNode->leftChild;
        else
            currentNode = currentNode->rightChild;
    }
    // If the string does not exist in the tree then show false.
    return false;
}

// In-order traversal
void AVLTree::inOrder() const {
    inOrder(root);
    std::cout << std::endl;
}

// Pre-order traversal
void AVLTree::preOrder() const {
    preOrder(root);
    std::cout << std::endl;
}

// Post-order traversal
void AVLTree::postOrder() const {
    postOrder(root);
    std::cout << std::endl;
}

// Method to balance a node in the AVL tree
AVLTree::Node* AVLTree::BalanceNode(Node* n) {
    if (n == nullptr)
        return n;

    int balanceFactor = nodeBalanceFactor(n);

    // Left heavy
    if (balanceFactor > 1) {
        if (nodeBalanceFactor(n->leftChild) < 0)
            n->leftChild = LeftRotation(n->leftChild);
        return RightRotation(n);
    }
    // Right heavy
    else if (balanceFactor < -1) {
        if (nodeBalanceFactor(n->rightChild) > 0)
            n->rightChild = RightRotation(n->rightChild);
        return LeftRotation(n);
    }
    return n;
}

// Method to perform a right rotation on a node in the AVL tree
AVLTree::Node* AVLTree::RightRotation(Node* n) {
    Node* temp = n->leftChild;
    n->leftChild = temp->rightChild;
    temp->rightChild = n;
    return temp;
}

// Method to perform a left rotation on a node in the AVL tree
AVLTree::Node* AVLTree::LeftRotation(Node* n) {
    Node* temp = n->rightChild;
    n->rightChild = temp->leftChild;
    temp->leftChild = n;
    return temp;
}

// Method to calculate the balance factor of a node in the AVL tree
int AVLTree::nodeBalanceFactor(Node* n) {
    if (n == nullptr)
        return 0;
    return n->leftChild->height() - n->rightChild->height();
}

// In-order traversal (recursive)
void AVLTree::inOrder(Node* treeNode) const {
    if (treeNode == nullptr)
        return;
    inOrder(treeNode->leftChild);
    std::cout << treeNode->word << " ";
    inOrder(treeNode->rightChild);
}

// Pre-order traversal (recursive)
void AVLTree::preOrder(Node* treeNode) const {
    if (treeNode == nullptr)
        return;
    std::cout << treeNode->word << " ";
    preOrder(treeNode->leftChild);
    preOrder(treeNode->rightChild);
}

// Post-order traversal (recursive)
void AVLTree::postOrder(Node* treeNode) const {
    if (treeNode == nullptr)
        return;
    postOrder(treeNode->leftChild);
    postOrder(treeNode->rightChild);
    std::cout << treeNode->word << " ";
}

// Method to dynamically resize an array
std::string* AVLTree::Resize(std::string* old, unsigned oldsize, unsigned newsize) {
    std::string* tmp = new std::string[newsize];
    unsigned minSize = (oldsize < newsize) ? oldsize : newsize;
    for (unsigned i = 0; i < minSize; ++i)
        tmp[i] = old[i];
    delete[] old;
    return tmp;
}


void AVLTree::Clear(Node* node) {
    if (node == nullptr) {
        return;
    }
    Clear(node->leftChild);
    Clear(node->rightChild);
    delete node;
}

AVLTree::~AVLTree() {
    Clear(root);
}
