/**************************Լɪ��*****************************
��֪n���ˣ��Ա��1��2��3...n�ֱ��ʾ��Χ����һ��Բ����Χ���ӱ��
Ϊk���˿�ʼ����������m���Ǹ��˳��У�������һ�����ִ�1��ʼ������
����m���Ǹ����ֳ��У����˹����ظ���ȥ��ֱ��Բ����Χ����ȫ�����С�
****************************************************************/

#include<iostream>
using namespace std;
struct node{
	int num;
	node *next;
};
node *creat(int n)
{
	node *q,*p,*head=NULL;
	for(int i=1;i<=n;i++)
	{
		p=new node;
		p->num=i;
		if(head==NULL)
			head=p;
		else
			q->next=p;
		q=p;
	}
	p->next=head;
	return p;
}
int main()
{  
	int n,k,m;
	cin>>n>>k>>m;
	node *l,*q;
	l=creat(n);
	q=l;
	l=l->next;
	for(int i=1;i<k;i++)
	{
        q=l;
		l=l->next;
	}
	while(l->next!=l)
	{
		for(int i=1;i<m;i++)
		{
			q=l;
			l=l->next;
		}
		cout<<l->num<<"->";
		q->next=l->next;
		delete l;
		l=q->next;
	}
	cout<<l->num<<endl;
	delete l;

	return 0;
}
