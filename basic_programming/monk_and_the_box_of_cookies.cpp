#include <iostream>
#include <vector>

int getIndexSetBit(int bit){
  int pos = 0;
  while (bit){
    bit = bit >>  1;
    pos++;
  }
  return pos-1;
}


int main(){
  int t;
  int n;
  std::cin >> t;

  for (int i = 0; i < t; i++){
    std::vector<int> values(32, 0);
    std::cin >> n;
    int v = 0;
    for (int j = 0; j < n; j++){
      std::cin >> v;
      while (v){
        int bit = v & ~(v-1);
        int pos = getIndexSetBit(bit);
        values.at(pos) = values.at(pos) + 1;
        v = v ^ bit;
      }
    }
    int max = -1;
    int index = -1;
    for (int j = 0; j < static_cast<int>(values.size()); j++){
      if (values.at(j) > max){
        max = values.at(j);
        index = j;
      }
    }
    std::cout << index << std::endl;
  }
  
  return 0;
}
