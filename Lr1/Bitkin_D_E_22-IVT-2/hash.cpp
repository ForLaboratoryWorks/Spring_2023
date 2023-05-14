#include <iostream>
#include <string>
#include <functional>
int main(int argc, char *argv[]) {
if(argc==1){
std::cout<<"Программа запущена без параметров"<<std::endl;
exit (1);
}
    
std::string s = argv[1];
std::hash<std::string> hash_fn;
size_t hash = hash_fn(s);
std::cout << hash << '\n';
}
