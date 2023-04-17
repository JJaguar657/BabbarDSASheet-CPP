//DSA Sheet Babbar
//Code: Jinam Jain
//Problem: Count set bits in an integer
//Link: https://practice.geeksforgeeks.org/problems/set-bits0143/0
#include<bits/stdc++.h>
using namespace std;
 int setBits(int N) {
        int sum=0;
        while(N>0){
            if(N%2==1) sum++;
            N = N/2;
        }
        return sum;
    }
void attempt(){
    int n;
    cin>>n;
    int ans = setBits(n);
    cout<<ans;
}
int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);
attempt();
return 0;
}