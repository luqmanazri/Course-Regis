

#include<iostream>
#include<string>
#include<fstream>
#include "Register.h"

using namespace std;

void login();  // function for login
void forgot(); // function if forgot password
void studentInfo(); //function for student information
void courseInfo(); // function for display course information
void menu(); // function for registeration course


//*******************************************************************
// Function main   													*
//*******************************************************************

int main()
{
	int ch; // to hold choice
	cout<<"************************************************************"<< endl;
	cout<<"                   WELCOME TO LOGIN PAGE" << endl;
	cout<<"************************************************************"<< endl;
	cout<< "MENU: " << endl;
	cout <<"1. Login" << endl;
	cout<< "2. Forgot username or password" << endl;
	cout <<"3. Exit" << endl;
	cout << "Enter your choice: " << endl;
	cin >> ch;
	cout << endl;
	
	switch(ch)
	{
		case 1: //student log in
			login();
			break;
	
		case 2:
			forgot(); // forgot password
			break;
			
		case 3: // exit
			system("cls");
			break;
			
		default:
			system("cls");
		    cout <<"You have made a mistake, Please try again." << endl;
		    main();
	}
	
	return 0;
}


//********************************************************
// Function login.                         				 *
// To log in the registration system page.         		 *
//********************************************************
void login() //function login
{
	int count;
	string user, // to hold user's username
		   pass, // to hold user's password
		   u, // username
		   p; //password
			   
	system("cls");
	cout<<"Please enter the following details: " << endl;
	cout<<"Username: ";
	cin>> user;
	cout<<"Password: ";
	cin>> pass;
		
	ifstream myFile("studentlog.txt"); // declare and open the text file
	
	while(myFile>>u>>p)
	{
		if(u == user && p == pass)
		{
			count = 1;
			system("cls");
		}
	}
		
		
	myFile.close(); // close the file
		
	if(count == 1)
	{
		cout<<"Hello " << user << " LOGIN SUCCESSFUL\n";
		cin.get();
		studentInfo(); // function call studentInfo()
		menu(); //function call menu()
	}
		
	else
	{
		cout<<"\nLOGIN ERROR!!!\nPlease check your username and password." << endl;
		main(); // function call main()
	}
		
}
	

//********************************************************
// Function forgot.                         			 *
// To help the user get it's own password for 			 *
// registration.         		 						 *
//********************************************************
void forgot() //function for forgot password
{
	system("cls");
	cout << "Forgotten? We're here to help." << endl;

	int count = 0;
	string searchUser, // hold remembered username
	       su, // hold username from file
		   sp; // hold password from file
	cout << " Enter your remembered username: " ;
	cin >> searchUser;
			
	ifstream search("studentlog.txt"); // read file
	
	while(search>>su>>sp)
	{
		if(su == searchUser)
		{
			count = 1;
						
		}
				
	}
	
	search.close(); // close file
	
	if(count == 1)
	{
		cout<<"Account found!" << endl;
		cout<<"Here is your password: " << sp <<endl;
		cout<<"Please try to login again."<< endl;
		cin.get();
		cout<< endl;
		main(); //function call main
	}

	else
	{
		cout<<"Sorry, your Id is not found in our data." << endl;
		cin.get();
		main(); //function call main
	}
			

}

//********************************************************
// Function studentInfo.                                 *
// Read text file with all the student's information and *
// displays all the student information.         		 *
//********************************************************
void studentInfo() //function for student info
{
	string name; // to hold name
	string gender; // to hold gender
	int matricNumber; // to hold matric number
	int semester; // to hold semester
	
	ifstream myFile("StudentInfo.txt"); // to open file
		
	while (myFile)  
	{
		// read file
		getline(myFile, name, '\t');
		getline(myFile, gender, '\t');
		myFile >> matricNumber;
		myFile >> semester;
		myFile.ignore();
		
		// display the student information    	
		cout << "\nSTUDENT INFORMATION" << endl << endl;
		    	
		cout << "Name :" << name <<endl;
		cout << "Gender :" << gender <<endl;
		cout << "Matric Number :" << matricNumber <<endl;
		cout << "Semester Registered :" << semester <<endl;
	
	}
		
	myFile.close(); // close the file
}

