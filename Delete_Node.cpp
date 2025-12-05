#include <iostream>
using namespace std;

struct BST {
    int data;
    BST *left, *right;
};

BST *root;

// Initialize BST
void init() {
    root = NULL;
}

// Create root node
void create_root(int x) {
    root = new BST;
    root->data = x;
    root->left = root->right = NULL;
}

// Insert a new node
void add_Nodes(int x) {
    BST *temp = root, *parent = NULL;

    while (temp != NULL) {
        parent = temp;
        if (x < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    BST *p = new BST;
    p->data = x;
    p->left = p->right = NULL;

    if (x < parent->data)
        parent->left = p;
    else
        parent->right = p;
}
BST* findMin(BST* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Delete a node
BST* delete_node(BST* root, int x) {
    if (root == NULL) return root;

    if (x < root->data)
        root->left = delete_node(root->left, x);
    else if (x > root->data)
        root->right = delete_node(root->right, x);
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            BST* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            BST* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        BST* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

// Count total nodes
int countNodes(BST* node) {
    if (node == NULL) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

// Inorder traversal
void inorder(BST* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    init();
    create_root(50);
    add_Nodes(10);
    add_Nodes(2);
    add_Nodes(85);
    add_Nodes(90);
    add_Nodes(15);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Total number of nodes = " << countNodes(root) << endl;

    // Delete a node
    root = delete_node(root, 85);

    cout << "After deleting 85: ";
    inorder(root);
    cout << endl;

    cout << "Total nodes now = " << countNodes(root) << endl;

    return 0;
}
