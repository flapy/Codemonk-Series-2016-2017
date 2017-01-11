#include <bits/stdc++.h>
using namespace std;
void computeLPSArray(string pat, int M, int *lps);
 
// Prints occurrences of txt[] in pat[]
bool KMPSearch(string pat, string txt)
{
    int M = pat.length();;
    int N = txt.length();
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
 
        if (j == M)
        {
            return true;
        }
 
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    return false;
}
 
// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(string pat, int M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar 
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                  lps[i] = 0;
                   i++;
            }
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    int n;
    cin >> n;
    string a[n + 2];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map <string,int> m;
    int l = a[0].length();
    for (int j = 0; j < l; j++)
    {
        string subStr = "";
        for (int k = j; k < l; k++)
        {
            subStr += a[0][k];
            m[subStr]++;
        }
    }
    map <string,int> :: iterator itr;
    int ans = 0;
    for (itr = m.begin(); itr != m.end(); itr++)
    {
        bool flag = true;
        for (int i = 1; i < n; i++)
        {
            if (!KMPSearch(itr -> first,a[i]))
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans = max(ans,(int)itr -> first.length());
        }
    }
    cout << ans << endl;
    return 0;
}