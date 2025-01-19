#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct Node{
    int l,c;
    bool operator<(const Node&b)const{return l==b.l?c<b.c:l<b.l;}
};
int idx;
void solve(){
    cout<<"Case #"<<++idx<<":"<<"\n";
    multiset<Node>ms;
    int n;cin>>n;
    for(int i=0;i<n;++i){
        Node x;
        cin>>x.l>>x.c;
        auto it=ms.lower_bound(x);
        if(it==ms.begin()||(--it)->c>x.c){
            ms.insert(x);
            it=ms.upper_bound(x);
            while(it!=ms.end()&&it->c>=x.c) ms.erase(it++);
        }
        cout<<ms.size()<<"\n";
    }
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
