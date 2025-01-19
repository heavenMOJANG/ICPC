#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
class Solution{
private:
    ll x,y,ans=0;
public:
    void main() {
	    cin>>x>>y;
	    while(x&&y){
		    swap(x,y); 
		    ans+=x*4*(y/x);
			y%=x;
	    }
        cout<<ans<<"\n";
    }
};
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Solution solution;
    solution.main();
    return 0;
}
