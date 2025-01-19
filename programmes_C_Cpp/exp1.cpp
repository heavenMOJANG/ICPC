#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct Node {
    int totalTime,tasksProcessed;
    vector<int>machineTimes;
};
struct cmp{bool operator()(const Node& a, const Node& b){return a.totalTime>b.totalTime;}};
int findMinimumCompletionTime(vector<int>&a,int n,int k){
    priority_queue<Node,vector<Node>,cmp>pq;
    Node tmp;
    tmp.totalTime=0;
    tmp.tasksProcessed=0;
    tmp.machineTimes=vector<int>(k,0);
    pq.push(tmp);
    while(!pq.empty()){
        Node current=pq.top();
        pq.pop();
        if(current.tasksProcessed==n) return current.totalTime;
        for(int i=0;i<k;++i){
            Node newNode=current;
            newNode.tasksProcessed++;
            int taskTime=a[newNode.tasksProcessed-1];
            newNode.machineTimes[i]+=taskTime;
            newNode.totalTime=*max_element(newNode.machineTimes.begin(),newNode.machineTimes.end());
            pq.push(newNode);
        }
    }
    return -1;
}
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    int res=findMinimumCompletionTime(a,n,k);
    cout<<res<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
