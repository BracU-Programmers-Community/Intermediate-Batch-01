#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001];
char S[5001], T[5001];

int main(){
    cin>>S;
    cin>>T;
    int n = strlen(S), m = strlen(T);

    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            if(i == 0 || j == 0){
                dp[i][j] == 0;
                continue;
            }

            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

            if(S[i-1] == T[j-1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }

    cout<<dp[n][m]<<endl;

    int cur1 = n, cur2 = m;
    string ans;
    while(cur1 > 0 && cur2 > 0){
        if(dp[cur1][cur2] == dp[cur1-1][cur2]){
            cur1--;
            continue;
        }
        if(dp[cur1][cur2] == dp[cur1][cur2-1]){
            cur2--;
            continue;
        }

        ans.push_back(S[cur1-1]);
        cur1--;
        cur2--;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;

}



