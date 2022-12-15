#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void partition3(vector<int> &a, int l, int r,int &begin, int &end) {
    int x = a[l];
    begin = l, end = r;
    int i = begin + 1;
    for (int i = begin +1 ; i <= end; i++) {
    //while (i<=end){
        if (a[i] <= x) {
            
            swap(a[i], a[begin]);
            ++begin;
            //i++;
      
        }
        if (a[i >= x]) 
        {
            swap(a[i], a[end]);
            end--;
            i--;
        }

        //i++;
    }
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return ;
  }

  //int k = l + rand() % (r - l + 1);
  //swap(a[l], a[k]);
  int begin1,end1;
  partition3(a,l,r,begin1,end1);
  randomized_quick_sort(a, l, --begin1);
  //randomized_quick_sort(a,++end1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
