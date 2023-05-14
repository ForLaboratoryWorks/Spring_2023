/* fig: labstruct2.cpp                      */
/*************************************/
/* filename: labstruct2.cpp                  */
/* Abstract: Simple C++ program      */
/* Description:                      */
/* Creation date: 2023/03/08         */
/* Version: 1.0                      */
/* None/ Linux                       */
#include "lab2str.h"

airport::airport(std::string name,double surface, size_t floor,int year,double money){
this->name=name;
this->surface=surface;
this->floor=floor;
this->year=year;
this->money=money;
}
std::string airport::get_name(struct airport *obj){
	return obj->name;
	}
double airport::get_surfase(struct airport *obj){
	return obj->surface;
	}
int airport::get_floor(struct airport *obj){
	return obj->floor;
	}
int airport::get_year(struct airport *obj){
	return obj->year;
	}
double airport::get_money(struct airport *obj){
	return obj->money;
	}
	
void airport::set_name(struct airport* obj, std::string value){
obj->name=value;
}
void airport::set_surfase(struct airport* obj, double value){
obj->surface=value;
}
void airport::set_floor(struct airport* obj, int value){
obj->name=floor;
}
void airport::set_year(struct airport* obj, int value){
obj->name=year;
}
void airport::set_money(struct airport* obj, double value){
obj->money=value;
}	
