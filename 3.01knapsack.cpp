 #include <bits/stdc++.h>
#define int long long
#define SIZE 100
using namespace std;

int knapsack(int v[],int wt[],int w,int n){
    if(w==0 || n==0) return 0;
    if(wt[n-1]>w){
        return knapsack(v,wt,w,n-1);
    }else{
        return max(knapsack(v,wt,w,n-1),v[n-1]+knapsack(v,wt,w-wt[n-1],n-1));
    }
}

int dp[1000][1000];

int topDown(int v[],int wt[],int w,int n){
    if(dp[n][w]==-1){
        if(w==0||n==0){
            dp[n][w] = 0;
        }else
            if(wt[n-1]>w){
                dp[n][w] = topDown(v,wt,w,n-1);
            }
            else{
                dp[n][w] = max(topDown(v,wt,w,n-1),v[n-1]+topDown(v,wt,w-wt[n-1],n-1));
        }
        return dp[n][w];
    }
    return dp[n][w];
}


int bottomUp(int v[],int wt[],int w,int n){
    int dpArray[n+1][w+1];
    for(int i=0;i<=w;i++){
        dpArray[0][i] = 0;
    }
    for(int i=0;i<=n;i++){
        dpArray[i][0] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(wt[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j],v[i-1]+dp[i-1][j-wt[i-1]]);
            }
        }
    }
    return dp[n][w];
}

int32_t main() {
#ifndef OJ
    freopen("input.txt","r",stdin);
#endif 

    int n;
    cin>>n;

    int wt[n];
    int v[n];
    int w;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cin>>w;
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(v,wt,w,n)<<endl;
    cout<<topDown(v,wt,w,n)<<endl;
    cout<<bottomUp(v,wt,w,n)<<endl;

   

    return 0;

}