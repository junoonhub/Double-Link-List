#include<iostream>
using namespace std;

struct node
{
	int info;
	struct node *next;
	struct node *prev;
}*head;

class double_list
{
	
	public:
		void create_list(int value);
		void display_list();
		void delete_element(int value);
		void add_begin(int value);
		void add_after(int value,int position);
		
		double_list()
		{
			head=NULL;
			
		}
};

void double_list::create_list(int value)
{
	struct node *current,*temp;
	
	temp=new(struct node);
	temp->info=value;
	temp->next=NULL;
	
	if(head==NULL)
	{
		
		temp->prev=NULL;
		head=temp;
	}
	else
	{
		current=head;
		while(current->next!=NULL)
		{
			current=current->next;
			
		}
		current->next=temp;
		temp->prev=current;
	}
}

void double_list::display_list()
{
	
	struct node *current;
	if(head==NULL)
	{
		cout << " list is Empty :"<<endl;
		
	}
	current=head;
	while(current!=NULL)
	{
		cout << "    "<<current->info;
		current =current->next;
		
	}
	

	
	
}


void double_list::delete_element(int value)
{
	struct node *temp,*current;
	
	if(head->info==value)
	{
		temp=head;
		head=head->next;
		head->prev==NULL;
		delete temp;
		
		cout << " Element deleted :"<<endl;
		
	}
	
	current=head;
	while(current->next->next!=NULL)
	{
		if(current->next->info==value)
		{
			temp=current->next;
			current->next=temp->next;
			delete temp;
			cout << " Element deleted :"<< endl;
			
		}current=current->next;
		
	}
}
    void double_list::add_begin(int value)
    
    {
    	if(head==NULL)
    	{
    		
    		cout << " first creat the list :"<<endl;
    		
		}   struct node *temp;
		    temp=new(struct node);
		    
		    temp->prev=NULL;
		    temp->info=value;
		    temp->next=head;
		    head->prev=temp;
		    head=temp;
		    cout << " value inserted :"<<endl;
		    
	}
    
    
    
     void double_list::add_after(int value,int pos)
     {
	     if(head==NULL)
	     {
	     	cout << " Head is null:"<<endl;
	     	
		 } struct node *temp,*current;
		   current=head;
		   for(int i=0;i<pos-1;i++)
		   {
		   	current=current->next;
		   	if(current==NULL)
		   	{
		   		
		   		cout << " there are less than :"<<pos<<"elements:"<<endl;
		   		
			   }
		   }
     	     temp=new(struct node);
     	     temp->info=value;
     	     if(current->next==NULL)
     	     {
     	     	current->next=temp;
     	     	temp->next=NULL;
     	     	temp->prev=current;
     	     	
			  }else
			  {
			  	temp->next=current->next;
			  	temp->next->prev=temp;
			  	current->next=temp;
			  	temp->prev=current;
			  	
			  	
			  }
     	    
     	    
     	    
     	    
	 }
    
    
    
    
int main()
{
  int choice ,element,position;
  double_list dl;
  while(1)
  {
  	cout << " operation of double linked lists is given :"<<endl;
  	cout << "1.create node :"<<endl<<endl;
  	
  	cout << "2.display node :"<<endl<<endl;
  	cout << "3.delete node :"<<endl<<endl;
  	cout << "4.Add value at beginning :"<<endl<<endl;
  	cout << "5.Add value after pposition :"<<endl<<endl;
  	cout << "6.Quit :"<<endl;
  	cout <<endl;
  	
  	cout << " Enter your choice :"<<endl;
  	cin >> choice;
  	
  	switch(choice)
  	{
  		
  		case 1:
  			cout << " enter element :=";
  			cin >> element;
  			dl.create_list(element);
  			cout << endl;
  			break;
  			
  			case 2:
  				dl.display_list();
  				cout <<endl;
  				break;
  				
  				case 3:
  					if(head==NULL)
  					{
  						cout << " linked list is empty ,Nothing to delete:"<<endl;
  						break;
  						
					  }
					  
					  cout << " enter element to delete :=";
					  cin >> element ;
					  dl.delete_element(element);
					  cout << endl;
					  break;
					  
					  case 4:
					  	cout << " enter element :=";
					  	cin >>element;
					  	dl.add_begin(element);
					  	cout << endl;
					  	break;
					  	
					  	case 5:
					  		cout << " enter element :=";
					  		cin >> element;
					  		
					  		cout << " insert element after position :=";
					  		cin >> position;
					  		dl.add_after(element,position);
					  		cout << endl;
					  		break;
					  		
					  
					  case 6:
					  	exit(1);
					  	default:
					  		
					  		cout << " wrong chocie :"<<endl;
					  		
	  }
	  }	
}

