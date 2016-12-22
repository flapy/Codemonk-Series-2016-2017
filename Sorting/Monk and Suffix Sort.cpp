#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
	string s;
	int k;
	cin >> s >> k;
	int l = s.length();
	reverse(s.begin(),s.end());
	string temp = "";
	string str[100004];
	for (int i = 0; i < l; i++)
	{
		temp += char(s[i]);
		string l  = temp;
		reverse(l.begin(),l.end());
		str[i] = l;
	}
	sort(str,str+l);
	cout << str[k-1] << endl;
    return 0;
}