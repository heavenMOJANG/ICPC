#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
int check(string s,string t){
    int n=s.size(),m=t.size();
    vector<vector<int>>f(m+1,vector<int>(52,0));
    vector<int>a(n),b(m);
    for(int i=0;i<n;++i)
        if('a'<=s[i]&&s[i]<='z') a[i]=s[i]-'a';
        else a[i]=s[i]-'A'+26;
    for(int i=0;i<m;++i)
        if('a'<=t[i]&&t[i]<='z') b[i]=t[i]-'a';
        else b[i]=t[i]-'A'+26;
    for(int i=0;i<52;++i) f[m][i]=m;
    for(int i=m-1;i>=0;--i)
        for(int j=0;j<52;++j)
            if(b[i]==j) f[i][j]=i;
            else f[i][j]=f[i+1][j];
    int add=0;
    for(int i=0;i<n;++i){
        if(f[add][a[i]]==m) return 0;
        add=f[add][a[i]]+1;
    }
    return 1;
}
void solve(){
    string s,t,str;
    while(getline(cin,str)){
        s=str.substr(0,str.find(' '));
        t=str.substr(str.find(' ')+1);
        cout<<(check(s,t)?"Yes\n":"No\n");
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
