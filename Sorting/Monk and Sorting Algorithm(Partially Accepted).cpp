// I am Back Because My frnds slept!
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
long long int readInt(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
bool cmp(pair<string,int> p1,pair<string,int> p2)
{
	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first < p2.first;
}
int main() {
	
	int n;
	n = readInt();
	lli a[n+2];
	for (int i = 0; i < n; i++)
		a[i] = readInt();
	// Let's check this shit!
	vector<lli> ve;
	vector<pair<string,int> > v;
	vector<lli> :: iterator itr;
	vector< pair< string,int > >:: iterator itr1;
	for (int i = 1;i <= 4;i++)
	{
		int r = 5*i;
		int l = 5*(i-1);
		string str = "";
		bool flag = true;
		// cout << l << " " << r << endl;
		for (int j = 0; j < n; j++)
		{
			string s = to_string(a[j]);
			
			reverse(s.begin(),s.end());
			string str;
			int len  = s.length();
			for (int k  = l; k < r ;k++)
			{
				if (k >=0 && k < len && k < len)
				{
					flag = false;
					str += s[k];
				}
				else
					str += "0";
			}
			reverse(str.begin(),str.end());
			// cout << str << " ";
			v.push_back({str,j});
		}
		//cout << endl;
		if (flag)
			break;
		sort(v.begin(),v.end(),cmp);
		for (int i = 0;  i < v.size(); i++)
			printf("%lld ",a[v[i].second]);
		printf("\n");
		for (itr1 = v.begin(); itr1 != v.end(); itr1++)
		{
			ve.push_back(a[itr1->second]);
		}
		int j = 0;
		for (itr = ve.begin(); itr != ve.end(); itr++)
		{
			a[j++] = *itr;
 
		}
		
		ve.clear(); v.clear();
	}
    return 0;
}
