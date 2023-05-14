#include "lab3class.h"


airport::airport(std::string name,double surface, size_t floor,int year,double money){
this->name=name;
this->surface=surface;
this->floor=floor;
this->year=year;
this->money=money;
}
std::string airport::get_name( airport *obj){
	return obj->name;
	}
double airport::get_surfase( airport *obj){
	return obj->surface;
	}
int airport::get_floor( airport *obj){
	return obj->floor;
	}
int airport::get_year( airport *obj){
	return obj->year;
	}
double airport::get_money( airport *obj){
	return obj->money;
	}
	
void airport::set_name( airport* obj, std::string value){
obj->name=value;
}
void airport::set_surfase( airport* obj, double value){
obj->surface=value;
}
void airport::set_floor( airport* obj, int value){
obj->name=floor;
}
void airport::set_year( airport* obj, int value){
obj->name=year;
}
void airport::set_money( airport* obj, double value){
obj->money=value;
}
	
