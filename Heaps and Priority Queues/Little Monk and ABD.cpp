// JIO :((()))
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    int arr[n + 2];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr + n);
    int q;
    cin >> q;
    while (q--)
    {
        int k;
        char ch;
        cin >> k >> ch;
        if (ch == 'S')
            cout << arr[k - 1] << endl;
        else
            cout << arr[n - k] << endl;
    }
    return 0;
}
