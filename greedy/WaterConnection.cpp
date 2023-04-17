//DSA Sheet Babbar
//Code: Jinam Jain
//Problem: Water Connection Problem
//Link: https://practice.geeksforgeeks.org/problems/water-connection-problem5822/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
{
    vector<vector<int>> ans;
    vector<int> in(n+1,0);
    vector<pair<int,int>> out(n+1,{-1,-1});

    for(int i=0;i<p;i++){
        out[a[i]]={b[i],d[i]};
        in[b[i]]=1;
    }
    for(int i=1;i<=n;i++){
        vector<int> final;
        final.push_back(i);
        if(in[i]==0 && out[i].first!=-1){
            int mindia = out[i].second;
            int last = out[i].first;
            while(out[last].first!=-1){
                mindia = min(mindia,out[last].second);
                last = out[last].first;
            }
            final.push_back(last);
            final.push_back(mindia);
            ans.push_back(final);
        }
    }
    return ans;
}

void attempt(){
    int n;
    cin>>n;
    int p;
    cin>>p;
    vector<int> a,b,d;
    for(int i=0;i<p;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<p;i++){
        int x;
        cin>>x;
        b.push_back(x);
    }
    for(int i=0;i<p;i++){
        int x;
        cin>>x;
        d.push_back(x);
    }
    vector<vector<int>> s = solve(n,p,a,b,d);
}
int main(){
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    attempt();
    return 0;
}