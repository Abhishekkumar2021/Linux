#include<bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(const vector<int> &arr1, const vector<int> &arr2){
    if(arr2.size()<arr1.size()) return findMedianSortedArrays(arr2,arr1);
    int n1 = arr1.size();
    int n2 = arr2.size();
    int left = (n1+n2+1)/2;
    int low = 0, high = n1;
    while(low<=high){
        int cut1 = (low+high)>>1;
        int cut2 = (left-cut1);
        int l1 = cut1==0?INT_MIN:arr1[cut1-1];
        int l2 = cut2==0?INT_MIN:arr2[cut2-1];
        int r1 = cut1==n1?INT_MAX:arr1[cut1];
        int r2 = cut2==n2?INT_MAX:arr2[cut2];

        if(l1<=r2&&l2<=r1){
            if((n1+n2)%2==0){
                return(max(l1,l2)+min(r1,r2))/2.0;
                
            }else{
                return max(l1,l2);
            }
        }
        if(l1>r2) high = cut1-1;
        else low = cut1+1;
    }
    return -1;
}
void solve(){
    vector<int>arr1,arr2;
    int n1,n2;
    cin>>n1;
    for(int i=0; i<n1; i++){
        int x;
        cin>>x;
        arr1.push_back(x);
    } 
    cin>>n2;
    for(int i=0; i<n2; i++){
        int x;
        cin>>x;
        arr2.push_back(x);
    }
    cout<<findMedianSortedArrays(arr1,arr2);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}