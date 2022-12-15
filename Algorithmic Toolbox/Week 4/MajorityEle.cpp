#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
//   for (int i = 1; i < right; i++)
//   {
//     int currentElement = a[i];
//     int count = 0;
//     // for (int j = 1; j < right; j++)
//     // {
//     //     if(a[j]==currentElement){
//     //         count += 1;
//     //     }
//     // }
    
//     count +=1;
//     if (count > right/2) return a[i];
    
//   }
  int count = 0,i,currentElement;
  for ( i = 1; i < right; i++)
  {
    if (count == 0) currentElement = a[i];
    if (a[i]==currentElement) count++;
    else count--;
  }
  count = 0;
  for (i = 0; i < right; i++) {
    if (a[i] == currentElement) count++;
  }
  if (count > right/2) return currentElement;
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
