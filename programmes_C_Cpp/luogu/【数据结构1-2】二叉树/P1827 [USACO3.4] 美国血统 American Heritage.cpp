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
string preOrder,inOrder;
void getPostOrder(ll pl,ll pr,ll il,ll ir){
    for(ll j=il;j<=ir;++j){
        if(preOrder[pl]==inOrder[j]){
            getPostOrder(pl+1,pl+j-il,il,j-1);
            getPostOrder(pl+j-il+1,pr,j+1,ir);
            cout<<inOrder[j];
            break;
        }
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>inOrder>>preOrder;
    getPostOrder(0,inOrder.size()-1,0,preOrder.size()-1);
    return 0;
}