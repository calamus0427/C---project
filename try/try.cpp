/***************删除字符串**************
**
** 删除给定字符串内给定的字符串
**
**几个实现思路：
**1.KMP算法
**2.用STL的string的 find,然后用erase
**3.用C的strstr找到字串位置,然后用strncpy写到新串中
**4.用boost库,用正则表达式
**
***************************************/

#include<iostream>
#include <string>
using namespace std;

/****************方法一*********************/

/*void deletestr(const char *str, const char* sub_str, char *result);

int main()
{  
	char str[100],sub[100];
	cin>>str;
	cin>>sub;
	char result;
	deletestr(str,sub,&result);
	return 0;
}

void deletestr(const char *str, const char* sub_str, char *result)
{   
    int sublen = 0;         //获得子串的长度
    const char *t = sub_str;
    while(*t++ != '\0')
    {
        sublen++;
    }

    int pos = 0;
    int pp = 0;
    int repos = 0; // 结果子串的索引
    while(*(str + pos) != '\0')
    {
        char t = *(str + pos);
        if(t == *(sub_str + pp)) // 重复子串起始位置
        {
            *(result + repos) = t;
            repos++;

            if(pp < sublen - 1) // 还未完全重复
            { 
                pp++;
            }
            else if(pp == sublen - 1) // 完全重复了
            {
                pp = 0;
                repos -= sublen; // 回溯下标位置
            }            
        }
        else{ // 不是一样的字符
            *(result + repos) = t;
            repos++;
        }
        pos++;
    }
    *(result + repos) = '\0';
	cout<<result<<endl;
}*/


/****************方法二：STL解决*********************/
void deletesub(string &str,const string &sub,int n);
int main()
{  
	string str,sub;
	cin>>str;
	cin>>sub;
	int n=sub.size();
	deletesub(str,sub,n);
	return 0;
}
void deletesub(string &str,const string &sub,int n)
{
	int m,flag=0,num=0;           //num是子串出现的次数
   while(flag==0)
   {
		m=str.find(sub);
		if(m<0)
			flag=1;
		else
		{
		  str.erase(m,n);           //删除子串
		  num++;
		}
   }
//	cout<<num<<endl;          //子串出现的次数
	cout<<str<<endl;         // 输出删除后的字符串   
}



