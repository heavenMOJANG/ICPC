#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,cnt,n1,n2,n3;
string s="123456789";
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>b>>c;
    do{
        n1=(s[0]-'0')*100+(s[1]-'0')*10+s[2]-'0';
        n2=(s[3]-'0')*100+(s[4]-'0')*10+s[5]-'0';
        n3=(s[6]-'0')*100+(s[7]-'0')*10+s[8]-'0';
        if(n1*b==n2*a&&n2*c==n3*b) cout<<n1<<" "<<n2<<" "<<n3<<"\n",cnt++;
    }while(next_permutation(s.begin(),s.end()));
    if(!cnt) cout<<"No!!!";
    return 0;
}