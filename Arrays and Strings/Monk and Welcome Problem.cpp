#include <iostream>
using namespace std;
 
int main()
{
	int n;
	cin >> n;
    int arr[n+2], b[n+2];
    for (int i = 0; i < n; i++)
    	cin >> arr[i];
    for (int i = 0;i < n; i++)
    	cin >> b[i];
    for (int i = 0 ;i < n; i++)
    	cout << arr[i] + b[i] << " ";
    cout << endl;
    return 0;
}