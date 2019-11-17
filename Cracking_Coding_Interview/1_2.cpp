#include <iostream>
#include <map>
#include <string>
using namespace std;

void isPermutation(string& str1, string& str2)
{
  if(str1.size()!=str2.size()){
     cout << "No Permutation\n";
    return ;
  }

  map<char, int> m;

  for(int i=0; i<str1.size(); i++)
  {
    map<char,int>::iterator it = m.find(str1[i]);
    if(it != m.end())
    {
      m[str1[i]]=0;
      m[str1[i]]++;
    }
    else
    {
      m[str1[i]]++;
    }
  }
  for(int i=0; i<str2.size(); i++)
  {
      map<char,int>::iterator it = m.find(str2[i]);
      if(it != m.end())
      {
        m[str2[i]]--;
        if(m[str2[i]]==0)
          m.erase (str2[i]);
      }
  }
  if(m.empty()==true)
    cout << "Permutation\n";
  else
    cout << "No Permutation\n";
}

int main(int argc, char const *argv[]) {
  string str1="coaie";
  string str2="baioe";
  isPermutation(str1, str2);

}
