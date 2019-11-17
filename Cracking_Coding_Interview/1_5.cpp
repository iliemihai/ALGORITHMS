#include <string>
#include <iostream>
using namespace std;

bool OneEditAway(string& s1, string& s2) {
    string a, b;
    a = s1.length() >= s2.length() ? s1:s2;
    b = s1.length() < s2.length() ? s1:s2;
    int len1=a.length(), len2=b.length();

    if(abs(len1-len2) > 1)
        return false;

    bool flag = false;
    for(int i=0, j=0; i<len1 && j<len2;){
        if(a[i]!=b[j]){
            if(flag)
                return false;
            flag = true;
            if(len1==len2){
                i++,j++;
            }else{
                i++;
            }
        }else{
            i++,j++;
        }
    }
    return true;
}



int main(){
    string s1 = "oaie";
    string s2 = "cadlaie";

    if(OneEditAway(s1, s2)){
        cout << "One edit distance\n";
    }else{
        cout << "No one edit distance\n";
    }

    return 0;
}