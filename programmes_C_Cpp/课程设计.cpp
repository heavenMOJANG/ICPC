#include<bits/stdc++.h>
using namespace std;
struct News{
    string title;//新闻标题字段
    double auctionValue;//新闻拍卖值字段
    string category;//分类字段
    string sourceDepartment;//来源部门字段
    string time;//新闻发布时间字段
};
class NewsManager{
private:
    vector<News>newsList;
public:
    unordered_map<string,double>keywordValues={
        {"vital",20.0},{"Vital",21.0},
        {"important",15.0},{"Important",16.0},
        {"breaking",10.0},{"Breaking",11.0},
        {"exclusive",5.0},{"Exclusive",9.0}
    };
    double calculateAuctionValue(const News&news){
        double value=0.0;
        for(const auto &pair:keywordValues)
			if(news.title.find(pair.first)!=string::npos)
				value+=pair.second;
        return value;
    }
    bool addNews(const News&newNews){
        for(const auto&news:newsList)
            if(news.title==newNews.title) return false;
        News modifiedNew=newNews;//创建一个新的副本以避免改变原始数据
        modifiedNew.auctionValue=calculateAuctionValue(modifiedNew);//计算拍卖值并设置
        newsList.push_back(modifiedNew);//如果没有找到相同标题的新闻，则添加新闻
        return true;
    }
    vector<News>getAll(){return newsList;}
    //新闻基于发布时间排序
    vector<News> sortByTime(){
        vector<News> result = newsList;
        sort(result.begin(),result.end(),[](const News& a, const News& b){
            return a.time>b.time;
        });
        return result;
    }
    //新闻基于拍卖值排序
    vector<News> sortByAuctionValue(){
        vector<News>result=newsList;
        sort(result.begin(),result.end(),[](const News&a, const News&b){
            return a.auctionValue>b.auctionValue;
        });
        return result;
    }
    //新闻基于标题长度排序
    vector<News> sortByKeywords(){
        vector<News> result=newsList;
        sort(result.begin(),result.end(),[this](const News&a, const News&b){
            return a.title.size()>b.title.size();
        });
        return result;
    }
    vector<News> searchByTitle(const string&keyword){
        vector<News> result;
        for(auto &n:newsList)
            if(n.title.find(keyword)!=string::npos)
				result.push_back(n);
        return result;
    }
    void deleteByTitle(const string&title){
        bool deleted=false;
        for(auto it=newsList.begin();it!=newsList.end();){
            if(it->title==title){
                it=newsList.erase(it);
                deleted=true;
                cout<<"删除成功！\n\n";
            }
            else
                ++it;
        }
        if(deleted==false)
            cout<<"未找到新闻，删除失败。\n\n";
    }
   	//按类别获取新闻的方法
   	vector<News> getByCategory(const string&category){
       vector<News>result;
       for(auto& n:newsList)
           	if(n.category==category)
            	result.push_back(n);
       return result;
   	}
   	//按来源部门获取新闻的方法
   	vector<News> getBySourceDepartment(const string&department){
       vector<News> result;
       for(auto& n:newsList)
           	if(n.sourceDepartment==department)
               	result.push_back(n);
       return result;
   	}
    void modifyByTitle(const string&title, const News&newNews){
        bool found=false;
        for(auto& news:newsList)
            if(news.title==title){
                News modifiedNew = newNews;//创建一个新的副本以避免改变原始数据
                modifiedNew.auctionValue = calculateAuctionValue(modifiedNew);//计算拍卖值并设置
                news=modifiedNew;//使用新的新闻替换旧的
                found=true;
                break;
            }
        if(found==false)
            cout<<"未找到新闻，修改失败。\n\n";
    }
};
class Display{
private:
    NewsManager&manager;
public:
    Display(NewsManager&m):manager(m){}
    void showSortedNews(int threshold){
        auto all_news=manager.getAll();
        switch(threshold){
            case 0:
                all_news=manager.sortByTime();
                break;
            case 1:
                all_news=manager.sortByAuctionValue();
                break;
            case 2:
                all_news=manager.sortByKeywords();
                break;
        }
        for(auto& n:all_news){
            cout<<n.title<<"\n";
			//输出其他信息...
        }
    }  
    void showSearchResults(const string&keyword){
        bool found=false;
        auto results=manager.searchByTitle(keyword);
        for(auto& n:results){
            found=true;
            cout<<n.title<<"\n";
			//输出其他信息...
        }
        if(found==false)
            cout<<"未找到包含关键词的内容。\n\n";   
    } 
    // 显示特定类别的新闻的方法
    void showCategoryResults(const string&category){
        bool found=false;
    	auto results=manager.getByCategory(category);
        for(auto& n:results){
            found=true;
            cout<<n.title<<"\n";//输出其他信息...
        }
        if(found==false)
            cout<<"未找到属于该分类的内容。\n";
	} 
	// 显示来自特定部门的新闻的方法
    void showSourceDepartmentResults(const string&department){
        bool found=false;
        auto results=manager.getBySourceDepartment(department);
        for(auto& n:results){
            found=true;
            cout<<n.title<<"\n";//输出其他信息...
        }
        if(found==false)
            cout<<"未找到来源于该部门的内容。\n\n";
    }
};
int main(int argc,const char**argv){
    bool running=true;
    NewsManager manager;
    Display display(manager);
    while(running==true){
        //system("cls");
        int command;
        cout<<"欢迎使用新闻发布推送系统\n\n"
            <<"请选择操作:\n"
            <<"0->退出\n"
            <<"1->录入新闻\n"
            <<"2->浏览新闻\n"
            <<"3->删除新闻\n"
            <<"4->修改新闻\n"
            <<"5->搜索新闻\n"
            <<"6->按分类显示新闻\n"
            <<"7->按来源部门显示新闻\n\n";
        cin>>command;
        char ch;cin.get(ch);
        switch(command){
            case 0:{
                running=false;
                break;
            }
            case 1:{
                string strTitle,strCategory,strSource,strTime;
                cout<<"请输入新闻标题、分类、来源部门和发布时间（发布日期格式为yyyymmdd）：\n\n";
                getline(cin,strTitle);
                getline(cin,strCategory);
                getline(cin,strSource);
                getline(cin,strTime);
                if(manager.addNews({strTitle,0.0,strCategory,strSource})==true)
                    cout<<"新闻成功添加。\n\n";
                else
                    cout<<"新闻已经存在，添加失败。\n\n";
                break;
            }
            case 2:{
                int sortOption;
                cout<<"请选择新闻排序方式:\n\n"
                    <<"0->基于发布时间排序\n\n"
                    <<"1->基于拍卖值排序\n\n"
                    <<"2->基于标题长度排序\n\n";
                cin>>sortOption;cin.get(ch);
                Display display(manager);
                display.showSortedNews(sortOption);
                break;
            }
            case 3:{
                string strTitle;
                cout<<"请输入你想删除的新闻标题：\n\n";
                getline(cin,strTitle);
                manager.deleteByTitle(strTitle);
                break;
            }
            case 4:{
                string strOrigin,strTitle,strCategory,strSource,strTime;
                cout<<"请输入你要修改的新闻标题：\n\n";
                getline(cin,strOrigin);
                cout<<"请输入你要填入的新闻，包括标题、分类、来源部门和发布时间（发布日期格式为yyyymmdd）：\n\n";
                getline(cin,strTitle);
                getline(cin,strCategory);
                getline(cin,strSource);
                getline(cin,strTime);
                manager.modifyByTitle(strOrigin,{strTitle,0.0,strCategory,strTime});
                break;
            }
            case 5:{
                string strKeyword;
                cout<<"请输入你要搜索的关键词：\n\n";
                getline(cin,strKeyword);
                display.showSearchResults(strKeyword);
                break;
            }
            case 6:{
                string strCategory;
                cout<<"请输入你要搜索的分类：\n\n";
                getline(cin,strCategory);
                display.showCategoryResults(strCategory);
                break;
            }
            case 7:{
                string strSource;
                cout<<"请输入你要搜索的来源部门：\n\n";
                getline(cin,strSource);
                display.showSourceDepartmentResults(strSource);
                break;
            }
            default:
                cout<<"没有对应操作，请重新输入。\n\n";
        }
    }
	return 0;
}