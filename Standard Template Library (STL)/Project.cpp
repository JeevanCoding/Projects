//Project:Creating our own STL(Standard Template Library)

#include<iostream>
using namespace std;
//////////////////////////////////////////////
//Singly Linear Linked List
//
/////////////////////////////////////////////
template <typename T>
struct node
{
    T data;
    struct node* next;
};

template <class T>
class SinglyLL
{
private:
    node<T>* first;
    int size;
    
public:
    SinglyLL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
};
	
	template <class T>
	SinglyLL<T>::SinglyLL()
    {
        first = NULL;
        size = 0;
    }

template <class T>	
void SinglyLL<T>::InsertFirst(T no)
    {
        node<T>* newn = new node<T>;  // newn = (PNODE)malloc(sizeof(NODE))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        size++;
    }
    
	template <class T>
    void SinglyLL<T>::InsertLast(T no)
    {
        node<T>* newn = new node<T>;  // newn = (PNODE)malloc(sizeof(NODE))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            node<T>* temp = first;
            
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        size++;
    }
    
	template <class T>
    void SinglyLL<T>::InsertAtPos(T no, int ipos)
  {
		node<T>* temp=first;
		node<T>* newn=new node<T>;
	if((ipos<1)||(ipos>(size+1)))
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
			int i=0;
			newn->data=no;
			newn->next=NULL;
			
			for(i=1;i<(ipos-1);i++)
			{
				temp=temp->next;
			}
			newn->next=temp->next;
			size++;
	}
	}  
	template <class T>
    void SinglyLL<T>::DeleteFirst()
    {
        node<T>* temp = first;
        
        if(first != NULL)
        {
            first = first->next;
            delete temp;
            
            size--;
        }
    }
    
	template <class T>
    void SinglyLL<T>::DeleteLast()
    {
        node<T>* temp = first;
        
        if(first == NULL)
        {
            return;
        }
        else if(first->next == NULL)
        {
            delete first;
            first = NULL;
            size--;
        }
        else
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            
            delete temp->next;
            temp->next = NULL;
            size--;
        }
    }
	
	template <typename T>
    void SinglyLL<T>::DeleteAtPos(int ipos)
    {
		node<T>* temp=first;
		node<T>* targeted=temp->next;
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
			for(int i=1;i<(ipos-1);i++)
			{
				temp=temp->next;
			}
			temp->next = targeted->next;
			delete(targeted);
			size--;

	}
	}
    
	template <class T>
    void SinglyLL<T>::Display()
    {
        node<T>* temp = first;
        
        while(temp!= NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }
    
	template <class T>
    int SinglyLL<T>::Count()
    {
        return size;
    }
//End of Singly Linear Linked List
//////////////////////////////////////////////////////////////////////////////////////////	

//************************************************************************************************************************************************************************
////////////////////////////////////////
//Singly Circular Linked List
////////////////////////////////////////
template<typename T>
struct node2                     //node2 means node of singly circular linked list 
{
	T data;
	struct node2 *next;
};

template<class T>
class SinglyCL
{
 private:
	node<T>* first;
	node<T>* last;
	int size;
	
	public:
	SinglyCL();
	int Count();
	void Display();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
};

template<class T>
SinglyCL<T>::SinglyCL()
	{
		first=NULL;
		last=NULL;
		size=0;
	}
	
	template<class T>
	void SinglyCL<T>::Display()
	{
		node<T>* temp=first;
		if((first==NULL) && (last==NULL))
		{
			return;
		}
		do
		{
			cout<<"|"<<temp->data<<"|-> ";
			temp=temp->next;
		}while(temp!=last->next);
		cout<<"\n";
	}
	
	template<class T>
	int SinglyCL<T>::Count()
	{
		return size;
	}
	
	template<class T>
	void SinglyCL<T>::InsertFirst(T no)
	{
		node<T>* newn=new node<T>;
				
		newn->data=no;
		newn->next=NULL;
		
		if((first==NULL) && (last==NULL))
		{
			first=newn;
			last=newn;
		}
		else
		{
			newn->next=first;
			first=newn;
		}
		last->next=first;
		size++;
	}
	
	template<class T>
	void SinglyCL<T>::InsertLast(T no)
	{
		node<T>* newn=new node<T>;	
		newn->data=no;
		newn->next=NULL;
		
		if((first==NULL) && (last==NULL))
		{
			first=newn;
			last=newn;
		}
		else
		{
		last->next=newn;
		last=newn;
		}
		last->next=first;
		size++;
	}
	
	template<class T>
	void SinglyCL<T>::InsertAtPos(T no,int ipos)
	{
		if((ipos<1)||(ipos>(size+1)))
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
			int i=0;
			node<T>* newn=new node<T>;
			node<T>* temp=first;
			newn->data=no;
			newn->next=NULL;
			
			for(i=1;i<(ipos-1);i++)
			{
				temp=temp->next;
			}
			newn->next=temp->next;
			temp->next=newn;
			size++;
		}
	}
	
	template<class T>
	void SinglyCL<T>::DeleteFirst()
	{
		if((first==NULL)&&(last==NULL))
		{
			return;
		}
		else if(first==last)
		{
			delete(first);
			first=NULL;
			last=NULL;
		}
		else
		{
			first=first->next;
			delete(last->next);
			last->next=first;
		}
		size--;
	}
	
	template<class T>
	void SinglyCL<T>::DeleteLast()
	{
		node<T>* temp=first;
		if((first==NULL)&&(last==NULL))
		{
			return;
		}
		else if(first==last)
		{
			delete(first);
			first=NULL;
			last=NULL;
		}
		else
		{
			while(temp->next!=last)
			{
				temp=temp->next;
			}
			delete(last);
			last=temp;
			last->next=first;
		}
		size--;
	}
	
	template<class T>
	void SinglyCL<T>::DeleteAtPos(int ipos)
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
			node<T>* temp=first;
			for(int i=1;i<(ipos-1);i++)
			{
				temp=temp->next;
			}
			node<T>* targeted=temp->next;
			temp->next = targeted->next;
			delete(targeted);
			size--;
		}
	}




