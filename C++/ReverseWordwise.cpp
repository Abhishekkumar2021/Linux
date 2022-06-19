#include <iostream>
using namespace std;

string reverseStringWordWise(string input)
{
    int n = input.size();
    string ans= "";
    int space = n;
    for(int i=n-1; i>=0; i--){
        if(input[i]==' '){
            // for(int j=i+1; j<space; j++){
            //     ans+=input[j];
            // }
            // cout<<"The space = "<<space<<"\n";
            // space= i; 
            // ans+=" ";
            cout<<"space = "<<i<<"\n";
        }else{
            cout<<i<<"\n";
        }
        
        
    }
    // cout<<"The space = "<<space<<"\n";
    for(int j=0; j<space; j++){
        ans+=input[j];
    } 
    return ans;
    //Write your code here
}

int main()
{
    string s;
    getline(cin, s);
    string ans = reverseStringWordWise(s);
    // cout << ans << endl;
}