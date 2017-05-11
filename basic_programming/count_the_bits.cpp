#include <iostream>

int count_the_bits(int v){
  int count = 0;
  while (v){
    int rbit = v & ~(v-1);
    v ^= rbit;
    count++;
  }
  return count;
}

int main(){
  int t;
  std::cin >> t;
  for (int i = 0; i < t; i++){
    int v;
    std::cin >> v;
    std::cout << count_the_bits(v) << std::endl;
  }

  return 0;
}

