#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    lli n, q;
    cin >> n >> q;
    pair<lli,lli> p[n+2];
    for (int i = 0; i < n; i++)
    {
    	cin >> p[i].first >> p[i].second;
    }
    sort(p,p+n);
    lli a[n+2];
    a[0] =  p[0].second - p[0].first + 1;
    for (int i = 1; i < n; i++)
    {
    	a[i] = p[i].second - p[i].first + 1 + a[i-1];
    }
    while (q--)
    {
    	lli x;
    	cin >> x;
    	lli ind = lower_bound(a,a+n,x) - a;
    	if (ind > 0)
    	x -= a[ind-1];
    	cout << p[ind].first + x - 1<< endl;
    }
    return 0;
}