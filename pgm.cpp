#include<iostream>
#include<cstring>
#include<fstream>
#include<vector>
#include<algorithm>
#define infinity 999999999

using namespace std;
class filehandlingmodule{
	public:
	string username1,password1;
    
	bool login_user(string username,string password){
		ifstream fileread;
		fileread.open("login.txt");
		while(fileread>>username1>>password1){
			if((username==username1)&&(password==password1)){
				cout<<endl<<"                 Account Login Successful..."<<endl;
				return true;
			}
		}
		cout<<endl<<"                 Account Login Failed..."<<endl;
		return false;
	 }
	void createaccount(string username,string password){
		ofstream filewrite;
		filewrite.open("login.txt",ios::app);
		filewrite<<username<<" "<<password<<"\n";
		filewrite.close();
		cout<<endl<<"                 Account Created ..."<<endl;
	}
	void ticket(string username,string firstname[],string lastname[],string sex[],int age[],int no){
		ofstream filewrite;
		filewrite.open("ticket.txt",ios::app);
		for(int i=0;i<no;i++){
			filewrite<<username<<" "<<firstname[i]<<" "<<lastname[i]<<" "<<sex[i]<<" "<<age[i]<<"\n";
		}
		filewrite.close();
	}
};

class inputmodule{
	public:
	string source,destination;
	string username,password;
	void user_input(string userchoice[]){
		//system("CLS");
		cout<<"------------------------------------------------------------------------";
					cout<<"\n\n                      Welcome to Flight Management System      "<<endl;
                    cout<<"------------------------------------------------------------------------";
		cout<<endl;
		cout<<"                 *****"<<endl;
		cout<<"                 Enter Your City:";
		cin>>source;
		cout<<"                 *****"<<endl;
		cout<<"                 Enter Your Destination:";
		cin>>destination;
		cout<<"                 *****"<<endl;
		userchoice[0]=source;
		userchoice[1]=destination;
	}
	string login(){
		while(1){
		cout<<"------------------------------------------------------------------------";
					cout<<"\n\n                      Welcome to Flight Management System      "<<endl;
                    cout<<"------------------------------------------------------------------------";
		cout<<"\n\n\n\n";
		cout<<"                 ENTER                     "<<endl;
		//cout<<"                 *****"<<endl;
		cout<<"                 1. To Login                  "<<endl;
		//cout<<"                 *****"<<endl;
		cout<<"                 2. To Create New Account     "<<endl;
		//cout<<"                 *****"<<endl;
		cout<<"\n                Enter Your Choice:";
		int ch;
		bool res;
			filehandlingmodule fobj;
			cin>>ch;
			 switch(ch){
				case 1:
					cout<<"------------------------------------------------------------------------";
					cout<<"\n\n                      Welcome to Flight Management System      "<<endl;
                    cout<<"------------------------------------------------------------------------";
					cout<<endl;
					
					cout<<"                 Enter Username:";
					cin>>username;
					
					cout<<"                 Enter Your Password:";
					cin>>password;
					
					res=fobj.login_user(username,password);
					break;
				case 2:
				
					cout<<"------------------------------------------------------------------------";
					cout<<"\n\n                      Welcome to Flight Management System      "<<endl;
                    cout<<"------------------------------------------------------------------------";
					
					cout<<endl;
					
					cout<<"                 Enter Username:";
					cin>>username;
					
					cout<<"                 Enter Your Password:";
					cin>>password;
					cout<<"                 *****"<<endl;
					fobj.createaccount(username,password);
					break;
			}
			if(res==true)
				return username;
		}
	}
	int noofpassenger(){
		int no;
		cout<<endl<<"                 Enter the no of passengers:";
		cin>>no;
		return no;
	}
};

struct flight
{
    char* name;
	long long int cost[20];
	//int array[20];
    int tim[100], known[100], path[100], array[100];
    int arra[100];
	//int cost[100];
}travel[15];

struct initialdata{
	long long int cost[20];
	long long int tim[100];
}ini[15];
class init2{
	public:
	string city[5] = {"Delhi","Mumbai","Chennai","Kolkata","Kerala"};
	
