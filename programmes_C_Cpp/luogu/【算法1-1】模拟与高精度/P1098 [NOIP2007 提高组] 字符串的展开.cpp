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
ll p1,p2,p3;
string s,t;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>p1>>p2>>p3>>s;
    for(ll i=0;i<s.size();++i){
        if(s[i]=='-'){
            if(!('0'<=s[i-1]&&s[i-1]<='9'&&'0'<=s[i+1]&&s[i+1]<='9')&&!('a'<=s[i-1]&&s[i-1]<='z'&&'a'<=s[i+1]&&s[i+1]<='z')){t+="-";continue;}
            if(s[i-1]<s[i+1]){
                if(s[i+1]-s[i-1]==1) continue;
                string tmp="";
                if(p1==3){
                    for(char ch=s[i-1]+1;ch<=s[i+1]-1;++ch)
                        for(ll j=1;j<=p2;++j) tmp+="*";
                }
                else{
                    char start=s[i-1],end=s[i+1];
                    if(p1==2&&'a'<=start&&start<='z') start-=32,end-=32;
                    for(char ch=start+1;ch<=end-1;++ch)
                        for(ll j=1;j<=p2;++j) tmp+=ch;
                    if(p3==2) reverse(tmp.begin(),tmp.end());
                }
                t+=tmp;
            }
            else t+="-";
        }
        else t+=s[i];
    }
    cout<<t;
    return 0;
}