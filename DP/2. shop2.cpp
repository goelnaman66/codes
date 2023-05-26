// Find the maximum happiness if a shop has N items and each item has price pi and happiness hi, maximum items you can buy is K and Budget is B.

#include<bits/stdc++.h>
using namespace std;


int n;
int k, b;
int p[10010];
int h[10010];

int ans=0;


//complexity of this code is 2^n (for every subset)
// we removed the bulky data structutre
void rec(int level, int totalcost, int items, int totalhap){
    if(level==n){
        if(totalcost<=b and items<=k){
            ans=max(ans, totalhap);
        }

        return;
    }

    //dont take
    rec(level+1, totalcost, items, totalhap);

    //take
    //we dont need to revert these variables now as these are local variables
    rec(level+1, totalcost+p[level], items+1, totalhap+h[level]);
    
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i]>>h[i];
    }
    cin>>b>>k;
    rec(0,0,0,0);
    cout<<ans<<endl;
    return 0;
}