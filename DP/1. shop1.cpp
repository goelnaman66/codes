// Find the maximum happiness if a shop has N items and each item has price pi and happiness hi, maximum items you can buy is K and Budget is B.

#include<bits/stdc++.h>
using namespace std;


int n;
int k, b;
int p[10010];
int h[10010];

vector<pair<int, int>> cur;
int ans=0;


//complexity of this code is n*2^n (for every subset we are iterating and checking)
void rec(int level){
    if(level==n){
        int totalcost=0;
        int totalhap=0;
        for(auto v: cur){
            totalcost+=v.first;
            totalhap+=v.second;
        }

        if(totalcost<=b and cur.size()<=k){
            ans=max(ans, totalhap);
        }

        return;
    }

    //dont take
    rec(level+1);

    //take
    cur.push_back({p[level], h[level]});
    rec(level+1);
    cur.pop_back();
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i]>>h[i];
    }
    cin>>b>>k;
    rec(0);
    cout<<ans<<endl;
    return 0;
}