#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define FILENAME_LEN 3	//文件名长度
#define SHELL_LEN 5		//命令动词长度
#define ShellCount 6	//命令种类
char[] *path = "disk.txt";	//保存磁盘文件
char *shellstr[ShellCount]={"dir","cre","del","dis","fat","exit"};
//文件目录结构：文件名3B，文件属性1B，长度2B，起始簇号2B
#define HPC 4			//每柱面磁道数
#define SPT 16			//每磁道的扇区数
#define Cylinders 64	//柱面数
#define SectorSize 128	//扇区大小
#define DirSize 16		//根目录大小(扇区),占16扇区
int Maxfilecount=DirSize*SectorSize/8;  //存放的最大文件数
//FAT表占用的扇区数和开始扇区号
int FatSize=((HPC*SPT*Cylinders*2)%SectorSize==0)?(HPC*SPT*Cylinders*2)/SectorSize:(HPC*SPT*Cylinders*2)/SectorSize+1;
int FatBegin=DirSize;
//位示图占用的扇区数和开始扇区号
int BitMapSize=((HPC*SPT*Cylinders/8)%SectorSize==0)?(HPC*SPT*Cylinders/8)/SectorSize:(HPC*SPT*Cylinders/8)/SectorSize+1;
int BitMapBegin=DirSize+FatSize;
int DataBeginSector=DirSize+FatSize+BitMapSize; //存放数据起始扇区号

unsigned short Memory=0;							//空闲盘块数
unsigned char DISK[Cylinders][HPC][SPT][SectorSize];//磁盘大小
unsigned short FAT[HPC*SPT*Cylinders];				//内存FAT表
unsigned short bitmap[HPC*SPT*Cylinders/16];		//内存位示图
unsigned char Dir[DirSize*SectorSize];				//内存目录
unsigned char filecon[1024];						//文件内容

//功能：错误命令处理
//id：错误代码
void errorp(int id){	//错误命令处理函数
 	switch(id){
		case 0 : puts("文件不存在！");break;
		case 1 : puts("文件/目录已存在！");break;
		case 2 : puts("语法不正确！");break;
		case 3 : puts("不存在命令！");break;
 		case 4 : puts("存储空间不够！");break;
		case 5 : puts("文件名太长！");break;
		case 6 : puts("无空闲目录！");break;
		case 7 : puts("操作命令太长！");break;
		default: puts("无效命令！");
 	}
}

//功能：如果位示图第n位为1则返回真,为0返回假
bool getbitmap(int n){  
	return bool(bitmap[n/16] & (1<<(n%16))); 
}
 
//功能：初始化位示图和FAT
void initbitmap(){
	int i;
	int k1=HPC*SPT*Cylinders-DataBeginSector;
	int	k2=(k1%16==0)?k1/16:k1/16+1;
	for(i=0;i<k2;i++)
		bitmap[i]=(rand()*3)%65536;
	for(i=0;i<k1;i++)
		if(getbitmap(i)==0){
			Memory ++;
			FAT[i]=0;
		}
		else
			FAT[i]=-1;
}

//功能：显示位示图
void showbitmap(){
	int i;
	//int k=HPC*SPT*Cylinders-DataBeginSector;//显示全部位图
	int k=128;//显示部分位图
	std::cout << "位示图:" <<std::endl;
	for(i=0;i<k;i++){
		printf("%d ",bool(bitmap[i/16] & (1<<(i%16))));
		if(i%16==15) std::cout<<std::endl;
	}
	std::cout<<std::endl;
}

//功能：显示FAT
void showfat(){
	int i;
	//int k=HPC*SPT*Cylinders;//显示全部FAT
	int k=128;//显示部分FAT
	std::cout << "FAT表:" <<std::endl;
	for(i=0;i<k;i++){
		printf("%-8d",FAT[i]);
		if(i%8==7) std::cout<<std::endl;
	}
	std::cout<<std::endl;
}
		
//功能：将位示图中的第n位设成k状态
void setbitmap(int n,int k){
	if(k)
		bitmap[n/16]=bitmap[n/16] | (1<<(n%16));
	else
		bitmap[n/16]=bitmap[n/16] & ~(1<<(n%16));
}

//功能：从内促Dir[]开始查找str目录结点并返回str节点指针,如没查到则返回NULL。
//str：文件名
unsigned char *find(char *str){
	unsigned char *p=Dir;
	bool mark;
	unsigned short j;
	if(str[0]=='\0') return NULL;

	for(int i=0;i<Maxfilecount;i++){
		if(*p!='\0'){  //目录不空对比
 			mark=true;
			for(j=0;j<strlen(str);j++){
				if(*(str+j)!=*(p+j)){
					mark=false;break;
				}
			}
			if((mark==true && j==FILENAME_LEN)||(mark==true && j<FILENAME_LEN && *(p+j)=='\0'))
				return p;
		}
		p+=8;
  	}
  	return NULL;
}

