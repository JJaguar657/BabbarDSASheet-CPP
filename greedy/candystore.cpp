//DSA Sheet Babbar
//Code: Jinam Jain
//Problem: Find the minimum and maximum amount to buy all N candies
//Link: https://practice.geeksforgeeks.org/problems/shop-in-candy-store/0
#include<bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        int min = 0;
        int max = 0;
        int ind = N/(K+1) + ((N%(K+1))!=0);
        for(int i=0;i<ind;i++){
            min += candies[i];
        }
        for(int i=0;i<ind;i++){
            max += candies[N-i-1];
        }
        vector<int> ans = {min,max};
        return ans;
    }

void attempt(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans = candyStore(arr,n,k);
}
int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);
attempt();
return 0;
}