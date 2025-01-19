#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
vector<string> findTwoWordCompounds(const vector<string>&dictionary){
    unordered_set<string>se;
    for(const string& word:dictionary) se.insert(word);
    vector<string>res;
    for(const string& word:dictionary) {
        for(int i=1;i<word.length();++i) {
            string pre=word.substr(0,i);
            string suf=word.substr(i);
            if(se.count(pre)&&se.count(suf)){res.push_back(word);break;}
        }
    }
    return res;
}
void solve(){
    vector<string>dict;
    string s;
    while(cin>>s) dict.push_back(s);
    vector<string>ans=findTwoWordCompounds(dict);
    sort(ans.begin(),ans.end());
    for(auto x:ans) cout<<x<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
