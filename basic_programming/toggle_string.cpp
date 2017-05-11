#include <iostream>
#include <string>

void toogleString(std::string & s){
  for (int i = 0; i < s.size(); i++){
    int diff = 0;
    if (s.at(i) <= 'z' && s.at(i) >= 'a'){
      diff = s.at(i) - 'a';
      s.at(i) = 'A' + diff;
    }
    else{
      diff = s.at(i) - 'A';
      s.at(i) = 'a' + diff;
    }
  }
}


int main(){
  std::string s;
  std::cin >> s;
  toogleString(s);
  std::cout << s << std::endl;

  return 0;
}

