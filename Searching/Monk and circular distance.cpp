#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    lli n;
    cin >> n;
    unsigned lli x, y;
    unsigned lli a[n+2];
    for (int i = 0;i < n; i++)
    {
    	cin >> x >> y;
    	a[i] = x*x + y*y ;
    }
    sort (a,a+n);
    lli q;
    cin >> q;
    lli reqd = INT_MAX;
    while (q--)
    {
    	lli r;
    	cin >> r;
    	if (r >= reqd)
    	{
    		cout << n << endl;
    		continue;
    	}
    	lli ind = lower_bound(a,a+n,r*r) - a;
    	if (ind >= n)
    	cout << ind << endl;
    	else
    	{
    		if (a[ind] <= r*r)
    			cout << ind + 1 << endl;
    		else
    			cout << ind << endl;
    	}
    }
    return 0;
}