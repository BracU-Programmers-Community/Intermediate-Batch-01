#include <bits/stdc++.h>
using namespace std;

const int nmax = 10005;
int grundy[nmax];

void precal(vector<int> &S){
    grundy[0] = 0;
    for(int g = 1; g<nmax; g++){

        vector<int> reachable;
        for(int x : S){
            if(g-x >= 0){
                reachable.push_back(grundy[g-x]);
            }
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin>>k;
    vector<int> S(k);
    for(int i = 0; i<k; i++) cin>>S[i];

    precal(S);

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

        if(XOR == 0){
            cout<<'L';
        }
        else{
            cout<<'W';
        }
    }


    return 0;
}
