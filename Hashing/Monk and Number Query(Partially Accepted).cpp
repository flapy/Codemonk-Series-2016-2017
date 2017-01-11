#include <bits/stdc++.h>
using namespace std;
 
map <int,map <int,string> > m;
int parent[200005];
int arr[200005];
int n;
string foo(int u,int node,string s)
{
	if (u == node)
	{
		return s;
	}
	return foo(parent[u],node,s + to_string(arr[parent[u] - 1]));
}
int main()
{
	int k, q;
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	parent[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		cin >> parent[i];
	}
 
	while(q--)
	{
		int u, v;
		cin >> u >> v;
		
		string str = foo(v,u,to_string(arr[v - 1]));
		reverse(str.begin(),str.end());
		long long val = 0;
		for (int i = 0; str[i] != '\0'; ++i)
   			val = (val * 10 + str[i] - '0') % k;
 
		cout << (val % k ? "NO" : "YES") << endl;
		
	}
	return 0;
}