
#include<iostream>
using namespace std;
template<typename T>
struct node4             //node 3 for doubly linked list node
{
	T data;
	struct node4 *next;
	struct node4 *prev;
};

template<class T>
class DoublyLL
{
	private:
	node4<T>* first;
	node4<T>* last;
	int size;
	
	public:
	DoublyLL();
	void Display();
	int Count();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int ipos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int ipos);
};

//Return-Value Class_Name::Function_Name(Parameter)
	template<class T>
    DoublyLL<T>::DoublyLL()
	{
		first=NULL;
		last=NULL;
		size=0;
	}

template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
		node4<T>* newn=new node4<T>;
		newn->data=no;
		newn->next=NULL;
		newn->prev=NULL;
		
		if((first==NULL)&&(last==NULL))
		{
			first=newn;
			last=newn;
		}
		else
		{
			newn->next=first;
			first->prev=newn;
			first=newn;
		}
		
		size++;
}

template<class T>
void DoublyLL<T>::InsertLast(T no)
{
		node4<T>* newn=new node4<T>;
		newn->data=no;
		newn->next=NULL;
		newn->prev=NULL;
		
		if((first==NULL)&&(last==NULL))
		{
			first=newn;
			last=newn;
		}
		else
		{
			newn->prev=last;
			last->next=newn;
			last=newn;
		}
		size++;
}

template<class T>
void DoublyLL<T>::Display()
{
	node4<T>* temp=first;
	
	for(int i=1;i<=size;i++)
	{
		cout<<"|"<<temp->data<<"|->";
		temp=temp->next;
	}
	cout<<"\n";
}

template<class T>
int DoublyLL<T>::Count()
{
	return size;
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
	if((first==NULL)&&(last==NULL))
	{
		return;
	}
	else if(first==last)
	{
		delete first;
		first=NULL;
		last=NULL;
	}
	else
	{
		first=first->next;
		delete (last->next);
		first->prev=last;
		last->next=first;
	}
	size--;
	
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
	if((first==NULL)&&(last==NULL))
	{
		return;
	}
	else if(first==last)
	{
		delete first;
		first=NULL;
		last=NULL;
	}
	else
	{
		last=last->prev;
		delete (last->next);
		first->prev=last;
		last->next=first;
	}
	size--;
}

template<class T>
void DoublyLL<T>::InsertAtPos(T no,int ipos)
{
	if((ipos<1)||(ipos>size+1))
	{
		return;
	}
	if(ipos==1)
	{
		InsertFirst(no);
	}
	else if(ipos==size+1)
	{
		InsertLast(no);
	}
	else
	{
	node4<T>* newn=new node4<T>;
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	node4<T>* temp=first;
	int i=0;
	for(i=1;i<ipos-1;i++)
	{
		temp=temp->next;
	}
	newn->next=temp->next;
	temp->next->prev=newn;
	temp->next=newn;
	newn->prev=temp;
	size++;
	}
}

template<class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
	if((ipos<1)||(ipos>size))
	{
		return;
	}
	if(ipos==1)
	{
		DeleteFirst();
	}
	else if(ipos==size)
	{
		DeleteLast();
	}
	else
	{
		node4<T>* temp=first;
		node4<T>* targeted=NULL;
		int i=0;
		for(i=1;i<ipos-1;i++)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		delete targeted;
		temp->next->prev=temp;
		size--;
	}	
}
int main()
{	
	cout<<"************************************************\n";
	cout<<"This is a Doubly Linear Linked List\n";
	DoublyLL<int> dlobj;
	dlobj.InsertFirst(21);
	dlobj.InsertFirst(11);
	dlobj.InsertLast(51);
	dlobj.InsertLast(101);
	
	dlobj.InsertAtPos(75,3);
	dlobj.Display();
	int iret=dlobj.Count();
	cout<<"Number of elements are:"<<iret<<"\n";
	
	dlobj.DeleteAtPos(3);
	dlobj.DeleteFirst();
	dlobj.DeleteLast();
	dlobj.Display();
	iret=dlobj.Count();
	cout<<"Number of elements are:"<<iret<<"\n";
	cout<<"************************************************\n";
//*********************************************************************************** 
	cout<<"************************************************\n";
}