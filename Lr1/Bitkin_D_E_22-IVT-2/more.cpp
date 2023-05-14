/* fig: more.cpp                                    */
/*****************************************************/
/* Filename: more.cpp                               */
/* Abstract: Simple C++ program                      */
/* Description:                                      */
/* Creation date: 2023/03/15                         */
/* Auther: Studet IRIT Bitkin D.E.   22-IVT-2        */
/* None/ Linux                                       */
/*****************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <sys/ioctl.h>
#include <unistd.h>
struct winsize w;

int main() {
system("stty -icanon -echo");
int kod;
std::ifstream text;
text.open("text2.txt");
if (!text.is_open()) {
	 printf("Error!");
	 
	 return 0;
	}
	
ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
int row2=0;
char stro[1900000];
while (text.eof() == 0) {
	text.getline(stro,1900000);
	int len = strlen(stro);
	for(int i{1}; i < len+1; i++) {
		std::cout << stro[i-1];     
		if(i%w.ws_col==0){
               	 std::cout<<std::endl;
               	 ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
               	 row2++;                
               		 if(row2%(w.ws_row-1)==0){
           				 while((kod = getchar()) != 32){}
        			  } 
            	 }
        }
        std::cout<<std::endl;
        row2++;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
       if(row2%(w.ws_row-1)==0){
            while((kod = getchar()) != 32){}
        }
        }
      //  std::cout<<row2<<" "<<w.ws_row-1;
        if((row2-1)%(w.ws_row-1)!=0){
        while(row2%(w.ws_row-1)!=0){
        row2++;
        std::cout<<std::endl;
        }
        }
system("stty icanon echo");
return 0;
}







