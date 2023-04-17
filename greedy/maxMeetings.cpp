// DSA Sheet Babbar
// Code: Jinam Jain
// Problem: Activity Selection Problem
// Link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> meet;
    for (int i = 0; i < n; i++)
    {
        meet.push_back({start[i], end[i]});
    }
    sort(meet.begin(), meet.end(), cmp);
    int count = 1;
    int endp = meet[0].second;
    for (int i = 1; i < n; i++)
    {
        if (meet[i].first > endp)
        {
            count++;
            endp = meet[i].second;
        }
    }
    return count;
}
void attempt()
{
    int n;
    cin >> n;
    int start[n], end[n];
    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> end[i];
    }
    int ans = maxMeetings(start, end, n);
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    attempt();
    return 0;
}