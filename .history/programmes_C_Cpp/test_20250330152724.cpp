#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10,INF = 1e18;
struct Node{
    int l,r,id,id2;
    bool operator < (const Node &t) const{
        if(l == t.l) return r < t.r;
        return l< t.l;
    }
}X[N];
bool cmp(Node a,Node b){
    return a.id2 < b.id2;
}
int ans[N];
void solve(){
    int n,m;
    cin>>n>>m;
    vector<Node>a,b;
    for(int i = 1;i <= n;i++){  
        int l,r;
        cin>>l>>r;
        X[i] = {l,r,i,i};
        if(l >= m) b.push_back({l,r,i,i});
        else a.push_back({l,r,i,i});
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ra = -1,cnt = 0;
    for(int i = 0;i < a.size();i++){
        ra = max(ra,a[i].r);
    }
    if(ra >= m){
        for(int i = 0;i < a.size();i++){
            ans[a[i].id] = ++cnt;
        }
        for(int i = 0;i < b.size();i++){
            ans[b[i].id] = ++cnt;
        }
    }
    else{
        for(int i = 0;i < b.size();i++){
            ans[b[i].id] = ++cnt;
        }
        for(int i = 0;i < a.size();i++){
            ans[a[i].id] = ++cnt;
        }
    }
    int R = m;
    int sum = 0;
    for(int i = 1;i <= n;i++){
        X[i].id2 = ans[i];
    }
    sort(X + 1,X + 1 + n,cmp);
    for(int i = 1;i <= n;i++){
        sum += max(X[i].l - R,0LL) + X[i].r - X[i].l;
        R = X[i].r;
    }
    cout<<sum<<'\n';
    for(int i = 1;i <= n;i++){
        cout<<X[i].id<<" \n"[i == n];
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}