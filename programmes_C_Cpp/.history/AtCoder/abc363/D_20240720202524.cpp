#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int n;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    int count = 0,number = 9;
    int w=0;
    long half;                            //保存回文数的左半边的结果
    long h = 1;                            //回文数的左半边的起始基数
    long res;                            //结果
        while(true) {
            if(w > 0 && w%2 == 0) {            //每进两个数位，回文数乘以10
                number *= 10;
            }
            w++;                            //数位加一
            if(count + number > n)        //回文数大于查找的回数,跳出
                break;
                
            count += number;                //回文数加上当前数位上的回文数
        }
        
        n -= count;                        //在当前数位上的位置。如w=5,index=50,则万位上的第50个回文数是我们所求
        
        for(int i = 0; i < (w-1) / 2; i++) {    //求回文数的左半边的基数，如回文数在万位上，则为100
            h *= 10;
        }
        
        half = h + n;                        //回文数的左半边，如100 + 50 = 150
        
        res = half;
        
        if(w%2 != 0)                            //如果为奇数，则中间那个数不必算入右半边了！
            half /=10;
            
        while(half != 0) {                        //拼接回文数
            res = res *10 + half % 10;
            half /= 10;
        }
    cout<<res<<"\n";
    return 0;
}