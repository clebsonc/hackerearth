#include <iostream>
#include <vector>

void swap(std::vector<int> & v, int i, int j){
  int temp = v.at(i);
  v.at(i) = v.at(j);
  v.at(j) = temp;
}

int bubble_sort(std::vector<int> & values){
  bool not_sorted = true;
  int count_swaps = 0;
  while (not_sorted){
    not_sorted = false;
    for (int i = 0; i < values.size()-1; i++){
      if (values.at(i) > values.at(i+1)){
        swap (values, i, i+1);
        count_swaps++;
        not_sorted = true;
      }
    }
  }
  return count_swaps;
}

void print_array(const std::vector<int> & v){
  for (auto x : v){
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

int main(){
  int n = 0;
  std::cin >> n;
  std::vector<int> values(n);
  for (int i = 0; i < n; i++){
    int v;
    std::cin >> v;
    values.at(i) = v;
  }
  int qt = bubble_sort(values);
  std::cout << qt << std::endl;

  return 0;
}

