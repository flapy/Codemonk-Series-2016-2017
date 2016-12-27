// Editorial Implementation
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define MOD 1000000007
map <lli, map <lli,lli> > m;

lli power(lli a,lli b)
{
	if (b == 0)
		return 1;
	if (b % 2)
	{
		return ((power(a, b / 2) * power(a,b / 2)) % MOD * a) % MOD;
	}
	else
	{
		return (power(a, b / 2) * power(a,b / 2)) % MOD;	
	}
}


void findPrimeFactors(int id,lli n,lli c)
{
	for (lli i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			int cnt = 0;
			while (n % i == 0)
			{
				cnt++;
				n /= i;
			}
			m[id][i] = cnt * c;
		}
	}
	if (n != 1)
	{
		m[id][n]++;
		m[id][n] *= c;
    }
}


int main()
{
	ios_base :: sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		lli a, b, c;
		cin >> a >> b >> c;
		findPrimeFactors(0,a,1);
		findPrimeFactors(1,b,c);
		map <lli,lli> :: iterator itr;
		map <lli,lli> mB = m[1];
		map <lli,lli> mA = m[0];
		for (itr = mB.begin(); itr != mB.end(); itr++)
		{
			if (mA[itr -> first])
			{
				if (mA[itr -> first] <= itr -> second)
				{
					mB[itr -> first] = itr -> second - mA[itr -> first];
				}
				else
				{
					mB[itr -> first] = 0;
				}
			}
		}
		lli ans = 1;

		for (itr = mB.begin(); itr != mB.end(); itr++)
		{
			ans = (ans * power(itr -> first % MOD,itr -> second)) % MOD;
		}
		cout << ans << endl;
		m.clear();
	}
	return 0;
}