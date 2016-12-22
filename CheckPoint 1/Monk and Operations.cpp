#include <bits/stdc++.h>
using namespace std;
int arr[1003][1004], n , m;
#define lli long long int
lli rowOnly(int v1,int v2)
{
	lli sum = 0;
	for (int i = 0; i < n; i++)
	{
		lli rowSum = 0, newSum = 0;
		for (int j = 0; j < m; j++)
		{
			rowSum += abs((lli)arr[i][j]);
			newSum += abs((lli)arr[i][j] + (lli)v1);
		}
		sum += max(rowSum,max(abs((lli)m * (lli)v2),newSum));
	}
	return sum;
}
 
lli colOnly(int v3,int v4)
{
	lli sum = 0;
	for (int i = 0; i < m; i++)
	{
		lli colSum = 0, newSum = 0;
		for (int j = 0; j < n; j++)
		{
			colSum += abs((lli)arr[j][i]);
			newSum += abs((lli)arr[j][i] + (lli)v3);
		}
		sum += max(colSum,max(abs((lli)n * (lli)v4),newSum));
	}
	return sum;
}
 
 
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
    	for (int j = 0; j < m; j++)
    	{
    		cin >> arr[i][j];
    	}
    }
    int v1, v2, v3, v4;
    cin >> v1 >> v2 >> v3 >> v4;
    cout << max(rowOnly(v1,v2),colOnly(v3,v4)) << endl;
    return 0;
}