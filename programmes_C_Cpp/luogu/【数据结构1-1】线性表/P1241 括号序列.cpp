#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
stack<char>st;
ll vis[100010];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    ll len=s.size();
    for(ll i=0;i<len;++i){
        if(s[i]=='['||s[i]=='(') st.push(i); 
        else{
            if(s[i]==']'){
                if(st.empty()) continue;
                ll k=st.top();
                if(s[k]=='[') vis[i]=vis[k]=1,st.pop(); 
            } 
            if(s[i]==')'){
                if(st.empty()) continue;
                ll k=st.top();
                if(s[k]=='(') vis[i]=vis[k]=1,st.pop(); 
            }
        }
    } 
    for(ll i=0;i<len;++i){
        if(vis[i]) cout<<s[i];
        else{
            if(s[i]=='('||s[i]==')') cout<<"()";
            if(s[i]==']'||s[i]=='[') cout<<"[]";
        }
    }
    return 0;
}