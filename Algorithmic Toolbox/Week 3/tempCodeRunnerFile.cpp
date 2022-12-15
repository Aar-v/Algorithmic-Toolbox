#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int amount;
  int max = 0;

  // write your code here
  while (capacity>0){
    if (capacity==0){return 0;;}
    for (int i = 0; i < weights.size(); i++)
    {
        if (values[i]>=values[max]){max = i;}
    }
    amount = std::min(weights[max],capacity);
    value = (values[max]*(amount/weights[max]));
    weights.erase(weights.begin()+max); 
    values.erase(values.begin()+max);
  }    
  return value + get_optimal_value(capacity,weights,values);

}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

 // double optimal_value = get_optimal_value(capacity, weights, values);
  cout<< get_optimal_value(capacity, weights, values);
  std::cout.precision(10);
  //std::cout << optimal_value << std::endl;
  return 0;
}
