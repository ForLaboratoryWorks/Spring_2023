/* fig: lab3.cpp                      */
/*************************************/
/* filename: lab3.cpp                 */
/* Abstract: Simple C++ program      */
/* Description:                      */
/* Creation date: 2023/03/22         */
/* Version: 1.0                      */
/* None/ Linux                       */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "lab3class.h"

template <typename T>
T Secure(std::string errorText){
	T a;
	std::cin>>a;
	while(!std::cin.good()|| a<1){
		if (!std::cin.good()){//проверяем ввод на наличие числа не более 10000
			std::cout<<"Данные введены некорректно!\n";//вывод ошибки при некорректных данных
			std::cin.clear();
			std::cin.ignore(32767,'\n');
			}
		std::cout<< errorText ;
		std::cin>>a;
	}
return a;
}
void help();
void create(char *argv[]);
void hello();

int main(int argc, char** argv){
hello();

if (argc!=4){
        std::cout<<"Программа запущена не правильно!\n\n"
                 <<"Корректный список параметров: <Выбор режима работы> <Количиство необходимых записей> <Текстовый файл>\n\n"
                 <<"Допустимые режимы работы: \n'-c' '--create' - запуск программы в режиме создания электронной таблицы записей\n"
                 <<"'-r' '--read'   - запуск программы в режиме чтения содержимого текстового файла\n"
                 <<"'-h' '--help'   - запуск программы в режиме получения справки\n";
                 exit (1);
	}
	else{
	if(strcmp(argv[1],"-h")==0 || strcmp(argv[1], "--help")==0){
		help();	
		}
	else{	
		if(strcmp(argv[1],"-r")==0 || strcmp(argv[1], "--read")==0){
         		if (atoi(argv[2]) <= 0){
            			std::cout << "Ошибка ввода данных\n";
            			exit (1);
            		}
         		else{
         			std::ifstream out(argv[3]);
         			if (!out.is_open()){
         				std::cout<<"Файл не удалось открыть!";
         				exit (1);
         				}
         			std::string str;
         			int count{};
         			while(!out.eof() && count<(atoi(argv[2])+1)){
             				getline(out,str);
         				std::cout<<str<<std::endl;
         				count++;
      					}
      				out.close();      
               		}
               		}
               		
               		
		if(strcmp(argv[1],"-c")==0 || strcmp(argv[1], "--create")==0){
			if (atoi(argv[2]) <= 0){
            			std::cout << "Ошибка ввода данных";
            			exit (1);
            			}
            		std::cout<<"Начало записи информации\n";
             		create(argv);	
         		}
		}
		if((strcmp(argv[1],"-c")!=0 && strcmp(argv[1], "--create")!=0) &&(strcmp(argv[1],"-r")!=0 && strcmp(argv[1], "--read")!=0)&&(strcmp(argv[1],"-h")!=0 && strcmp(argv[1], "--help")!=0) ){
			std::cout<<"Все настолько плохо, что вы не можете даже правильно ввести режим работы\n"
			<<"Допустимые режимы работы: \n'-c' '--create' - запуск программы в режиме создания электронной таблицы записей\n"
             		<<"'-r' '--read'   - запуск программы в режиме чтения содержимого текстового файла\n"
                 	<<"'-h' '--help'   - запуск программы в режиме получения справки\n";
			}       
	}
    return 0;
}


void hello(){
std::cout<< "*********************************************\n"     //Приветствие программы
	/*        */"*  Nizhniy Novgorod Technical University    *\n"
	/*        */"*  Study work number 3 Task number 5      *\n"
	/*        */"*  Performed student Bitkin Dmitry          *\n"
	/*        */"*********************************************\n";}
	


void create(char *argv[]){
int count=atoi(argv[2]);
std::ofstream in(argv[3], std::ofstream::app);
std::ifstream out(argv[3]);
if (!in.is_open()){
	std::cout<<"Файл не удалось открыть!";
	exit (1);
	}
if (!out.is_open()){
	std::cout<<"Файл не удалось открыть!";
	exit (1);
	}
else{
if(out.peek() ==EOF){
in<<std::fixed<<std::setw(30)<<std::setprecision(1)<<"Name:"<<"  |  "
  <<std::setw(20)<<std::setprecision(1)<<"Building area:"<<"  |  "
  <<std::setw(25)<<std::setprecision(1)<<"Number of storeys:"<<"  |  "
  <<std::setw(25)<<std::setprecision(1)<<"Year of commissioning:"<<"  |  "
  <<std::setw(15)<<std::setprecision(1)<<"assessed value:"<<"  |  "<<"\n";
  }
  
	std::string name;
    	double surface;
    	int floor;
    	int year;
    	double money;
    	
        for(int i{}; i<count; i++){
       	std::cout<< "Наименование: ";
		std::cin>>name;
       		
        	std::cout<< "Площадь сдания: ";
       	surface=Secure<double>("Площадь сдания: ");
        	
        	
        	std::cout<<"Этажность здания: ";
        	floor=Secure<int>("Этажность здания: ");
        	      	
        	std::cout<<"Год ввода в эксплоуатацию: ";
        	year=Secure<int>("Год ввода в эксплоуатацию: ") ;
        	
        	std::cout<<"Оценочная стоимость: ";
        	money=Secure<double>("Оценочная стоимость: ");
        
         	airport a1(name,surface, floor, year, money);
         	
         	in <<std::fixed<<std::setw(30)<<std::setprecision(2)<<a1.get_name(&a1)<<"  |  "
		   <<std::setw(20)<<a1.get_surfase(&a1) <<"  |  "
  		   <<std::setw(25)<<a1.get_floor(&a1)<<"  |  "
  		   <<std::setw(25)<<a1.get_year(&a1)<<"  |  "
 		   <<std::setw(15)<<a1.get_money(&a1)<<"  |  "<<"\n";
  }
             
         	}
         
in.close();
out.close();
}

void help(){
std::cout<<"Вы выбрали режим работы : 'Справка'\n";
             		std::cout<<"Вы используете программу учета аэропортов.\n"
             		<<"Данная программа создана для внесения в файл сведений об аэропортах и вывода уже занесенныз данных:\n"
             		<<"-Наименование аэропорта\n"
             		<<"-Площадь сдания\n"
             		<<"-Этажность здания\n"
             		<<"-Год ввода в эксплоуатацию\n"
             		<<"-Оценочная стоимость млн.руб\n\n"
             		<<"Программа написана в качестве лабораторной работы №3 по Программированию\n"
             		<<"Студентом группы 22-ИВТ-2 Биткиным Дмитрием\n";
}
       
             
