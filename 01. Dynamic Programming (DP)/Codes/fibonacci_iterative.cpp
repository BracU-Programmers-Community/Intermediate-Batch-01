#include <bits/stdc++.h>
using namespace std;

long long int memo[500];

void fib(int n){
    memo[0] = 1;
    memo[1] = 1;
    for(int i = 2; i<=n; i++)
        memo[i] = memo[i-1] + memo[i-2];
    return;
}


int main(){



}
