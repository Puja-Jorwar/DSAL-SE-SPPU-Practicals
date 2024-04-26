#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void traversal(Node* root) {
    if (root == NULL) {
        return;
    }
    else {
        cout << root->data << " ";
        traversal(root->left);
        traversal(root->right);
    }
}

Node* insert(Node* &root, int x) {
    if (root == NULL) {
        root = new Node(x);
    }
    else if (x >= root->data) {
        root->right = insert(root->right, x);
    }
    else if (x < root->data) {
        root->left = insert(root->left, x);
    }
    return root;
}

int depth(Node* root) {
    if (root == NULL) {
        return 0;
    }    
    int left_subtree = 1 + depth(root->left);
    int right_subtree = 1 + depth(root->right);
    return max(left_subtree, right_subtree);
}

int minimum(Node* root) {
    if (root->left == NULL) {
        return root->data;
    }
    return min(minimum(root->left), root->data);
}

bool search(Node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    else if (root->data > key) {
        return search(root->left, key);
    }
    else if (root->data <= key) {
        return search(root->right, key);
    }
    return false; // Return false if the element is not found
}

void mirror(Node* &root) {
    if (root == NULL) {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

int main() {
    Node *root = NULL;
    int n;
    cout << "Enter the number of nodes to be inserted in the BST-\n";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int element;
        cout << "Enter the data value to be inserted-\n";
        cin >> element;
        insert(root, element);
    }
    cout << "Displaying the elements of the BST-\n";
    traversal(root);
    cout << endl;
    cout << "Depth of the tree is " << depth(root) << endl;
    cout << "Minimum value in the BST is " << minimum(root) << endl;
    
    char choice;
    do {
        int key;
        cout << "Enter the data value to be searched in the BST-\n";
        cin >> key;
        if (search(root, key)) {
            cout << "Key is present in the BST!" << endl;
        }
        else {
            cout << "Key is not present in the BST!" << endl;
        }
        cout << "Do you want to search for another key? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}


/*
OUTPUT:
Enter the number of nodes to be inserted in the BST-
12
Enter the data value to be inserted-
10
Enter the data value to be inserted-
8
Enter the data value to be inserted-
15
Enter the data value to be inserted-
12
Enter the data value to be inserted-
13
Enter the data value to be inserted-
7
Enter the data value to be inserted-
9
Enter the data value to be inserted-
17
Enter the data value to be inserted-
20
Enter the data value to be inserted-
18
Enter the data value to be inserted-
4
Enter the data value to be inserted-
5
Displaying the elements of the BST-
10 8 7 4 5 9 15 12 13 17 20 18
Depth of the tree is 5
Minimum value in the BST is 4
Enter the data value to be searched in the BST-
16
Key is not present in the BST!
Do you want to search for another key? (y/n): y
Enter the data value to be searched in the BST-
17
Key is present in the BST!
Do you want to search for another key? (y/n): y
Enter the data value to be searched in the BST-
9
Key is present in the BST!
Do you want to search for another key? (y/n): y
Enter the data value to be searched in the BST-
1
Key is not present in the BST!
Do you want to search for another key? (y/n): n
*/
