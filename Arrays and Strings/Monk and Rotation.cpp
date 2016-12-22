#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
    	int n, k;
    	cin >> n >> k;
    	int a[n+2];
    	for (int i = 0; i < n; i++)
    		cin >> a[i];
    	k %= n;
    	int b[n+2];
    	for (int i = 0; i < n; i++)
    	{
    		b[(i+k)%n] = a[i];
    	}
    	
    	for (int i = 0; i < n; i++)
    		cout << b[i] <<" ";
    	cout << endl;
    }
    return 0;
}