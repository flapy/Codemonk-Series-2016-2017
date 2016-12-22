#include <iostream>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	cin >> n;
    	int arr[n][n];
    	for (int i = 0; i < n; i++)
    	{
    		for (int j = 0; j < n; j++)
    		{
    			cin >> arr[i][j];
    		}
    	}
    	int cnt  = 0;
    	for (int i = 0; i < n; i++)
    	{
    		for (int j = 0; j < n; j++)
    		{
    			for (int k = i ; k < n; k++)
    			{
    				for (int l = j; l < n; l++)
    				{
    					if (arr[i][j] > arr[k][l])
    						cnt ++;
    				}
    			}
    		}
    	}
    	
    	cout << cnt << endl;
    }
    return 0;
}