#include <iostream>
#include <string>

void count_digits(const std::string & s){
  int n[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (char c : s){
    n[c-'0'] += 1;
  }
  for (int i = 0; i < 10; i++){
    std::cout << i << " " << n[i] << std::endl;
  }
}

int main(){
  std::string s="";
  std::cin >> s;
  count_digits(s);

  return 0;
}

