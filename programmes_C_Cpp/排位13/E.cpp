#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;
    while(cin>>n){
        stack<int>s;
        queue<int>q;
        priority_queue<int>pq;
        vector<int>f(3,1);
        for(int i=0,x,y;i<n;++i){
            cin>>x>>y;
            switch(x){
                case 1:s.push(y),q.push(y),pq.push(y);break;
                case 2:{
                    if(!s.empty()){
                        if(s.top()!=y) f[0]=0;
                        s.pop();
                    }
                    else f[0]=0;
                    if(!q.empty()){
                        if(q.front()!=y) f[1]=0;
                        q.pop();
                    }
                    else f[1]=0;
                    if(!pq.empty()){
                        if(pq.top()!=y) f[2]=0;
                        pq.pop();
                    }
                    else f[2]=0;
                }break;
            }
        }
        int cnt=0;
        for(int i=0;i<3;++i) cnt+=f[i];
        switch(cnt){
            case 0:cout<<"impossible\n";break;
            case 1:{
                if(f[0]) cout<<"stack\n";
                if(f[1]) cout<<"queue\n";
                if(f[2]) cout<<"priority queue\n";
            }break;
            default:cout<<"not sure\n";break;
        }
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
