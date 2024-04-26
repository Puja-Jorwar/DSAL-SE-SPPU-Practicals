#include <iostream>
using namespace std;

// Structure for a dictionary entry
struct Entry {
    string keyword;
    string meaning;
    Entry* left;
    Entry* right;
    int height;
};

// Function to get the height of a node
int getHeight(Entry* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new dictionary entry
Entry* createEntry(string keyword, string meaning) {
    Entry* entry = new Entry;
    entry->keyword = keyword;
    entry->meaning = meaning;
    entry->left = NULL;
    entry->right = NULL;
    entry->height = 1;
    return entry;
}

// Function to perform a right rotation
Entry* rightRotate(Entry* y) {
    Entry* x = y->left;
    Entry* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Function to perform a left rotation
Entry* leftRotate(Entry* x) {
    Entry* y = x->right;
    Entry* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Function to get the balance factor of a node
int getBalance(Entry* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to insert a new entry into the dictionary
Entry* insertEntry(Entry* root, string keyword, string meaning) {
    if (root == NULL)
        return createEntry(keyword, meaning);

    if (keyword < root->keyword)
        root->left = insertEntry(root->left, keyword, meaning);
    else if (keyword > root->keyword)
        root->right = insertEntry(root->right, keyword, meaning);
    else {
        cout << "Keyword already exists in the dictionary." << endl;
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && keyword < root->left->keyword)
        return rightRotate(root);

    if (balance < -1 && keyword > root->right->keyword)
        return leftRotate(root);

    if (balance > 1 && keyword > root->left->keyword) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && keyword < root->right->keyword) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to traverse and print the AVL tree in inorder
void printInorder(Entry* root) {
    if (root == NULL)
        return;
    
    printInorder(root->left);
    cout << "Keyword: " << root->keyword << ", Meaning: " << root->meaning << endl;
    printInorder(root->right);
}

int main() {
    Entry* root = NULL;

    // Inserting entries into the AVL tree
    root = insertEntry(root, "apple", "A fruit");
    root = insertEntry(root, "banana", "Another fruit");
    root = insertEntry(root, "cat", "An animal");

    // Printing the contents of the AVL tree
    cout << "Contents of the AVL tree:" << endl;
    printInorder(root);
    
    return 0;
}
