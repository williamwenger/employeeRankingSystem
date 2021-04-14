#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Employee.h"

using namespace std;


void join(string name, vector<Employee*> &Employees);
void quit(string name, vector<Employee*> &Employees);
void promote(string name, vector<Employee*>& Employees);
void demote(string name, vector<Employee*>& Employees);
bool compare(int rank, int rank2);

//Function join adds employee to vector with a rank of 1
void join(string name, vector<Employee*> &Employees) {
	int rank = 1;
	Employee *emp = new Employee(name, rank); //Employee object created with name inputted and a rank of 1
	if (!Employees.empty()) {
		for (int i = 0; i < Employees.size(); i++) { // for loop increases the rank of everyone already in the array by 1.
			Employees[i]->setRank(Employees[i]->getRank() + 1);
		}
	}
	Employees.push_back(emp); //Employee object is pushed into vector from rear
	
}
//Function takes name as a parameter, finds an employee with that name,
//deletes them from the vector, and decreases the rank of their superiors by 1
void quit(string name, vector<Employee*>& Employees) {
		int i = Employees.size()-1;
		while (i >= 0) { //while iterates through vector from lowest to highest rank and finds an employee with the inputted name
			if (Employees[i]->getName() == name) { 
				cout << Employees[i]->getName() << " has left the company.\n";
				Employees.erase(Employees.begin() + i);
				break;
				
			}
			i--;

		}
		for (i >= 0; i--;) { // if name is not in vector, for loop wont run since i would already be equal to 0 from the while loop, otherwise
			Employees[i]->setRank(Employees[i]->getRank() - 1); // for loop decreases the rank by 1 of superiors previously ranked higher than the
		}                                                        //employee that quit
		

}

//Prompted name is entered into the function
//If they are found and do not have the highest rank in the vector,
//they swap positions and ranks with their superior.
void promote(string name, vector<Employee*>& Employees) {
	for (int i = Employees.size()-1; i > 0; i--) {
		if (Employees[i]->getName() == name) { // for loop checks for name in vector, checks if their rank is lower than their superior,
			if (compare(Employees[i]->getRank(), Employees[i - 1]->getRank())) { // and if it is swaps their positions and ranks.
				Employees[i]->setRank(Employees[i - 1]->getRank()); //Sets the new ranks of the Employees
				Employees[i - 1]->setRank(Employees[i - 1]->getRank() - 1); 
				swap(Employees[i], Employees[i - 1]); //Swaps positions
				cout << Employees[i-1]->getName() << " promoted to a Rank: " << Employees[i-1]->getRank() << endl;
				break;
			}
		}
	}
	
}
//Prompted name is entered into the function
//If they are found and do not have the lowest rank in the vector,
//they swap positions and ranks with their subordinate.
void demote(string name, vector<Employee*>& Employees) {
	for (int i = Employees.size()-1; i >= 0; i--) { // for loop checks for name in vector, checks if their ranks is higher than their 
		if (Employees[i]->getName() == name) { // subordinate, and if it is, swaps their positions and ranks.
			if (compare(Employees[i+1]->getRank(), Employees[i]->getRank())) {
				Employees[i+1]->setRank(Employees[i]->getRank()); //Sets the new ranks of the Employees
				Employees[i]->setRank(Employees[i]->getRank() - 1);
				swap(Employees[i], Employees[i + 1]); //Swaps positions
				cout << Employees[i + 1]->getName() << " demoted to a Rank: " << Employees[i + 1]->getRank() << endl;
				break;
			}
		}
	}
	

}

bool compare(int rank, int rank2) {
	return (rank < rank2);

}

