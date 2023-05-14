/* fig: lab1.cpp                      */
/*************************************/
/* filename: lab1.cpp                 */
/* Abstract: Simple C++ program      */
/* Description:                      */
/* Creation date: 2023/02/21         */
/* Version: 1.0                      */
/* None/ Linux                       */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
void file();
void foo(char name[]);
const size_t password {16078667606130765862L};
int main(int argc, char *argv[]){
if(argc<2){
std::cout<<"Программа запущенна без аргументов\n";
exit (-1);
}

std::string s = argv[1];
std::hash<std::string> hash_fn;
size_t hash = hash_fn(s);
if(password==hash){
std::cout<< "*********************************************\n"     //Приветствие программы
/*        */"*  Nizhniy Novgorod Technical University    *\n"
/*        */"*  Study work number 1 Task number 5      *\n"
/*        */"*  Performed student Bitkin Dmitry          *\n"
/*        */"*********************************************\n";
file();
return 0;
}
else{
std::cout<<"Пароль введен неверно\n";
exit (-1);
}
}

void file()
{
    std::ifstream fin{"lab1.txt"}; 
    if (!fin.is_open())
        {
            std::cout<<"Error\n";
            exit(1);
        }
std::string s;
char bas[6][10];
char *args[1]{};
int count=1;
while(getline(fin,s)){
     strcpy(bas[count], s.c_str());
     count++; 
}

for(int i=count-1; i>0; i--){
     args[0]=bas[i];
     foo(args[0]);
     }
fin.close();

}

void foo(char name[]){
std::cout<<name<<"\n";
system(name);
}



