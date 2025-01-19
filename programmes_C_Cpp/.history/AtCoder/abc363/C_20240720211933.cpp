#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int n,k,h[26],cnt;
string s,t="**********";
int check(string str1){
    string str2=str1;
    reverse(str1.begin(),str1.end());
    return str1==str2;
}
void dfs(int x){
    if(x==n){
        int flag=1;
        for(int i=0;i+k-1<n;++i) if(check(t.substr(i,k))){flag=0;break;}
        if(flag) cnt++;
        return;
    }
    for(int i=0;i<26;++i)
        if(h[i]>0){
            h[i]--;
            t[x]=char('a'+i);
            dfs(x+1);
            h[i]++;
        }
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>k>>s;
    for(int i=0;i<n;++i) h[s[i]-'a']++;
    dfs(0);
    cout<<cnt<<"\n";
    return 0;
}