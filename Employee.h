#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;

//Class Employee
class Employee {
private:
	string name;
	int rank;
public:
	//constructor
	Employee(string _name, int _rank) {
		name = _name;
		rank = _rank;
	};
	string getName() { return name; }
	void setName(string _name) { name = _name; };
	int getRank() { return rank; }
	void setRank(int _rank) { rank = _rank; }

};
#endif EMPLOYEE_H