int main() {
	//Vector of Employees
	vector<Employee*> Employees;
	//ofstream used to output to employ.txt
	ofstream out;
	out.open("employ.txt");
	//name is prompted for functions to get Employees
	string name;
	//cmd is prompted for conditional statements
	string cmd = "0";
	while (cmd != "7") {
		cout << "1.JOIN <person>" << endl; //Menu is displays
		cout << "2.QUIT <person>" << endl; //User is prompted to enter cmd
		cout << "3.PROMOTE <person>" << endl;
		cout << "4.DEMOTE <person>" << endl;
		cout << "5.SALARY" << endl;
		cout << "6.EMPLOYEES" << endl;
		cout << "7.END" << endl;
		cout << "Enter a choice: ";
		cin >> cmd;
		out << "1.JOIN <person>" << endl;
		out << "2.QUIT <person>" << endl;
		out << "3.PROMOTE <person>" << endl;
		out << "4.DEMOTE <person>" << endl;
		out << "5.SALARY" << endl;
		out << "6.EMPLOYEES" << endl;
		out << "7.END" << endl;
		out << "Enter a choice: ";
		out << cmd << endl;
		if (cmd == "1") { //Employee joins company
			cout << "Enter the employee's name: ";
			cin >> name;
			out << "Enter the employee's name: ";
			out << name << endl;
			join(name, Employees); //join call
		}
		else if (cmd == "2") { // Employee quits company
			if (!Employees.empty()) {
				cout << "Enter name to leave company: ";
				cin >> name;
				out << "Enter name to leave company: ";
				out << name << endl;
				quit(name, Employees); //quit call
			}
			else {
				cout << "There are no employees to leave the company.\n";
				out << "There are no employees to leave the company.\n";
			}
		}
		else if (cmd == "3") { // Employee in company is promoted
			if (Employees.size() == 1) {
				cout << "You cannot promote anyone if there is only one person in the company." << endl;
				out << "You cannot promote anyone if there is only one person in the company." << endl;

			}
			else if (!Employees.empty()) {
				cout << "Enter name of worker to promote: ";
				cin >> name;
				out << "Enter name of worker to promote: ";
				out << name << endl;
				promote(name, Employees); //promote call
			}
			else {
				cout << "There are no employees to promote.\n";
				out << "There are no employees to promote.\n";
			}
		}
		else if (cmd == "4") { // Employee in company is demoted
			if (Employees.size() == 1) {
				cout << "You cannot demote anyone if there is only one person in the company." << endl;
				out << "You cannot demote anyone if there is only one person in the company." << endl;

			}
			else if (!Employees.empty()) {
				cout << "Enter name of worker to demote: ";
				cin >> name;
				out << "Enter name of worker to demote: ";
				out << name << endl;
				demote(name, Employees); //demote call
				//out << Employees[i + 1]->getName() << " demoted to a Rank: " << Employees[i + 1]->getRank() << endl;
			}

			else {
				cout << "There are no employees to demote.\n";
				out << "There are no employees to demote.\n";
			}
			
		}
		else if (cmd == "5") { //Employees in company are displayed along with their salaries
			if (!Employees.empty()) {
				cout << "List of Employees and their salaries\n";
				cout << "Employee" <<"\t\tRank" << "\t\tSalary\n";
				cout << "--------" <<"\t\t----" << "\t\t------\n";
				out << "List of Employees and their salaries\n";
				out << "Employee" << "\t\tRank" << "\t\tSalary\n";
				out << "--------" << "\t\t----" << "\t\t------\n";
				for (int i = 0; i < Employees.size(); i++) {
					if (Employees[i]->getName().length() < 8) {
						cout << Employees[i]->getName() << "\t\t\t" << Employees[i]->getRank() << "\t\t" << Employees[i]->getRank() * 2000 << endl;
						out << Employees[i]->getName() << "\t\t\t" << Employees[i]->getRank() << "\t\t" << Employees[i]->getRank() * 2000 << endl;

					}
					else if (Employees[i]->getName().length() < 16) {
						cout << Employees[i]->getName() << "\t\t" << Employees[i]->getRank() << "\t\t" << Employees[i]->getRank() * 2000 << endl;
						out << Employees[i]->getName() << "\t\t" << Employees[i]->getRank() << "\t\t" << Employees[i]->getRank() * 2000 << endl;
					}
					else {
						cout << Employees[i]->getName() << "\t" << Employees[i]->getRank() << "\t\t" << Employees[i]->getRank() * 2000 << endl;
						out << Employees[i]->getName() << "\t" << Employees[i]->getRank() << "\t\t" << Employees[i]->getRank() * 2000 << endl;
					}
				}
				cout << "--------" << "\t\t----" << "\t\t------\n" << endl;
				out << "--------" << "\t\t----" << "\t\t------\n" << endl;
			}
			else {
				cout << "There are no employees in the company to display.\n";
				out << "There are no employees in the company to display.\n";
			}
		}

		else if (cmd == "6") { //Employees are displayed in descending order by rank
			if (!Employees.empty()) {
				cout << "Employees\n";
				cout << "---------\n";
				out << "Employees" << endl;
				out << "---------" << endl;
				

				for (int i = 0; i < Employees.size(); i++) {

					cout << Employees[i]->getName() << endl;
					out << Employees[i]->getName() << endl;
				}
			}
			else {
				cout << "There are no employees in the company to display.\n";
				out << "There are no employees in the company to display.\n";
			}
			cout << "---------\n\n";
			out << "---------\n\n";
		}
		else if (cmd == "7") { //Program ends
			cout << "Thank you.\n";
			out << "Thank you.\n";
		}
		else{ //Re-dislays menu and user is prompted to enter an option again
			cout << "That is not an option. Please choose an appropriate option.\n";
			out << "That is not an option. Please choose an appropriate option.\n";
		}
	}

}