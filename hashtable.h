#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

// Node class
class Node {
public:
    string value;
    int key;
    int appear;

    Node(int key, const string& value);
};

// HashTable class
class HashTable {
    vector<unique_ptr<Node>> arr;
    int capacity;
    int size;

    int hashCode(int key) const;
    void rehash();

public:
    HashTable();
    ~HashTable();

    int CreateHashTable(const std::string& filename);
    void insertNode(const string& value);
    void search(const string& value) const;
    int sizeofMap() const;
    bool isEmpty() const;
    void printElements() const;
};

#endif // HASHMAP_H