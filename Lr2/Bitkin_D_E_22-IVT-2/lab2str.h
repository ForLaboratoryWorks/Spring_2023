/* fig: lab2str.h                      */
/*************************************/
/* filename: lab2str.h                 */
/* Abstract: Simple C++ program      */
/* Description:                      */
/* Creation date: 2023/03/08         */
/* Version: 1.0                      */
/* None/ Linux                       */
#ifndef __LAB2__
#define __LAB2__
#include <iostream>
#include <cstring>

struct airport{
    std::string name;
    double surface;
    int floor;
    int year;
    double money;
   
	
    
airport(std::string ,double , size_t ,int ,double );
std::string get_name(struct airport *);
double get_surfase(struct airport*);
int get_floor(struct airport *);
int get_year(struct airport *);
double get_money(struct airport *);
void set_name(struct airport*, std::string);
void set_surfase(struct airport*, double);
void set_floor(struct airport*, int );
void set_year(struct airport* , int);
void set_money(struct airport* , double);	
};

#endif
