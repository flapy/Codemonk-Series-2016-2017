#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    string vow = "AEIOUaeiou";
    while (t--)
    {
    	string s;
    	int cnt = 0;
    	cin >> s;
    	int len = s.length();
    	int l = vow.length();
    	for (int i = 0;i < len; i++)
    	{
    		for (int j = 0; j < l; j++)
    		{
    			if (s[i] == vow[j])
    			{
    				cnt++;
    			}
    		}
    	}
    	cout << cnt << endl;
    }
    return 0;
}