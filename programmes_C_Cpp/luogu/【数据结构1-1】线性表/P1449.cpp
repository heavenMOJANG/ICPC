#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
stack<ll>s;
ll tmp;
char ch;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>ch&&ch!='@'){
        if(ch=='.') s.push(tmp),tmp=0;
        else if('0'<=ch&&ch<='9') tmp=tmp*10+ch-'0';
        else{
            ll n1=s.top();s.pop();
            ll n2=s.top();s.pop();
            switch(ch){
                case '+':s.push(n2+n1);break;
                case '-':s.push(n2-n1);break;
                case '*':s.push(n2*n1);break;
                case '/':s.push(n2/n1);break;
            }
        }
    }
    cout<<s.top();
    return 0;
}