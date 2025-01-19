#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll n,h[1000010];
class Solution{
public:
    void main(){
        cin>>n;
        ll maxn=0;
        for(ll i=1,x;i<=n;++i){
            cin>>x;
            maxn=max(maxn,x);
            for(ll k=1;k<=sqrt(x);++k)
                if(x%k==0){
                    h[k]++;
                    if(k*k!=x) h[x/k]++;
                }
        }
        ll cur=maxn;
        for(ll i=1;i<=n;++i){
            while(h[cur]<i) cur--;
            cout<<cur<<"\n";
        }
    }
};
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Solution solution;
    solution.main();
    return 0;
}
