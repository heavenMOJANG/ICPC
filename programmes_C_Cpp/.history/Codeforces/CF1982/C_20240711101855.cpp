#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,l,r;cin>>n>>l>>r;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int sum=0,cnt=0;
    for(int i=0,j=1;i<n;++i)
        while (sum<l&&j<n){
            if(a[j]>r){
                sum=0;
                i=j;
                j=i+1;
                break;
            }
            if(a[j]>=l){
                cnt++;
                sum=0;
                i=j;
                j=i+1;
                break;
            }
            if(a[j]<l){
                if(sum+a[j]>r){sum-=a[i];break;}
                if(sum+a[j]>=l&&sum+a[j]<=r){
                    sum=0;
                    cnt++;
                    i=j;
                    j=i+1;
                    break;
                }
                else if(sum+a[j]<l) sum+=a[j++];
            }
        }
    cout<<cnt<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}