#include <bits/stdc++.h>
using namespace std;
bool isVowel(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return true;
	return false;
}
int main()
{
    string s;
    cin >> s;
    int l = s.length();
    int cnt = 0;
    int ans = INT_MIN;
    for (int i = 0; i < l; i++)
    {
    	if (isVowel(s[i]))
    	{
    		cnt++;
    	}
    	else
    	{
    		ans = max(ans,cnt);
    		cnt = 0;
    	}
    }
    cout << max(ans,cnt) << endl;
    return 0;
}