//Peixin Fan
//Project3
//10.15.17

#include<string>
#include<iostream>
#include<fstream>
#include "course.h"
#include "node.h"
#ifndef COLLEGE_H
#define COLLEGE_H

using namespace std;

class college{

public:
    typedef course value_type;
    college();
    ~college();
    college(const string& other);
    college operator =(const college& other);

    void load(std::ifstream& ifs);
    void add(const course& s);
    void display(std::ostream& cou);
    void remove(value_type n);
    double hours();
    double gpa();
    void save(std::ofstream& outs);
    void set_name(std::string n){name = n;}

private:
    std::string name;
    node *head;
};

#endif
