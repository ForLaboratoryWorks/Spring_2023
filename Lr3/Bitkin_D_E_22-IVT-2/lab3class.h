#ifndef __LABCLASS3__
#define __LABCLASS3__
#include <iostream>
#include <cstring>

class airport{
private:
    std::string name;
    double surface;
    int floor;
    int year;
    double money;
   
public:
airport(std::string ,double , size_t ,int ,double );
std::string get_name( airport*);
double get_surfase(airport*);
int get_floor( airport*);
int get_year( airport*);
double get_money( airport*);

void set_name(airport*, std::string);
void set_surfase(airport*, double);
void set_floor(airport*, int );
void set_year(airport* , int);
void set_money(airport* , double);	

};
#endif
