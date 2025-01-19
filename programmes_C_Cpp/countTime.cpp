#include<time.h>
#include<iostream>
int main(){
    clock_t start,finish;
    //clock_t为CPU时钟计时单元数
    start=clock();//clock()函数返回此时CPU时钟计时单元数
    /*
    程序体
    */
    finish=clock();//clock()函数返回此时CPU时钟计时单元数
    std::cout<<"\n"<<double(finish-start)/CLOCKS_PER_SEC<<"\n";
    //finish与start的差值即为程序运行花费的CPU时钟单元数量，再除每秒CPU有多少个时钟单元，即为程序耗时
    return 0;
}