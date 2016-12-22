#include <bits/stdc++.h>
using namespace std;
int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
#define lli long long int
lli MAX;
lli m[200005];
lli foo(lli p)
{
	lli cnt = 0;
	lli mul = 1;
	while (mul * p <= MAX)
	{
		if (m[mul * p])
		{
			cnt += m[mul * p];
		}
		mul++;
	}
	return cnt;
}
lli intersect(lli p,lli q)
{
	return ((long long)p * (long long) q) / __gcd(p,q);
}
int main()
{
    lli n;
    n = readInt();
    lli arr;
    lli ma = INT_MIN;
    for (int i = 0; i < n; i++)
    {
    	arr = readInt();
    	m[arr]++;
    	ma = max(arr,ma);
    }
    MAX = ma;
    int t;
    t = readInt();
    while (t--)
    {
    	lli p, q;
    	p  = readInt(); q = readInt();
    	if (p == 1 || q == 1)
    	{
    		printf("%d\n",n);
    		continue;
    	}
   		printf("%lld\n",foo(p) + foo(q) - foo(intersect(p,q)));
    }
    return 0;
}