// Sometimes you are LOST! 
#include <bits/stdc++.h>
using namespace std;
list <int> adj[100004];
#define lli long long int 
#define pb push_back
void addEdge(int u,int v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}
bool visit[100005];
map <int,int> ma;
int foo(int u)
{
    visit[u] = true;
    list <int> :: iterator itr;
    int ans = 0;
    for (itr = adj[u].begin(); itr != adj[u].end();itr++)
    {
        if (!visit[*itr])
        {
            ans += foo(*itr);
        }
    }
    ma[u] = ans + 1;
    return ans + 1;
}
int main()
{
    int t;
    t = 1;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int m = n - 1;
        pair <int,int> p[m + 2];
        int cnt = 1;
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            addEdge(u,v);
            p[cnt++] = {u,v};
        }
        foo(1);
        while (q--)
        {
            int x;
            cin >> x;
            int u = p[x].first;
            int v = p[x].second;
            list <int> :: iterator itr;
            int cntU = min(ma[u],ma[v]);
            cout << ((lli)cntU) * ((lli)(n - cntU)) << endl;
        }
    }
    return 0;
}