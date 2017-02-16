// FUCKCC There was no need of comparator!!
// #AfterContest
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main(){
	int n, k, a;
	cin >> n >> k;
	lli sum = 0;
	priority_queue <pair <int ,int > > pq;
	for (int i = 0; i < n; i++)
	{
	    cin >> a;
	    pq.push({a,-i});
	}
	while(k--)
	{
		pair < int , int > temp;
		temp = pq.top();
		temp.first--;
		pq.pop();
		cout << - temp.second + 1 << " ";
		pq.push(temp);
	}
	printf("\n");
	return 0;
}