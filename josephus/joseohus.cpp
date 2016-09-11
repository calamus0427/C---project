/**************************约瑟夫环*****************************
已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围。从编号
为k的人开始报数，数到m的那个人出列；他的下一个人又从1开始报数，
数到m的那个人又出列；依此规律重复下去，直到圆桌周围的人全部出列。
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
