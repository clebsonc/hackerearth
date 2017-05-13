#include <iostream>
#include <vector>

std::vector<std::vector<int>> getTranspose(const std::vector<std::vector<int>>& m){
  std::vector<std::vector<int>> mt(m.at(0).size(), std::vector<int>(m.size()));
  for (int i = 0; i < m.size(); i++){
    for (int j = 0; j < m.at(i).size(); j++){
      mt.at(j).at(i) = m.at(i).at(j);
    }
  }
  return mt;
}

void print_vector(const std::vector<std::vector<int>> & v){
  for (auto & value : v){
    for (auto & i : value){
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}

int main(){
  int a = 0, b = 0;
  std::cin >> a >> b;
  std::vector<std::vector<int>> v(a, std::vector<int>(b));

  for (int i = 0; i < a; i++){
    for (int j = 0; j < b; j++){
      int c;
      std::cin >> c;
      v.at(i).at(j) = c;
    }
  }
  std::vector<std::vector<int>> v2 = getTranspose(v);
  print_vector(v2);

  return 0;
}

