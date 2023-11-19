#ifndef REGISTER_H 
#define REGISTER_H

#include<iostream> 
#include<string> 
#include<string.h>
using namespace std;

//****************************
// Course class declaration  * 
//****************************
template <class Temp> class Course
{
	private:
		// Declare a structure for the list
		struct ListNode
		{
			Temp value;
			struct ListNode *next;
		};
		
		ListNode *head;  // List head pointer
			
		int numUnit[7];
		int total;
		string courseName[7];
		
		public:
			// Constructor
			Course() {head = nullptr;}
			
			// Destructor
			~Course();
			
	    void setNumCourse(Temp);
	    
	     // List operations
	    void appendNode(Temp); // to register course
	    void addNode(Temp);    // to add new course
	    void deleteNode(Temp); // to remove the course
	    void displayCourse();  //to display all courses registered
	    
	    void getCourseName();  // to get the name of course by code
	    
	    void setUnit();
	    int TotalUnit();
	    void CGPA();
};

//************************************************** 
// appendNode appends a node containing the value  * 
// pased into newValue, to the end of the list.    * 
//**************************************************
template <class Temp>
void Course<Temp>::appendNode(Temp code)
{
	ListNode *newNode = nullptr; // To point to a new node and set to nullptr
	ListNode *Ptr = nullptr;     // To move through the list and set to nullptr
	
	newNode = new ListNode;
	newNode->value = code;
	newNode->next = nullptr;
	
	// If there are no nodes in the list, make newNode the first node.
	if(!head)
	{
		head = newNode;
	}
	
	// Otherwise, insert newNode at end. 
	else
	{
		// Initialize Ptr to head of list.
		Ptr = head;
		// Find the last node in the list.
		while (Ptr->next)
		{
			Ptr = Ptr->next;
		}
		
		// Insert newNode as the last node.
		Ptr->next = newNode;
	}
	
	this->setUnit();
	this->getCourseName();
	cout << "\n";
}

//************************************************** 
// setUnit set the unit of course registered by    *
// a code.										   * 
//**************************************************
template <class Temp>
void Course<Temp>::setUnit()
{
	ListNode *Ptr = nullptr;
	
	Ptr =  head;
	
	int credit= 0;
	while(Ptr)
	{
		if(Ptr->value == "CPC151"|| Ptr->value == "CPC152"|| Ptr->value == "AKW104"|| Ptr->value == "STU231"|| Ptr->value == "MAA101")
		numUnit[credit] = 4;
		
		else if (Ptr->value == "CPT111" || Ptr->value == "CPT113" || Ptr->value == "CPC351"|| Ptr->value == "CPC352" || Ptr->value == "CMT323")
		numUnit[credit]=3;
		
		else if (Ptr->value == "HFE224"|| Ptr->value == "LKM400"|| Ptr->value == "LSP300"|| Ptr->value == "WUS101")
		numUnit[credit] = 2;
		
		Ptr = Ptr->next;
		credit++;
	}
}

