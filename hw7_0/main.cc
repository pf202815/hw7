#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "habitats.h"
using namespace std;

int rint(string n){
    string in;
	int ins;
	cout << n;
	getline(cin, in);
	stringstream(in) >> ins;
	return ins;
}

double rdouble(string n){
	string in;
	double ins;
	cout << n;
	getline(cin, in);
	stringstream(in) >> ins;
	return ins;
}

string rstring(string n){
	string in;
	cout << n;
	getline(cin, in);
	return in;
}

cave *rcave(){
	cout << "create a cave" << endl;
	string name = rstring("Enter name: ");
	int capacity = rint("Enter capacity: ");
	double food_count = rdouble("Enter the number of food: ");
	double raduis = rdouble("Enter raduis of cave: ");
	return new cave(name, capacity, food_count, raduis);
}

nest *rnest(){
	cout << "create a nest" << endl;
	string name = rstring("Enter name: ");
	int capacity = rint("Enter capacity: ");
	bool withhay = rint("Do you need the hay(1.yes(if not choose yes, next question type to 0)): ") == 1;
	int hay_count = rint("Enter number of hay: ");
	return new nest(name, capacity, withhay, hay_count);
}

kennel *rkennel(){
	cout << "create a kennel" << endl;
	string name = rstring("Enter name: ");
	int capacity = rint("Enter capacity: ");
	double bone_count = rint("Enter the number of bone: ");
	bool withbathroom = rint("Do you need the bathroom(1.yes): ") == 1;
	return new kennel(name, capacity, bone_count, withbathroom);
}

stable *rstable(){
	cout << "create a stable" << endl;
	string name = rstring("Enter name: ");
	int capacity = rint("Enter capacity: ");
	double stablesize  = rdouble("Enter the size of stable: ");
	int stablenum = rint("Enter number of stable: ");
	return new stable(name, capacity, stablesize, stablenum);
}

cattery *rcattery(){
	cout << "create a cattery" << endl;
	string name = rstring("Enter name: ");
	int capacity = rint("Enter capacity: ");
	bool withwater = rint("Do you need the water(1.yes): ") == 1;
	bool withfood = rint("Do you need the food(1.yes): ") == 1;
	return new cattery(name, capacity, withwater, withfood);
}

void load_file(list<habitats *> t){
    ifstream infile("data.dat");
	if (!infile.is_open()){
		return;
	}
    string line;
    getline(infile, line);
	int count;
	stringstream(line) >> count;
    for(int i =0; i < count; i++){
        habitats *hab;
        getline(infile, line);
        if (line.compare("cave") == 0){
			hab = new cave();
		}
		else if (line.compare("nest") == 0){
			hab = new nest();
		}
		else if (line.compare("kennel") == 0){
			hab = new kennel();
		}
		else if (line.compare("stable") == 0){
			hab = new stable();
		}
		else if (line.compare("cattery") == 0){
			hab = new cattery();
		}
		hab->input(infile);
		t.push_back(hab);
    }   
}

void save_file(list<habitats *> t){
	ofstream outfile("data.dat");
	outfile << t.size() << endl;
	for (list<habitats *>::iterator it = t.begin(); it != t.end(); it++){
		habitats *hab = *it;
		hab->output(outfile);
	}
	outfile.close();
}

void list_home(list<habitats *> t){
	for (list<habitats *>::iterator it = t.begin(); it != t.end(); it++){
		habitats *hab = *it;
		cout << hab->tostring() << endl;
		cout << endl;
	}
}

int main(){
	list<habitats *> t;
	load_file(t);
	while(true){
		cout<<"welcome to animal home!"<<endl;
		cout<<"1. create a cave"<<endl;
		cout<<"2. create a nest"<<endl;
		cout<<"3. create a kennel"<<endl;
		cout<<"4. create a stable"<<endl;
		cout<<"5. create a cattery"<<endl;
		cout<<"6. display all the homes"<<endl;
		cout<<"0. quit"<<endl;
		int option = rint("option: ");
		if(option == 0){
			break;
		}
		switch(option){
			case 1:
				t.push_back(rcave());
				break;
			case 2:
				t.push_back(rnest());
				break;
			case 3:
				t.push_back(rkennel());
				break;
			case 4:
				t.push_back(rstable());
				break;
			case 5:
				t.push_back(rcattery());
				break;
			case 6:
				list_home(t);
				break;
		}
	}
	save_file(t);
	return 0;
}