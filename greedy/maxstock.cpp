//DSA Sheet Babbar
//Code: Jinam Jain
//Problem: 
//Link: 
#include<bits/stdc++.h>
using namespace std;

int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> ratio(n);
        for(int i=0;i<n;i++){
            ratio[i].first = price[i];
            ratio[i].second = i+1;
        }
        sort(ratio.begin(),ratio.end());
        int stocks = 0;
        for(int i=0;i<n;i++){
            if((price[ratio[i].second-1]*ratio[i].second)<k){
                stocks += ratio[i].second;
                k -= (ratio[i].second*price[ratio[i].second-1]);
            }
            else{
                if((k/price[ratio[i].second-1])<=ratio[i].second){
                    stocks += (k/price[ratio[i].second-1]);
                     k = (k%price[ratio[i].second-1]);
                } 
                else{
                    stocks += ratio[i].second;
                    k -= (ratio[i].second*price[ratio[i].second-1]);
                } 
            }
        }
        return stocks;
    }

void attempt(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = buyMaximumProducts(n,k,a);
    cout<<ans<<endl;
}
int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);
attempt();
return 0;
}