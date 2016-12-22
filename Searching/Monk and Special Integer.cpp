#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    lli n, x;
    cin >> n >> x;
    lli a[n+2];
    for (int i = 0; i < n; i++)
    	cin >> a[i];
    lli sum = 0;
    lli dp[n + 2];
    dp[0] = a[0];
    for (int i = 1; i < n; i++)
    {
    	dp[i] = dp[i-1] + a[i];
    }
    list<int> ans;
    for (int i = 0; i < n; i++)
    {
    	sum += a[i];
    	if (sum <= x)
    	{
    		ans.push_back(i);
    	}
    }
    
    list<int> :: reverse_iterator itr;
    for (itr = ans.rbegin(); itr != ans.rend(); itr++)
    {
    	bool flag = true;
	    for (int i = 0; i < n; i++)
	    {
	    	if (i + *itr < n)
	    	{
		    	if (dp[i + *itr] - (i-1 >= 0 ? dp[i - 1] : 0) > x)
		    	{
		    		flag = false;
		    		break;
		    	}
	    	}
	    	else
	    		break;
	    }
	    if (flag)
	    {
	    	cout << *itr + 1 << endl;
	    	break;
	    }
    }
    return 0;
}