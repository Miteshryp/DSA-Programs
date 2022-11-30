#include<bits/stdc++.h>
using namespace std;


void printMatrix(vector<vector<int>>& v) {
   cout << endl << endl;
   for(int i = 0; i < v.size(); i++) {
      for(int j = 0; j < v[i].size(); j++)
         cout << v[i][j] << " ";
      cout << endl;
   }
   cout << endl << endl;
}

void printVector(vector<pair<int, int>>& v) { 
   cout << endl << endl;
   for(auto p : v) {
      cout << p.first << " " << p.second << endl;
   }
   cout << endl << endl;
}

int knapsack(vector<pair<int, int>>& v, int weight) {
   vector<vector<int>> dp(v.size() + 1, vector<int>(weight + 1));
   sort(v.begin(), v.end(), [&](auto a, auto b) {
      return a.first < b.first;
   });

   printVector(v);

   for(int i = 0; i < v.size(); i++) dp[i][0] = 0;
   for(int i = 0; i < weight; i++) dp[0][i] = 0;

   for(int i = 1; i <= v.size(); i++) {
      int curr_profit = v[i-1].second;
      int curr_weight = v[i-1].first;

      for(int j = 1; j < weight + 1; j++) {
         if(i > j) dp[i][j] = dp[i-1][j];
         else dp[i][j] = max(curr_profit + dp[i-1][j - curr_weight], dp[i][j-1]);
      }   
   }

   printMatrix(dp);

   return dp[v.size()][weight];
}

int main() {
   int n;
   cout << "Enter size: ";
   cin >> n;

   vector<pair<int, int>> entries(n);
   cout << "Enter weight-profit pairs: \n";
   for(int i = 0; i < n; i++) cin >> entries[i].first >> entries[i].second;

   int weight;
   cout << "Enter max weight: ";
   cin >> weight;

   cout << "Max profit is: " << knapsack(entries, weight);
}