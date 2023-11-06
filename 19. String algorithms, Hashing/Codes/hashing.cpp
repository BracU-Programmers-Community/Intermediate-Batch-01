#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int nmax = 1e6+10;
namespace H1{
    const ll prime = 1e9+7;
    const ll base = 1000003;      /// x

    ll power[nmax];
    ll H[nmax];

    void precal(){
        power[0] = 1;
        for(int i = 1; i<nmax; i++) power[i] = power[i-1] * base % prime;
    }

    void buildHash(string &s){
        H[0] = s[0];
        for(int i = 1; i<s.size(); i++)
            H[i] = ( H[i-1] * base + s[i] ) % prime;
    }

    ll hashval(int L, int R){
        if(L == 0) return H[R];

        ll ret = (H[R] - H[L-1] * power[R-L+1]) % prime;
        if(ret < 0) ret += prime;
        return ret;
    }

}

namespace H2{
    const ll prime = 1e9+9;
    const ll base = 1e8;      /// x

    ll power[nmax];
    ll H[nmax];

    void precal(){
        power[0] = 1;
        for(int i = 1; i<nmax; i++) power[i] = power[i-1] * base % prime;
    }

    void buildHash(string &s){
        H[0] = s[0];
        for(int i = 1; i<s.size(); i++)
            H[i] = ( H[i-1] * base + s[i] ) % prime;
    }

    ll hashval(int L, int R){
        if(L == 0) return H[R];

        ll ret = (H[R] - H[L-1] * power[R-L+1]) % prime;
        if(ret < 0) ret += prime;
        return ret;
    }

}

pair<ll, ll> hashval(int L, int R){
    ll ret1 = H1::hashval(L, R);
    ll ret2 = H2::hashval(L, R);

    return make_pair(ret1, ret2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    H1::precal();
    H2::precal();


    string s;
    cin>>s;
    H1::buildHash(s);
    H2::buildHash(s);

    int q;
    cin>>q;
    for(int i = 0; i<q; i++){
        int l1, r1, l2, r2;

        cin>>l1>>r1>>l2>>r2;

        if(r1-l1+1 != r2-l2+1){
            cout<<"No\n";
        }
        else if(hashval(l1, r1) == hashval(l2, r2)){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }


}
