#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x7f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
string inOrder,postOrder;
void getPreOrder(ll root,ll l,ll r){
    if(l>r) return;
    ll p=l;
    while(p<r&&inOrder[p]!=postOrder[root]) p++;
    cout<<postOrder[root];
    getPreOrder(root-1-r+p,l,p-1);
    getPreOrder(root-1,p+1,r);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>inOrder>>postOrder;
    getPreOrder(inOrder.size()-1,0,inOrder.size()-1);
    return 0;
}