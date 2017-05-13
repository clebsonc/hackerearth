#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> insertion_sort(std::vector<int> values){
  for (int i = 1; i < values.size(); i++){
    int key = values.at(i);
    int j = i;
    while (j > 0 && values.at(j-1) > key){
      values.at(j) = values.at(j-1);
      j--;
    }
    values.at(j) = key;
  }
  return values;
}

std::unordered_map<int, int> map_index(const std::vector<int> & v){
  int index=1;
  std::unordered_map<int, int> map;
  for (int x : v){
    map.emplace(x, index);
    index++;
  }
  return map;
}

int main(){
  int n = 0;
  std::cin >> n;
  std::vector<int> values(n);
  for (int i = 0; i < n; i++){
    int v=0;
    std::cin >> v;
    values.at(i) = v;
  }
  std::vector<int> sorted_values = insertion_sort(values);
  std::unordered_map<int, int> map = map_index(sorted_values);
  for(int v : values){
    std::cout << map.at(v) << " ";
  }
  std::cout << std::endl;

  return 0;
}

