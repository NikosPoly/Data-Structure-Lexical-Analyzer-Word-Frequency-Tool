#include <iostream>
#include <fstream>
#include "binarytree.h"
#include "avltree.h"
#include "hashtable.h"
#include <chrono>
using namespace std;


bool ValidateFile(const std::string& filename) {
    std::ifstream fileStream(filename.c_str());
    if (!fileStream.is_open()) {
        cerr << "Error: Unable to open file: " << filename << std::endl;
        return false;
    }

    // Check if the file is empty
    fileStream.seekg(0, std::ios::end);
    if (fileStream.tellg() == 0) {
        cerr << "Error: File is empty: " << filename << std::endl;
        return false;
    }

    // Reset file position to the beginning
    fileStream.seekg(0, ios::beg);

    // Perform additional validation if needed
    // For example, check if the file format is correct

    return true;
}


/*
string* Resize(string *old,unsigned oldsize,unsigned newsize){
    string *tmp=new string[newsize];
    if(newsize<oldsize) oldsize=newsize;
    for(int i=0;i<oldsize;++i)
        tmp[i]=old[i];
    delete[] old;
    return tmp;
}
*/

int main()
{
    string filename;
    cout << "Enter the name of the input file: ";
    cin >> filename;

    // Check if the file is valid
    if (!ValidateFile(filename)) {
        return 1; // Return error code
    }

    int choice;
    bool validChoice = false;

    while (!validChoice) {
        cout << "Choose the data structure to use:\n";
        cout << "1. AVL Tree\n";
        cout << "2. Binary Tree\n";
        cout << "3. Hash Table\n";
        cout << "Enter your choice (1/2/3): ";
        cin >> choice;

        // Check if the choice is valid
        if (choice >= 1 && choice <= 3) {
            validChoice = true;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }
    }
    
    switch (choice) {
        case 1: {
            auto start = chrono::high_resolution_clock::now();
            AVLTree avltree;
            int numWords = avltree.CreateTree(filename);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<float> duration = end - start;
            cout << "It takes " << duration.count() << " seconds for the AVL tree to be created." << endl;

            if (numWords != -1) {
                cout << "Successfully created tree with " << numWords << " words." << endl;

                string response;
                while (true) {
                    cout << "Do you want to search for a specific word? (yes/no): ";
                    cin >> response;
                    
                    if (response == "yes") {
                        // Perform searches after creating the tree
                        string searchWord;
                        cout << "Enter a word to search for: ";
                        cin >> searchWord;

                        // Perform search
                        avltree.Search(searchWord);
                    } else if (response == "no") {
                        break;
                    } else {
                        cout << "Invalid response. Please enter 'yes' or 'no'." << endl;
                    }
                }
            } else {
                cerr << "Failed to create tree." << endl;
            }
            break;
        }
        case 2: {
            auto start = chrono::high_resolution_clock::now();
            BinaryTree binarytree;
            int numWords = binarytree.CreateTree(filename);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<float> duration = end - start;
            cout << "It takes " << duration.count() << " seconds for the binary tree to be created." << endl;

            if (numWords != -1) {
                cout << "Successfully created tree with " << numWords << " words." << endl;

                string response;
                while (true) {
                    cout << "Do you want to search for a specific word? (yes/no): ";
                    cin >> response;
                    
                    if (response == "yes") {
                        // Perform searches after creating the tree
                        string searchWord;
                        cout << "Enter a word to search for: ";
                        cin >> searchWord;

                        // Perform search
                        binarytree.Search(searchWord);
                    } else if (response == "no") {
                        break;
                    } else {
                        cout << "Invalid response. Please enter 'yes' or 'no'." << endl;
                    }
                }
            } else {
                cerr << "Failed to create tree." << endl;
            }
            break;
        }
        case 3: {
            auto start = chrono::high_resolution_clock::now();
            HashTable hashtable;   
            int wordCount = hashtable.CreateHashTable(filename);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<float> duration = end - start;
            cout << "It takes " << duration.count() << " seconds for the hash table to be created." << endl;

            if (wordCount != -1) {
                cout << "Successfully created hash table with " << wordCount << " words." << endl;

                string response;
                while (true) {
                    cout << "Do you want to search for a specific word? (yes/no): ";
                    cin >> response;
                    
                    if (response == "yes") {
                        // Perform searches after creating the table
                        string searchWord;
                        cout << "Enter a word to search for: ";
                        cin >> searchWord;

                        // Perform search
                        hashtable.search(searchWord);
                    } else if (response == "no") {
                        break;
                    } else {
                        cout << "Invalid response. Please enter 'yes' or 'no'." << endl;
                    }
                }
            } else {
                cerr << "Failed to create table" << endl;
            }
            break;
        }
        default:
            cout << "Invalid choice. Exiting." << endl;
    }

    return 0;
}
