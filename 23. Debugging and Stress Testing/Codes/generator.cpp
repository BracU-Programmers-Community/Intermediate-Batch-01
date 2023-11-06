#include <bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));

int main(){
    int n = rng()%5 + 1;

    cout<<n<<endl;

    for(int i = 0; i<n; i++){
        cout<<int(rng()%10) - 5<<" ";
    }
}
