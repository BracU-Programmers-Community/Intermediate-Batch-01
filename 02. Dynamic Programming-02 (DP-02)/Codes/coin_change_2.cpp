#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int dp[5001][5001];
int coins[5001];

int main(){
    int X, C;
    cin>>X>>C;
    for(int i = 0; i<C; i++){
        cin>>coins[i];
    }


    for(int x = 0; x<=X; x++){
        for(int i = 0; i<C; i++){
            if(x == 0){
                dp[x][i] = 1;
                continue;
            }

            if(i != 0)          /// not using coin[i]
                dp[x][i] += dp[x][i-1];

            if(x >= coins[i] && i > 0)   /// using coin[i]
                dp[x][i] += dp[x-coins[i]][i-1];

            dp[x][i] %= mod;
        }
    }

}


