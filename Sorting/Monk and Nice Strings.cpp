#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    string str[n+2];
    int j = 0;
    while (n--)
    {
    	int cnt = 0;
    	string s;
    	cin >> s;
    	str[j++] = s;
    	for (int k = 0; k < j-1; k++)
    	{
    		if (str[k] < s)
    			cnt++;
    	}
    	cout << cnt << endl;
    }
    return 0;
}