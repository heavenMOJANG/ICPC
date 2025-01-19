#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const double eps=1e-8;
struct Node{
    ll l,r;
    double add,sumx,sumd;
}t[400010];
double n,m;
double a[100010];
double sgn(double x){
    if(fabs(x)<eps) return 0;
	if(x>0) return 1;
	return -1;
}
void pushUp(ll p){
	t[p].sumx=t[p<<1].sumx+t[p<<1|1].sumx;
	t[p].sumd=t[p<<1].sumd+t[p<<1|1].sumd;
}
void build(ll l,ll r,ll p){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].sumx=a[l];
		t[p].sumd=a[l]*a[l];
		return;
	}
	double mid=l+r>>1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	pushUp(p);
}
void pushDown(ll p){
	double l1=t[p<<1].r-t[p<<1].l+1;
	double l2=t[p<<1|1].r-t[p<<1|1].l+1;
	double d=t[p].add;
	t[p<<1].add+=d,t[p<<1|1].add+=d;
	t[p<<1].sumd+=2*d*t[p<<1].sumx+l1*d*d;
	t[p<<1|1].sumd+=2*d*t[p<<1|1].sumx+l2*d*d;
	t[p<<1].sumx+=l1*d,t[p<<1|1].sumx+=l2*d;
	t[p].add=0;
}
void update(double l,double r,double d,ll p){
	if(t[p].l==l&&t[p].r==r){
		t[p].add+=d;
		double len=r-l+1;
		t[p].sumd+=2*d*t[p].sumx+len*d*d;
		t[p].sumx+=len*d;
		return ;
	}
	if(sgn(t[p].add)) pushDown(p);
	double mid=t[p].l+t[p].r>>1;
	if(r<=mid) update(l,r,d,p<<1);
	else if(l>mid) update(l,r,d,p<<1|1);
	else update(l,mid,d,p<<1),
	update(mid+1,r,d,p<<1|1);
	pushUp(p);
}
double queryx(double l,double r,ll p){
	if(t[p].l==l&&t[p].r==r) return t[p].sumx;
	if(sgn(t[p].add)) pushDown(p);
	double mid=t[p].l+t[p].r>>1;
	if(r<=mid) return queryx(l,r,p<<1);
	else if(l>mid) return queryx(l,r,p<<1|1);
	else return queryx(l,mid,p<<1)+queryx(mid+1,r,p<<1|1);
}
double queryd(double l,double r,ll p){
	if(t[p].l==l&&t[p].r==r) return t[p].sumd;
	if(sgn(t[p].add)) pushDown(p);
	double mid=t[p].l+t[p].r>>1;
	if(r<=mid) return queryd(l,r,p<<1);
	else if(l>mid) return queryd(l,r,p<<1|1);
	else return queryd(l,mid,p<<1)+queryd(mid+1,r,p<<1|1);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i];
    build(1,n,1);
    while(m--){
        double op,x,y;cin>>op>>x>>y;
        if(op==1){
            double k;cin>>k;
            update(x,y,k,1);
        }
        if(op==2) cout<<fixed<<setprecision(4)<<queryx(x,y,1)/(y-x+1)<<"\n";
        if(op==3){
            double tmp1=queryx(x,y,1)/(y-x+1);
			double tmp2=queryd(x,y,1)/(y-x+1);
            cout<<fixed<<setprecision(4)<<tmp2-tmp1*tmp1<<"\n";
        }
    }   
    return 0;
}