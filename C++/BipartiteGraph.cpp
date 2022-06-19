#include<bits/stdc++.h>
using namespace std;

// using adjacency list
 bool helper(vector<int>adj[],int n,int color[],int col,int sv){
    if(color[sv]==-1) color[sv] = col;
    for(int i=0; i<adj[sv].size(); i++){
        int x= adj[sv][i];
        if(color[x]==col) return false;
        if(color[x]==-1) if(!helper(adj,n,color,1-col,x)) return false;
    }
    return true;
}
bool isBipartite(int n, vector<int>adj[]){
    int col =0;
    int color[n];
    for(int i=0; i<n; i++) color[i]= -1;
    for(int i=0; i<n; i++)
        if(color[i]==-1)
            if(!helper(adj,n,color,col,i)) return false;
    
    return true;
    // Code here
}

//DFS way
bool isBipartite(vector<vector<int>> edges,int color[],int sv,int col){
    int n = edges.size();
    if(color[sv]==-1) color[sv] = col;
    for(int i=1; i<=n; i++){
        if(edges[sv][i]==1){
            if(color[i]==col)
            return false;
            if(color[i]==-1)
            if(!isBipartite(edges,color,i,1-col)) return false;
        }

    }
    return true;

    //find all the neighbours which are not visited and if you wan
}

void solve(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> edges(n+1);
    for(int i=0; i<=n; i++) edges[i] = vector<int>(n+1);
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) edges[i][j] = 0;
    for(int i=0; i<e; i++){
        int a,b;
        cin>>a>>b;
        edges[a][b]  = 1;
        edges[b][a]  = 1;
    }
    int color[n+1];
    for(int i=0; i<=n; i++){
        color[i] = -1;
    }
    int sv = 1;
    int col= 1;
    for(int i=0; i<n; i++)
    if(color[i]==-1)
    if(!isBipartite(edges,color,i, col)){
        cout<<0;
        return ;
    } 
    cout<<1;

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}