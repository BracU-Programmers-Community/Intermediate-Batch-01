#include <bits/stdc++.h>
using namespace std;

int dp[505][505];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;

    cin>>n>>m;


    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }


            dp[i][j] = 1000000000;

            for(int k = 1; k<i; k++){
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            }

            for(int k = 1; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }


    cout<<dp[n][m];

    return 0;
}
