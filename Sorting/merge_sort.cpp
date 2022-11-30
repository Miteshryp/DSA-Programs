#include<bits/stdc++.h>

std::vector<int> merge(std::vector<int>& v1, std::vector<int>& v2) {
   std::vector<int> v(v1.size() + v2.size());

   int i = 0, j = 0, k = 0;

   // creating a sorted array from the given 2
   while(i < v1.size() && j < v2.size()) {
      if(v1[i] < v2[j]) v[k++] = v1[i++];
      else v[k++] = v2[j++];
   }

   // filling up the remaining element if v2 has been exhausted
   while(i < v1.size()) {
      v[k++] = v1[i++];
   }

   // filling up the remaining element if v1 has been exhausted 
   while(j < v2.size()) {
      v[k++] = v2[j++];
   }

   // returning the sorted vector
   return v;
}

void merge_sort(std::vector<int>& v) {

   if(v.size() == 1) return;

   int mid = v.size() / 2;
   std::vector<int> v1 = std::vector<int>(v.begin(), v.begin() + mid);
   std::vector<int> v2 = std::vector<int>(v.begin() + mid, v.end());

   merge_sort(v1);
   merge_sort(v2);

   v = merge(v1, v2);

   // 1. return if only one element exists in the array
   // 2. split array into 2 from mid
   // 3. run merge sort on both
   // 4. merge the 2 arrays returned
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

   merge_sort(v);

   std::cout << "After sort: \n";
   printVector(v);
}