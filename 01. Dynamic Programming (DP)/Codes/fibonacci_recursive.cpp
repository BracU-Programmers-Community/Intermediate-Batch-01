#include <bits/stdc++.h>
using namespace std;

long long int memo[5000];

long long int fib(int n){
    if(memo[n] != 0) return memo[n];

    if(n <= 0){
        memo[n] = n;
        return n;
    }

    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}
