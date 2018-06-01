/***********单词计数P376****************/

#include<iostream>    
#include<string>    
#include<fstream>  
#include<vector>   
#include<map>    
using namespace std;  
  
int main(int argc, char**argv)    
{   
    //map的定义  
    map<string,size_t> word_count;  
    fstream in("1.txt");//定义一个输入流  
    string word;  
  
    while (in>>word)  
    {  
        ++word_count[word];  
    }  
  
    //map同样支持迭代器操作  
    map<string ,size_t>::iterator mapi;  
    for (mapi = word_count.begin(); mapi != word_count.end(); ++mapi)//C++ 11支持:const auto &s : word_count  
    {  
        //两个成员分别代表关键字和对应值  
        cout<<mapi->first<<" ";  
        cout<<mapi->second<<" "<<endl;  
    }  
  
    return 0;    
}   


/***********建立mapP378****************/
#include<iostream>    
#include<string>    
#include<fstream>  
#include<vector>   
#include<map>    
#include<cctype>//ctype无法打开，包含tolower()函数和ispunct函数  
#include<algorithm>  
using namespace std;  
  
int main(int argc, char**argv)    
{   
    //map的定义  
    map<string,vector<string>> family;  
      
    string first_name,child_name;  
  
    //在while中使用lambda语句，可以传入多条语句参数，将我们想要传入的的输出参数也放在其中，注意后面的一对括号  
    while ( [&]()->bool {cout<<"请输入家庭的姓:"; return cin>>first_name && (first_name != "end");}() )  
    {  
            cout<<"请输入孩子的名字：";  
            while (cin>>child_name && (child_name != "end"))  
            {  
                family[first_name].push_back(child_name);  
            }     
    }  
  
    //map同样支持迭代器操作  
    map<string ,vector<string>>::iterator mapi;  
    for (mapi = family.begin(); mapi != family.end(); ++mapi)//C++ 11支持:const auto &s : word_count  
    {  
        //两个成员分别代表关键字和对应值  
        cout<<mapi->first<<" :";  
        vector<string>::iterator it1 = mapi->second.begin();  
        for (it1; it1 != mapi->second.end(); ++it1)  
        {  
            cout<<*it1<<" ";  
        }  
          
    }  
  
    return 0;    
}    

/***********vector2D向量实例****************/

/** 
在x-y平面上给定四个顶点ABCD,确定它是否是一个矩形 
*/  
#include<iostream>  
class vector2D  
{  
public:  
    vector2D(){}  
    vector2D(float a,float b)  
    { x=a; y=b; }///内联(1)  
    vector2D difference(vector2D& a);  
    float inner(vector2D& a);  
    bool isPerpendicular(vector2D& a);  
    bool nonzero()///内联(2)自动内联  
    { return (x!=0.0||y!=0.0); }  
    void display();  
private:  
    float x,y;  
};  
float vector2D::inner(vector2D&a)  
{ return(x*a.x + y*a.y); }  
void vector2D::display()  
{ std::cout<<"("<<x<<","<<y<<")"; }  
vector2D vector2D::difference(vector2D& v){  
    vector2D tmp;  
    tmp.x = x-v.x;  
    tmp.y = y-v.y;  
    return tmp;  
}  
inline float ABS(float x) { return (x>0?x:-x); }  
bool vector2D::isPerpendicular(vector2D& v){  
    return (nonzero()&&v.nonzero()&&ABS(inner(v))<0.00000001);  
}  
vector2D getVec(int i){  
    float x,y;  
    std::cin>>x>>y;  
    return vector2D(x,y);  
}  
int main()  
{  
    vector2D p[4];  
    for(int i=0;i<4;i++)  
        p[i]=getVec(i);  
    vector2D u=p[0].difference(p[3]);  
    vector2D v;  
    for(int i=0;i<3;i++){  
        v=p[i+1].difference(p[i]);  
        if(!u.isPerpendicular(v))  
        {  
            std::cout<<"Not a rectangle.\n";  
            return -1;  
        }  
        u=v;  
    }  
    std::cout<<"Yes\n";  
    return 0;  
}  
