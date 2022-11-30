#include<bits/stdc++.h>


void selection_sort(std::vector<int>& v) {
   for(int i = 0; i < v.size(); i++) {
      int min = v[i];
      int min_index = i;

      for(int j = v.size() - 1; j > i; j--) {
         if(v[j] < min) { min = v[j]; min_index = j; }
      }
      std::swap(v[i], v[min_index]);
   }
}

void printVector(const std::vector<int>& v) {
   std::cout << "Vector is: ";
   for(int k : v) std::cout << k << " ";
   std::cout << "\n";
}

int main() {
   int n;
   std::cout << "Enter the size of array: ";
   std::cin >> n;

   std::vector<int> v(n);

   std::cout << "Enter the elements: ";
   for(int i = 0; i < n; i++) std::cin >> v[i];

   std::cout << "Before sort: \n";
   printVector(v);

   selection_sort(v);

   std::cout << "After sort: \n";
   printVector(v);
}