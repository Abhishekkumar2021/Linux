#include<bits/stdc++.h>
using namespace std;

int findParent(int p[],int x){
    if(p[x]==x)
    return x;
    return findParent(p,p[x]);
}
void solve(){
    int n;
    int e;
    cin>>n>>e;
    vector<pair<int,int>> edges(e);
    for(int i=0; i<e; i++){
        int a,b;
        cin>>a>>b;
        edges[i] = {a,b}; 
    }
    int parent[n+1];
    for(int i=0; i<=n; i++) parent[i] = i;
    for(int i=0; i<e; i++){
        int firstParent = findParent(parent,edges[i].first);
        int secondParent = findParent(parent, edges[i].second);
        if(firstParent==secondParent) cout<<"Cycle found!\n";
        else parent[firstParent] = secondParent;
    
    }
    // for(auto x:parent) cout<<x<<" ";

    for(int i=1; i<=n; i++) cout<<"Parent of "<<i<<" is = "<<findParent(parent,i)<<"\n";

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}