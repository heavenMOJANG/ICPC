#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    int score_a=0,score_b=0;
    int positiveScore=0,negativeScore=0;
    for(int i=0;i<n;++i){
        if(a[i]==1&&b[i]==1) positiveScore++;
        if(a[i]==-1&&b[i]==-1) negativeScore++;
        if(a[i]>b[i]&&a[i]==1) score_a++;
        if(a[i]<b[i]&&b[i]==1) score_b++;
    }
    if(score_a>score_b) swap(score_a,score_b);
    int tmp=score_a;
    score_a+=min(score_b-score_a,positiveScore);
    positiveScore-=min(score_b-tmp,positiveScore);
    score_a+=positiveScore/2;
    score_b+=positiveScore-positiveScore/2;
    if(score_a>score_b) swap(score_a,score_b);
    tmp=score_b;
    score_b-=min(score_b-score_a,negativeScore);
    negativeScore-=min(tmp-score_a,negativeScore);
    score_a-=negativeScore/2;
    score_b-=negativeScore-negativeScore/2;
    cout<<min(score_a,score_b)<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}