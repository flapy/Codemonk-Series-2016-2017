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
int main()
{
    int t;
    t = 1;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int val[n + 2];
        for (int i = 0; i < n; i++)
            cin >> val[i];
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            addEdge(u,v);
        }
        vector <pair <int,int> > v;
        for (int i = 1 ; i <= n; i++)
        {
            list <int> :: iterator itr;
            int u = i;
            for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
            {
                v.push_back({val[*itr - 1],*itr});
            }
            sort (v.rbegin(),v.rend());
            if (v.size() >= k)
            {
                cout << v[k - 1].second << endl;
            }
            else
                cout << -1 << endl;
            v.clear();
        }
    }
    return 0;
}