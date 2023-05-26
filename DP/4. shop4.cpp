// Find the maximum happiness if a shop has N items and each item has price pi and happiness hi, maximum items you can buy is K and Budget is B.


// for formulating it in dp problem,
// constraints: n<=100 B<=1000

#include<bits/stdc++.h>
using namespace std;


int n;
int k, b;
int p[10010];
int h[10010];

int dp[101][1001][101];


// When we are moving the ans to return parameter of thye function, we can
// no longer keep it global, we will have to return it through the function
// int ans=0;


//complexity of this code is n*b*k as all the values of dp needs to be computed only once.


int rec(int level, int totalcost, int items){
    if(level==n){
        // when we reached the level n, there is no item left to take,
        // so max happiness we can get is 0
        return 0;
    }

    // cache check for the current state
    if(dp[level][totalcost][items]!=-1){
        return dp[level][totalcost][items];
    }
    //dont take
    int ans= rec(level+1, totalcost, items);

    //take
    //we dont need to revert these variables now as these are local variables
    if(items+1<=k and totalcost+p[level]<=b)
        ans =max(ans, rec(level+1, totalcost+p[level], items+1)+h[level]);

    // save the answer for the current state
    return dp[level][totalcost][items]=ans;
    
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i]>>h[i];
    }
    cin>>b>>k;

    memset(dp, -1, sizeof(dp));
    cout<<rec(0,0,0);
    return 0;
} 