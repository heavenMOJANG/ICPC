#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int n,k;
string s;
map<string,int>mp;
int manacher(string str){
    if(!str.length()) return 0;
    int l=(int)(str.length()*2+1);
    char *s=new char[l];
    int *p=new int[l];
    int r,c,index,mx;
    r=c=-1;
    index=mx=0;
    for(int i=0;i<l;i++) s[i]=i&1?str[index++]:'#';
    for(int i=0;i<l;i++)
    {
        p[i]=r>i?min(r - i, p[2 * c - i]):1;
        while(i+p[i]<l&&i-p[i]>-1)
        {
            if(s[i+p[i]]==s[i-p[i]]) p[i]++;
            else break;
        }
        if(i+p[i]>r) 
        {
            r=i+p[i];
            c=i;
        }
        mx=max(mx,p[i]);
    }
    delete[] s;
	delete[] p;
    return mx-1;
    
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>k>>s;
    int cnt=0;
    do{
        if(mp[s].count()==1) continue;
        mp[s]=1;
        if(manacher(s)<k) cnt++; 
    }while(next_permutation(s.begin(),s.end()));
    cout<<cnt<<"\n";
    return 0;
}