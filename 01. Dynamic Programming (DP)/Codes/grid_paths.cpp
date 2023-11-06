#include <bits/stdc++.h>
using namespace std;


char grid[1005][1005];
int dp[1005][1005];
const int mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>grid[i];
    }

    for(int i = 0; i<n; i++){
        /// per row processing
        for(int j = 0; j<n; j++){


            dp[i][j] = 0;

            /// if obstacle
            if(grid[i][j] == '*') continue;

            /// base case
            if(i == 0 && j == 0){
                dp[i][j] = 1;
                continue;
            }

            if(i > 0) dp[i][j] += dp[i-1][j];
            if(j > 0) dp[i][j] += dp[i][j-1];

            dp[i][j] %= mod;
        }
    }

    cout<<dp[n-1][n-1];


}

