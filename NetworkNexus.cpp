#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

struct Node{
    string name;
    long int phonenum;
    Node* prev;
    Node* next;
};

class NetworkNexus{
    Node *head;
    string x;
    long int y;
    
    public:
        NetworkNexus(){
            head=NULL;
            x="";
            y=0;
        }

    void CreateNode(){
        if(head==NULL){
            Node *newnode = new Node;
            cout<<"Name of Contact: ";
            cin>>x;
            newnode->name=x;

            cout<<"Phone Number: ";
            cin>>y;
            newnode->phonenum=y;

            newnode->prev=NULL;
            newnode->next=NULL;
            head=newnode;

            cout<<"Contact Saved Successfully!"<<endl;
            cout<<endl;
        }else{
            Node* temp=head;
            Node* newnode = new Node;
            cout<<"Name of Contact: ";
            cin>>x;
            newnode->name=x;

            cout<<"Phone Number: ";
            cin>>y;
            newnode->phonenum=y;

            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
            newnode->next=NULL;
            cout<<"Contact Saved Successfully!"<<endl;
            cout<<endl;
        }
    }

    void Display(){
        Node* temp=head;
        int count=0;
        if(temp==NULL){
            cout<<"No contacts found!"<<endl<<"Add some Contacts";
        }else{
            BubbleSort();
            cout<<"Name: "<<"              Number:\n"<<endl;
            while(temp!=NULL){
                count++;
                cout<<" "<<temp->name;
                cout<<"                "<<temp->phonenum<<endl;
                temp=temp->next;
            }
            cout<<"Total Contacts: "<<count<<endl;
        }
    }
    int Search(){
        bool found=false;
        Node* temp=head;
        cout<<endl;
        cout<<"*****************"<<endl;
        cout<<"Press 1 to search by Name"<<endl;
        cout<<"Press 2 to search by Number"<<endl;
        int command;
        cout<<"Enter the Command: ";
        cin>>command;

        if(command==1 && temp!=NULL){
            cout<<"Enter the Name to search: ";
            cin>>x;
            while(temp!=NULL){
                if(temp->name==x){
                    cout<<endl;
                    cout<<"*********"<<endl;
                    cout<<"Name: "<<temp->name<<endl;
                    cout<<"Phone Number: "<<temp->phonenum<<endl;
                    cout<<"*********"<<endl;
                    cout<<endl;
                    found=true;
                    break;
                }
                temp=temp->next;
            }
            if(found=false){
                cout<<"Name not found"<<endl;
            }
        }else if(command==2){
            cout<<"Enter the Phone Number to search: ";
            cin>>y;
            while(temp!=NULL){
                if(temp->phonenum==y){
                    cout<<endl;
                    cout<<"*********"<<endl;
                    cout<<"Name: "<<temp->name<<endl;
                    cout<<"Phone Number: "<<temp->phonenum<<endl;
                    cout<<"*********"<<endl;
                    cout<<endl;
                    found=true;
                    break;
                }
                temp=temp->next;
            }
            if(found=false){
                cout<<"Phone Number not found"<<endl;
            }
        }else{
            cout<<"Enter valid command";
        }
    }
    void DeleteAllContacts(){
        Node* temp=head;
        Node* temp1;
        if(head=NULL){
            cout<<endl;
            cout<<"Already Contact List is empty"<<endl;
            cout<<"****************"<<endl;
        }else{
            while(temp!=NULL){
                temp1=temp;
                temp=temp->next;
                delete temp1;
            }
            head=NULL;
            cout<<endl;
            cout<<"Successfully Deleted all Contacts"<<endl;
            cout<<"**************"<<endl;
        }
    }

