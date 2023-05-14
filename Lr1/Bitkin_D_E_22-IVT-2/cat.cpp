#include <iostream>
#include <fstream>
#include <sys/ioctl.h>
#include <unistd.h>
using namespace std;



int main(int argc, char** argv) {
    if(argc == 1) {
        printf("App <namefile1.txt> <namefile2.txt> ...\n");
        return 0;
    }
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	int col = w.ws_col;

    for(int i{1}; i < argc; i++){

	ifstream text;
	text.open(argv[i]);
	if (!text.is_open()) {
		 cout<<"\nError! Don't open \n"<< argv[i];
		 continue;
	}
    cout<<"    Open "<< argv[i];
	string s;
    int size;
    while(getline(text, s)) {
        size = s.size();
        for(int j{}; j< size; j++){
            if(j % col == 0){
                std::cout << std::endl;
            }
            cout << s[j];
        }
    }
    cout <<endl;
    text.close();
    }

	return 0;
}

	
	
    
