#include<iostream>
#include<queue>
using namespace std;

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

int getheight(BST* root) {
    if (root ==NULL) return 0;

    queue<BST*> q;
    q.push(root);
    int maxheight = 0;

    while (!q.empty()) {
        int count = q.size();  // number of nodes at current level
        maxheight = max(maxheight, count);

        while (count--) {
            BST* temp = q.front();
            q.pop();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    return maxheight;
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
 add_Nodes(658);
  cout << "Height of BST = " << getheight(root);
 return 0;
}