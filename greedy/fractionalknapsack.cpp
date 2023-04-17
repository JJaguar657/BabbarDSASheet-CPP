// DSA Sheet Babbar
// Code: Jinam Jain
// Problem: frational KnapSack
// Link: https://practice.geeksforgeeks.org/problems/fractional-knapsack/0
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

static bool comp(pair<int, double> a, pair<int, double> b)
{
    return a.second > b.second;
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    vector<pair<int, double>> ratio(n);
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        ratio[i].second = arr[i].value / (double)(arr[i].weight);
        ratio[i].first = i;
    }
    sort(ratio.begin(), ratio.end(), comp);
    int j = 0;
    while (W > 0 && j < n)
    {
        if (W > arr[ratio[j].first].weight)
        {
            ans += arr[ratio[j].first].value;
            W -= arr[ratio[j].first].weight;
            j++;
        }
        else
        {
            ans += arr[ratio[j].first].weight * ratio[j].second;
            W = 0;
        }
    }
    return ans;
}

void attempt()
{
    int n;
    cin >> n;
    int v[n], weigh[n];
    Item arr[n];
    int W;
    cin >> W;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weigh[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i].value = v[i];
        arr[i].weight = weigh[i];
    }
    double ans = fractionalKnapsack(W, arr, n);
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    attempt();
    return 0;
}