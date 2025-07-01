#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int>a(n);
    map<int,int>mp;
    for(int i = 0;i < n;i++){
        cin>>a[i];
        mp[a[i]] = 1;
    }
    
    mp[0] = 1;
    for(int i = 1;i < n;i++){
        mp[a[i] & a[i-1] ] = 1;
        mp[a[i] | a[i - 1]] = 1;
        mp[a[i] ^ a[i - 1]] = 1;
    }
    cout<<mp.size()<<'\n';
    
    return 0;
}