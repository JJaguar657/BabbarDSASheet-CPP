// DSA Sheet Babbar
// Code: Jinam Jain
// Problem: Minimum Platforms
// Link: https://practice.geeksforgeeks.org/problems/minimum-platforms/0
#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    priority_queue<int, vector<int>, greater<int>> dept;
    vector<pair<int, int>> t(n);
    for (int i = 0; i < n; i++)
    {
        t[i].first = arr[i];
        t[i].second = dep[i];
    }
    sort(t.begin(), t.end());
    int cnt = 1;
    dept.push(t[0].second);
    for (int i = 1; i < n; i++)
    {
        if (t[i].first > dept.top())
        {
            dept.pop();
            dept.push(t[i].second);
        }
        else
        {
            dept.push(t[i].second);
            cnt++;
        }
    }
    return cnt;
}

void attempt()
{
    int n;
    cin >> n;
    int a[n], d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    int ans = findPlatform(a, d, n);
    cout << ans << endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    attempt();
    return 0;
}