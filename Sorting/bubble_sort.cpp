#include<bits/stdc++.h>


void bubble_sort(std::vector<int>& v) {
   for(int i = v.size() - 1; i >= 0; i--) {
      int max = v[i];
      int max_index = i;

      for(int j = 0; j < i; j++) {
         if(v[j] > max) { max = v[j]; max_index = j; }
      }

      std::swap(v[i], v[max_index]);
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

   bubble_sort(v);

   std::cout << "After sort: \n";
   printVector(v);
}