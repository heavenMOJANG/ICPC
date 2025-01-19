#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll _,n;
void read(ll&n){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    n=x*f;
}
void write(ll n){
    if(n<0){putchar('-');n*=-1;}
    static ll sta[128];
    ll top=0;
    do{
        sta[top++]=n%10,n/=10;
    }while(n);
    while(top) putchar(sta[--top]+48);
}
class Solution{
public:
    void main(){
        read(n);
        vector<ll>a(n),id(n),v(n);
        for(ll i=0;i<n;++i) read(a[i]),id[i]=i;
        a[0]=min(a[0],1LL);
        a[n-1]=min(a[n-1],1LL);
        sort(id.begin(),id.end(),[&](ll x,ll y){return a[x]>a[y];});
        int ans = 0;
        for(auto x:id){
        if(v[x]) continue;
        if(a[x]<2) break;
        ans+=1;
        v[x]=1;
        {
            int cur = x;
            while(cur + 1 < n && !v[cur + 1]){
                v[++cur] = true; 
                if (a[cur] == 0) break;
            }
        }
        {
            int cur = x;
            while(cur - 1 >= 0 && !v[cur - 1]){
                v[--cur] = true;
                if (a[cur] == 0) break;
            }
        }
    }
    }
};
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Solution solution;
    //read(_);
    _=1;
    while(_--){
        solution.main();
    }
    return 0;
}
