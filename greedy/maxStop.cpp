// DSA Sheet Babbar
// Code: Jinam Jain
// Problem: maximum train for which stoppage can be provided
// Link: https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/
#include <bits/stdc++.h>
using namespace std;

int maxStop(int n, int m, vector<vector<int>> &train)
{
    vector<pair<int, int>> v[n + 1];
    for (int i = 0; i < m; i++)
    {
        v[train[i][2]].push_back({train[i][1], train[i][0]});
    }
    for (int i = 1; i <= n; i++)
        sort(v[i].begin(), v[i].end());
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size() == 0)
            continue;

        count++;
        int last = v[i][0].first;
        for (int j = 1; j < v[i].size(); j++)
        {
            if (v[i][j].second >= last)
            {
                count++;
                last = v[i][j].first;
            }
        }
    }
    return count;
}

void attempt()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> train(m,vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> train[i][0] >> train[i][1] >> train[i][2];
    }
    int ans = maxStop(n, m, train);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    attempt();
    return 0;
}