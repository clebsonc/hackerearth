#include <iostream>
#include <vector>


void swap(std::vector<long int> & values, int & l, int & r){
  long int temp = values.at(l);
  values.at(l) = values.at(r);
  values.at(r) = temp;
  l++;
  r--;
}

void move_values(std::vector<long int> & values, int & l, int & r, int p){
  while (l <= r){
    while (values.at(l) < p)
      l++;
    while (values.at(r) > p)
      r--;
    if (l <= r)
      swap(values, l, r);
  }
}

long int median_of_three(std::vector<long int> & values, int l, int r){
  int a = values.at(l);
  int b = values.at(r);
  int c = values.at((l+r)/2);
  if (a < b)
    return b < c ? b : c;
  if (a < c)
    return c < b ? c : b;
  if (b < c)
    return c < a ? c : a;
}

void quick_sort(std::vector<long int> & v, int l, int r){
  if (l < r){
    int i = l, j = r;
    long int pivot = median_of_three(v, i, j);
    move_values(v, i, j, pivot);
    if (l < j)
      quick_sort(v, l, j);
    if (i < r)
      quick_sort(v, i, r);
  }
}

int main(){
  int n;
  std::cin >> n;
  std::vector<long int> values(n);
  for (int i = 0; i < n; i++){
    std::cin >> values.at(i);
  }
  quick_sort(values, 0, values.size()-1);

  for (int v : values)
    std::cout << v << " ";
  std::cout << std::endl;

  return 0;
}

