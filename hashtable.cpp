#include "hashtable.h"
#include <fstream>

// Node constructor
Node::Node(int key, const string& value) : key(key), value(value), appear(1) {}

// HashTable constructor
HashTable::HashTable() : capacity(16), size(0), arr(capacity) {
    std::cout << "Create Hash Table" << std::endl;
}

// HashTable destructor
HashTable::~HashTable() {
    std::cout << "Hash Table Destroyed" << std::endl;
}

// Hash function
int HashTable::hashCode(int key) const {
    return key % capacity;
}

// Method to create hash table from file
int HashTable::CreateHashTable(const std::string& filename) {
    int wordCount = 0; // Counter for the number of words processed
    std::ifstream file(filename); // Open the file
    if (!file) {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        return -1; // Return -1 to indicate failure
    }

    std::string word;
    while (file >> word) { // Read words from the file
        insertNode(word); // Insert each word into the hash table
        ++wordCount;
    }

    if (file.bad()) { // Check for any errors while reading the file
        std::cerr << "Error reading file: " << filename << std::endl;
        return -1; // Return -1 to indicate failure
    }

    return wordCount; // Return the number of words processed
}


// Rehash function to resize the hash table
void HashTable::rehash() {
    int oldCapacity = capacity;
    capacity *= 2;
    vector<unique_ptr<Node>> newArr(capacity);

    for (auto& node : arr) {
        if (node && node->key != -1) {
            int hashIndex = hashCode(node->key);
            while (newArr[hashIndex]) {
                hashIndex = hashCode(hashIndex + 1);
            }
            newArr[hashIndex] = move(node);
        }
    }
    arr = move(newArr);
}

// Insert a new node
void HashTable::insertNode(const string& value) {
    for (int i = 0; i < capacity; i++) {
        if (arr[i] != nullptr && arr[i]->key != -1) {
            if (arr[i]->value == value) {
                arr[i]->appear++;
                return;
            }
        }
    }
    if (size / capacity >= 0.7) {
        rehash();
    }

    int hashIndex = hashCode(size);
    while (arr[hashIndex]) {
        hashIndex = hashCode(hashIndex + 1);
    }

    arr[hashIndex] = make_unique<Node>(size, value);
    size++;
}

// Search for a word
void HashTable::search(const string& word) const {
    for (const auto& node : arr) {
        if (node && node->key != -1 && node->value == word) {
            cout << "the word \"" << node->value << "\" found " << node->appear << " times in the hash map."<<'\n';
            return;
        }
    }
    cout << "The " << word << " is not in the HashTable" << endl;
}

// Return the size of the hash table
int HashTable::sizeofMap() const {
    return size;
}

// Check if the hash table is empty
bool HashTable::isEmpty() const {
    return size == 0;
}

// Print all elements of the hash table
void HashTable::printElements() const {
    for (const auto& node : arr) {
        if (node && node->key != -1) {
            cout << "key = " << node->key << " value = " << node->value << " appear = " << node->appear << endl;
        }
    }
}
