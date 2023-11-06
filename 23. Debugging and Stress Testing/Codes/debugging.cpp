#include <bits/stdc++.h>
using namespace std;

#define print(x) cout<< #x << " = " <<x <<endl;
#define hoise cout<<"hoise" << endl;
#define tham getchar()

int main(){
    int n;
    cin>>n;

    int lo = 1, hi = 1000000;

    int x = 100;

    while(lo <= hi){
        tham;
        hoise;

        int mid = (lo+hi)/2;
        print(hi);
        print(lo);
        print(mid);


        if(mid < x)
            hi = mid-1;
        else
            lo = mid;
    }

    cout<<x<<endl;
}
