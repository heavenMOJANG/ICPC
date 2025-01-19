#include<iostream>
#define m 3				//实际为该作业分配的主存块块数
#define page_length 5	//页表实际长度
struct  //页表
{
	int lnumber;	//页号
	int pnumber;	//该页所在主存块的块号
	int flag;		//状态位,"1"表示该页在主存,"0"表示该页不在主存
	int write;		//修改位,"1"表示该页内容被修改过,"0"表示该页内容末修改过
	int dnumber;	//该页存在外存位置,即磁盘块号
}page[page_length];
int p[m];			//存放在主存中页的页号
int head;			//主存中页号队列p首指针

void page_interrupt(int lnumber)  //缺页中断处理函数
{
    //自行设计
    std::cout<<lnumber<<"页不在主存,发生缺页中断";
    if(page[p[head]].write==1){
        page[p[head]].write=0;
        std::cout<<"将页"<<p[head]<<"写回磁盘"<<page[p[head]].dnumber<<"中";
    }
    std::cout<<std::endl;
    page[p[head]].flag=0;
    int index=0;
    for(index=0;index<page_length;index++){
        if(page[index].lnumber==lnumber){
            break;
        }
    }
    page[index].pnumber=page[p[head]].pnumber;
    page[p[head]].pnumber=0;
    std::cout<<"淘汰主存"<<page[index].pnumber<<"块中的页"<<p[head]<<",从磁盘"<<page[index].dnumber<<"中调入页"<<lnumber<<std::endl;
    p[head]=lnumber;
    head=(head+1)%m;
}

void command(unsigned laddress,int write)  //命令处理函数结束
{
    //自行设计
    int blockSize=1<<10; 
    int lNumber=laddress/blockSize;
    int w=laddress%blockSize;
    int pA;
    if(lNumber>=page_length){
            std::cout<<"超出页长，不存在该页";
    }
    else {
        for(int i=0;i<page_length;i++){
            if(page[i].lnumber==lNumber){
                if(page[i].flag==1){
                    pA=page[i].pnumber*blockSize+w;
                    if(write==1){
                        page[i].write=1;
                    }
                }else{
                    page_interrupt(lNumber);
                    int index;
                    for(index=0;index<page_length;index++){
                        if(page[index].lnumber==lNumber)break;
                    } 
                    pA=page[index].pnumber*blockSize+w; 
                    break;
                }
        
            }
    
    }

        std::cout<<"逻辑地址:"<<laddress<<std::endl;
        std::cout<<"对应的物理地址:"<<pA<<std::endl; 
    }
}

void main()  //主函数
{
	int write;
	unsigned laddress;
	//初始化页表，分配3个物理块。数据可改
	page[0].lnumber=0;page[0].pnumber=4;page[0].flag=1;page[0].write=0;page[0].dnumber=4;
	page[1].lnumber=1;page[1].pnumber=3;page[1].flag=1;page[1].write=0;page[1].dnumber=20;
	page[2].lnumber=2;page[2].pnumber=7;page[2].flag=1;page[2].write=0;page[2].dnumber=18;
	page[3].lnumber=3;page[3].pnumber=0;page[3].flag=0;page[3].write=0;page[3].dnumber=6;
	page[4].lnumber=4;page[4].pnumber=0;page[4].flag=0;page[4].write=0;page[4].dnumber=9;
	head=0;			//开始指向p[0]
	p[0]=0;p[1]=1;p[2]=2;  //3个物理块中所放的页为0页、1页、2页
	while(1)
	{
		std::cout<<"输入指令性质(1-写指令,0-读指令,其他--结束程序运行)和逻辑地址:";
		std::cin>>write;
		std::cin>>laddress;
		if(write==0||write==1)
			command(laddress,write);
		else
			break;
	}
}
