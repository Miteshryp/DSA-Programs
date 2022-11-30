#include<bits/stdc++.h>


void insertion_sort(std::vector<int>& v) {
   for(int i = 1; i < v.size(); i++) {
      // element is unsorted
      if(v[i] < v[i-1]) {
         int j = i;

         // pushing the element to the correct position
         while(j > 0 && v[j] < v[j-1]) {
            std::swap(v[j], v[j-1]);
            j--;
         }
      }
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

   insertion_sort(v);

   std::cout << "After sort: \n";
   printVector(v);
}