//功能：将p后的长度为SectorSize字符串写到ls扇区中
//如果字符串长度小于SectorSize,则写实际长度
void writedisk(unsigned char *p,int ls){
	int C,H,S;
	C=ls/(HPC*SPT);		//计算柱面号
	H=(ls/SPT) % HPC;	//计算磁头号
	S=ls % SPT;			//计算扇区号
	for(int i=0;i<SectorSize;i++){
		DISK[C][H][S][i]=*(p+i);
	}
}

//功能：将ls扇区中长度为size的字符串写到p中
void readdisk(unsigned char *p,int ls,int size){
	int C,H,S;
	C=ls/(HPC*SPT);		//计算柱面号
	H=(ls/SPT) % HPC;	//计算磁头号
	S=ls % SPT;			//计算扇区号
	for(int i=0;i<size;i++)
		*(p+i)=DISK[C][H][S][i];
}

//初始化程序
void init(){
	int i=0;
	FILE *fp1;
	unsigned char *tmp=&DISK[0][0][0][0];
	fp1=fopen(path,"rb");
	if(fp1==NULL)//第一次运行该程序
		initbitmap();
	else{
		while(!feof(fp1)){
			*(tmp+i)=fgetc(fp1);
			i++;
		}
		fclose(fp1);
		//将磁盘根目录读到Dir[]中,便于操作
		unsigned char *p=Dir;
		for(i=0;i<DirSize;i++){
			readdisk(p,i,SectorSize);
			p+=SectorSize;
		}
		//将FAT表读入内存FAT[]中
		unsigned short *p1=FAT;
		for(i=0;i<FatSize;i++){
			readdisk((unsigned char*)p1,i+FatBegin,SectorSize);
			p1+=SectorSize/2;
		}
		//将bitmap表读入内存bitmap[]中
		p1=bitmap;
		for(i=0;i<BitMapSize;i++){
			readdisk((unsigned char*)p1,i+BitMapBegin,SectorSize);
			p1+=SectorSize/2;
		}
		int k1=HPC*SPT*Cylinders-DataBeginSector;
		for(i=0;i<k1;i++)
			if(getbitmap(i)==0)
				Memory ++;
	}
}

//程序运行完后保存磁盘DISK到文件中
void save(){
	int i=0;
	FILE *fp1;
	//将内存Dir[]写到DISK中，然后用文件的方式保存
	unsigned char *p=Dir;
	for(i=0;i<DirSize;i++){
		writedisk(p,i);
		p+=SectorSize;
	}
	//将内存FAT[]表写入DISK中
	unsigned short *p1=FAT;
	for(i=0;i<FatSize;i++){
		writedisk((unsigned char*)p1,i+FatBegin);
		p1+=SectorSize/2;
	}
	//将内存bitmap[]写到DISK中
	p1=bitmap;
	for(i=0;i<BitMapSize;i++){
		writedisk((unsigned char*)p1,i+BitMapBegin);
		p1+=SectorSize/2;
	}

	//将DISK保存在磁盘文件中
	unsigned char *tmp=&DISK[0][0][0][0];
	fp1=fopen(path,"wb");
	if(fp1==NULL)
		std::cout<<"无法写入文件！";
	else{
		for(i=0;i<Cylinders*HPC*SPT*SectorSize;i++)
			fputc(*(tmp+i),fp1);
		fclose(fp1);
	}
}

//功能：显示str目录内容
//str：可以采用绝对或相对路径
bool direxc(char *str){
	int i,j;
	char *dirstr[2]={"<file>","<dir>"};
	//showbitmap();
	unsigned char *p=Dir;
	char filename[4];
	unsigned short length,start;
	std::cout<<"文件名  类型    长度   起始块号"<<std::endl;
	for(i=0;i<Maxfilecount;i++){
		if(*p!='\0'){  //目录不空显示
 			for(j=0;j<3;j++)
				filename[j]=*(p+j);
			filename[j]='\0';
			length=*(p+5);
			length=(length<<8)+*(p+4);
			start=*(p+7);
			start=(start<<8)+*(p+6);
			printf("%6s %6s %5u%5u\n",filename,dirstr[*(p+3)],length,start);
		}
		p+=8;
  	}
	printf("磁盘剩余空间为：%d字节 \n",Memory*SectorSize);
 	return true;
}

