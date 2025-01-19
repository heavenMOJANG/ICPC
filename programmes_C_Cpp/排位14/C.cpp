#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct Node{
    int val,id;
    friend bool operator<(Node x,Node y){return x.val>y.val;}
};
void solve(){
    int n;
    while(cin>>n){
        vector<int>a(760),b(760);
        for(int i=1;i<=n;++i) cin>>a[i];
        for(int i=2;i<=n;++i){
            for(int j=1;j<=n;++j) cin>>b[j];
            sort(b.begin()+1,b.begin()+1+n);
            priority_queue<Node>pq;
            Node tmp;
            for(int j=1;j<=n;++j){
                tmp.val=a[j]+b[1];
                tmp.id=1;
                pq.push(tmp);
            }
            for(int j=1;j<=n;++j){
                tmp=pq.top();pq.pop();
                a[j]=tmp.val;
                if(tmp.id<n) pq.push({tmp.val-b[tmp.id]+b[tmp.id+1],tmp.id+1});
            }
        }
        for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
