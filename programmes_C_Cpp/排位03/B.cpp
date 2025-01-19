#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    unordered_map<char,int>pri;
    char ops[4]={'+','-','*','/'};
    for(int i=0,x;i<4;++i) cin>>x,pri[ops[i]]=x;
    string s;cin>>s;
    stack<int>stkn;
    stack<char>stko;
    auto proc=[&](int num1,int num2,char op){
        switch(op){
            case '+':return num1+num2;
            case '-':return num1-num2;
            case '*':return num1*num2;
            case '/':return num1/num2;
        }
    };
    function<void()>calc=[&](){
        int num2=stkn.top();stkn.pop();
        int num1=stkn.top();stkn.pop();
        char op=stko.top();stko.pop();
        stkn.push(proc(num1,num2,op));
    };
    int tmp=0;
    for(int i=0;i<s.size();++i){
        if(isdigit(s[i])) tmp=tmp*10+(s[i]-'0');
        else{
            stkn.push(tmp);tmp=0;
            char op=s[i];
            while(!stko.empty()&&pri[op]>=pri[stko.top()]) calc();
            stko.push(op);
        }
    }
    stkn.push(tmp);
    while(!stko.empty()) calc();
    cout<<stkn.top()<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
