#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5+10;
int failure[nmax];

int KMP(string &str){
    int cur = 0, mxcur = 0;
    failure[0] = cur;

    for(int i = 1; i<str.size(); i++)
    {
        while(cur != 0 && str[cur] != str[i]) cur = failure[cur-1];
        if(str[cur] == str[i]) ++cur;

        failure[i] = cur;

        mxcur = max(mxcur, cur);
    }

    return mxcur;
}

vector<int> adj[nmax];

void buildPrefixTree(int n){
    for(int i = 0; i<n; i++){
        int parent = failure[i];
        adj[parent].push_back(i+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string p, t;
    cin>>p>>t;

    string s = p + '$' + t;

    KMP(s);

    for(int i = 0; i<s.size(); i++){
        cout<<"Failure["<<i<<"] = "<<failure[i]<<endl;
        if(failure[i] == p.size()){
            cout<<"match found"<<endl;
        }
    }



}
