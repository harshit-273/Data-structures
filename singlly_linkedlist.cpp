#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node1
{
	int data;
	struct node1 *next;
}node;
node *start=NULL,*ptr=NULL,*traverse=NULL;
void create_begin()
{
	int num;
	cout<<"\nPlease enter the number:";
	cin>>num;
	node *nnode;
	nnode=(node*)malloc(sizeof(node));
	nnode->data=num;
	nnode->next=NULL;
	if(start==NULL)
	{
		start=nnode;
	}
	else
	{
		nnode->next=start;
		start=nnode;
	}
}
void create_end()
{
	int num;
	cout<<"\nPlease enter the number:";
	cin>>num;
	node *nnode;
	nnode=(node*)malloc(sizeof(node));
	nnode->data=num;
	nnode->next=NULL;
	traverse=start;
	if(traverse==NULL)
	{
		start=nnode;
	}
	else
	{
		while((traverse->next)!=NULL)
		{
			traverse=traverse->next;
		}
		traverse->next=nnode;
	}
}
void remove_begin()
{
	if(start==NULL)
	{
		printf("\nNo node available to delete\n");
		return;
	}
	node *nnode;
	nnode=start;
	start=start->next;
	free(nnode);
}
void remove_end()
{
	if(start==NULL)
	{
		printf("\nNo node available to delete\n");
		return;
	}
	node *nnode;
	traverse=start;
	if(traverse->next==NULL)
	{
		start=NULL;
		free(traverse);
		return;
	}
	while(traverse->next->next!=NULL)
	{
		traverse=traverse->next;
	}
	nnode=traverse->next;
	traverse->next=NULL;
	free(nnode);
	return;
}
void enter_spec()
{
	int pos,count=1;
	cout<<"\nPlease enter the position:";
	cin>>pos;
	if(pos==1)
	{
		create_begin();
		return;
	}
	traverse=start;
	while(count!=(pos-1) && traverse->next!=NULL)
	{
		traverse=traverse->next;
		count++;
	}
	if(traverse->next==NULL && count==(pos-1))
	{
		create_end();
		return;
	}
	if(traverse->next==NULL && (pos-1)>count)
	{
		cout<<"\nSorry, can't enter the data at the specified position"<<endl;
		return;
	}
	node *nnode;
	nnode=(node*)malloc(sizeof(node));
	int num;
	cout<<"\nPlease enter the number:";
	cin>>num;
	nnode->data=num;
	nnode->next=traverse->next;
	traverse->next=nnode;
	return;
}
void remove_spec()
{
	int pos,count=1;
	cout<<"\nPlease enter the position:";
	cin>>pos;
	if(pos==1)
	{
		remove_begin();
		return;
	}
	traverse=start;
	while(count!=(pos-1) && traverse->next!=NULL)
	{
		traverse=traverse->next;
		count++;
	}
	if(traverse->next==NULL && count==(pos-1))
	{
		remove_end();
		return;
	}
	if(traverse->next==NULL && (pos-1)>count)
	{
		cout<<"\nSorry, can't remove the node at the specified position"<<endl;
		return;
	}
	node *nnode;
	nnode=traverse->next;
	traverse->next=nnode->next;
	free(nnode);
	return;
}
void print_list()
{
	ptr=start;
	if(ptr==NULL)
	{
		cout<<"\nList is empty."<<endl;
	}
	else
	{
		while((ptr->next)!=NULL)
		{
			cout<<ptr->data<<"->";
			ptr=ptr->next;
		}
		cout<<ptr->data<<endl<<endl;
	}
}
void print_reverse(node *node2)
{
	if(node2==NULL)
	{
		cout<<"\nList is empty."<<endl;
	}
	if((node2->next)!=NULL)
	{
		print_reverse(node2->next);
	}
	if(node2==start)
	{
		cout<<node2->data<<endl<<endl;
	}
	else
	{
		cout<<node2->data<<"<-";
	}
	return;
}
int main()
{
	int flag=0;
	char choice;
	while(1)
	{
		cout<<"Hello, Harshit."<<endl<<"Here are the choices for you:\n\n";
		cout<<"1-Enter the node at begin.\n";
		cout<<"2-Enter the node at end.\n";
		cout<<"3-Remove the node from begin.\n";
		cout<<"4-Remove the node from end.\n";
		cout<<"5-Enter the node at specified position.\n";
		cout<<"6-Remove the node from specified position.\n";
		/*cout<<"7-Remove the specified node.\n";*/
		cout<<"8-Print the link-list.\n";
		cout<<"9-Print the link-list in reverse order.\n";
		cout<<"q-To quit this session.\n";
		cin>>choice;
		switch(choice)
		{
			case '1':
				create_begin();
				break;
			case '2':
				create_end();
				break;
			case '3':
				remove_begin();
				break;
			case '4':
				remove_end();
				break;
			case '5':
				enter_spec();
				break;
			case '6':
				remove_spec();
				break;
			case '8':
				print_list();
				break;
			case '9':
				print_reverse(start);
				break;
			case 'q':
				flag=1;
				goto quit;
				break;
			default:
				cout<<"\nPlease enter the correct choice\n";
		}
		quit:
			if(flag==1)
			{
				break;
			}
	}	
	cout<<"Thank you Harshit for working here,\n\t\t\t\tcome back soon.\n\nPress the cross icon above dumbo.";
	return (0);
}
