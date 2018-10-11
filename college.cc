//Peixin Fan
//Project3
//10.15.17
#include "college.h"
#include "course.h"
#include "node.h"
#include<iostream>
#include<string>
using namespace std;

college::college()
{
    head = NULL;
}
college::~college()
{
      delete head;
}
college::college(const string& other)
{
    head = NULL;
    node *new_head;
    node *last = NULL;
    while(new_head != NULL){
        node *next = new node;
        next->set_data(new_head->data());
        next->set_link(NULL);
        if(last != NULL)
            last->set_link(next);
        else
            head = new_head;
        last = new_head;
        new_head = new_head->link();
    }
}
college college::operator =(const college& other)
{
    if(this == &other)
        return *this;
    else{
        delete head;
        node *new_head = other.head;
        node *last = NULL;
        head = NULL;
        while(new_head != NULL){
            if(last == NULL){
                head = new node;
                head->set_data(new_head->data());
                head->set_link(NULL);
                last = head;
            }else{
                last->set_link(new node);
                last = last->link();
                last->set_data(new_head->data());
                last->set_link(NULL);
            }
            new_head = new_head->link();
        }
        return *this;
    }
}
void college::load(std::ifstream& ifs)
{
    course tmp;
    while(ifs>>tmp){
        add(tmp);}
}
void college::add(const course& s)
{
    node *tmp;
    if (head == NULL){
        head = new node;
        head -> data() = s;
        head -> link() == NULL;
    }
    else{
        for(tmp = head; tmp -> link() != NULL; tmp = tmp -> link()){
            tmp ->link() == new node;
            tmp = tmp -> link();
            tmp ->data() = s;
            tmp ->link() == NULL;}}
}
void college::display(std::ostream& cou)
{
    for(node *tmp = head; tmp != NULL; tmp = tmp->link())
        cou << tmp->data() << endl;
}


void college::remove(value_type n)
{
    for(node *tmp = head; tmp!=NULL; tmp =tmp->link()){
        if(tmp->data()==n){
            delete tmp;
            tmp = tmp->link();}}
    /*node *cursor;
    node *previous;
    if(head->data==nam){
        cursor=head;
        head=head->link;
        delete cursor;
    }
    else{
        cursor=head;
        while(cursor!=NULL&&cursor->data!=nam){
            previous=cursor;
            cursor=cursor->link();
        }
        if(cursor!=NULL){
            previous->link()==cursor->link;
        }
        delete cursor;
    }*/
}
double college::hours(){
    course c;
    double count = 0.0;
    for(head; head!=NULL;head=head->link()){
        count += c.get_hours();
    }
    return count;
}
double college::gpa(){
    course c;
    double count =0.0;
    double gpa=0.0;
    double hours=0.0;
    for(head; head!=NULL;head=head->link()){
        count += c.get_number_grade() * c.get_hours();
        hours +=c.get_hours();
    }
    return gpa = count/hours;
}
void college::save(std::ofstream& ofs){
    for(node *cur = head; cur != NULL; cur = cur->link()){
        ofs<<cur->data()<<endl;}}

