#include<iostream>
using namespace std;
char board[80][100];
static int m=2,n=4,m1=1,n1=3;
struct food
{
	int x=2;
	int y=4;
	char value='A';
}f;
struct poison
{
	int x=7;
	int y=8;
	char value='P';
}p;
struct node
{	
	int a;
	int b;
	char data;
	node *next;
};
class abc
{
	public:
			node *head=NULL;

	node *create(int n)
{
	node *ptr=new node();
	ptr->data=n;
	ptr->next=NULL;
		return ptr;
}
	void insert_tail(char x)
{
	node *t,*temp;
	temp=new node();
	t=new node();
	temp=create(x);
	if(head==NULL)
	head=temp;
	else
	t=head;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=temp;
	temp->next=NULL;
	
}
void del_tail()
{
	node *t,*p;
	t=head;
	while(t->next!=NULL)
	{
		p=t;
		t=t->next;
	}
board[t->a][t->b]='*';
delete(p->next);
p->next=NULL;
p->data='t';
cout<<"abc";
}
void snake()
{
	node *t;
	t=head;
	int i=3,j=4;
	while(t!=NULL)
	{
		t->a=i;
		t->b=j;
		j++;
	    board[t->a][t->b]=t->data;
		t=t->next;
		
	}
}
void sec_last()
{
		node *t,*temp;
	temp=new node();
	t=new node();
	temp=create('t');
	if(head==NULL)
	head=temp;
	else
	t=head;
	while(t->next!=NULL)
	{
		t=t->next;
		t->data='#';
	}
	t->next=temp;
	temp->next=NULL;
}
void change_food()
{
	m=(m*2)-1;
	n=n*2;
	f.x=m;
	f.y=n;
	f.value='A';
	board[f.x][f.y]=f.value;
}
void change_poison()
{
	m1=(m1*1)+1;
	n1=n1+2;
	p.x=m1;
	p.y=n1;
	board[p.x][p.y]='P';
}
void swap(node *t,int r,int c)
{
	int r1,c1;
	while(t!=NULL)
	{
		r1=t->a;
		c1=t->b;
		t->a=r;
		t->b=c;
	    board[t->a][t->b]=t->data;
		r=r1;
		c=c1;
		t=t->next;
	}
board[r1][c1]='*';
}	
void shift_left()
{
		node *t;
	int i,j;
	int r,c;
	t=head;
		r=t->a;
    	c=t->b;
		char x='t';
		t->b=t->b-1;
		if(t->b<0)
		{
		t->b=9;	
		}
		board[t->a][t->b]=t->data;
		t=t->next;
			if(r==f.x && c==f.y)
		{
						sec_last();

			change_food();
		}
if(board[r][c]=='P')
		{ 
		cout<<"abc";

					del_tail();
					change_poison();

		}
			swap(t,r,c);
}
void shift_right()
{
		node *t;
	int i,j;
	int r,c;
	t=head;
		r=t->a;
    	c=t->b;
		char x='t';
		t->b=t->b+1;
		if(t->b>9)
		{
		t->b=0;	
		}
		board[t->a][t->b]=t->data;
		t=t->next;
			if(r==f.x && c==f.y)
		{
			sec_last();
			change_food();
		}
	if(board[r][c]=='P')
		{ 
		cout<<"abc";

					del_tail();
					change_poison();

		}
		swap(t,r,c);
}
void shift_up()
{
	node *t;
	int i,j;
	int r,c;
	t=head;
		r=t->a;
    	c=t->b;
		char x='t';
		t->a=t->a-1;
		if(t->a<0)
		{
		t->a=9;	
		}
		board[t->a][t->b]=t->data;
		t=t->next;
			if(r==f.x && c==f.y)
		{
			sec_last();
			change_food();
		}
	else if(r==p.x && c==p.y)
		{ 
		cout<<"abc";

					del_tail();
					change_poison();

		}
			swap(t,r,c);
}	
void shift_down()
{
		node *t;
	int i,j;
	int r,c;
	t=head;
		r=t->a;
    	c=t->b;
		char x='t';
		t->a=t->a+1;
		if(t->a>9)
		{
		t->a=0;	
		}
		board[t->a][t->b]=t->data;
		t=t->next;
			if(r==f.x && c==f.y)
		{
			sec_last();
			change_food();
		}
		else if(r==p.x && c==p.y)
		{ 
					del_tail();
					change_poison();

		}
			swap(t,r,c);
}
void display()
{
	node *t;
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<endl;
		t=t->next;
	}
}
void board_display()
{
	int i,j;
		for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}
};
int main()
{
	abc a;
	char c;
	for(int i=0;i<5;i++)
	{
		cin>>c;
		a.insert_tail(c);
	}
for(int x=0;x<20;x++)
{
	for(int y=0;y<20;y++)
	{
		board[x][y]='*';
	}
}
	board[f.x][f.y]=f.value;
		board[p.x][p.y]=p.value;

	a.snake();
	system("cls");

	a.board_display();

		char dire;
	cout<<"enter direction";
cin>>dire;
while(dire!='n')
{
if(dire=='l')
{
a.shift_left();
	system("cls");

a.board_display();
}
if(dire=='r')
{
a.shift_right();
	system("cls");

a.board_display();
}
if(dire=='u')
{
a.shift_up();

	system("cls");

a.board_display();
}
if(dire=='d')
{
a.shift_down();
 system("cls");

a.board_display();
}
cin>>dire;
}
}
