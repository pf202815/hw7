#ifndef HABITATS_H
#define HABITATS_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class habitats{
    public:
        habitats();
        habitats(string name, int capacity);
        virtual ~habitats();
        virtual string tostring();
        void input(istream &in);
        void output(ostream &out);
    protected:
        string name;
        int capacity;
        virtual void dooutput(ostream &out) = 0;
	    virtual void doinput(istream &in) = 0;
};

class cave:public habitats{
    public:
        cave();
        cave(string name, int capacity,double food_count,double raduis);
        ~cave();
        string tostring();
    private:
        double food_count;
        double raduis;
        void dooutput(ostream &out);
	    void doinput(istream &in);
};
class nest:public habitats{
    public:
        nest();
        nest(string name, int capacity,bool withhay,int hay_count);
        ~nest();
        string tostring();
    private:
        bool withhay;
        int hay_count;
        void dooutput(ostream &out);
	    void doinput(istream &in);
};
class kennel:public habitats{
    public:
        kennel();
        kennel(string name, int capacity,int bone_tcoun,bool withbathroom);
        ~kennel();
        string tostring();
    private:
        int bone_count;
        bool withbathroom;
        void dooutput(ostream &out);
	    void doinput(istream &in);
};
class stable:public habitats{
    public:
        stable();
        stable(string name, int capacity,double stablesize,int stablenum );
        ~stable();
        string tostring();
    private:
        double stablesize;
        int stablenum;
        void dooutput(ostream &out);
	    void doinput(istream &in);
};
class cattery:public habitats{
    public:
        cattery();
        cattery(string name, int capacity,bool withwater,bool withfood);
        ~cattery();
        string tostring();
    private:
        bool withwater;
        bool withfood;
        void dooutput(ostream &out);
	    void doinput(istream &in);
};

#endif
