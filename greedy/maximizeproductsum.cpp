// DSA Sheet Babbar
// Code: Jinam Jain
// Problem: Maximize sum
// Link: https://practice.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/0
#include <bits/stdc++.h>
using namespace std;
int Maximize(int a[], int n)
{
    long long int ans = 0, mod = 1e9 + 7;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        ans = (ans % mod + ((a[i] % mod) * (i % mod)) % mod) % mod;
    }
    int product = ans;
    return product;
}
void attempt()
{
    int n, a[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = Maximize(a, n);
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    attempt();
    return 0;
}