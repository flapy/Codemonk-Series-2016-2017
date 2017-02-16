#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	map  <int,int> m;
	while (t--)
	{
		string s;
		cin >> s;
		int x;
		if (s == "Push")
		{
			cin >> x;
			m[x]++;
		}
		else if (s == "CountHigh")
		{
			if (m.size() == 0)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << m.rbegin() -> second << endl;
			}
		}
		else if (s == "CountLow")
		{
			if (m.size() == 0)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << m.begin() -> second << endl;
			}
		}
		// Diff
		else
		{
			if (m.size() == 0)
			{
				cout << -1 << endl;
			}
			else if (m.size() == 1)
			{
			    cout << 0 << endl;
			    int val = m.begin() -> first;
			    m[val]--;
			    if (m[val] == 0)
			        m.erase(val);
			}
			else
			{
				cout << m.rbegin() -> first - m.begin() -> first << endl;
				int val = m.begin() -> first;
			    m[val]--;
			    if (m[val] == 0)
			        m.erase(val);
			    val = m.rbegin() -> first;
			    m[val]--;
			    if (m[val] == 0)
			        m.erase(val);
			}
		}
	}
	return 0;
}