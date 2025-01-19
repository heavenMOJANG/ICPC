#include <windows.h>
#include <iostream>

using namespace std;

HANDLE hThread1; // 生产者线程句柄
HANDLE hThread2; // 消费者线程句柄
HANDLE hFull;    // full信号量句柄
HANDLE hEmpty;   // empty信号量句柄

const int PRODUCE_CONSUME_COUNT = 2; // 每次生产或消费的次数

DWORD WINAPI producer(LPVOID lpParam)
{
    for (int i = 0; i < 10; i += PRODUCE_CONSUME_COUNT)
    {
        // 连续生产PRODUCE_CONSUME_COUNT次
        for (int j = 0; j < PRODUCE_CONSUME_COUNT; ++j)
        {
            WaitForSingleObject(hEmpty, INFINITE); // 等待empty信号量
            cout << "生产者线程在生产！" << endl;
            Sleep(1000); // 模拟生产时间
            ReleaseSemaphore(hFull, 1, NULL);    // 增加full信号量
        }
    }
    return 0;
}

DWORD WINAPI consumer(LPVOID lpParam)
{
    for (int i = 0; i < 10; i += PRODUCE_CONSUME_COUNT)
    {
        // 连续消费PRODUCE_CONSUME_COUNT次
        for (int j = 0; j < PRODUCE_CONSUME_COUNT; ++j)
        {
            WaitForSingleObject(hFull, INFINITE); // 等待full信号量
            cout << "消费者线程在消费！" << endl;
            Sleep(500); // 模拟消费时间
            ReleaseSemaphore(hEmpty, 1, NULL);    // 增加empty信号量
        }
    }
    return 0;
}

int main()
{
    hFull = CreateSemaphore(NULL, 2, 0, NULL); // 创建full信号量, 最大值2, 初值0
    hEmpty = CreateSemaphore(NULL, 2, 2, NULL); // 创建empty信号量, 最大值2, 初值2

    hThread1 = CreateThread(NULL, 0, producer, NULL, 0, NULL); // 创建生产者线程
    hThread2 = CreateThread(NULL, 0, consumer, NULL, 0, NULL); // 创建消费者线程

    WaitForSingleObject(hThread1, INFINITE); // 等待生产者线程结束
    WaitForSingleObject(hThread2, INFINITE); // 等待消费者线程结束

    cout << "主函数运行结束！" << endl;

    // 关闭句柄
    CloseHandle(hFull);
    CloseHandle(hEmpty);
    CloseHandle(hThread1);
    CloseHandle(hThread2);

    return 0;
}