#include <bits/stdc++.h>
#define int long long
#define SIZE 100
using namespace std;

int lcs(string s1,string s2,int m,int n){
    
    if(m==0 || n==0) return 0;
    
    if(s1[m-1]==s2[n-1]){
        return 1+lcs(s1,s2,m-1,n-1);
    }
    return max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n));
}

int memo[1000][1000];

int topDown(string s1,string s2,int m,int n){
    if(memo[m][n]==-1){
        if(m==0||n==0){
            memo[m][n] = 0;
        }else{
            if(s1[m-1]==s2[n-1]){
                memo[m][n] = 1 + topDown(s1,s2,m-1,n-1);
            }else{
                memo[m][n] = max(topDown(s1,s2,m-1,n),topDown(s1,s2,m,n-1));
            }
        }
        return memo[m][n];
    }
    return memo[m][n];
}   


int bottomUp(string s1,string s2,int m,int n){
    int dp[m+1][n+1];
    memset(dp,-1,sizeof(dp));

    for(int i=0;i<=m;i++)
        dp[0][i] = 0;
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];

}

int32_t main() {
#ifndef OJ
    freopen("input.txt","r",stdin);
#endif 

    string s1,s2;
    cin>>s1>>s2;

    int m = s1.length();
    int n = s2.length();
    
    memset(memo,-1,sizeof(memo));
    

    cout<<lcs(s1,s2,m,n)<<endl;
    cout<<topDown(s1,s2 ,m,n)<<endl;
    cout<<bottomUp(s1,s2,m,n)<<endl;
  

    return 0;

}