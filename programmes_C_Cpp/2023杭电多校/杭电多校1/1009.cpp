#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
class Solution{
public:
    ll T,n,m,d;
    void main(){
        cin>>T;
        while(T--){
            ll flag=0;
            cin>>n>>m>>d;
            if(m%n==0&&m/n>=d) flag=1;
            if(m%n&&m/n+1>=d) flag=1;
            cout<<(flag?"Yes\n":"No\n");
        }
        return;
    }
};
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Solution solution;
    solution.main();
    return 0;
}
