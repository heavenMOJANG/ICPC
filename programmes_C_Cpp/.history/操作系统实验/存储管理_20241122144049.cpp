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

void page_interrupt(int lnumber) // 缺页中断处理函数
{
    // 查找逻辑页号是否在页表中
    for (int i = 0; i < page_length; i++)
    {
        if (page[i].lnumber == lnumber)
        {
            // 找到逻辑页号对应的页条目
            if (page[i].flag == 1)
            {
                std::cout << "Page already in memory." << std::endl;
                return;
            }
            // 从主存中找到一个空闲的物理块，若都占用则使用 FIFO 替换
            int replaceIndex = -1;
            for (int j = 0; j < m; j++)
            {
                if (p[j] == -1)
                {
                    replaceIndex = j;
                    break;
                }
            }
            if (replaceIndex == -1)
            {
                // 主存已满，使用 FIFO 策略替换
                replaceIndex = head; // 替换头指针指向的
                head = (head + 1) % m; // 移动到下一个
            }

            // 更新页表
            page[replaceIndex].lnumber = lnumber;
            page[replaceIndex].pnumber = replaceIndex; // 假装映射为块号
            page[replaceIndex].flag = 1; // 设为在内存中
            page[replaceIndex].write = 0; // 初始为未修改
            page[replaceIndex].dnumber = -1; // 设为 -1 表示未在外存中
            p[replaceIndex] = lnumber; // 更新 p 数组

            std::cout << "Page " << lnumber << " loaded into memory at frame " << replaceIndex << std::endl;
            return;
        }
    }
    std::cout << "Page not found in page table." << std::endl;
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

void main() // 主函数
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
