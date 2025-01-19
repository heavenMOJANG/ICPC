#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
struct Node{
    int row; //行
    int col; //列
    int step; //跳至当前位置步数
};
queue<Node> Q; //搜索队列
int V[401][401]; //访问标记 -1: 未访问, 其他: 步
//初始化
void init(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            V[i][j]=-1;
    V[x][y]=0;
    Node node={x,y,0};
    Q.push(node);
}
//广度优先搜索
void bfs(){
    int r[8]={-1,-2,-2,-1,1,2,2,1};
    int c[8]={2,1,-1,-2,-2,-1,1,2};
    while(!Q.empty()){
        Node node = Q.front() ; //队首元素
        for(int i=0;i<8;i++){ //八个方向
            int row = node.row + r[i];
            int col = node.col + c[i];
            if(row<1||row>n||col<1||col>m ) continue; //跳出界外
            if( V[row][col]>=0 ) continue; //已访问过
            V[row][col] = node.step+1;
            Node t = {row,col,node.step+1};
            Q.push(t) ; //进队
        }
        Q.pop() ; //出队
    }
}
int main(){
    scanf("%d%d%d%d",&n,&m,&x,&y);
    init();
    bfs();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%-5d",V[i][j]);
        printf("\n");
    }
}