#include <bits/stdc++.h>
using namespace std;
int rnk[100004],parent[100004];
#define lli long long int
#define MOD 1000000007
void merge(int a,int b)
{
    if (a == b)
        return;
	if (rnk[a] < rnk[b])
	{
		parent[a] = b;
	}
	else if (rnk[a] > rnk[b])
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
		rnk[b]++;
	}
}
 
int find(int a)
{
	if (parent[a] == a)
		return a;
	parent[a] = find(parent[a]);
	return parent[a];
}
 
 
void init(int n)
{
	for(int i = 1; i <= n; i++)
	{
		rnk[i] = 0;
		parent[i] = i;
	}
}
 
int main()
{
	ios_base :: sync_with_stdio(false);
	int n,ma;
	cin >> n >> ma;
	init(n);
	while (ma--)
	{
		int a,b;
		cin >> a >> b;
		merge(find(a),find(b));
	}
	map <int,int> m;
	for (int i = 1; i <= n; i++)
	{
		m[parent[i]]++;
	}
	int noOfComponenets = m.size();
	lli ans = 1;
	for (int i = 1; i <= noOfComponenets; i++)
	{
		ans = (ans * (lli) 10) % MOD;
	}
	cout << ans << endl; 
	return 0;
}