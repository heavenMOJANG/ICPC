#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char ch;
ll sum11u,sum11v,sum21u,sum21v;
string s1,s2;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>ch&&ch!='E'){
        if(ch=='\n') continue;
        if(ch=='W') sum11u++,sum21u++;
        else sum11v++,sum21v++;
        if((sum11u>=11||sum11v>=11)&&abs(sum11u-sum11v)>=2) s1+=to_string(sum11u)+":"+to_string(sum11v)+"\n",sum11u=sum11v=0;
        if((sum21u>=21||sum21v>=21)&&abs(sum21u-sum21v)>=2) s2+=to_string(sum21u)+":"+to_string(sum21v)+"\n",sum21u=sum21v=0;
    }
    s1+=to_string(sum11u)+":"+to_string(sum11v)+"\n";
    s2+=to_string(sum21u)+":"+to_string(sum21v)+"\n";
    cout<<s1<<"\n"<<s2;
    return 0;
}