// I started at 2:13 hrs late :P
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
}*root = NULL;
 
Node *createNode(int val)
{
    Node *temp = new Node();
    temp -> data = val;
    return temp;
}
Node *insert(Node * itr,int val)
{
    if (!itr)
        return createNode(val);
    if (itr -> data < val)
    {
        itr->left = insert(itr->left,val);
    }
    else
    {
        itr->right = insert(itr->right,val);
    }
    return itr;
}
 
int height(Node *itr)
{
    if (!itr)
    {
        return 0;
    }
    return max(height(itr->left),height(itr->right)) + 1;
}
int main()
{
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        root = insert(root,a);
    }
    cout << height(root) << endl;
    return 0;
}