	void costdeclaration(){
		int N,i,j;
		N=5;
		
		//Ten different major cities are considered

		//The cost of travelling between any two cities in direct flight is initialized. In further steps the minimum fare will be calculated

		long long int arr[5][5]={{0, 3500, 2000, infinity, 1000},
							   {3500, 0, infinity, 1520, infinity},
							   {2000, infinity, 0, 1500, infinity},
							   {infinity, infinity, 3000, 1200, 1500},
							   {infinity, 2500, infinity, infinity, infinity}};;

	//the main array i.e. arr is not changed. Instead, the values are copied to structure and then the structure store with data member cost is changed. The structure store will hold the
	//minimum possible fare between any origin and destination

		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				travel[i].cost[j]=arr[i][j];
				travel[i].array[j]=j;
				ini[i].cost[j]=arr[i][j];
			}
		}
	}
};

class bmf2:public init2{
	public:
	int N,i,j,k;
	bmf2(){
		N=5;
	}
	void algo(){
	
		//3 different loops are executed
	
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				for(k=0;k<N;k++){
					if(travel[i].cost[j]>travel[i].cost[k]+travel[k].cost[j])
					{
					
						travel[i].cost[j]=travel[i].cost[k]+travel[k].cost[j];
						travel[i].array[j]=k;
					}
				}
			}
		}
	}
};
int p;

int display_price2()
{
        int N=5;
        string source,destination;
		cout<<"                 "<<endl;
		cout<<"                 Enter Your City:";
		cin>>source;
		cout<<"                 "<<endl;
		cout<<"                 Enter Your Destination:";
		cin>>destination;
		cout<<"                 "<<endl;
		init2 o;
		//inputmodule in;
		int i,j,choiceofpassenger;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(source==o.city[i] && destination==o.city[j]){
					cout<<endl;
					if(ini[i].cost[j]==infinity){
						cout<<"                 There is no direct flight from "<<source<<" to "<<destination<<". So, Travel via other cities is only possible."<<endl;
						cout<<"                 The Price is:"<<travel[i].cost[j]<<endl<<endl;
						cout<<"					The Route is:"<<source;
                        p=travel[i].cost[j];
						int c1=i,c2=j;
						while(c1!=c2){
							cout<<"-->"<<o.city[travel[c1].array[j]];
							c1=travel[c1].array[j];
						}
						cout<<endl<<endl;
					}
					else if((ini[i].cost[j]!=infinity)&&(ini[i].cost[j]==travel[i].cost[j])){
						cout<<"                 There is direct flight available from "<<source<<" to "<<destination<<" . And,it is cheapest among all other paths..."<<endl;
						cout<<"                 The Price is:"<<travel[i].cost[j]<<endl;
                        p=travel[i].cost[j];
					}
					else if((ini[i].cost[j]!=infinity)&&(ini[i].cost[j]>travel[i].cost[j])){
						cout<<"                 There is direct flight available from "<<source<<" to "<<destination<<" ."<<endl;
						cout<<"                 The Price is:"<<ini[i].cost[j]<<endl<<endl;
						cout<<"                 *****************************************"<<endl<<endl;
						cout<<"                 You can go via other cities that will cost you less than direct flight."<<endl;
						cout<<"                 The Price is:"<<travel[i].cost[j]<<endl<<endl;
						cout<<"					The Route is:"<<source;
						int c1=i,c2=j;
						while(c1!=c2){
							cout<<"-->"<<o.city[travel[c1].array[j]];
							c1=travel[c1].array[j];
						}
						cout<<endl<<endl;
						cout<<"                 Press 1 to go by direct flight and Press 2 to go via other cities: ";
						cin>>choiceofpassenger;
					}
					/*char c;
					cout<<endl;
					cout<<"                 Do You want to Continue(Y/N)?";
					cin>>c;
					if(c=='Y'){
						/*int no;
						string firstname[no],lastname[no],sex[no];
						int age[no];
						for(int i=0;i<no;i++){
							cout<<endl;
							cout<<"                 *****************************************"<<endl;
							cout<<"                 Passenger "<<(i+1)<<":"<<endl<<endl;
							cout<<"                 First Name:";
							cin>>firstname[i];
							cout<<endl<<"                 Last Name:";
							cin>>lastname[i];
							cout<<endl<<"                 Sex(Male/Female/Other):";
							cin>>sex[i];
							cout<<endl<<"                 Age:";
							cin>>age[i];
						}
						int total_price;
						if(choiceofpassenger==1){
							total_price=no*ini[i].cost[j];
						}
						else{
							total_price=no*travel[i].cost[j];
						}
						cout<<endl<<"                 The total Price is:"<<total_price<<endl;
						char y;
						cout<<"                 Do You want to confirm Your Ticket(Y/N)?";
						cin>>y;
						if(y=='Y'){
							filehandlingmodule f;
							f.ticket(username,firstname,lastname,sex,age,no);
							ticket(total_price,no,source,destination,username);
							passengerdetailedticket(no,firstname,lastname,sex,age);
						}
						else{
							cout<<endl<<"                 Thank You For choosing Us...";
							cout<<endl<<"                 Do You Want to Continue(Y/N)?";
							char ch;
							cin>>ch;
							if(ch=='Y'){
								initial();
							}
						return 0;
						}
					}
					else{
						cout<<endl<<"                 Thank You For choosing Us...";
						cout<<endl<<"                 Do You Want to Continue(Y/N)?";
						char ch;
						cin>>ch;
						if(ch=='Y'){
							initial();
						}
					}*/
					return 0;
				}
			}
		}
		cout<<"                 Sorry, There are no flights available connecting the cities..."<<endl;
		cout<<endl<<"                 Do You Want to Continue(Y/N)?";
		char ch;
		cin>>ch;
		if(ch=='Y'){
			//initial();
            display_price2();
		}
		return 0;
	}






