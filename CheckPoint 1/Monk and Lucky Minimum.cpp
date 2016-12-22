#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	cin >> n;
    	map<int,int> m;
    	int a;
    	for (int i = 0 ; i < n; i++)
    	{
    		cin >> a;
    		m[a]++;
    	}
    	int minNumFreq = m.begin() -> second;
    	cout << (minNumFreq % 2 ? "Lucky" : "Unlucky") << endl;
    }
    return 0;
}