    int DeleteConatctbySearch(){
        Node* temp=head;
        cout<<"************"<<endl;
        cout<<"Press 1 to search by Name: "<<endl;
        cout<<"Press 2 to search by Number: "<<endl;
        int command;
        cout<<"Enter the command: ";
        cin>>command;

        if(command==1){
            bool found=false;
            cout<<"Enter Name to Delete: ";
            cin>>x;
            while(temp!=NULL){
                if(temp->name==x){
                    cout<<"************"<<endl;
                    cout<<"Name: "<<temp->name<<endl;
                    cout<<"Phone Number: "<<temp->phonenum<<endl;
                    found=true;
                    break;
                }
                temp=temp->next;
            }
            if(found==false){
               cout<<"Contact of this Name is not found";
            }else if(found==true){
                if(temp==head){
                    Node* temp1;
                    temp1=temp;
                    temp=temp->next;
                    delete temp1;
                    temp->prev=NULL;
                    head=temp;
                    cout<<"Contact Deleted Successfully!"<<endl;
                }else if(temp->next==NULL){
                    temp->prev->next=NULL;
                    delete temp;
                    cout<<"Contact Deleted Successfully!"<<endl;
                }else{
                    Node* temp1;
                    temp1=temp;
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                    delete temp1;
                    cout<<"Contact Deleted Successfully!"<<endl;
                }
            }
        }else if(command==2){
            bool found=false;
            cout<<"Enter Number to Delete: ";
            cin>>y;
            while(temp!=NULL){
                if(temp->phonenum==y){
                    cout<<endl;
                    cout<<"************"<<endl;
                    cout<<"Name: "<<temp->name<<endl;
                    cout<<"Phone Number: "<<temp->phonenum<<endl;
                    found=true;
                    break;
                }
                temp=temp->next;
            }
            if(found==false){
               cout<<"Contact of this Number is not found";
            }else if(found==true){
                if(temp==head){
                    Node* temp1;
                    temp1=temp;
                    temp=temp->next;
                    delete temp1;
                    temp->prev=NULL;
                    head=temp;
                    cout<<"Contact Deleted Successfully!"<<endl;
                }else if(temp->next==NULL){
                    temp->prev->next=NULL;
                    delete temp;
                    cout<<"Contact Deleted Successfully!"<<endl;
                }else{
                    Node* temp1;
                    temp1=temp;
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                    delete temp1;
                    cout<<"Contact Deleted Successfully!"<<endl;
                }
            }
        }else{
            cout<<"You entered wrong command"<<endl;
        }
    }
    void BubbleSort(){
        Node* temp=head;
        Node *i, *j;
        string n1;
        long int n2;
        if(temp=NULL){
            cout<<"Empty Contact List"<<endl;
        }else{
            for(i=head;i->next!=NULL;i=i->next){
                for(j=i->next;j->next!=NULL;j=j->next){
                    if(i->name>j->name){
                        n1=i->name;
                        i->name=j->name;
                        j->name=n1;

                        n2=i->phonenum;
                        i->phonenum=j->phonenum;
                        j->phonenum=n2;
                    }
                }
            }
        }
    }

    int EditContact(){
        Node* temp=head;
        cout<<endl;
        cout<<"************"<<endl;
        cout<<"Press 1 to search by Name: "<<endl;
        cout<<"Press 2 to search by Number: "<<endl;
        int command;
        cout<<"Enter the command: ";
        cin>>command;

        if(command==1){
            bool found=false;
            cout<<"Enter Name to Edit: ";
            cin>>x;
            while(temp!=NULL){
                if(temp->name==x){
                    
                    cout<<"Name: "<<temp->name<<endl;
                    cout<<"Phone Number: "<<temp->phonenum<<endl;
                    found=true;
                    break;
                }
                temp=temp->next;
            }
            if(found==false){
               cout<<"OOPS! Contact of this Name is not found";
            }else if(found==true){
                cout<<"Enter New Name: "<<endl;
                cin>>x;
                cout<<"Enter New Number: "<<endl;
                cin>>y;

                temp->name=x;
                temp->phonenum=y;
                cout<<"Contact Edited Successfully!"<<endl;
            }
        }else if(command==2){
            bool found=false;
            cout<<"Enter Number to Edit";
            cin>>y;
            while(temp!=NULL){
                if(temp->phonenum==y){
                    cout<<"************"<<endl;
                    cout<<"Name: "<<temp->name<<endl;
                    cout<<"Phone Number: "<<temp->phonenum<<endl;
                    found=true;
                    break;
                }
                temp=temp->next;
            }
            if(found==false){
               cout<<"Contact of this Number is not found";
            }else if(found==true){
                cout<<"Enter New Name: "<<endl;
                cin>>x;
                cout<<"Enter New Number: "<<endl;
                cin>>y;

                temp->name=x;
                temp->phonenum=y;
                cout<<"Contact Edited Successfully!"<<endl;
            }
        }else{
            cout<<"You entered wrong command"<<endl;
        }
    }

