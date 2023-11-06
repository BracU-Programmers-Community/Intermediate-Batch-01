#include <bits/stdc++.h>
using namespace std;

const int nmax = 10005;
int grundy[nmax];

void precal(){
    grundy[0] = 0;
    for(int g = 1; g<nmax; g++){

        vector<int> reachable;

        /// g -> a  b

        for(int a = 1; a <=g/2; a++){
            int b = g - a;
            if(a == b) continue;

            int x = grundy[a] ^ grundy[b];
            reachable.push_back(x);
        }


        sort(reachable.begin(), reachable.end());
        int cur = 0;
        for(int x : reachable){
            if(cur == x) cur++;
            else if(cur < x) break;
        }

        grundy[g] = cur;
    }
}

/// N * k * log(k)

/// 10^4 * 100 * log(k) = 10^6 * log(k)

int main(){

    precal();

    int m;
    cin>>m;

    for(int i = 0; i<m; i++){
        int l;
        cin>>l;

        int XOR = 0;
        for(int j = 0; j<l; j++){
            int x;
            cin>>x;
            XOR ^= grundy[x];
        }

        cout<<"Case "<<i+1<<": ";
        if(XOR == 0){
            cout<<"Bob\n";
        }
        else{
            cout<<"Alice\n";
        }
    }


    return 0;
}

