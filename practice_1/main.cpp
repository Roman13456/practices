#include <iostream>
#include <fstream>
//#include <string>
#include "cstring"
#define MAX_LINE_LENGTH 1000
#include "lib/stream/appStream.h"
#include "lib/pointer/firstFile.h"
using namespace std;





int main(int argc, char* argv[])
{
    string pointer = "-mode FilePointer";
    string stream = "-mode FileStream";
    if(argc==3){
        cout<<"-appending to existing file"<<endl;
        if(pointer==argv[1]){
            cout<<"-mode FilePointer"<<endl;
            appPointer(true, argv[2]);
        }else if(stream==argv[1]){
            cout<<"-mode FileStream"<<endl;
            appStream(true, argv[2]);
        } else{
            cout<<"No args or invalid"<<endl;
        }
    } else if(argc==2){
        if(pointer==argv[1]){
            cout<<"-mode FilePointer"<<endl;
            appPointer(false, "");
        }else if(stream==argv[1]){
            cout<<"-mode FileStream"<<endl;
            appStream(false, "");
        } else{
            cout<<"No args or invalid"<<endl;
        }
    }
    return 0;
}
