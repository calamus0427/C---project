/***************ɾ���ַ���**************
**
** ɾ�������ַ����ڸ������ַ���
**
**����ʵ��˼·��
**1.KMP�㷨
**2.��STL��string�� find,Ȼ����erase
**3.��C��strstr�ҵ��ִ�λ��,Ȼ����strncpyд���´���
**4.��boost��,��������ʽ
**
***************************************/

#include<iostream>
#include <string>
using namespace std;

/****************����һ*********************/

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
    int sublen = 0;         //����Ӵ��ĳ���
    const char *t = sub_str;
    while(*t++ != '\0')
    {
        sublen++;
    }

    int pos = 0;
    int pp = 0;
    int repos = 0; // ����Ӵ�������
    while(*(str + pos) != '\0')
    {
        char t = *(str + pos);
        if(t == *(sub_str + pp)) // �ظ��Ӵ���ʼλ��
        {
            *(result + repos) = t;
            repos++;

            if(pp < sublen - 1) // ��δ��ȫ�ظ�
            { 
                pp++;
            }
            else if(pp == sublen - 1) // ��ȫ�ظ���
            {
                pp = 0;
                repos -= sublen; // �����±�λ��
            }            
        }
        else{ // ����һ�����ַ�
            *(result + repos) = t;
            repos++;
        }
        pos++;
    }
    *(result + repos) = '\0';
	cout<<result<<endl;
}*/


/****************��������STL���*********************/
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
	int m,flag=0,num=0;           //num���Ӵ����ֵĴ���
   while(flag==0)
   {
		m=str.find(sub);
		if(m<0)
			flag=1;
		else
		{
		  str.erase(m,n);           //ɾ���Ӵ�
		  num++;
		}
   }
//	cout<<num<<endl;          //�Ӵ����ֵĴ���
	cout<<str<<endl;         // ���ɾ������ַ���   
}