//**********************************************************************************************
////////////////////////////////
//Doubly Linear Linked List
////////////////////////////////
template<typename T>
struct node4             //node4 for doubly Linear linked list node
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



//************************************************************************************************************************************************************************
////////////////////////////////
//Doubly Circular Linked List
////////////////////////////////
template<typename T>
struct node3             //node 3 for doubly linked list node
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
//******************************************************************************************************************************************************************



	
//////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int iret = 0;
/////////////////////////////////////
//object of singly linear linked list
/////////////////////////////////////
	cout<<"************************************************\n";
	cout<<"This is a Singly Linear Linked List\n";
    SinglyLL <char> cobj;
    cobj.InsertFirst('A');
    cobj.InsertFirst('B');
    cobj.InsertFirst('C');
    
    cobj.InsertLast('S');
    cobj.InsertLast('R');
    
    cobj.Display();  
    iret = cobj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
    
	///////////////
	SinglyLL <int> iobj;
    iobj.InsertFirst(11);
    iobj.InsertFirst(21);
    iobj.InsertFirst(51);
    
    iobj.InsertLast(101);
    iobj.InsertLast(111);
    
    iobj.Display();  
    iret = iobj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
	cout<<"************************************************\n";


    //***********************************************************************************
/////////////////////////////////////////
//object of singly circular Linked List
/////////////////////////////////////////
	cout<<"************************************************\n";
	cout<<"This is a Singly circular Linked List\n";
	int ipos=0;
	SinglyCL<int> obj2;
		
	obj2.InsertFirst(51);
	obj2.InsertFirst(21);
	obj2.InsertFirst(11);
	
	obj2.InsertLast(101);

	obj2.InsertAtPos(111,3);
	obj2.Display();
	
	iret=obj2.Count();
	cout<<"Number of elements are :"<<iret<<"\n";
	
	obj2.DeleteFirst();
	obj2.Display();
	iret=obj2.Count();
	cout<<"Number of elements are :"<<iret<<"\n";
	
	obj2.DeleteLast();
	obj2.Display();
	iret=obj2.Count();
	cout<<"Number of elements are :"<<iret<<"\n";
	
	obj2.DeleteAtPos(2);
	obj2.Display();
	iret=obj2.Count();
	cout<<"Number of elements are :"<<iret<<"\n";
	cout<<"************************************************\n";


//***********************************************************************************
/////////////////////////////////////
//object of Doubly Linear Linked list
/////////////////////////////////////
	cout<<"************************************************\n";
	cout<<"This is a Doubly Linear Linked List\n";
	DoublyLL<int> dlobj;
	dlobj.InsertFirst(21);
	dlobj.InsertFirst(11);
	dlobj.InsertLast(51);
	dlobj.InsertLast(101);
	
	dlobj.InsertAtPos(75,3);
	dlobj.Display();
	iret=dlobj.Count();
	cout<<"Number of elements are:"<<iret<<"\n";
	
	dlobj.DeleteAtPos(3);
	dlobj.DeleteFirst();
	dlobj.DeleteLast();
	dlobj.Display();
	iret=dlobj.Count();
	cout<<"Number of elements are:"<<iret<<"\n";
	cout<<"************************************************\n"; 
	cout<<"************************************************\n";


//***********************************************************************************	
///////////////////////////////////////
//Object of doubly circular linked list
///////////////////////////////////////
	cout<<"************************************************\n";
	cout<<"This is a Doubly circular Linked List\n";
	DoublyCL<int> dcobj;
	dcobj.InsertFirst(21);
	dcobj.InsertFirst(11);
	dcobj.InsertLast(51);
	dcobj.InsertLast(101);
	
	dcobj.InsertAtPos(75,3);
	dcobj.Display();
	iret=dcobj.Count();
	cout<<"Number of elements are:"<<iret<<"\n";
	
	dcobj.DeleteAtPos(3);
	dcobj.DeleteFirst();
	dcobj.DeleteLast();
	dcobj.Display();
	iret=dcobj.Count();
	cout<<"Number of elements are:"<<iret<<"\n";
	cout<<"************************************************\n";
//*********************************************************************************** 
	cout<<"************************************************\n";
 return 0;
}