//************************************************** 
// The addNode function inserts a node with.       * 
// newValue copied to its value member.            * 
//**************************************************
template <class Temp>
void Course<Temp>::addNode(Temp newCourse)
{
	ListNode *newNode = nullptr;
	ListNode *Ptr = nullptr;
	ListNode *previousNode = nullptr;
	
	newNode = new ListNode;
	newNode-> value = newCourse;
	newNode->next= nullptr;
	
	// If there are no nodes in the list
   // make newNode the first node
	if(!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	
	// Otherwise, insert newNode
	else
	{
		// Position Ptr at the head of list. 
		Ptr = head;
		
		while(Ptr != nullptr)
		{
			previousNode = Ptr;
			Ptr = Ptr->next;
		}
		
		if(previousNode != nullptr)
		{
			previousNode-> next = newNode;
			newNode->next = Ptr;
		}
	}
	
	this->setUnit();
	this->getCourseName();
	cout << "\n";
}

//***************************************************** 
// The deleteNode function searches for a node        * 
// with searchValue as its value. The node, if found, * 
// is deleted from the list and from memory.          * 
//*****************************************************
template <class Temp>
void Course<Temp>::deleteNode(Temp courseCode)
{
	ListNode *Ptr = nullptr;	// To traverse the list 
	ListNode *previousNode = nullptr;
	
	// If the list is empty, do nothing. 
	if(!head)
		cout<<"Course not found." << endl;
	
	int i=0;
	
	// Determine if the first node is the one.
	if(head->value == courseCode)
	{
		Ptr = head;
		head=head->next;
		numUnit[i] = 0;
		delete Ptr;
	}
	else
	{
		// Initialize Ptr to head of list 
		Ptr = head;
		
		// Skip all nodes whose value member is not equal to courseCode.
		while (Ptr!= nullptr && Ptr->value != courseCode)
		{
			previousNode = Ptr;
			Ptr = Ptr -> next;
			i++;
		}
		
		// If Ptr is not at the end of the list, link the previous node // to the node after nodePtr, then delete nodePtr.
		if (Ptr)
		{
			numUnit[i]= 0;
			previousNode->next = Ptr->next;
			delete Ptr;
		}
		
		else
		{
			cout<< "Course " << courseCode << " cannot be found." << endl;
		}
	}
	
	this->setUnit();
//	cout << "Course Register before: ";
	this->getCourseName();
	cout << "\n";
}

//************************************************** 
// TotalUnit calculate the overall course unit 	   *
// that a student registeredbased 				   *
//**************************************************
template <class Temp>
int Course<Temp>::TotalUnit()
{
	ListNode *Ptr = nullptr;
	
	Ptr = head;
	
	total = 0;
	
	int i = 0;
	while(Ptr != nullptr)
	{
		total += numUnit[i];
		i++;
		
		Ptr = Ptr->next;
	}
	
	return total;
}

//************************************************** 
// displayCourse shows the value stored in each    *
// node of the linked list pointed to by head.     *
// Display all the courses that have been 		   *
// registered by the user    					   *
//**************************************************
template <class Temp>
void Course<Temp>::displayCourse()
{
	ListNode *Ptr = nullptr;
	
	Ptr = head;
	
	int count = 1;
	
	cout << "************************************************************************************" << endl;
	cout << "  #  | Course Code  |                      Course Name                      |  Units" << endl;
	cout << "************************************************************************************" << endl;
	
	while(Ptr)
	{
		cout << "  " << count << "  |    " << Ptr->value << "    |  ";
		cout << courseName[count-1] <<  "    |  ";
		cout << " " << numUnit[count-1] << endl;
		Ptr= Ptr->next;
		count++;
	}
	cout << "\n Total number of credit: " << total << endl;
	
}


//************************************************** 
// getCourseName is to get the name of the course  * 
// based on the code user input                    *
//**************************************************
template <class Temp>
void Course<Temp>::getCourseName()
{
	ListNode *Ptr = nullptr;
	
	Ptr =  head;
	
	int count= 0;
	
	while(Ptr)
	{
		if(Ptr->value == "CPC151")
			courseName[count] = "FUNDAMENTALS OF LOGIC AND ARTIFICIAL INTELLIGENCE";
		else if (Ptr->value == "CPC152")
			courseName[count] = "FOUNDATIONS AND PROGRAMMING FOR DATA ANALYTICS   ";
		else if (Ptr->value == "AKW104")
			courseName[count] = "FINANCE AND ACCOUNTING                           ";
		else if (Ptr->value == "STU231")
			courseName[count] = "FUNDAMENTALS OF PSYCHOLOGY                       ";
		else if (Ptr->value == "MAA101")
			courseName[count] = "CALCULUS FOR SCIENCE STUDENTS                    ";
		else if (Ptr->value == "CPT111")
			courseName[count] = "PRINCIPLES OF PROGRAMMING                        ";
		else if (Ptr->value == "CPT113")
			courseName[count] = "PROGRAMMING METHODOLOGY AND DATA STRUCTURES      ";
		else if (Ptr->value == "CPC351")
			courseName[count] = "PRINCIPLES OF DATA ANALYTICS                     ";
		else if (Ptr->value == "CPC352")
			courseName[count] = "MULTIMEDIA SYSTEMS AND INTERACTION DESIGN        ";
		else if (Ptr->value == "CMT323")
			courseName[count] = "INFORMATION SYSTEMS THEORY AND MANAGEMENT        ";
		else if (Ptr->value == "HFE224")
			courseName[count] = "APPRECIATION OF ETHICS AND CIVILIZATION          ";
		else if (Ptr->value == "LKM400")
			courseName[count] = "BAHASA MALAYSIA IV                               ";
		else if (Ptr->value == "LSP300")
			courseName[count] = "ACADEMIC ENGLISH                                 ";
		else if (Ptr->value == "WUS101")
			courseName[count] = "CORE ENTREPRENEURSHIPS                           ";
		
		Ptr = Ptr->next;
		count++;
		
		cout << courseName[count];
	}
}

//************************************************** 
// CGPA is to calculate a student CGPA last		   *	 
// semester in their study year                    *
//**************************************************
template<class Temp>
void Course<Temp>::CGPA()
{

    cout<<"     Grading System of this UNIVERSITY.........\n"<<endl;
    cout<<" Numerical Scores        Letter Grade        Grade Point\n"<<endl;
    cout<<"     80-100                  A                   4.00"<<endl;
    cout<<"     70-79                   A-                  3.67"<<endl;
    cout<<"     64-69                   B+                  3.33"<<endl;
    cout<<"     58-63                   B                   3.00"<<endl;
    cout<<"     52-57                   B-                  2.67"<<endl;
    cout<<"     46-51                   C+                  2.33"<<endl;
    cout<<"     40-45                   C                   2.00"<<endl;
    cout<<"     36-39                   C-                  1.67"<<endl;
    cout<<"     32-35                   D+                  1.33"<<endl;
    cout<<"     28-31                   D                   1.00"<<endl;
    cout<<"     25-27                   D-                  0.67"<<endl;
    cout<<"    Below 24                 F                   0.00"<<"\n\n"<<endl;

    int number,i,cradit[10];
    char Grade[10][10];
    float sum=0, multiply=0,Summation_Of_Grade_and_Cradit=0,CGPA=0;

    cout << "Enter How many Course You Did In the LasT Semester?..._";
    cin >> number;
    cout<<"\n\n";


    for(i=0; i<number; i++){
        cout<<"Enter "<<i+1<<" Subject Grade:";
        cin>>Grade[i];
        cout<<"\n";
        cout<<"Enter " <<i+1<<" Subject Credit:";
        cin>>cradit[i];
        cout<<"\n";
        if(strcmp(Grade[i],"A")==0||strcmp(Grade[i],"a")==0){
            multiply=(4)*cradit[i];
            Summation_Of_Grade_and_Cradit=Summation_Of_Grade_and_Cradit+multiply;
        }
       else if(strcmp(Grade[i],"A-")==0||strcmp(Grade[i],"a-")==0){
            multiply=(3.67)*cradit[i];
            Summation_Of_Grade_and_Cradit=Summation_Of_Grade_and_Cradit+multiply;
        }
       else if(strcmp(Grade[i],"B+")==0||strcmp(Grade[i],"b+")==0){
            multiply=(3.33)*cradit[i];
            Summation_Of_Grade_and_Cradit=Summation_Of_Grade_and_Cradit+multiply;
        }
        else if(strcmp(Grade[i],"B")==0||strcmp(Grade[i],"b")==0){
            multiply=(3.00)*cradit[i];
            Summation_Of_Grade_and_Cradit=Summation_Of_Grade_and_Cradit+multiply;
        }
        else if(strcmp(Grade[i],"B-")==0||strcmp(Grade[i],"b-")==0){
            multiply=(2.67)*cradit[i];
            Summation_Of_Grade_and_Cradit=Summation_Of_Grade_and_Cradit+multiply;
        }
        else if(strcmp(Grade[i],"C+")==0||strcmp(Grade[i],"c+")==0){
            multiply=(2.33)*cradit[i];
            Summation_Of_Grade_and_Cradit=Summation_Of_Grade_and_Cradit+multiply;
        }
        else if(strcmp(Grade[i],"C")==0||strcmp(Grade[i],"c")==0){
            multiply=(2.00)*cradit[i];
            Summation_Of_Grade_and_Cradit=Summation_Of_Grade_and_Cradit+multiply;
        }
        else if(strcmp(Grade[i],"C-")==0||strcmp(Grade[i],"c-")==0){
            multiply=(1.67)*cradit[i];
            Summation_Of_Grade_and_Cradit=Summation_Of_Grade_and_Cradit+multiply;
        }
        else if(strcmp(Grade[i],"D+")==0||strcmp(Grade[i],"d+")==0){
            multiply=(1.33)*cradit[i];
            Summation_Of_Grade_and_Cradit=Summation_Of_Grade_and_Cradit+multiply;
        }
        else if(strcmp(Grade[i],"D")==0||strcmp(Grade[i],"d")==0){
            multiply=(1.00)*cradit[i];
            Summation_Of_Grade_and_Cradit=Summation_Of_Grade_and_Cradit+multiply;
        }
        else if(strcmp(Grade[i],"D-")==0||strcmp(Grade[i],"d-")==0){
            multiply=(0.67)*cradit[i];
            Summation_Of_Grade_and_Cradit=Summation_Of_Grade_and_Cradit+multiply;
        }
        else if(strcmp(Grade[i],"F")==0||strcmp(Grade[i],"f")==0){
            multiply=(0.00)*cradit[i];
            Summation_Of_Grade_and_Cradit=Summation_Of_Grade_and_Cradit+multiply;
        }
        else{
            cout<<"You are Fail in this Subject OR Something went wrong.!"<<endl;
        }
        sum=sum+cradit[i];
    }

    
    CGPA=float(Summation_Of_Grade_and_Cradit)/sum;
    cout<<"Your CGPA is: "<<CGPA<<"\n\n"<<endl;

    float X=CGPA;

    if(X>=3.80){
        cout<<"WELL DONE.Your Result Is Very Good.\nKeep It Up...\n";
    }
    else if(X>=3.30 && X<3.80){
        cout<<"BrillianT!\n";
    }
    else if(X>=3.00 && X<3.30){
        cout<<"GooD Result...\n";
    }
    else if(X>=2.50 && X<3.00){
        cout<<"Not Enough GOOD.\n";
    }
    else if(X>=2.00 && X<2.50){
        cout<<"Work Hard. You are in DANGER!.\nYou Will be probation, If You Can't Improve Your Results\n";
    }
    else{
        cout<<"WARNING!!!\nYou Are Already In Probation.\n";
    }
}

//************************************************** 
// Destructor                                      * 
// This function deletes every node in the list.   * 
//**************************************************
template<class Temp>
Course<Temp>::~Course()
{
	ListNode *Ptr = nullptr;
	ListNode *nextNode = nullptr;
	
	Ptr = head;
	while(Ptr != nullptr)
	{
		nextNode =  Ptr->next;
		delete Ptr;
		Ptr = nextNode;
	}
}

#endif
