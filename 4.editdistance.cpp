#include <bits/stdc++.h>
#define int long long
using namespace std;

int editDistance(string s1,string s2,int m,int n){
    if(m==0) return n;
    if(n==0) return m;

    if(s1[m-1]==s2[n-1]){
        return editDistance(s1,s2,m-1,n-1);
    }else{
        return 1 + min(min(editDistance(s1,s2,m-1,n),
        editDistance(s1,s2,m,n-1)),editDistance(s1,s2,m-1,n-1));
    }
}
int dp[1000][1000];
int topDown(string s1,string s2,int m,int n){
    if(dp[m][n]==-1){
        if(m==0){
            dp[m][n] = n;
        }else if(n==0){
            dp[m][n] = m;
        }else{
            if(s1[m-1]==s2[n-1]){
                dp[m][n] = topDown(s1,s2,m-1,n-1);
            }else{
                dp[m][n] = 1 + min(min(topDown(s1,s2,m-1,n),topDown(s1,s2,m,n-1)),topDown(s1,s2,m-1,n-1));
            }
        }
        return dp[m][n];
    }
    return dp[m][n]; 
}

int bottomUp(string s1,string s2,int m,int n){
    int dp[m+1][n+1];
    memset(dp,-1,sizeof(dp));
    
    for(int i=0;i<=m;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=n;i++){
        dp[0][1] = 0;
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
           if(s1[i-1]==s2[j-1]){
               dp[i][j] = dp[i-1][j-1];
           }else{
               dp[i][j] = 1 + min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
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
    
    memset(dp,-1,sizeof(dp));
    

    cout<<editDistance(s1,s2,m,n)<<endl;
    cout<<topDown(s1,s2 ,m,n)<<endl;
    cout<<bottomUp(s1,s2,m,n)<<endl;
  

    return 0;

}