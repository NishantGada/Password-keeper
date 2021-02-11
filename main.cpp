#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

// function declaration
void addPassword();
void authentication();
void view();
void searchPassword();
void choices();
void end();

// global variables
string admin_name, admin_password, password, password_title; 
bool admin;
int choice;

int main() {
	system("cls");
	cout << "\n! Passwork Keeper !\n";

	authentication();
	
	choices();	
	
	return 0;
}

void authentication() {
	
	cout << "\nEnter admin name : ";
	cin >> admin_name;
	cout << "Enter admin password : ";
	cin >> admin_password;
	
	if (admin_name == "Nishant") {
		if (admin_password == "admin") {
			system("cls");
			cout << "\n\nWelcome " << admin_name;
			admin = true;
		}
		else {
			cout << "Incorrect admin name / password\n\n";
			admin = false;
			authentication();
		}
	}
	else {
		cout << "Incorrect admin name / password 2\n\n";
		admin = false;
		authentication();
	}
}

void addPassword() {
	
	ofstream passwords("Passwords.txt", ios::app);
	
	system("cls");
	cout << "Please add a password:- \n\n";
	cout << "please separate different words with '_' \n\n";
	cout << "Enter password title : ";
	cin >> password_title;
	cout << "Enter password : ";
	cin >> password;
	
	if (passwords.is_open()) {
		passwords << password_title << " " << password << endl;
		cout << "\n\nPassword successfully added !!\n\n";
		
		choices();	
	}
	else {
		cout << "\nError saving password, please try again ...";
		choices();
	}
}

void choices() {
	if (admin == true) {
		cout << "\n\n\nPlease Choose:- \n\n1. Add password\n2. View all passwords\n3. Search for a password\n4. Logout\n\nChoice = ";
		cin >> choice;
		
		switch(choice) {
			case 1: addPassword(); break;
			case 2: view(); break;
			case 3: searchPassword(); break;
			case 4: end(); break;
			default: cout << "\n\nInvalid choice"; choices(); break;
		}
	}
	else {
		cout << "Something is wrong . . . ";
	}
}

void searchPassword() {
	system("cls");
	cout << "\n\nSearch here . . . \n\n";
	
	bool pass = false;
	
	ifstream passwords("Passwords.txt");
	
	string keyword;
	cout << "Password title you are looking for : ";
	cin >> keyword;
	
	while (passwords >> password_title >> password) {
		if (keyword == password_title) 
		{	
			cout << "\n\nThere you go:- \n\n";
			cout << "Password title : " << password_title;
			cout << "\nPassword : " << password;
			pass = true;
			choices();
		}
	}
	
	if (pass == false) {
		cout << "\n\nPassword not found . . . ";
		choices();
	}
}

void view() {
	system("cls");
	
	ifstream passwords("Passwords.txt");
	
	if (password_title.length() == 0) {
		cout << "\nNo passwords saved";
	}
	
	else {
		cout << "\nYour passwords " << admin_name << "\n\n";
	
		while (passwords >> password_title >> password) {
			
			cout << "\nTitle : ";
			for (int i=0; i<password_title.length(); i++) {
				cout << password_title[i];
			}
			cout << "\n";
			
			cout << "Password : ";
			for (int j=0; j<password.length(); j++) {
				cout << password[j];
			}
			cout << "\n";
		}
	}
	
	
	choices();
	
}

void end() {
	system("cls");
	cout << "\nClosing password keeper..\nThank You\n\nPress any key to continue .. ";
	exit(1);
}










