#include <bits/stdc++.h>
using namespace std;

int dp[100005][2];

int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    dp[0][0] = input[0];
    dp[0][1] = -input[0];

    for(int i = 1; i<n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + input[i];
        dp[i][1] = dp[i-1][0] + (-input[i]);
    }

    int ans = max(dp[n-1][0], dp[n-1][1]);

    cout<<ans<<endl;
}
