//Doubly circular Linked list using template

#include<iostream>
using namespace std;

template<typename T>
struct node3
{
	T data;
	struct node3 *next;
	struct node3 *prev;
};

template<class T>
class DoublyCL
{
	private:
	node3<T>* first;
	node3<T>* last;
	int size;
	
	public:
	DoublyCL();
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
    DoublyCL<T>::DoublyCL()
	{
		first=NULL;
		last=NULL;
		size=0;
	}

template<class T>
void DoublyCL<T>::InsertFirst(T no)
{
		node3<T>* newn=new node3<T>;
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
		
		last->next=first;
		first->prev=last;
		size++;
}

template<class T>
void DoublyCL<T>::InsertLast(T no)
{
		node3<T>* newn=new node3<T>;
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
		
		last->next=first;
		first->prev=last;
		size++;
}

template<class T>
void DoublyCL<T>::Display()
{
	node3<T>* temp=first;
	
	for(int i=1;i<=size;i++)
	{
		cout<<"|"<<temp->data<<"|->";
		temp=temp->next;
	}
	cout<<"\n";
}

template<class T>
int DoublyCL<T>::Count()
{
	return size;
}

template<class T>
void DoublyCL<T>::DeleteFirst()
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
void DoublyCL<T>::DeleteLast()
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
void DoublyCL<T>::InsertAtPos(T no,int ipos)
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
	node3<T>* newn=new node3<T>;
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	node3<T>* temp=first;
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
void DoublyCL<T>::DeleteAtPos(int ipos)
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
		node3<T>* temp=first;
		int i=0;
		for(i=1;i<ipos-1;i++)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		delete temp->next->prev;
		temp->next->prev=temp;
		size--;
	}
	
}
int main()
{
	DoublyCL<int> dcobj;
	dcobj.InsertFirst(21);
	dcobj.InsertFirst(11);
	dcobj.InsertLast(51);
	dcobj.InsertLast(101);
	
	dcobj.InsertAtPos(75,3);
	dcobj.Display();
	int iret=dcobj.Count();
	cout<<"Number of elements are:"<<iret<<"\n";
	
	dcobj.DeleteAtPos(3);
	dcobj.DeleteFirst();
	dcobj.DeleteLast();
	dcobj.Display();
	iret=dcobj.Count();
	cout<<"Number of elements are:"<<iret<<"\n";
	
	return 0;
}