#include <bits/stdc++.h>
using namespace std;
vector<int> successors;
int arr[504];
void findSuccessors(vector<int> children[505],int u)
{
	// cout << u <<  " " ;
	successors.push_back(u);
	vector<int> :: iterator itr;
	for (itr = children[u].begin(); itr != children[u].end(); itr++)
	{
		findSuccessors(children,*itr);
	}
}
#define lli long long int
int countTriplets(lli k)
{
	int n = successors.size();
	int cnt = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((lli)arr[successors[0]] + (lli)arr[successors[i]] + (lli)arr[successors[j]] >= k)
			{
				cnt++;
			}
		}
	}
	successors.clear();
	return cnt;
}
int main()
{
	ios_base :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	vector <int> children[505];
	for (int i = 2; i <= n ; i++)
	{
		int j;
		cin >> j;
		children[j].push_back(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		findSuccessors(children,i);
		// cout << endl;
		ans += countTriplets(k);
		
	}
	cout << ans << endl;
	return 0;
}