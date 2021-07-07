#include <bits/stdc++.h>
#define int long long
using namespace std;

int fibonacci(int n){
    if(n==0 || n==1) return n;
    return fibonacci(n-1) + fibonacci(n-2); 
}


int topDown(int n,vector<int> dp){
    if(n==0 || n==1) return n;

    if(dp[n]==-1){
        dp[n]= topDown(n-1,dp) + topDown(n-2,dp);
    }
    return dp[n];

}

int bottomUp(int n){
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int32_t main() {
#ifndef OJ
    freopen("input.txt","r",stdin);
#endif 

    int n;
    cin>>n;
    vector<int> dp(100,-1);
    cout<<fibonacci(n)<<endl;
    cout<<topDown(n,dp)<<endl;
    cout<<bottomUp(n)<<endl;

    return 0;

}