//********************************************************
// Function courseInfo.                          		 *
// Displays all courses that can be registered by 		 *
// a student.         		 							 *
//********************************************************
void courseInfo()
{
	cout << "**********************************************************" << endl;
	cout << "            COURSE LIST FOR REGISTERATION" << endl;
	cout << "**********************************************************" << endl;
	
	cout<<"|----------------------------------------------------------------------------|"<<endl;
    cout<<"|                                 Course                                     |"<<endl;
    cout<<"|                                (Credit)                                    |"<<endl;
    cout<<"|----------------------------------------------------------------------------|"<<endl;
    cout<<"|----------------------------------------------------------------------------|"<<endl;
    cout<<"|     Unit : T    |     Unit : E       |     Unit : M     |     Unit : U     |"<<endl;
    cout<<"|-----------------|--------------------|------------------|------------------|"<<endl;
    cout<<"|  CPT111         |  CPC351            |  AKW104          |  LKM400          |"<<endl;
    cout<<"|  PRINCIPLES OF  |  PRINCIPLES OF     |  FINANCE AND     |  BAHASA          |"<<endl;
    cout<<"|  PROGRAMMING    |  DATA ANALYTICS    |  ACCOUNTING      |  MALAYSIA IV     |"<<endl;
    cout<<"|  (3)            |  (3)               |  (4)             |  (2)             |"<<endl;
    cout<<"|-----------------|--------------------|------------------|----------------- |"<<endl;
    cout<<"|  CPT113         |  CPC352            |  STU231          |  HFE224          |"<<endl;
    cout<<"|  PROGRAMMING    |  MULTIMEDIA        |  FUNDAMENTALS OF |  APPRECIATION OF |"<<endl;
    cout<<"|  METHODOLOGY AND|  SYSTEMS AND       |  PSYCHOLOGY      |  ETHICS AND      |"<<endl;
    cout<<"|  DATA STRUCTURES|  INTERACTION DESIGN|  (4)             |  CIVILIZATION    |"<<endl;
    cout<<"|  (3)            |  (3)               |                  |  (2)             |"<<endl;
    cout<<"|-----------------|--------------------|------------------|------------------|"<<endl;
    cout<<"|  CPC151         |  CMT323            |  MAA101          |  LSP300          |"<<endl;
    cout<<"|  FUNDAMENTALS OF|  INFORMATION SYSTEM|  CALCULUS FOR(3) |  ACADEMIC        |"<<endl;
    cout<<"|  LOGIC AND      |  THEORY AND        |  SCIENCE STUDENTS|  ENGLISH         |"<<endl;
    cout<<"|  ARTIFICIAL     |  MANAGEMENTMAT     |  (4)             |  (2)             |"<<endl;
    cout<<"|  INTELLIGENCE   |  (3)               |                  |                  |"<<endl;
    cout<<"|  (4)            |                    |                  |                  |"<<endl;
    cout<<"|-----------------|--------------------|------------------|------------------|"<<endl;
    cout<<"|  CPC152         |                    |                  |  WUS101          |"<<endl;
    cout<<"|  FOUNDATIONS AND|                    |                  |  CORE            |"<<endl;
    cout<<"|  PROGRAMMING FOR|                    |                  |  ENTREPRENEURSHIP|"<<endl;
    cout<<"|  DATA ANALYTICS |                    |                  |  (2)             |"<<endl;
    cout<<"|  (4)            |                    |                  |                  |"<<endl;
    cout<<"|----------------------------------------------------------------------------|"<<endl;
}

//********************************************************
// Function menu.                          				 *
// Displays menu for registration process.         		 *
//********************************************************
void menu() 
{	
	Course<string> Courses; // Courses as object type class Course 
	string code; // to hold course's code
	int choice; // to hold user choice
	int numcourse; // to hold number of course registered
	
	do
	{
		cout<<"************************************************************"<< endl;
	    cout<<"          COMPUTER SCIENCES COURSE REGISTERATION" << endl;
	    cout<<"************************************************************"<< endl;
		cout << "\nMENU: " << endl;
		cout << "1. Register Course" << endl;
		cout << "2. Add New Course." << endl;
		cout << "3. Delete Course." << endl;
		cout << "4. Display Register Courses." << endl;
		cout << "5. CGPA calculator." << endl;
		cout << "6. Exit." << endl;
		cout<<"\t Please enter your choice (1-6)\n";
		cin >> choice;
		
		switch(choice)
		{
			case 1: // for course registeration
				system("cls");
				courseInfo();
			    cout << "Enter number of courses you want to register.";
	 			cin>> numcourse;
		
				while (numcourse < 1 || numcourse > 7)
				{
					cout<< "Error! You only can register 1-7 courses for this semester" << endl;
					cout<< "Enter number of courses you want to register: ";
					cin>>numcourse;
				}
	
				for (int count = 0; count<numcourse ; count++)
				{
					cout<< "Enter the course code: ";
					cin>> code;
					Courses.appendNode(code);
		     	}
				break;
			
			case 2: // add new course
				system("cls");
				courseInfo();
				cout << "Enter the new course code you want to add: ";
				cin >> code;
				Courses.addNode(code);
				break;
			
			case 3: // remove course by the code
				system("cls");
				cout<< "Enter the course code you want to remove: ";
				cin>> code;
				Courses.deleteNode(code);		
				break;
			
			case 4: // display registered courses
				system("cls");
				Courses.TotalUnit();
				Courses.displayCourse();
				break;
				
			case 5:  //calculate student CGPA
	       		Courses.CGPA();
            	break;
				
			case 6: // exit
				break;
			
			default: // wrong user input
				cout << "\n\n\n Invalid Choice...Please Try Again." << endl;
				
		}
		
	}
	
	while(choice != 6);
	cout << "End Program.";

}

