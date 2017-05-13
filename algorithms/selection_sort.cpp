#include <iostream>
#include <vector>

void print_vector(const std::vector<int> & vector){
  for (auto & x : vector){
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

void swap(std::vector<int> & v, int i, int j){
  int temp = v.at(i);
  v.at(i) = v.at(j);
  v.at(j) = temp;
}

void selection_sort_to_iteration_x(std::vector<int> & v, int x){
  for (int i = 0; i < static_cast<int>(v.size()); i++){
    if (x == i)
      break;
    int min_index = i;
    for (int j = i+1; j < v.size(); j++){
      if (v.at(j) < v.at(min_index))
        min_index = j;
    }
    swap(v, i, min_index);
  }
  print_vector(v);
}

int main(){
  int n = 0;
  int x = 0;
  std::cin >> n >> x;
  std::vector<int> values(n);
  for (int i = 0; i < n; i++){
    int v = 0;
    std::cin >> v;
    values.at(i) = v;
  }
  selection_sort_to_iteration_x(values, x);

  return 0;
}

