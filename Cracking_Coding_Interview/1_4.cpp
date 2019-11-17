#include <iostream>
#include <map>
using namespace std;

int isPalindrome(string str)
{
  map<char, int> m;
  for(int i=0; i<str.size(); i++)
    if(str[i]!=' ')
    {
      //cout<<"AVEM "<<str[i]<<endl;
      if(m.find(tolower(str[i]))==m.end())
      {
        //cout<<"AICI 1 "<<str[i]<<endl;
        m[tolower(str[i])]=0;
        m[tolower(str[i])]++;
      }else{
        //cout<<"AICI 2 "<<str[i]<<endl;
        m[tolower(str[i])]++;
      }
    }

    int count = 0;
    for(map<char, int>::iterator it=m.begin(); it!=m.end(); it++)
    {
        //cout << it->first<<" "<<it->second<<endl;
        if(it->second%2!=0)
        count++;
    }
    if(count<=1)
      return 0;
    return 1;
}

int main()
{
  string s = "Tact Cooa";
  cout << isPalindrome(s);
}
