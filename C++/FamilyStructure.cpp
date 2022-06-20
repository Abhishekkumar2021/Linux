#include<bits/stdc++.h>
using namespace std;
int NthGenKthMem(int n, long long k,int gen){
    if(n==1 && k==1) return gen;
    long long mid = (1<<(n-2));
    // cout<<"mid = "<<mid<<" and k = "<<k<<"\n";
    if(k<=mid) return NthGenKthMem(n-1,k,gen);
    return NthGenKthMem(n-1,k-mid,1-gen);
}

string getGeneration(int n,int gen){
    if(n==1){
        return to_string(gen);
    }
    string ans1 = getGeneration(n-1,gen);
    string ans2 = getGeneration(n-1,1-gen);
    return ans1+ans2;
}
void solve(){
    int n;
    cin>>n;
    // long long int k;
    // cin>>k;
    cout<<getGeneration(n,1)<<"\n";
    for(int i=1; i<=(1<<(n-1)); i++)
    cout<<NthGenKthMem(n,i,1);


}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}