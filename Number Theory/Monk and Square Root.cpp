#include <bits/stdc++.h>
using namespace std;
 
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
   		long long int n, m ;
   		cin >> n >> m;
   		int ans = -1;
   		for (long long int i = 0; i < m; i++)
   		{
   			if (i * i % m == n)
   			{
   				ans = i;
   				break;
   			}
   		}
   		cout << ans << endl;
   }
    return 0;
}