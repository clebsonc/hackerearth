#include <iostream>
#include <string>
#include <algorithm>

int main(){
  std::string s;
  int a = 0, b = 0;
  int n = 0;
  std::cin >> n;

  for(int i = 0; i < n; i++){
    std::cin >> s >> a >> b;
    std::string::reverse_iterator it = s.rbegin()+(s.size()-b-1);
    std::string::reverse_iterator ite = s.rend() - a;
    std::sort(it, ite);
    std::cout << s << std::endl;
  }


  return 0;
}

