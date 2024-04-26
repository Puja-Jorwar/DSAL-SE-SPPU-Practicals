#include <bits/stdc++.h>
using namespace std;
 

struct Node {
    int key;
    Node *left, *right;
 	bool isThreaded;
};
 
void populateQueue(Node* root, queue<Node*>* q)
{
    if (root == NULL)
        return;
    if (root->left)
        populateQueue(root->left, q);
    q->push(root);
    if (root->right)
        populateQueue(root->right, q);
}

void createThreadedUtil(Node* root, queue<Node*>* q)
{
    if (root == NULL)
        return;
 
    if (root->left)
        createThreadedUtil(root->left, q);
    q->pop();
 
    if (root->right)
        createThreadedUtil(root->right, q);

    else 
	{
        root->right = q->front();
        root->isThreaded = true;
    }
}

void createThreaded(Node* root)
{

    queue<Node*> q;

    populateQueue(root, &q);

    createThreadedUtil(root, &q);
}

Node* leftMost(Node* root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

void inOrder(Node* root)
{
    if (root == NULL)
        return;

    Node* cur = leftMost(root);
 
    while (cur != NULL) {
        cout << cur->key << " ";

        if (cur->isThreaded)
            cur = cur->right;
 
        else 
            cur = leftMost(cur->right);
    }
}

Node* newNode(int key)
{
    Node* temp = new Node;
    temp->left = temp->right = NULL;
    temp->key = key;
    return temp;
}

int main()
{
    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);
 
    createThreaded(root);
 
    cout << "Inorder traversal of created threaded tree "
            "is\n";
    inOrder(root);
   
    return 0;
}

/*
OUTPUT:
Inorder traversal of created threaded tree is
1 2 3 4 5 6 7
*/
