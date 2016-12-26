#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int parent[100005];
int arr[100005];
void foo(int currXor,int u,int reqd)
{
    if ((currXor ^ arr[u])  == reqd)
    {
        ans++;
    }
    if (parent[u] == u)
    {
        return;
    }
    foo(currXor ^ arr[u],parent[u],reqd);
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    parent[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> parent[i];
    }
    for (int i = 1; i<= n; i++)
    {
        foo(0,i,k);
    }
    cout << ans << endl;
    return 0;
}