class init{
	public:
	string city[5] = {"Delhi","Mumbai","Chennai","Kolkata","Kerala"};
	void Print()
	{
		cout<<"                 Cities List:\n";
		
		for(int i=0;i<5;i++)
		{
			cout<<"                 "<<city[i]<<"\n";
		}
	}
	
	void costdeclaration(){
		int N,i,j;
		N=5;
		
		//Ten different major cities are considered

		//The cost of travelling between any two cities in direct flight is initialized. In further steps the minimum fare will be calculated

		long long int arr[5][5]={{0, 3500, 2000, infinity, 1000},
							   {3500, 0, infinity, 1520, infinity},
							   {2000, infinity, 0, 1500, infinity},
							   {infinity, infinity, 3000, 1200, 1500},
							   {infinity, 2500, infinity, infinity, infinity}};;
       long long int ar[5][5]={{0, 350, 200, infinity, 100},
							   {350, 0, infinity, 152, infinity},
							   {200, infinity, 0, 150, infinity},
							   {infinity, infinity, 300, 120, 150},
							   {infinity, 250, infinity, infinity, infinity}};;
	//the main array i.e. arr is not changed. Instead, the values are copied to structure and then the structure store with data member cost is changed. The structure store will hold the
	//minimum possible fare between any origin and destination

		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				travel[i].cost[j]=arr[i][j];
				travel[i].array[j]=j;
				ini[i].cost[j]=arr[i][j];
			}
		}
		
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				travel[i].tim[j]=ar[i][j];
				travel[i].arra[j]=j;
				ini[i].tim[j]=ar[i][j];
			}
		}
	}
};

class bmf:public init{
	public:
	int N,i,j,k;
	bmf(){
		N=5;
	}
	void algo(){
	
		
	
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				for(k=0;k<N;k++){
					if(travel[i].tim[j]>travel[i].tim[k]+travel[k].tim[j])
					{
						//if low fare is found for the same origin and destination, the minimum possible fare is changed.
					
						travel[i].cost[j]=travel[i].cost[k]+travel[k].cost[j];
						travel[i].array[j]=k;
						travel[i].tim[j]=travel[i].tim[k]+travel[k].tim[j];
						travel[i].arra[j]=k;
					}
				}
			}
		}
	}
};

int T=0;

