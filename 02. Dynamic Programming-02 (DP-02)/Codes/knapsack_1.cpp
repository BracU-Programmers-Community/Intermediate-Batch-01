#include <bits/stdc++.h>
using namespace std;


long long int dp[100000+10][100+5];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, W;
    cin>>n>>W;


    vector<int> weights(n);
    vector<long long int> vals(n);

    for(int i = 0; i<n; i++){
        cin>>weights[i];
        cin>>vals[i];
    }



    for(int x = 0; x <= W; x++){
        for(int i = 0; i<n; i++){
            if(x == 0){
                dp[x][i] = 0;
                continue;
            }



            if(i > 0)       /// i-th weight was not used
                dp[x][i] = max(dp[x][i], dp[x][i-1]);

            if(x >= weights[i])     /// i-th weight was used
                dp[x][i] = max(dp[x][i], dp[x-weights[i]][i-1]+vals[i]);

        }
    }


    long long int ans = 0;
    for(int x = 0; x<=W; x++){
        ans = max(ans, dp[x][n-1]);
    }

    cout<<ans;


    return 0;
}
