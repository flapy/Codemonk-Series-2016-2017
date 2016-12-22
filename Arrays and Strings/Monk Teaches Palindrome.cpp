#include <iostream>
using namespace std;
bool isPalin(string s)
{
	int l = s.length();
	int i = 0;
	l--;
	while (i < l)
	{
		if (s[i] != s[l])
		{
			return false;
		}
		i++,l--;
	}
	return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
    	string s;
    	cin >> s;
    	if (isPalin(s))
    	{
    		cout << "YES ";
    		cout << (s.length() % 2 ? "ODD" : "EVEN") << endl;
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }
    return 0;
}