#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
	lli n, k;
	cin >> n >> k;
	double a;
	double sum = 0;
	priority_queue<double> q;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		sum += a;
		q.push(a);
	}
	double avg = sum / (n * (1.0));
	printf ("%lf ",avg);
	double ans = 0;
	while (k--)
	{
		double val = q.top();
		q.pop();
		q.push(ceil(val / 3));
	}
    while (!q.empty())
    {
        ans += q.top();
        q.pop();
    }
    printf ("%lf\n",(double)ans / n);
}