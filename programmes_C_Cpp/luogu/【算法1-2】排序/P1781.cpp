#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{ll id,len;string sum;}a[30];
ll n;
int cmp(node x,node y){return x.len==y.len?x.sum>y.sum:x.len>y.len;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i){
        a[i].id=i;
        cin>>a[i].sum;
        a[i].len=a[i].sum.size();
    }
    sort(a+1,a+1+n,cmp);
    cout<<a[1].id<<"\n"<<a[1].sum;
    return 0;
}