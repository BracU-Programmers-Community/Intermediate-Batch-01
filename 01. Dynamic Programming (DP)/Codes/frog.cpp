#include <bits/stdc++.h>
using namespace std;

int memo[100005];

int main(){

    int n;
    cin>>n;

    vector<int> heights(n);

    for(int i = 0; i<n; i++){
        cin>>heights[i];
    }

    memo[0] = 0;

    for(int i = 1; i<n; i++){
        memo[i] = memo[i-1] + abs(heights[i] - heights[i-1]);
        if(i>1)
            memo[i] = min(memo[i], memo[i-2] + abs(heights[i] - heights[i-2]));
    }

    cout<<memo[n-1];

}
