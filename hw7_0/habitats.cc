
#include "habitats.h"
using namespace std;

habitats::habitats(){
    name = " ";
    capacity = 0;
}

habitats::habitats(string name, int capacity){
    this->name = name;
	this->capacity = capacity;
}

habitats::~habitats(){
}

string habitats::tostring(){
	stringstream n;
	n << "Name: " << name << endl;
	n << "Capacity: " << capacity;
	return n.str();
}

void habitats::output(ostream &out){
	dooutput(out);
	out << name << endl;
	out << capacity << endl;
}

void habitats::input(istream &in){
	doinput(in);
	string line;
	getline(in, name);
	getline(in, line);
	stringstream(line) >> capacity;
}

cave::cave(){
    food_count = 0.0;
    raduis = 0.0;
}

cave::cave(string name, int capacity,double food_count,double raduis)
    : habitats(name, capacity){
        this->food_count = food_count;
        this->raduis = raduis;
}
  
cave::~cave(){
}

string cave::tostring(){
    stringstream n;
    n << "Type: cave" << endl;
	n << habitats::tostring() << endl;
	n << "Number Of Food: " << food_count << "KG." << endl;
	n << "Cave Raduis: " << raduis << "M."<<endl;
	return n.str();
}

void cave::dooutput(ostream &out){
	out << "Cave" << endl;
	out << food_count << endl;
	out << raduis << endl;
}

void cave::doinput(istream &in){
	string line;
	getline(in, line);
	stringstream(line) >> food_count;
	getline(in, line);
	stringstream(line) >> raduis;
}

nest::nest(){
    withhay = false;
    hay_count = 0.0;
}

nest::nest(string name, int capacity,bool withhay,int hay_count)
    : habitats(name, capacity){
        this->withhay = withhay;
        this->hay_count = hay_count;
}
  
nest::~nest(){
}

string nest::tostring(){
    stringstream n;
    n << "Type: Nest" << endl;
	n << habitats::tostring() << endl;
	n << "With Hay: ";
    if (withhay){
		n << "Yes";
	}
	else{
		n << "No";
	}
    n << endl;
	n << "Number Of Hay: " << hay_count << "KG."<<endl;
	return n.str();
}

void nest::dooutput(ostream &out){
	out << "Nest" << endl;
	if (withhay){
		out << "yes";
	}
	else{
		out << "no";
	}
	out << endl;
	out << hay_count << endl;
}

void nest::doinput(istream &in){
	string line;
	getline(in, line);
	withhay = line.compare("yes") == 0;
	getline(in, line);
	stringstream(line) >> hay_count;
}

kennel::kennel(){
	bone_count = 0;
    withbathroom = false;
}

kennel::kennel(string name, int capacity,int bone_tcoun,bool withbathroom)
    : habitats(name, capacity){
        this->bone_count = bone_count;
        this->withbathroom = withbathroom;
}
  
kennel::~kennel(){
}

string kennel::tostring(){
    stringstream n;
    n << "Type: Kennel" << endl;
	n << habitats::tostring() << endl;
	n << "Number Of Bone: " << bone_count << "."<<endl;
	n << "With Bathroom: ";
    if (withbathroom){
		n << "Yes";
	}
	else{
		n << "No";
	}
    n << endl;
	return n.str();
}

void kennel::dooutput(ostream &out){
	out << bone_count << endl;
	out << "Kennel" << endl;
	if (withbathroom){
		out << "yes";
	}
	else{
		out << "no";
	}
	out << endl;
}

void kennel::doinput(istream &in){
	string line;
	getline(in, line);
	stringstream(line) >> bone_count;
	getline(in, line);
	withbathroom = line.compare("yes") == 0;
}

stable::stable(){
    stablesize = 0.0;
    stablenum = 0;
}

stable::stable(string name, int capacity,double stablesize,int stablenum )
    : habitats(name, capacity){
        this->stablesize = stablesize;
        this->stablenum = stablenum;
}
  
stable::~stable(){
}

string stable::tostring(){
    stringstream n;
    n << "Type: Stable" << endl;
	n << habitats::tostring() << endl;
	n << "Size Of Stable: " << stablesize << "SQ M." << endl;
	n << "Number of Stable: " << stablenum << "."<<endl;
	return n.str();
}

void stable::dooutput(ostream &out){
	out << "Stable" << endl;
	out << stablesize << endl;
	out << stablenum << endl;
}

void stable::doinput(istream &in){
	string line;
	getline(in, line);
	stringstream(line) >> stablesize;
	getline(in, line);
	stringstream(line) >> stablenum;
}

cattery::cattery(){
    withwater = false;
    withfood = false;
}

cattery::cattery(string name, int capacity,bool withwater,bool withfood)
    : habitats(name, capacity){
        this->withwater = withwater;
        this->withfood = withfood;
}
  
cattery::~cattery(){
}

string cattery::tostring(){
    stringstream n;
    n << "Type: Cattery" << endl;
	n << habitats::tostring() << endl;
	n << "With Water: ";
    if (withwater){
		n << "Yes";
	}
	else{
		n << "No";
	}
    n << endl;
	n << "With Food: ";
    if (withfood){
		n << "Yes";
	}
	else{
		n << "No";
	}
    n << endl;
	return n.str();
}

void cattery::dooutput(ostream &out){
	out << "Cattery" << endl;
	if (withwater){
		out << "yes";
	}
	else{
		out << "no";
	}
	out << endl;
	if (withfood){
		out << "yes";
	}
	else{
		out << "no";
	}
	out << endl;
}

void cattery::doinput(istream &in){
	string line;
	getline(in, line);
	withwater = line.compare("yes") == 0;
	getline(in, line);
	withfood = line.compare("yes") == 0;
}
