#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int n,k;
struct Matrix{
    int a[40][40];
    friend Matrix operator+(const Matrix&A,const Matrix&B){
        Matrix C;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j) C.a[i][j]=(A.a[i][j]+B.a[i][j])%10;
        return C;
    }
    friend Matrix operator*(const Matrix&A,const Matrix&B){
        Matrix C;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j){
                C.a[i][j]=0;
                for(int k=0;k<n;++k) C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j])%10;
            }
        return C;
    }
    friend Matrix operator^(Matrix A,int x){
        Matrix res;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j) res.a[i][j]=(i==j);
        while(x){
            if(x&1) res=res*A;
            A=A*A;
            x>>=1;
        }
        return res;
    }
};
Matrix sum(Matrix A,int x){
    if(x==1) return A;
    Matrix E;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j) E.a[i][j]=(i==j);
    if(!x) return E;
    Matrix res=E+(A^(x/2));
    res=res*sum(A,x/2);
    if(x&1) res=res+(A^n);
    return res;
}
void solve(){
    while(cin>>n>>k,n||k){
        Matrix A;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j) cin>>A.a[i][j],A.a[i][j]%=10;
        A=sum(A,k);
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j) cout<<A.a[i][j]<<" \n"[j==n-1];
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
