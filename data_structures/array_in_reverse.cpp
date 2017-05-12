#include <iostream>
#include <exception>

int main(){
  int n = 0;
  std::cin >> n;
  
  int * p = nullptr;

  try{
    p = new int[n];
    for (int i = 0; i < n; i++){
      std::cin >> *(p+i);
    }
    for (int i = n-1; i >= 0; i--){
      std::cout << *(p+i) << std::endl;
    }

  } catch (const std::bad_alloc & ba){
    std::cout << ba.what() << std::endl;
  }

  delete[] p;
  
  return 0;
}

