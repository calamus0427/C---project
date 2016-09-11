#include<iostream>
#include<queue>
using namespace std;


class node
{
public:
	int data;
	node *parent;
	node *left;
	node *right;
	node():data(-1),parent(NULL),left(NULL),right(NULL){}
	node(int num):data(num),parent(NULL),left(NULL),right(NULL){}

};

class tree
{
private:
	node *root;
	void insertnode(node *current,int data);
	node *searchnode(node *current,int data);
	void deletenode(node *current);
	void inordertree(node *current);
public:
	tree(int num[],int len);
	void insertnode(int data);    //µÝ¹é
	void insertnode1(int data);   //·ÇµÝ¹é
	node *searchnode(int data);
	void deletenode(int data);
	void inordertree();
	void levelordertree();
};

tree::tree(int num[], int len)
{
	root=new node(num[0]);
	for(int i=1;i<len;i++)
		insertnode1(num[i]);
}

void tree::insertnode1(int data)
{
	node *p,*q,*newnode;
    new node=new node(data);
	p=q=root;
	while(p)
	{
		q=p;
		if(data<p->data)
			p=p->left;
		else if(data>p->data)
			p=p->right;
		else
		{
			delete newnode;
			return;
		}
	}
	newnode->parent=q;
	if(data<q->data)
		q->left=new node;
	else
		q->right=new node;
}

void tree::insertnode(int data)
{
	if(root!=NULL)
	{
		insertnode(root,data);
	}
}

void tree::insertnode(node *current, int data)
{
	if(data<current->data)
	{
		if(current->left==NULL)
		{
			node *newnode=new node(data);
			current->left=newnode;
			newnode->parent=current;
		}
		else
			insertnode(current->left,data);
	}
	else if(data>current->data)
	{
		if(current->right==NULL)
		{
			node *newnode=new node(data);
			current->right=newnode;
			newnode->parent=current;
		}
		else
			insertnode(current->right,data);
	}

	return;
}

node *tree::searchnode(int data)
{
	if(root)
		return searchnode(root,data);
}

node *tree::searchnode(node *current,int data)
{
	if(data<current->data)
	{
		if(current->left==NULL)
			return NULL;
		return searchnode(current->left,data);
	}
	else if(data>current->data)
	{
		if(current->right==NULL)
			return NULL;
		return searchnode(current->right,data);
	}
	else
		return current;
}

void tree::deletenode(int data)
{
	node *current=NULL;
	current=searchnode(data);
	if(current)
		deletenode(current);
}

void tree::deletenode(node *current)
{
	if(current->left!=NULL)
		deletenode(current->left);
	if(current->right!=NULL)
		deletenode(current->right);
	if(current->parent==NULL)
	{
		delete current;
		root=NULL;
		return;
	}
	if(current->parent->data>current->data)
		current->parent->left=NULL;
	else
		current->parent->right=NULL;

	delete current;

}

void tree::inordertree()
{
	if(root==NULL)
		return;
	inordertree(root);
}

void tree::inordertree(node *current)
{
	if(current!=NULL)
	{
		inordertree(current->left);
		cout<<current->data<<" ";
		inordertree(current->right);                            
	}
}

void tree::levelordertree()
{
	queue<node*>q;
	node *p=NULL;
	q.push(root);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		cout<<p->data<<" ";
		if(p->left)
			q.push(p->left);
		if(p->right)
			q.push(p->right);

	}
}
int main()
{  
	int num[10]={5,1,6,2,7,3,8,4,9,0},len=10;
	tree t(num,10);
	/*node *c;
	c=t.searchnode(6);
	cout<<c->data<<endl;*/
	t.inordertree();
	cout<<endl;
	t.levelordertree();

	return 0;
}