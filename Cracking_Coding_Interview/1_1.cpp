#include <iostream>
#include <string>
#include "../lib/BloomFilter.h"
#define VOCAB_SIZE 128

using namespace std;

bool str_unique_chars(string str){
    int len = str.size();
    
    if(len > VOCAB_SIZE)
        return false;

    bloom_filter<int> bloom(VOCAB_SIZE);

    for(int i=0; i<len; i++){
        int val = str[i];
        if(bloom.contains(val)){
            return false;}
        bloom.add(val);
    }
    return true;
}

int main(){
    vector<string> words = {"cveva", "ceva"};

    for(auto w:words)
        if(str_unique_chars(w))
          cout << w << " is unique\n";
        else
          cout << w << " is not unique\n";
    return 0;
}