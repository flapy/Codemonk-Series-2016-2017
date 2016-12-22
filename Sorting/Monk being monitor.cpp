#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n+2];
		map<int,int> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			m[a[i]]++;
		}
		int ansma = INT_MIN, ansmi=INT_MAX;
		int ma = INT_MIN, mi = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			if (m[a[i]] > ma)
			{
				ma = m[a[i]];
				ansma = a[i];
			}
			if (m[a[i]] < mi)
			{
				mi = m[a[i]];
				ansmi = a[i];
			}
		}
		if (ma > mi)
		cout << (ma - mi == 0 ? -1 :ma - mi) << endl; 
		else
		cout << -1 << endl;
	}
    return 0;
}