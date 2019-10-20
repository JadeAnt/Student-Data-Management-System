#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
//#Student Data Management Test System

using namespace std;

void printConsole(string message, bool top, bool bottom);

void welcomeScreen();

void studentLoginPage(string name, string id);

void studentLogin();

void checkGrades(string name, string id, bool login);

void facultyLoginPage();

void addStudent();

int main(){

	welcomeScreen();

	system("pause");
	return 0;
}

void printConsole(string message, bool top, bool bottom) {

	if (top) {
		cout << "+==================================+" << endl;
	}

	cout << "|	" << message << "	|" << endl;


	if (bottom) {
		cout << "+==================================+" << endl;
	}

}

void welcomeScreen() {
	char choice;

	system("CLS");
	printConsole("Welcome User	", true, true);
	printConsole("1. Student Login", false, false);
	printConsole("2. Faculty Login", false, true);

	cout << "Please choose an option to continue (y to exit): "; cin >> choice;

	switch (choice) {

	case '1':
		studentLogin();
	case '2':
		system("CLS");
		facultyLoginPage();
	case 'y':
		exit(1);

	}

}

void checkGrades(string name, string id, bool login) {
	string find, Class;
	int Current_Average = 0, Cumulative_Average = 0;

	ifstream input;

	input.open("StudentData.txt");

	while (input >> find) {
		if (find == name) {
			input >> find;

			if (find == id) {
				input >> Class >> Current_Average >> Cumulative_Average;
				cout << "Name	ID			Class	Current Average	Cumulative Average" << endl;
				cout << name << "	" << id << "		" << Class << "	" << Current_Average << "		" << Cumulative_Average << endl;
				break;
			}
		}
	}

	system("pause");
	if (login) {
		studentLoginPage(name, id);
	}
	else
		facultyLoginPage();
}

void studentLoginPage(string name, string id) {
	char choice;
	string welcome = "Welcome " + name + "	";

	system("CLS");
	printConsole(welcome, true, true);
	printConsole("1. View Grades	", false, true);

	cout << "Please choose an option to continue (y to exit): "; cin >> choice;

	switch (choice) {

	case '1':
		//view grades in file
		checkGrades(name, id, true);
	case 'y':
		exit(1);

	}

}

void studentLogin() {
	string name, ID, find;

	ifstream input;

	cout << "Input name: "; cin >> name;
	cout << "Input ID: "; cin >> ID;

	input.open("StudentData.txt");

	while (input >> find) {
		if (find == name) {
			input >> find;
			if (find == ID) {
				input.close();
				studentLoginPage(name, ID);
			}
		}
	}

	cout << "Incorrect information. Please try again" << endl;
	system("pause");
	welcomeScreen();

}


void facultyLoginPage() {
	char choice;
	int tries = 0;
	string admin, password, name, id;

	while (tries != 3) {
		cout << "Input credentials: "; cin >> admin;
		cout << "Input password: "; cin >> password;

		string welcome = "Welcome ADMIN	";

		if (admin == "admin" && password == "pw12345") {
			system("CLS");

			printConsole(welcome, true, true);
			printConsole("1.View Grades of Student", false, true);
			printConsole("2.Add new Student", false, false);
			printConsole("3. Change Grades", false, true);
			cout << "Please choose an option to continue (y to exit): "; cin >> choice;

			switch (choice) {

			case '1':
				//view grades in file
				cout << "Input name of student to search: "; cin >> name;
				cout << "Input ID of student to search: "; cin >> id;
				checkGrades(name, id, false);
			case '2':
				addStudent();
			case '3':
				//changeGrades();
			case 'y':
				exit(1);

			}
		}
		else {
			tries++;
			cout << "Incorrect Information " << tries << "/3.";

			if (tries == 3) {
				cout << " TOO MANY TRIES. EXITING PROGRAM." << endl;
				exit(1);
			}

			system("pause");
			system("CLS");
		}
	}
}//end of function

void addStudent() {
	cout << "function works" << endl;
	string Name, ID, Class;

	ofstream output;

	output.open("StudentData.txt", ios::app);

	cout << "Input new student name: "; cin >> Name;
	cout << "Input new student ID: "; cin >> ID;
	cout << "Input new student Class: "; cin >> Class;
	int Current_Average = 0, Cumulative_Average = 0;

	if (Name.length() <= 4) {
		output << "\t" << Name << "		\t" << ID << "			" << Class << "		" << Current_Average << "					" << Cumulative_Average << endl;
	}
	else if(Name.length() > 5 && Name.length() < 8){
		output << "\t" << Name << "	\t" << ID << "		\t" << Class << "		" << Current_Average << "					" << Cumulative_Average << endl;
	}
	else{
		output << "\t" << Name << "	\t" << ID << "		\t" << Class << "		" << Current_Average << "					" << Cumulative_Average << endl;
	}
	facultyLoginPage();
}
