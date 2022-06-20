#include<bits/stdc++.h>
using namespace std;

class State{
    public:
    int parent;
    int path;
    State(){
        parent = -1;
        path = -1;
    }
    void setState(int a,int b){
        parent = a;
        path = b;
    }
};

// string smallestMultiple(int n){
//     if(n==1)
//     return "1";
//     vector<string> number(n); //contains the string corresponding to the remainders
//     number[1] = "1";
//     queue<int> pd;
//     pd.push(1);
//     while(!pd.empty()){
//         int r = pd.front();
//         pd.pop();
//         if(r==0) return number[r];
//         for(int dig : {0,1}){
//             int new_rem = (10*r+dig)%n; 
//             if(number[new_rem].size()==0){
//                 pd.push(new_rem);
//                 number[new_rem] = number[r] + char(dig+'0');
//             }    
//         }
//     }
//     return "Not Possible";
// }


string smallestMultiple2(int n){
    if(n==1)
    return "1";
    vector<State> states(n); 
    states[1].setState(INT_MAX,INT_MAX);
    queue<int> pd;
    pd.push(1);
    while(!pd.empty()){
        int r = pd.front();
        pd.pop();
        if(r==0){
            string ans = "";
            int curr = r;
            while(states[curr].parent!=INT_MAX){
                ans+=states[curr].path+'0';
                curr = states[curr].parent;
            }
            ans+="1";
            reverse(ans.begin(),ans.end());
            return ans;
        }
        for(int dig : {0,1}){
            int new_rem = (10*r+dig)%n; 
            if(states[new_rem].parent==-1){
                pd.push(new_rem);
                states[new_rem].setState(r,dig);
            }    
        }
    }
    return "Not Possible";
}

void solve(){
    int n;
    cin>>n;
    cout<<smallestMultiple2(n);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}