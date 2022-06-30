#include<bits/stdc++.h>
using namespace std;
void printSubset(vector<int> arr, int i,int curr,int rem,int x[],int m){
    // Base case
    if(i==arr.size()){
        for(int j=0; j<i; j++) cout<<x[j]<<" ";
        cout<<"\n";
        return;
    }

    // Let first include the i-th item
    x[i] = 1;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int rem = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        rem+=arr[i];
    } 
    int sum;
    cin>>sum;
    int x[n];
    printSubset(arr,0,0,rem,x,sum);

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}