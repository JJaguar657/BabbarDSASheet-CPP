// DSA Sheet Babbar
// Code: Jinam Jain
// Problem:
// Link:
#include <bits/stdc++.h>
using namespace std;
long long int maximizeSum(long long int a[], int n, int k)
{
    sort(a, a + n);
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (k > 0 && a[i] < 0)
        {
            a[i] = abs(a[i]);
            k--;
        }
    }
    sort(a, a + n);
    if (k >= 0 && k % 2 == 1)
        a[0] = (-1) * a[0];
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}

void attempt()
{
    int n, k;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> k;
    long long int ans = maximizeSum(a, n, k);
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    attempt();
    return 0;
}