#include<bits/stdc++.h>
using namespace std;

void printVector(vector<pair<int, int>>& v) {
   for(auto p : v) {
      cout << p.first << " " << p.second << endl;
   }
}

float fractional_knapsack(vector<pair<int,int>> v, int weight) {
   sort(v.begin(), v.end(), [&](auto a, auto b){
      float v1 = (float)a.second / (float)a.first;
      float v2 = (float)b.second / (float)b.first;

      return v1 > v2; 
   });


   int k = 0;
   float profit = 0;

   while(k < v.size() && weight > 0) {
      if(v[k].first > weight) {
         profit += ((float)weight / (float)v[k].first) * v[k].second;
         weight = 0;
         break;
      } else {
         profit += v[k].second;
         weight -= v[k].first;
      }
      k++;
   }

   return profit;
}

int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;

   vector<pair<int, int>> entries(n);

   cout << "Enter weight-profit pairs: ";
   for(int i = 0; i < n; i++) {
      cin >> entries[i].first >> entries[i].second;
   }

   int maximum_weight;
   cout << "Enter max weight: ";
   cin >> maximum_weight;

   cout << "Maximum profit: " << fractional_knapsack(entries, maximum_weight);

   return 0;
}