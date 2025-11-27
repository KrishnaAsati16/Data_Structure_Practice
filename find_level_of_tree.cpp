#include<iostream>
using namespace std;

// GIVEN A DATA THIS DATA IS PRESENT IN BINARY SEARCH TREE THEN FIND LEVEL OF THE DATA IN THIS TREE

struct BST{
    int data;
    BST *left, *right,*p;

};
BST*root,*temp, *ttemp;
void init ()
{
    root=temp=ttemp=NULL;
}
void create_root(int x){
    root=new BST;
    root->data=x;
    root->left=root->right=NULL;
}

void add_Nodes(int x) {
    temp = root;
    while (temp != NULL) {
        ttemp = temp;
        if (x < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    BST *p = new BST;
    p->data = x;
    p->left = p->right = NULL;

    if (x < ttemp->data)
        ttemp->left = p;
    else
        ttemp->right = p;
}

int getlevel(BST *p, int n, int level) {
    if (p == NULL) 
        return 0;  // not found

    if (p->data == n) 
        return level;

    // Search in left subtree
    int downlevel = getlevel(p->left, n, level + 1);
    if (downlevel != 0) 
        return downlevel;

    // Search in right subtree
    return getlevel(p->right, n, level + 1);
}
int main ()
{
    init();
    create_root(50);
   add_Nodes(10);
  add_Nodes(2);
  add_Nodes(85);
  add_Nodes(90);
  add_Nodes(15);

   // Test getlevel

    int target = 90;
    int level = getlevel(root, target, 1);

    if (level != 0)
        printf("Node %d found at level %d\n", target, level);
    else
        printf("Node %d not found in the tree\n", target);

    return 0;


}
