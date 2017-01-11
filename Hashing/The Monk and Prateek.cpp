#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	map <int,int> m;
	while (n--)
	{
		string s;
		cin >> s;
		int l = s.length();
		int sum = 0;
		for (int i = 0; i < l; i++)
		{
			sum += (s[i] - '0');
		}
		int rezen = stoi(s) ^ sum;
		m[rezen]++;
	}
	map <int,int> :: iterator itr;
	int ans = INT_MIN;
	int val = INT_MAX;
	int coll = 0;
	int ma = INT_MIN;
	for (itr = m.begin(); itr != m.end(); itr++)
	{
	    ma = max(ma,itr -> first);
	    coll += (itr -> second - 1);
		if (itr -> second > ans)
		{
			ans = itr -> second;
			val = itr -> first;
		} 
		else if (itr -> second == ans)
		{
		    if (itr -> first < val)
		    {
		        val = itr -> first;
		    }
		}
	}
	if (coll == 0)
	{
	    cout << ma << " " << coll << endl;
	    return 0;
	}
	cout << val << " ";
	cout << coll << endl;
	return 0;
}	