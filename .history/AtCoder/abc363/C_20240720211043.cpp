#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int n,k;
string s;
map<string,int>mp;
void dfs(){

}
int check(string s){
    string t=s;
    reserse(s.begin(),s.end());
    return s==t;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>k>>s;
    int cnt=0;
    do{
        if(mp.count(s)==1) continue;
        mp[s]=1;
        if(manacher(s)!=k) cnt++; 
    }while(next_permutation(s.begin(),s.end()));
    cout<<cnt<<"\n";
    return 0;
}