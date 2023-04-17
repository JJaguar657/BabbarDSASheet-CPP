//DSA Sheet Babbar
//Code: Jinam Jain
//Problem: Minimum Cost to cut a board into squares
//Link: https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/
#include<bits/stdc++.h>
using namespace std;

int minimumCostOfBreaking(vector<int> x, vector<int> y, int m, int n){
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int i=x.size()-1,j=y.size()-1,vp=1,hp=1,cost=0;
        while(i>=0 && j>=0){
            if(x[i]>y[j]){
                cost += x[i]*hp;
                vp++;
                i--;
            }
            else {
                cost += y[j]*vp;
                hp++;
                j--;
            }
        }
        while(i>=0){
            cost += x[i]*hp;
            vp++;
            i--;
        }
        while(j>=0){
            cost += y[j]*vp;
            hp++;
            j--;
        }
        return cost;
    }

void attempt(){
    int n;
    int m;
    cin>>n>>m;
    vector<int> x(m-1),y(n-1);
    for(int i=0;i<m-1;i++){
        cin>>x[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>y[i];
    }
    int ans = minimumCostOfBreaking(x,y,m,n);
}
int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);
attempt();
return 0;
}