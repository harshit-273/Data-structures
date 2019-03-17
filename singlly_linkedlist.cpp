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
	return;
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
void remove_spec_node()
{
	int num;
	if(start==NULL)
	{
		cout<<"Sorry, can't perform this action as list is empty'"<<endl;
		return;
	}
	cout<<"Enter the value of data in the node:";
	cin>>num;
	ptr=start;
	if(num==start->data)
	{
		remove_begin();
	}
	while(ptr->next!=NULL)
	{
		if(ptr->next->data==num)
		{
			node *nnode;
			nnode=ptr->next;
			ptr->next=ptr->next->next;
			free(nnode);
			cout<<"node removed with data "<<num<<endl;
			return;
		}
		else
		{
			ptr=ptr->next;
		}
	}
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
	return;
}
void search_node(int num)
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
			if(ptr->data==num)
			{
				cout<<"Data Found."<<endl<<endl;
				return;
			}
			ptr=ptr->next;
		}
		cout<<"Sorry, Data not found."<<endl<<endl;
	}
	return;
}
void print_reverse(node *node2)
{
	if(start==NULL)
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
		cout<<"Hello!"<<endl<<"Here are the choices for you:\n\n";
		cout<<"a-Enter the node at begin.\n";
		cout<<"b-Enter the node at end.\n";
		cout<<"c-Remove the node from begin.\n";
		cout<<"d-Remove the node from end.\n";
		cout<<"e-Enter the node at specified position.\n";
		cout<<"f-Remove the node from specified position.\n";
		cout<<"g-Remove the specified node.\n";
		cout<<"h-Print the link-list.\n";
		cout<<"i-Print the link-list in reverse order.\n";
		cout<<"j-Search for Data.\n";
		cout<<"q-To quit this session.\n";
		cin>>choice;
		switch(choice)
		{
			case 'a':
				create_begin();
				break;
			case 'b':
				create_end();
				break;
			case 'c':
				remove_begin();
				break;
			case 'd':
				remove_end();
				break;
			case 'e':
				enter_spec();
				break;
			case 'f':
				remove_spec();
				break;
			case 'g':
				remove_spec_node();
				break;
			case 'h':
				print_list();
				break;
			case 'i':
				print_reverse(start);
				break;
			case 'j':
				int num;
				cout<<"Enter the data you want to search for:";
				cin>>num;
				search_node(num);
				break;
			case 'q':
				cout<<"Thank you for trying this here,\n\t\t\t\tcome back soon.\n\nPress the cross icon above dumbo.";
				break;
			default:
				cout<<"\nPlease enter the correct choice\n";
				break;
		}
	}	
	
	return (0);
}
