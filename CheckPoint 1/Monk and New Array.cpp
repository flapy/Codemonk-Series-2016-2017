#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n + 2][m  + 2];
    for (int i = 0; i < n; i++)
    {
    	for (int j = 0; j < m; j++)
    	{
    		cin >> arr[i][j];
    	}
    	sort(arr[i],arr[i] + m);
    }
    int ans = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
    	for (int j = 0; j < m ;j++)
    	{
    		int ind = lower_bound(arr[i + 1], arr[i + 1] + m,arr[i][j]) - arr[i + 1];
    		int ans1, ans2;
    		ans1 = ans2 = INT_MAX;
    		if (ind < m)
    			ans1 = abs(arr[i + 1][ind] - arr[i][j]);
    		if (ind > 0)
    			ans2 = abs(arr[i + 1][ind - 1] - arr[i][j]);
    		ans = min(ans,min(ans1,ans2));
    	}
    }
    cout << ans << endl;
    return 0;
}