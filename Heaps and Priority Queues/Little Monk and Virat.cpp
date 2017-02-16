#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    ios_base :: sync_with_stdio(false);
    lli n;
    cin >> n;
    lli a[n + 2], b[n + 2], c[n + 2];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < n; i++) 
        cin >> b[i];
    for (int i = 0; i < n; i++) 
        cin >> c[i];
    map <lli,lli> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i] + b[i] + c[i]]++;
    }
    lli q, k;
    cin >> q;
    lli val = 0;
    map <lli,lli> :: iterator itr;
    for (itr = m.begin(); itr != m.end(); itr++)
    {
        val += itr -> second;
    }
    while (q--)
    {
        lli k;
        cin >> k;
 
        if (k > val)
            printf("-1\n");
        else
        {
            lli cnt = 0;
            for (itr = m.begin(); itr != m.end(); itr++)
            {
                cnt += itr -> second;
                if (cnt >= k)
                {
                    printf ("%lld\n",itr -> first);
                    m[itr -> first]--;
                    val--;
                    if (m[itr -> first] == 0)
                        m.erase(itr -> first);
                    break;
                }
            }
        }
    }
    return 0;
}