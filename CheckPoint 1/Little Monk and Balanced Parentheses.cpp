#include <bits/stdc++.h>
using namespace std;
int main()
{	
    stack <int> s;
    int n;
    cin >> n;
    int cnt = 0;
    int ans = 0;
    int a[n + 2], i;
    s.push(0);
    for (i = 1; i <= n; i++)
    {
    	cin >> a[i];
    	if (a[i] > 0)
    		s.push(i);
    	else
    	{
    		int tp = s.top();
    		s.pop();
    		if (abs(a[i]) == a[tp])
    		{
    			if (!s.empty())
				ans = max(ans,i - s.top());
			else
				s.push(i);
    		}
    		else
    			s.push(i);
    	}
    }
    cout << ans << endl;
    return 0;
}
