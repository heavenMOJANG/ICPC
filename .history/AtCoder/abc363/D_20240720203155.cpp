#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int __int128
using namespace std;
constexpr int inf=0x7fffffff;
int n;
void read(__int128&n){
    __int128 x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    n=x*f;
}
void write(__int128 n){
    if(n<0){putchar('-');n*=-1;}
    static __int128 sta[256];
    __int128 top=0;
    do{
        sta[top++]=n%10,n/=10;
    }while(n);
    while(top) putchar(sta[--top]+48);
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    read(n);
    int count=0,number=9,w=0,half,h=1,res;
    while(1){
        if(w>0&&w%2==0) number*=10;
        w++;
        if(count+number>n) break;    
        count+=number;
    }
    n-=count;
    for(int i=0;i<(w-1)/2;++i) h*=10;    
    half=h+n;
    res=half; 
    if(w%2!=0) half/=10;
    while(half!=0){
        res=res*10+half%10;
        half/=10;
    }
    write(res);
    return 0;
}