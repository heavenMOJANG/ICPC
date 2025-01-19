/*独占设备的分配和回收模拟*/
#include"stdio.h"
#include"string.h"        
#define n 4		//4类设备
#define m 10	//10个设备
struct 
{
	char type[10];	//设备类名
	int count ;		//拥有设备台数
	int remain;		//现存的可用设备台数
	int address;	//该类设备在设备表中的起始地址
}equiptype[n];		//设备类表定义,假定系统有n个设备类型

struct
{
	int number;		//设备绝对号
	int status;		//设备好坏状态 1-好、0-坏
	int remain;		//设备是否已分配 1-已分配、0-空闲
	char jobname[4];//占有设备的作业名
	int lnumber;	//设备相对号
}equipment[m];		//设备表定义,假定系统有m个设备

void allocate(char J[],char type[],int mm)//设备分配函数
{
	int i, found = 0;

    int typeIndex = -1;

    // 查找设备类型

    for (i = 0; i < n; i++) {

        if (strcmp(equiptype[i].type, type) == 0) {

            typeIndex = i;

            break;

        }

    }

    if (typeIndex == -1) {

        printf("设备类型不存在！分配失败。\n");

        return;

    }

    // 查找是否有空闲设备

    for (i = equiptype[typeIndex].address; i < equiptype[typeIndex].address + equiptype[typeIndex].count; i++) {

        if (equipment[i].remain == 0) {

            // 找到空闲设备，分配设备

            equipment[i].remain = 1;

            strcpy(equipment[i].jobname, J);

            equipment[i].lnumber = mm;

            equiptype[typeIndex].remain--; // 可用设备数减少

            printf("设备分配成功！设备绝对号: %d, 设备相对号: %d\n", equipment[i].number, equipment[i].lnumber);

            found = 1;

            break;

        }

    }

    if (!found) {

        printf("没有空闲设备可分配！分配失败。\n");

    }
}

void reclaim(char J[],char type[])//设备回收函数
{
    int i, found = 0;

    int typeIndex = -1;

    // 查找设备类型

    for (i = 0; i < n; i++) {

        if (strcmp(equiptype[i].type, type) == 0) {

            typeIndex = i;

            break;

        }

    }

    if (typeIndex == -1) {

        printf("设备类型不存在！回收失败。\n");

        return;

    }

    // 查找设备是否被指定作业占用

    for (i = equiptype[typeIndex].address; i < equiptype[typeIndex].address + equiptype[typeIndex].count; i++) {

        if (equipment[i].remain == 1 && strcmp(equipment[i].jobname, J) == 0) {

            // 找到该设备，进行回收

            equipment[i].remain = 0;

            memset(equipment[i].jobname, 0, sizeof(equipment[i].jobname));

            equipment[i].lnumber = 0;

            equiptype[typeIndex].remain++; // 可用设备数增加

            printf("设备回收成功！设备绝对号: %d\n", equipment[i].number);

            found = 1;

            break;

        }

    }

    if (!found) {

        printf("作业没有占用该设备或设备不存在！回收失败。\n");

    }
}

int main()
{
	char J[4];
	int i,mm,a;
	char type[10];
	//设备类表初始化
	strcpy(equiptype[0].type,"input");//输入机
	equiptype[0].count=2;
	equiptype[0].remain=2;
	equiptype[0].address=0;
	strcpy(equiptype[1].type,"printer");//打印机
	equiptype[1].count=3;
	equiptype[1].remain=3;
	equiptype[1].address=2;
	strcpy(equiptype[2].type,"disk");//磁盘机
	equiptype[2].count=4;
	equiptype[2].remain=4;
	equiptype[2].address=5;
	strcpy(equiptype[3].type,"tape");//磁带机*/
	equiptype[3].count=1;
	equiptype[3].remain=1;
	equiptype[3].address=9;
	//设备表初始化
	for(i=0;i<10;i++)
	{
		equipment[i].number=i;
		equipment[i].status=1;
		equipment[i].remain=0;
	}
	while(1)
	{
		printf("\n0－退出,1-分配,2－回收,3－显示");
		printf("\n选择功能项(0－3):");
		scanf("%d",&a);
		switch(a)
		{
		case 0://程序结束*/
			return 0;
		case 1://a=1分配设备
			printf("输入作业名、作业所需设备类和设备相对号");
			scanf("%s%s%d",J,type,&mm);
			allocate(J,type,mm);
			break;
		case 2://a=2回收设备
			printf("输入作业名和作业归还的设备类");
			scanf("%s%s",J,type);
			reclaim(J,type);
			break;
		case 3://a=3输出设备类表和设备表的内容
			printf("\n输出设备类表\n");
			printf(" 设备类型 设备总量 空闲好设备\n");
			for(i=0;i<n;i++)
				printf("%9s%6d%9d\n",equiptype[i].type,equiptype[i].count,equiptype[i].remain);
			printf("输出设备表:\n");
			printf("绝对号 好/坏 已/未分配 占用作业名 相对号\n");
			for(i=0;i<m;i++)
				printf("%3d%8d%9d%12s%8d\n",equipment[i].number,
				equipment[i].status,equipment[i].remain,equipment[i].jobname,
				equipment[i].lnumber);
		}
	}
    return 0;
}
