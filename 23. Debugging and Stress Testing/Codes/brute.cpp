#include <bits/stdc++.h>
using namespace std;

int arr[100];

int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> v;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n;j++){
            int sum = 0;
            for(int k = i; k<=j; k++){
                sum += arr[k];
            }
            v.push_back(sum);
        }
    }

    sort(v.begin(), v.end());

    cout<<v.back()<<endl;
}
