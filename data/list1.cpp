#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

node *createList(int n);
node *createListInvert(int n);
void outPutList(node *head)
{
	cout<<"List: ";
	node *curNode = head;
	while(curNode)
	{
		cout<<curNode->data;
		if(curNode->next)
		{
			cout<<"->";
		}
		curNode = curNode->next;
	}
	cout<<endl;
	return;
} 
int main()
{
	int n;
	node *listHead = NULL;
	node *listHeadI = NULL;
	cout<<"Please enter the number of nodes:"<<endl;
	cin>>n;
	if(n>0)
	{
		listHead = createList(n);
		listHeadI = createListInvert(n);
		outPutList(listHead);
		outPutList(listHeadI);
		
	}
	
	
	return 0;
}


node *createList(int n)
{
	node *temp = NULL,*tail = NULL,*head = NULL;
	int num;
	
	cin>>num;
	head = new node;
	if(head == NULL)
	{
		cout<<"Not memory available!"<<endl;
		return NULL;
	}
	else
	{
		head->data =num;
		head->next = NULL;
		tail = head;
	}
	
	for(int i=0;i<n-1;i++)
	{
		cin>>num;
		temp = new node;
		if(temp == NULL){
			cout<<"Not memory available!"<<endl;
			return head;
		}
		else
		{
			temp->data = num;
			temp->next = NULL;
			tail->next = temp;
			tail = temp;
		}
	}
	return head;
}

node *createListInvert(int n)
{
	node *temp = NULL,*head = NULL;
	int num;
	
	cin>>num;
	head = new node;
	if(head == NULL)
	{
		cout<<"Not memory available!"<<endl;
		return NULL;
	}
	else
	{
		head->data = num;
		head->next = NULL;
	}
	
	for(int i=0;i<n-1;i++)
	{
		cin>>num;
		temp = new node;
		if(temp == NULL)
		{
			cout<<"Not memory available!"<<endl;
			return head;
		}
		else
		{
			temp->data = num;
			temp->next = head;
			head = temp; 
		}
	}
	return head;
}