    void oflineSave(){
        Node* temp=head;
        ofstream myfile("contactbook.txt");
        if(myfile.is_open()){
            while(temp!=NULL){
                myfile<<temp->name<<endl;
                myfile<<temp->phonenum<<endl;
                temp=temp->next;
            }
            myfile.close();
            Structure();
        }else{
            cout<<"File is empty"<<endl;
        }
    }

      void reopenCB()
		{
			bool isEmpty;
			ifstream myfile ("contactbook.txt");
            if (myfile.is_open() & myfile.peek() != EOF)
            {
                int i=0;
                while(getline(myfile,x))
                {	
                    if(i % 2 == 0)
					{
						if(head==NULL)
	                    {
    	                  Node *newnode= new Node;
                          newnode->name=x;
		         
	                      newnode->next=NULL;
	                      newnode->prev==NULL;
	                      head=newnode;
		                }
						else
						{
							Node *newnode= new Node;
							
							newnode->name=x;
							newnode->next=NULL;
							
							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}
		                	temp->next=newnode;
		                	newnode->prev=temp;		
						} 
                    }
                   else
                    {
                    	Node *temp=head;
                    	if(temp->phonenum==0)
                    	{
                    		
                    		 stringstream convert(x);
			       	         convert>>y;
                             temp->phonenum=y;
						}
						else
						{
							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}
		                	
		                	stringstream convert(x);
			       	        convert>>y;
		                	temp->phonenum=y;
							
						}
                       
				    }
                    i++;
                }
            	myfile.close();
            }
            else
            {
            	cout<<"  File is Empty so Cannot open...Sorry!"<<endl;
			}
		} 

      void Structure(){
        cout<<endl;
        cout<<"************"<<endl;
        cout<<"1. Add Contact"<<endl;
        cout<<"2. Edit the Contact"<<endl;
        cout<<"3. Delete Contact"<<endl;
        cout<<"4. Search Contact"<<endl;
        cout<<"5. Display all Contact"<<endl;
        cout<<"6. Delete all Contact"<<endl;
        cout<<"************"<<endl;
        cout<<endl;

        int command;
        cout<<"Enter the command: ";
        cin>>command;
        
            if(command>=1 && command<=6){
                if(command==1){
                    CreateNode();
                    oflineSave();
                    Structure();
                }else if(command==2){
                    EditContact();
                    oflineSave();
                    Structure();
                }else if(command==3){
                     DeleteConatctbySearch();
                     Structure();
                }else if(command==4){
                    Search();
                    Structure();
                }else if(command==5){
                    Display();
                    Structure();
                }else if(command==6){
                    DeleteAllContacts();
                    Structure();
                }
            }else if(command>=7 && command<=0){
                cout<<"You entered wrong command"<<endl;
                Structure();
            }
        }
        
       
};

int main(){
    NetworkNexus nn;
    nn.reopenCB();
    string k;
    cout<<"What is your Name? ";
    cin>>k;

    cout<<"                                 "<<"-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-"<<endl;
    cout<<"                                         "<<k<<"  WELCOME TO NETWORKNEXUS       "<<endl;
    cout<<"                                 "<<"-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-"<<endl;
    nn.Structure();
    return 0;
}