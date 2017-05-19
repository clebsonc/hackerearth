#include <iostream>
#include <vector>

int matrix_sum(const std::vector<std::vector<int>> & values, 
    std::vector<std::vector<int>> & memo, int l, int c){
  if (l < 0 || c < 0)
    return 0;
  else if (memo.at(l).at(c) == -1){
    int up = matrix_sum(values, memo, l-1, c);
    int left = matrix_sum(values, memo, l, c-1);
    int diag = matrix_sum(values, memo, l-1, c-1);
    memo.at(l).at(c) = values.at(l).at(c) + up + left - diag;
  }
  return memo.at(l).at(c);
}

std::vector<std::vector<int>> cache_sum(const std::vector<std::vector<int>> & values){
  std::vector<std::vector<int>> memo(values.size(), 
      std::vector<int>(values.at(0).size(), -1));
  memo.at(0).at(0) = values.at(0).at(0);
  matrix_sum(values, memo, values.size()-1, values.at(0).size()-1);
  return memo;
}


int main(){
  int n=0, m=0;
  std::cin >> n >> m;
  std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      std::cin >> matrix.at(i).at(j);
    }
  }

  std::vector<std::vector<int>> memo = cache_sum(matrix);

  int queries = 0;
  std::cin >> queries;
  for (int i = 0; i < queries; i++){
    int x=0, y=0;
    std::cin >> x >> y;
    std::cout << memo.at(x-1).at(y-1) << std::endl;
  }

  return 0;
}

