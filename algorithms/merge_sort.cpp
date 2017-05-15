#include <iostream>
#include <vector>

void copy_values(const std::vector<int> & v1,
    std::vector<int> & v2, int i, int j){
  while (i <= j){
    v2.emplace_back(v1.at(i));
    i++;
  }
}

long long int combine(std::vector<int> & v, int il, int mid, int ir){
  std::vector<int> left;
  std::vector<int> right;
  copy_values(v, left, il, mid);
  copy_values(v, right, mid+1, ir);
  int i = 0, j = 0, k = il;
  long long int count = 0;
  while (i < static_cast<int>(left.size()) && 
      j < static_cast<int>(right.size())){
    if (left.at(i) <= right.at(j)){
      v.at(k) = left.at(i);
      i++;
      k++;
    }
    else {
      count += left.size()-i;
      v.at(k) = right.at(j);
      j++;
      k++;
    }
  }
  while (i < static_cast<int>(left.size())){
    v.at(k) = left.at(i);
    i++;
    k++;
  }
  while (j < static_cast<int>(right.size())){
    v.at(k) = right.at(j);
    j++;
    k++;
  }
  return count;
}


long long int merge_sort_count_inversion(std::vector<int> & v, int il, int ir){
  if (il < ir){
    int mid = (il + ir)/2;
    long long int c1 = merge_sort_count_inversion(v, il, mid);
    long long int c2 = merge_sort_count_inversion(v, mid+1, ir);
    long long int c3 = combine(v, il, mid, ir);
    return c1 + c2 + c3;
  }
  return 0;
}

int main(){
  int n;
  std::cin >> n;
  std::vector<int> values(n);
  for (int i = 0; i < n; i++){
    std::cin >> values.at(i);
  }
  long long int inversions = merge_sort_count_inversion(values, 0, values.size()-1);
  std::cout << inversions << std::endl;

  return 0;
}

