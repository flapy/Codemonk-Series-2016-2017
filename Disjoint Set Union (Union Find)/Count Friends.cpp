#include <bits/stdc++.h>
using namespace std;
int rnk[100004],parent[100004],size[100005];
 
void merge(int a,int b)
{
    if (a == b)
        return;
	if (rnk[a] < rnk[b])
	{
		size[b] += size[a];
		parent[a] = b;
	}
	else if (rnk[a] > rnk[b])
	{
		size[a] += size[b];
		parent[b] = a;
	}
	else
	{
		size[b] += size[a];
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
		size[i] = 1;
	}
}
 
int main()
{
	ios_base :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	init(n);
	while (m--)
	{
		int a,b;
		cin >> a >> b;
		merge(find(a),find(b));
	}
	for (int i = 1; i <= n; i++)
		cout << size[find(i)] - 1 << " ";
	cout << endl; 
	return 0;
}
Language: C++