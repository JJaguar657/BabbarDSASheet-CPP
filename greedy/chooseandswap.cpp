// DSA Sheet Babbar
// Code: Jinam Jain
// Problem: Greedy Algorithm to find no. of Coins
// Link: https://practice.geeksforgeeks.org/problems/coin-piles/0
#include <bits/stdc++.h>
using namespace std;

string chooseandswap(string a)
{
    vector<int> check(27, -1);
    for (int i = 0; i < a.size(); i++)
    {
        if (check[a[i] - 'a' + 1] == -1)
            check[a[i] - 'a' + 1] = i;
    }
    int i = 0, j = 0;
    for (i = 0; i < a.size(); i++)
    {
        bool ans = false;
        for (j = 0; j < a[i] - 'a' + 1; j++)
        {
            if (check[a[i] - 'a' + 1] < check[j])
            {
                ans = true;
                break;
            }
        }
        if (ans)
            break;
    }
    if (i < a.size() - 1)
    {
        char one = a[i];
        char two = (char)('a' + j - 1);
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == one)
                a[i] = two;
            else if (a[i] == two)
                a[i] = one;
        }
    }
    return a;
}

void attempt()
{
    string a;
    cin >> a;
    string ans = chooseandswap(a);
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    attempt();
    return 0;
}