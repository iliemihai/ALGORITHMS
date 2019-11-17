#include<iostream>

using namespace std;

//idea edit string from end. first we count the number of spaces
// triple it and compute how many extra chars we will have in final
//string. in the second pass in reverse order replace space with %20, if no space copy original char

void replace_chars(char* str, int length) {
    int count=0, final_index;

    for(int i=0; i<length; i++){
        if(str[i]==' '){
            count++;
        }
    }

    final_index = length+count*2;

    if(length < sizeof(str)/sizeof(char))
        str[length] = '\0';//end array
    for(int i=length-1; i>=0; i--){
        if(str[i]==' '){
            str[final_index-1]='0';
            str[final_index-2]='2';
            str[final_index-3]='%';
            final_index-=3;
        }else{
            str[final_index-1] = str[i];
            final_index--;
        }
    }
}

int main()
{
    char str[]="Mr John SMith    ";
    std::cout << "Actual string " << str << std::endl;
    replace_chars(str, 13);
    std::cout << "Modified " << str << std::endl;
}