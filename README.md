# Data Structure Lexical Analyzer: Word Frequency Tool

## Description
This project is a C++ program that reads a file provided by the user and allows them to choose between three data structures: Binary Tree, AVL Tree, and Hash Table. It then stores all unique words from the file along with the number of times each word appears. Additionally, users can search for a specific word within the chosen data structure.

## Files
- **main.cpp**: Contains the main function and user interface logic.
- **binarytree.cpp** and **binarytree.h**: Implementations of a binary search tree data structure.
- **avltree.cpp** and **avltree.h**: Implementations of an AVL tree data structure.
- **hashtable.cpp** and **hashtable.h**: Implementations of a hash table data structure.

## Requirements
- C++ compiler (e.g., g++)
- Input file containing text data

## Usage
1. To compile the program:
    g++ main.cpp binarytree.cpp avltree.cpp hashtable.cpp -o main

2. To execute the program:
    ./main
3. Enter the name of the input file when prompted.
4. Choose a data structure to use (Binary Tree, AVL Tree, or Hash Table) by entering the corresponding number.
5. Depending on the chosen data structure:
   - For Binary Tree or AVL Tree: The program will display the time taken to create the tree and provide options to search for specific words.
   - For Hash Table: The program will display the time taken to create the table and provide options to search for specific words.
6. Repeat step 5 as desired.
7. Exit the program when done.



## Example
### Input

Suppose you have a file named `input.txt` containing the following text:
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.

### Output

When you run the program with this input file, and you choose to use an AVL Tree (option 1), you might see output similar to the following:

It takes 85.005 seconds for the AVL tree to be created.
Successfully created tree with 44 words.
Do you want to search for a specific word? (yes/no): yes
Enter a word to search for: Lorem
the word "Lorem" found 1 times in the tree.
Do you want to search for a specific word? (yes/no): yes
Enter a word to search for: ipsum
the word "ipsum" found 1 times in the tree.
Do you want to search for a specific word? (yes/no): no

sql


## Authors
Developed by NikosPoly.

## License
This project is licensed under the [License Name] License - see the [LICENSE](LICENSE) file for details.
