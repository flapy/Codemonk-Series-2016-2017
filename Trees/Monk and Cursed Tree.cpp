// Today I went to a b'day party
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
vector<int> ans;
void display(vector<int> v)
{
    vector<int> :: iterator itr;
    for (itr = v.begin(); itr!= v.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
}
void path(Node *itr,int val,vector<int> v)
{
    if (!itr)
        return;
    if (itr -> data == val)
    {
        v.push_back(itr->data);
        ans = v;
        return ;
    }
    v.push_back(itr->data);
    path(itr->left,val,v);
    path(itr->right,val,v);
}
int findMax(vector<int> v)
{
    vector<int> :: iterator itr;
    int ma = INT_MIN;
    for (itr = v.begin(); itr!= v.end(); itr++)
    {
        ma = max(ma,*itr);
    }
    return ma;
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
    int x, y;
    cin >> x >> y;
    vector<int> pathX;
    vector<int> pathY;
    vector<int> temp;
    path(root,x,temp);
    pathX = ans;
    ans.clear();
    path(root,y,temp);
    pathY = ans;
    // display(pathX);
    // display(pathY);
    vector<int> :: iterator itr;
    int ans1 = max(x,y);
    int l1 = pathX.size();
    int l2 = pathY.size();
    int pos = -1;
    int lca;
    for (int i = 0 ; i < min(l1,l2); i++)
    {
    	if (pathX[i] == pathY[i])
    	{
    		lca = pathX[i]; // Can do a hell lot better for LCA
    		pos = i;
    	}
    }
    for (int i = pos; i < l1; i++)
    {
    	ans1 = max(ans1,pathX[i]);
    }
    for (int i = pos; i < l2; i++)
    {
    	ans1 = max(ans1,pathY[i]);
    }
    cout << ans1 << endl;
    return 0;
}