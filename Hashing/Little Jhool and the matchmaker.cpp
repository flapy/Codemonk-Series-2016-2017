#include <bits/stdc++.h>
using namespace std;
bool cmp(pair <int,pair <string,int> >  p1,pair <int,pair <string,int> >  p2)
{
	if (p1.first == p2.first)
		return p1.second.second < p2.second.second;
	return p1.first < p2.first;
}
int main()
{
	int t;
	cin >> t;
	string s = "littlejhool";
	map <char,bool> m;
	for (int i = 0; i < 11; i++)
		m[s[i]] = true;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		string str;
		pair <int,pair <string,int> > p[n + 2];
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			int len = str.length();
			int cnt = 0;
			for (int j = 0; j < len; j++)
			{
			    int val = 0;
				if (str[j] <= 90 && str[j] >= 65)
				    val = 32;
				if (m[str[j] + val])
				{
					m[str[j] + val] = false;
					cnt++;
				}
			}
			p[i] = {cnt,{str,i}};
			for (int j = 0; j < 11; j++)
				m[s[j]] = true;
		}
		sort(p,p + n,cmp);
		for (int i = 0; i < k; i++)
		    cout << p[i].second.first << " ";
		cout << endl;
		
	}
	return 0;
}
