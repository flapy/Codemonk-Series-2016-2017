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
int bfs(int u)
{
    int cnt = 0;
    queue<int> q;
    q.push(u);
    visit[u] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        list <int> :: iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
        {
            cnt++;
            if (!visit[*itr])
            {
                q.push(*itr);
                visit[*itr] = true;
            }
        }
    }
    return cnt / 2;
}
int main()
{
    int t;
    t = 1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            addEdge(u,v);
        }
        memset(visit,false,sizeof(visit));
        int ans = INT_MIN;
        for (int i  = 1; i <= n; i++)
        {
            if (!visit[i])
            {
                ans = max(ans,bfs(i));
            }
        }
        cout << ans << endl;
    }
    return 0;
}