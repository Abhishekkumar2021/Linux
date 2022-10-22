#include<bits/stdc++.h>
using namespace std;

#define inf 1e9+7;
int minCost(vector<vector<int>> arr,int n,int m){
    if(n==0 and m==0) return arr[m][n];
    if(n<0 or m<0) return inf;
    int cost1 = minCost(arr,n-1,m);
    int cost2 = minCost(arr,n-1,m-1);
    int cost3 = minCost(arr,n,m-1);
    return min(cost1,min(cost2,cost3)) + arr[m][n];
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n);
    for(int i=0; i<n; i++){
        arr[i].resize(m);
        for(int j=0; j<m; j++) cin>>arr[i][j];
    } 
    cout<<minCost(arr,n,m);

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}