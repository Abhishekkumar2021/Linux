#include<bits/stdc++.h>
using namespace std;
void printHanoi(int n,char src,char helper,char des){
    if(n==1){
        cout<<src<<"-"<<des<<"\n";
        return ;
    }
    printHanoi(n-1,src,des,helper);
    cout<<src<<"-"<<des<<"\n";
    printHanoi(n-1,helper,src,des); 
}
void solve(){
    int n;
    cin>>n;
    printHanoi(n,'A','B','C');
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}