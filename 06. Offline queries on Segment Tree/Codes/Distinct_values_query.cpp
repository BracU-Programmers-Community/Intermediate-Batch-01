#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int nmax = 2e5+10;

ll tree[4*nmax];


void update(int id, int l, int r, int k, ll val){

    if(l == r){
        tree[id] = val;     /// update operation
        return;
    }

    int mid = (l+r)/2;

    if(k <= mid)
        update(2*id, l, mid, k, val);
    else
        update(2*id+1, mid+1, r, k, val);


    tree[id] = tree[2*id] + tree[2*id+1];      /// merging child
    return;
}

ll query(int id, int l, int r, int a, int b){
    if(b < l || r < a){     /// disjoint case
        return 0;           /// return identity
    }

    if(a <= l && r <= b){   /// segment is completely inside [a, b] case
        return tree[id];    /// return node value
    }


    int mid = (l+r)/2;

    ll p = query(2*id, l, mid, a, b);
    ll q = query(2*id+1, mid+1, r, a, b);

    return p+q;         /// return merged answer
}

int arr[nmax];

vector<pair<int, int>> queries[nmax];        /// queries[r].push_back({l, id})

/// (1, 3), (2, 5), (1, 4), (3, 4)

/// queries[3] -> (1, id)
/// queries[5] -> (2, id)
/// queries[4] -> (1, id), (3, id)
int ans[nmax];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    int q;
    cin>>q;

    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }


    for(int i = 0; i<q; i++){
        int l, r;
        cin>>l>>r;

        queries[r].push_back(make_pair(l, i));
    }

    map<int, int> last;     /// map[x] = last occurrence of x kothai chilo
    for(int r = 1; r <= n; r++){
        update(1, 1, n, r, 1);

        if(last[arr[r]] != 0){
            update(1, 1, n, last[arr[r]], 0);
        }

        last[arr[r]] = r;

        for(auto p : queries[r]){
            int l = p.first;
            int id = p.second;

            int sum = query(1, 1, n, l, r);
            ans[id] = sum;
        }
    }

    for(int i = 0; i<q; i++){
        cout<<ans[i]<<"\n";
    }


    return 0;
}

