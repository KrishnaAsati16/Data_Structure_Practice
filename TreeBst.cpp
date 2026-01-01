#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

// Global pointers (same as your C code)
Node *root = nullptr, *temp, *ttemp, *p;

void init() {
    root = nullptr;
}

void create_root(int x) {
    root = new Node;
    root->data = x;
    root->left = root->right = nullptr;
}

void add_nodes(int x) {
    temp = root;

    while (temp != nullptr) {
        ttemp = temp;
        if (x < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    p = new Node;
    p->data = x;
    p->left = p->right = nullptr;

    if (x < ttemp->data)
        ttemp->left = p;
    else
        ttemp->right = p;
}

void inorder(Node *p) {
    if (p != nullptr) {
        inorder(p->left);
        cout << "\t" << p->data;
        inorder(p->right);
    }
}

void preorder(Node *p) {
    if (p != nullptr) {
        cout << "\t" << p->data;
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(Node *p) {
    if (p != nullptr) {
        postorder(p->left);
        postorder(p->right);
        cout << "\t" << p->data;
    }
}

int main() {
    init();

    create_root(50);
    add_nodes(30);
    add_nodes(70);
    add_nodes(90);
    add_nodes(20);
    add_nodes(10);
    add_nodes(100);
    add_nodes(60);
    add_nodes(80);
    add_nodes(55);
    add_nodes(85);
    add_nodes(25);
    add_nodes(15);
    add_nodes(35);
    add_nodes(45);
    add_nodes(59);
    add_nodes(24);

    cout << "\nInorder\n";
    inorder(root);

    cout << "\n\nPreorder\n";
    preorder(root);

    cout << "\n\nPostorder\n";
    postorder(root);

    return 0;
}