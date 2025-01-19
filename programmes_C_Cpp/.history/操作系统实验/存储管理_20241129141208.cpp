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

        cout << "页 " << replace_page << " 被修改过，需要写回外存块 " << page[replace_page].dnumber << endl;

    }

    // 替换页信息

    page[replace_page].flag = 0; // 被替换的页设置为不在内存

    page[replace_page].write = 0; // 修改位复位

    // 加载新页

    cout << "将页 " << lnumber << " 从外存块 " << page[lnumber].dnumber << " 读入内存块 " << page[replace_page].pnumber << endl;

    page[lnumber].flag = 1; // 新页置为在内存

    page[lnumber].pnumber = page[replace_page].pnumber; // 更新内存块号

    page[lnumber].write = 0; // 初始化修改位为0

    // 更新主存队列

    p[head] = lnumber;

    head = (head + 1) % m; // FIFO队列指针后移

}

void command(unsigned laddress, int write) // 命令处理函数
{
    int lnumber = laddress % page_length; // 逻辑页号
    bool page_found = false;

    // 检查页表以确定页是否已在内存中
    for (int i = 0; i < m; i++)
    {
        if (p[i] == lnumber)
        {
            page_found = true; // 页已在内存中
            if (write == 1)
            {
                // 设置修改位
                page[i].write = 1;
                std::cout << "Writing to page " << lnumber << std::endl;
            }
            else
            {
                std::cout << "Reading from page " << lnumber << std::endl;
            }
            break;
        }
    }

    // 如果页不在内存中, 则处理缺页中断
    if (!page_found)
    {
        std::cout << "Page " << lnumber << " not found in memory. Triggering page interrupt." << std::endl;
        page_interrupt(lnumber);
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