//自动生成文件内容,并返回文件长度
int createcon(unsigned char * con){
	int i;
	while(1){
		printf("请输入创建文件长度(1025B以下)：");
		scanf("%d",&i);
		if(i>0 && i<1025) break;
		fflush(stdin);
	}
	for (int k=0;k<i;k++,con++) *con=32+rand()%95;
	*con='\0';
	return i;
}

//查找第一个空白目录
unsigned char * findfirstemptyDir(){
	unsigned char *p=Dir;
	for(int i=0;i<Maxfilecount;i++)
		if(*p=='\0')
			return p;
		else
			p+=8;
	return NULL;
}

//功能：将文件名写到目录中，最多3个字符，
//如果文件名少于3个字符，则后面加'\0'
//p:目录开始指针，file：文件名指针
void writefilename(unsigned char *p,char *file){
	unsigned short i,k;
	k=strlen(file);
	for(i=0;i<k;i++){
		*p=(unsigned char) *file;
		p++;file++;
	}
	if(k<3)
		*p='\0';
}

//功能：创建str文件
//str：可以采用绝对或相对路径
bool creexc(char *str)
{
	unsigned short i,j,k;
	short l;
	int length;
	unsigned char *tmp=find(str);
	unsigned char *p=filecon;
	if(tmp!=NULL)	//文件已经存在
	{
		errorp(1);
		return false;
	}
	else
	{
		//自行补齐创建文件的代码。
	}
	return true;
 }

//功能：删除文件或目录
//str：文件名
void delexc(char *str)
{
	unsigned short k,l,front;
	unsigned char *tp=find(str);
	if (tp!=NULL){
		//自行补齐删除文件的代码。
	}
	else
		errorp(0);
}

//功能：显示文件内容
//str：文件名
void disexc(char *str){
	unsigned short k,l,size;
	unsigned char *p=filecon;
	unsigned char *tp=find(str);
	if (tp!=NULL){
		//自行补齐读文件内容到filecon中的代码
		*p='\0';
		std::cout<<filecon<<std::endl;
	}
	else
		errorp(0);
}

//功能：显示部分FAT和位示图内容
//str：文件名
void fatexc(){
	showbitmap();
	showfat();
}

void menu(){	//显示命令菜单
	printf("有下列命令可供使用：\n");
	printf("[1] dir    显示目录内容\n");
	printf("[2] cre    新建文件\n");
	printf("[3] del    删除文件\n");
	printf("[4] dis    显示文件内容\n");
	printf("[5] fat    显示部分FAT及位示图\n");	
	printf("[6] exit   退出系统\n");
}	

//功能：解释命令。根据不同的输入转到不同的函数执行
//str：键盘输入串
bool shell(char *str){
	int re=-1,i=0,cmdp=0,filep=0;
	char *p=str;
	char cmdstr[SHELL_LEN]="";
	char filestr[10]="";
	
	//以下程序完成命令和参数的分解分别放到cmdstr，filestr数组中
	while(*p==' ')					//删除字符串前面空格
		p++;
	int firstspace=0;				//第一个空格
	while(1){
		if(*p=='\0')
			break;
		if(*p==' '){
			firstspace=1;
			p++;
		}
		else{
			if(firstspace==0){
				cmdstr[cmdp++]=*p++;
				if(cmdp>=5){
					errorp(7);
					return false;
				}
			}
			else{
				filestr[filep++]=*p++;
				if(filep>=4){
					errorp(5);
					return false;
				}
			}
		}
	}
	filestr[filep]='\0';
	cmdstr[cmdp]='\0';

	for(i=0;i<ShellCount;i++)
		if(strcmp(cmdstr,shellstr[i])==0){
			re=i;break;
		}
	switch(re){			//根据解释的命令执行对应的操作
		case 0: direxc(filestr);break;
		case 1: if(strlen(filestr)==0) {errorp(2);return false;}creexc(filestr);break;
		case 2: if(strlen(filestr)==0) {errorp(2);return false;}delexc(filestr);break;
		case 3: if(strlen(filestr)==0) {errorp(2);return false;}disexc(filestr);break;
		case 4: fatexc();break;
		case 5: save();exit(0);break;
		default:errorp(8);break;
	}
	return true;
}

int main(){
	char inputs[256]="";
	srand((unsigned)time(0));						//每次产生不一样的随机数
	init();
	menu();
	while(1){
		printf("\n>");
		gets(inputs);
		shell(inputs);
		menu();
	}
    return 0;
}