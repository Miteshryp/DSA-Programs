#include<bits/stdc++.h>

void quick_sort(std::vector<int>& v) {
   // 1. select 1st element as a pivot element and mark its index
   // 2. assign a low and high pointer to the starting and ending position
   // 3. move the low pointer up untill the value of element is not greater than pivot
   // 4. move the high pointer down untill the value of element is not smaller than or equal to pivot
   // 5. if high < low, swap first element with high. The array is now sorted around high index
   // 6. if low < high, swap low and high. The 3
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

   quick_sort(v);

   std::cout << "After sort: \n";
   printVector(v);
}