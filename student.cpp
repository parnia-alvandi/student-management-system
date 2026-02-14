#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;


struct Student
{
	char name[50];
	char lname[50];
	string password;
	double gpa;
} student;


void Add() {
	ofstream myfile("students.txt", ios::app);
	if(!myfile) {
		cout <<"\t\t\t can not open file"<<endl;
	return;
	}

	cout <<"\t\t\t Enter student password: ";
	cin >>student.password;
	myfile <<"\t\t\t Password : " <<student.password <<endl;

	Student student;
	
	cout <<"\t\t\t Enter student name: ";
	cin >>student.name;
	myfile <<"\t\t\t Name : " <<student.name <<endl;

	cout <<"\t\t\t Enter student last name: ";
	cin >>student.lname;
	myfile <<"\t\t\t Last name : " <<student.lname <<endl;

	cout <<"\t\t\t Enter the student's grade point avrage: ";
	cin >>student.gpa;
	myfile <<"\t\t\t Gpa : " <<student.gpa <<endl;
	cout <<"\t\t\t -*-*-*-*-*-";
	cout << "\n\n";

	myfile.close();
}



void Display() {
	
    ifstream myfile("students.txt");
    if (!myfile) {
        cout << "\t\t\t Can not open file" << endl;
        return;
    }

    string line;
    while (getline(myfile, line)) {
        cout << line << endl;
    }

    myfile.close();
    
}



void Search(string password) {
    
    ifstream myfile("students.txt");
    if (!myfile) {
        cout << "\t\t\t Can not open file" << endl;
        return;
    }
    
	string line;
   	int lineNumber = 0;
   	int targetline = -1;
    
    
   	while (getline(myfile, line)) {
   		lineNumber ++;
   		if(line.find(password) != string::npos) {
   			targetline = lineNumber;
   			break;
		   }
	   }
	   
	   if (targetline != -1) {
	   	cout << "\t\t\t student found!\n";
	   	cout << endl;
	   	cout << line << endl;
	   	
	   	for (int i=0; i<3 ; i++) {
	   		if (getline(myfile, line)) {
	   			cout << line << endl;
			   }
		   }
	   }
	   else 
	   {
	   	cout << "\t\t\t student not found" << endl;
	   }
    
    myfile.close();
    
}



void Delete() {
	
    string student_password;
    cout << "\t\t\t Enter the password of the student you want to delete: ";
    cin >> student_password;

    ifstream infile("students.txt");
    ofstream outfile("temp.txt");

    bool found = false;
    string line;
    
    while (getline(infile, line)) {
        size_t pos = line.find("Password : ");
        if (pos != string::npos) {
            string password = line.substr(pos + 11);
            if (password == student_password) {
                found = true;
                for (int i = 0; i < 3; i++) { 
                    getline(infile, line);
                }
                
                cout << "\t\t\t Student deleted successfully!" << endl;
                cout << endl;
                cout << "\t\t\t Thanks for using this software :)";
                
            }else {
                outfile << line << endl;
            }
        } else {
            outfile << line << endl;
        }
    }

    infile.close();
    outfile.close();

    if (found) {
        remove("students.txt");
        rename("temp.txt", "students.txt");
    } else {
        remove("temp.txt");
        cout << "\t\t\t Student not found!" << endl;
    }
    
}


int main() {

	int choice;
	
	cout << "\n\n\t\t\t\t\t\t ***STUDENTS INFORMATION***";
	cout << "\n\n";
	cout << "\n\n";
		
	do{
		cout <<"\n\t\t\t 1.add a new student\
		\t\t\t 2.display all students\
		\t\t\t 3.search for student\
		\t\t\t 4.delete a student\n";
		
		cout << "\n\n";
		cout << "\n\n";
		cout <<"\t\t\t Select your choice :=>";
		
		cin >> choice;

		switch(choice) {
			
			case 1:
   				Add();
				break;

			case 2:
				Display();
				break;
	
			case 3:
				cout << "\t\t\t Enter student password :";
				cin >> student.password;
				Search(student.password);
				cout << endl;
				break;
				

			case 4:
				Delete();
				break;
	
		}

	}while(choice != 4);

	return 0;

}