int display_price()
{
        int N=5;
        string source,destination;
		cout<<"                 "<<endl;
		cout<<"                 Enter Your City:";
		cin>>source;
		cout<<"                 "<<endl;
		cout<<"                 Enter Your Destination:";
		cin>>destination;
		cout<<"                 "<<endl;
		init o;
		
		int i,j,choiceofpassenger;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(source==o.city[i] && destination==o.city[j]){
					cout<<endl;
					if(ini[i].cost[j]==infinity){
						cout<<"                 There is no direct flight from "<<source<<" to "<<destination<<". So, Travel via other cities is only possible."<<endl;
						cout<<"                 The Price is:"<<travel[i].cost[j]<<endl<<endl;
						cout<<"                 The Time is:"<<travel[i].tim[j]<<" Mins"<<endl<<endl;
						cout<<"					The Route is:"<<source;
						p=travel[i].cost[j];
                         T=travel[i].tim[j];
						int c1=i,c2=j;
						while(c1!=c2){
							cout<<"-->"<<o.city[travel[c1].array[j]];
							c1=travel[c1].array[j];
						}
						cout<<endl<<endl;
					}
					else if((ini[i].cost[j]!=infinity)&&(ini[i].cost[j]==travel[i].cost[j])){
						cout<<"                 There is direct flight available from "<<source<<" to "<<destination<<" . And,it is cheapest among all other paths..."<<endl;
						cout<<"                 The Time is:"<<travel[i].tim[j]<<" Mins"<<endl<<endl;
						cout<<"                 The Price is:"<<travel[i].cost[j]<<endl;
						p=travel[i].cost[j];
                        T=travel[i].tim[j];
					}
					else if((ini[i].cost[j]!=infinity)&&(ini[i].cost[j]>travel[i].cost[j])){
						cout<<"                 There is direct flight available from "<<source<<" to "<<destination<<" ."<<endl;
						cout<<"                 The Price is:"<<ini[i].cost[j]<<endl<<endl;
						cout<<"                 The Time is:"<<travel[i].tim[j]<<" Mins"<<endl<<endl;
						cout<<"                 ***************"<<endl<<endl;
						
						cout<<"                 You can go via other cities that will cost you less than direct flight."<<endl;
						cout<<"                 The Price is:"<<travel[i].cost[j]<<endl<<endl;
						cout<<"                 The Time is:"<<travel[i].tim[j]<<" Mins"<<endl<<endl;
						cout<<"					The Route is:"<<source;
                         T=travel[i].tim[j];
						int c1=i,c2=j;
						while(c1!=c2){
							cout<<"-->"<<o.city[travel[c1].array[j]];
							c1=travel[c1].array[j];
						}
						cout<<endl<<endl;
						cout<<"                 Press 1 to go by direct flight and Press 2 to go via other cities: ";
						cin>>choiceofpassenger;
					}
					
	
					return 0;
				}
			}
		}
		cout<<"                 Sorry, There are no flights available connecting the cities..."<<endl;
		cout<<endl<<"                 Do You Want to Continue(Y/N)?";
		char ch;
		cin>>ch;
		if(ch=='Y'){
			display_price();
		}
		return 0;
	}
	void book(){
		
		cout<<"                 Enter Number of passengers! ";
		int no;
		cin>>no;
						string firstname[no],lastname[no],sex[no];
						int age[no];
						ofstream filep;
						filep.open("passenger.txt",ios::app);
						
						for(int i=0;i<no;i++){
							cout<<endl;
							cout<<"------------------------------------------------------------------------\n";
							cout<<"                 Passenger "<<(i+1)<<":"<<endl<<endl;
							cout<<"                 First Name:";
							cin>>firstname[i];filep<<firstname[i]<<"\n";
							cout<<endl<<"                 Last Name:";
							cin>>lastname[i];filep<<lastname[i]<<"\n";
							cout<<endl<<"                 Sex(Male/Female/Other):";
							cin>>sex[i];filep<<sex[i]<<"\n";
							cout<<endl<<"                 Age:";
							cin>>age[i];filep<<age[i]<<"\n";
						}
						int tp;
						cout<<"------------------------------------------------------------------------\n";
						cout<<"                 Final price is "<<no*p<<" Rs\n";
                        if(T!=0)
                        cout<<"                 Time is "<<T<<" Mins\n";
						cout<<"                 Successfully Booked! Thank you for choosing us! \n";

						tp=no*p;
						filep<<tp<<"\n";

						filep.close();
						



	}

int main()
{
int N;
	N=5;
	
	
		string userchoice[2];
		inputmodule obj1;
	
		string username;
		username=obj1.login();
	
	init obj;
	obj.costdeclaration();
    init2 obj22;
    obj22.costdeclaration();
	
	
	
	
	
	
	init objj;
    int op;
	while(1){ 
		int choice;
cout<<"------------------------------------------------------------------------\n";		              cout<<"                 Enter 1 to view the cities list \n";
		cout<<"                 Enter 2 to book ticket\n";
		cout<<"                 Enter Your Choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				objj.Print();
				cout<<"\n\n                 Press 1 to Continue...";
				int cont;
				cin>>cont;
				
				break;
			case 2:
				
				{//display_price();
				int ch;
				cout<<"                 enter 1 to continue to book ticket ";
				cin>>ch;
                
				if(ch==1)
				{
					cout<<"                 Enter 1 to minimize cost and 2 to reduce time ";cin>>op;
                    if(op==2)
                    {
                        bmf ob;
	                    ob.algo();
                         display_price();
                         book();
                        
                    }
                    else if(op==1)
                    {
                        bmf2 ob2;
                        ob2.algo();
                        display_price2();
                        book();
                        
                    }
                   
				}
				break;}
		}
	}
display_price();    
return 0;
}