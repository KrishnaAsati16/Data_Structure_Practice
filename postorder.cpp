
#include <iostream>
#include <vector>
using namespace std;

struct Node {
        int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int index = -1;

Node* buildTree(const vector<int>& preorder) {
    index++;
    if (preorder[index] == -1) return NULL;

    Node* root = new Node(preorder[index]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void PostOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

int main() {
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preorder);
    PostOrder(root);
    cout << endl;
    return 0;
}

