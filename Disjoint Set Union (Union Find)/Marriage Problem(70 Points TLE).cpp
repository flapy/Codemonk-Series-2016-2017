#include <bits/stdc++.h>
using namespace std;
unordered_map <string,int> rnk;
unordered_map <string,string> parent;
#define lli long long int
void merge(string a,string b)
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
 
string find(string a)
{
	if (parent[a] == a)
		return a;
	parent[a] = find(parent[a]);
	return parent[a];
}
 
 
void init(int n,string s)
{
	for(int i = 1; i <= n; i++)
	{
		string str = to_string(i) + s;
		rnk[str] = 0;
		parent[str] = str;
	}
}
 
int main()
{
	ios_base :: sync_with_stdio(false);
	int x, y;
	cin >> x >> y;
	init(x, "m");
	init(y,"w");
	
	int q1, q2, q3;
	cin >> q1;
	while (q1--)
	{
		int u, v;
		cin >> u >> v;
		string sU = to_string(u) + "m";
		string sV = to_string(v) + "m";
		merge(find(sU),find(sV));
	}
	cin >> q2;
    cout << endl;
	while (q2--)
	{
		int u, v;
		cin >> u >> v;
		string sU = to_string(u) + "w";
		string sV = to_string(v) + "w";
		merge(find(sU),find(sV));
	}
	cin >> q3;
	while (q3--)
	{
		int u, v;
		cin >> u >> v;
		string sU = to_string(u) + "m";
		string sV = to_string(v) + "w";
		merge(find(sU),find(sV));
	}
    for (int i = 1; i <= x; i++)
        find(to_string(i) + "m");
    for (int i = 1; i <= y; i++)
        find(to_string(i) + "w");
    map <string,int> m;
    for (int j = 1 ;j <= y; j++)
    {
        m[parent[to_string(j) + "w"]]++;
    }
    lli sum = 0;
    for (int i = 1; i <= x; i++)
    {
        string pa = find(to_string(i) + "m");
        sum += (lli)y - (lli)m[pa];
    }
    cout << sum << endl;
	return 0;
}