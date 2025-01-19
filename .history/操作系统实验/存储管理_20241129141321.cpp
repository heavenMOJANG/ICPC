#include <iostream>
#define m 3              // 实际为该作业分配的主存块块数
#define page_length 5    // 页表实际长度

struct PageTableEntry // 页表
{
    int lnumber;  // 页号
    int pnumber;  // 该页所在主存块的块号
    int flag;     // 状态位, "1" 表示该页在主存, "0" 表示该页不在主存
    int write;    // 修改位, "1" 表示该页内容被修改过, "0" 表示该页内容未修改过
    int dnumber;  // 该页存在外存位置, 即磁盘块号
} page[page_length];

int p[m]; // 存放在主存中的页的页号
int head; // 主存中页号队列 p 的首指针

void page_interrupt(int lnumber)

{

    // 判断要替换的页

    int replace_page = p[head];

    // 如果被替换的页内容已修改，则需要写回外存

    if (page[replace_page].write == 1)

    {

        std::cout << "页 " << replace_page << " 被修改过，需要写回外存块 " << page[replace_page].dnumber << std::endl;

    }

    // 替换页信息

    page[replace_page].flag = 0; // 被替换的页设置为不在内存

    page[replace_page].write = 0; // 修改位复位

    // 加载新页

    std::cout << "将页 " << lnumber << " 从外存块 " << page[lnumber].dnumber << " 读入内存块 " << page[replace_page].pnumber << std::endl;

    page[lnumber].flag = 1; // 新页置为在内存

    page[lnumber].pnumber = page[replace_page].pnumber; // 更新内存块号

    page[lnumber].write = 0; // 初始化修改位为0

    // 更新主存队列

    p[head] = lnumber;

    head = (head + 1) % m; // FIFO队列指针后移

}

void command(unsigned laddress, int write)

{

    // 计算页号和页内偏移量

    int page_number = laddress / 1024; // 每页大小为1024B

    int offset = laddress % 1024;

    // 判断逻辑地址是否合法

    if (page_number >= page_length)

    {

        std::cout << "错误：逻辑地址超出范围！" << endl;

        return;

    }

    // 判断页是否在内存中

    if (page[page_number].flag == 0)

    {

        std::cout << "缺页中断：页 " << page_number << " 不在内存。" << endl;

        page_interrupt(page_number); // 调用缺页中断处理

    }

    // 页在内存，处理命令

    std::cout << "访问页 " << page_number << "，内存块号 " << page[page_number].pnumber

         << "，物理地址：" << (page[page_number].pnumber * 1024 + offset) << std::endl;

    if (write == 1)

    {

        page[page_number].write = 1; // 写操作，修改位置为1

        std::cout << "写操作：修改页 " << page_number << " 的内容。" << std::endl;

    }

    else

    {

        std::cout << "读操作：读取页 " << page_number << " 的内容。" << std::endl;

    }

}

int main() // 主函数
{
    int write;
    unsigned laddress;

    // 初始化页表，分配3个物理块。数据可改
    for (int i = 0; i < page_length; i++)
    {
        page[i].lnumber = i; // 初始化页号
        page[i].flag = 0;    // 初始状态为不在内存
        page[i].write = 0;   // 初始未修改
        page[i].dnumber = i * 10; // 假设外存块号
    }
    
    head = 0; // 开始指向 p[0]
    for (int i = 0; i < m; i++) p[i] = -1; // 初始化主存页号为 -1 以表示空闲

    // 玩家已经放置的初始页
    p[0] = 0; p[1] = 1; p[2] = 2; // 3个物理块中所放的页为0页、1页、2页

    while (true)
    {
        std::cout << "输入指令性质(1-写指令,0-读指令,其他--结束程序运行)和逻辑地址:";
        std::cin >> write;
        std::cin >> laddress;
        if (write == 0 || write == 1)
            command(laddress, write);
        else
            break;
    }
    return 0;
}
