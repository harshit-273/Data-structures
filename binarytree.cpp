#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct node1
{
    int data;
	struct node1 *lnode;
	struct node1 *rnode;
}node;
node *start=NULL,*ptr=NULL,*traverse=NULL;
//function specially related with creation of node and their positioning
void traversal(node *n1,node *n2)
{
    if((n1->data)>(n2->data))
    {
        if((n1->lnode)!=NULL)
        {
            traversal(n1->lnode,n2);
        }
        else
        {
            n1->lnode=n2;
        }
    }
    else
    {
        if((n1->rnode)!=NULL)
        {
            traversal(n1->rnode,n2);
        }
        else
        {
            n1->rnode=n2;
        }
    }
}
//creation of node
void create_node()
{
    int num;
	cout<<"\nPlease enter the number:";
	cin>>num;
	node *nnode;
	nnode=(node*)malloc(sizeof(node));
	nnode->data=num;
    nnode->lnode=NULL;
    nnode->rnode=NULL;
    if(start==NULL)
    {
        start=nnode;
    }
    else
    {
        traversal(start,nnode);
    }
}
void preorder(node *n1)
{
	if(n1==NULL)
	{
		cout<<"no data entered."<<endl;
		return;
	}
	//traversing to left most
	if((n1->lnode)!=NULL)
	{
		preorder(n1->lnode);
	}
	//printing the data
	cout<<(n1->data)<<" ";
	//traversing to right
	if((n1->rnode)!=NULL)
	{
		preorder(n1->rnode);
	}
}
void inorder(node *n1)
{
	if(n1==NULL)
	{
		cout<<"no data entered."<<endl;
		return;
	}
	//printing the data
	cout<<(n1->data)<<" ";
	//traversing to left most
	if((n1->lnode)!=NULL)
	{
		inorder(n1->lnode);
	}
	//traversing to right
	if((n1->rnode)!=NULL)
	{
		inorder(n1->rnode);
	}
}
void postorder(node *n1)
{
	if(n1==NULL)
	{
		cout<<"no data entered."<<endl;
		return;
	}
	if((n1->lnode)!=NULL)
	{
		postorder(n1->lnode);
	}
	if((n1->rnode)!=NULL)
	{
		postorder(n1->rnode);
	}
	cout<<(n1->data)<<" ";
}
int main()
{
    int select;
    while(1)
    {
	    cout<<"\nSelect from the following:"<<endl;
	    cout<<"1-Enter new data"<<endl;
	    cout<<"2-Show the tree in sorted(preorder) order"<<endl;
	    cout<<"3-Show the whole tree"<<endl;
	    cout<<"4-Delete data"<<endl;
	    cout<<"5-Update data"<<endl;
        cout<<"6-Show tree in inorder"<<endl;
        cout<<"7-Show tree in postorder"<<endl;
        cout<<"8-Show tree in levelorder"<<endl;
	    cout<<"Press Any Other Key-Exit"<<endl;
	    cin>>select;
	    switch(select)
	    {
	        case 1:
	        	create_node();
	            break;
	        case 2:
	        	preorder(start);
	            break;
	        case 3:
                cout<<"sorry, not available"<<endl;
	            break;
	        case 4:
                cout<<"sorry, not available"<<endl;
	            break;
	        case 5:
                cout<<"sorry, not available"<<endl;
	            break;
            case 6:
                inorder(start);
	            break;
            case 7:
                postorder(start);
	            break;
            case 8:
                cout<<"sorry, not available"<<endl;
	            break;
	        default:
	            cout<<"\n\tThank you User,\n\t\tVisit us again."<<endl;
	            exit(0);
	            break;
	    }
	}
    return (0);
}
