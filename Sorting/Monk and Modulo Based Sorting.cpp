#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
	if (p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second < p2.second;
}
int main() {
	
	int n, k;
	cin >> n >> k;
	pair<int,int> p[100005];
	int a[n+2];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		p[i] = make_pair(i,a[i]%k);
	}
	
	sort(p,p+n,cmp);
	
	for (int i = 0; i < n; i++)
		cout << a[p[i].first] << " ";
	cout << endl;
    return 0;
}