#include <bits/stdc++.h>
using namespace std;

int arr[100];
int main(){

    int n;
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }

    int ans = -1e9;
    int minsofar = 0;
    int sum = 0;

    for(int i = 1; i<=n; i++){
        sum += arr[i];
        ans = max(ans, sum - minsofar);
        minsofar = min(minsofar, sum);
    }

    cout<<ans<<endl;

}
