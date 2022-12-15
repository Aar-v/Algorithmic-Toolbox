// #include <iostream>
// #include <cassert>
// #include <vector>

// using std::vector;

// int binary_search(const vector<int> &a, int x) {
//   int left = 0, right = (int)a.size(); 
//   //write your code here
//   if (right<left){
//     return left -1;
//   }
//   mid = (int)(left+ ((left + right)/2))
//   if (x==a[mid]){return mid;}
//   else if (x<a[mid])
//   {
//     binary_search()
//   }
  
// }

// int linear_search(const vector<int> &a, int x) {
//   for (size_t i = 0; i < a.size(); ++i) {
//     if (a[i] == x) return i;
//   }
//   return -1;
// }

// int main() {
//   int n;
//   std::cin >> n;
//   vector<int> a(n);
//   for (size_t i = 0; i < a.size(); i++) {
//     std::cin >> a[i];
//   }
//   int m;
//   std::cin >> m;
//   vector<int> b(m);
//   for (int i = 0; i < m; ++i) {
//     std::cin >> b[i];
//   }
//   for (int i = 0; i < m; ++i) {
//     //replace with the call to binary_search when implemented
//     std::cout << linear_search(a, b[i]) << ' ';
//     std::cout << binary_search(a, b[i]) << ' ';
//   }
// }

#include<bits/stdc++.h>
using namespace std;
int binary_search(int L[],int low , int high, int key){
    if (high > low){return -1;}
    int mid= (int)(low +((low + high)/2));
    if (L[mid] == key){return mid;}
    else if (key < L[mid]){return binary_search(L,low,mid-1,key);}
    else {return binary_search(L,mid+1,high,key);}
}

int main()
{
    int a,b;
    cin >> a;
    int L[a];
    for ( int i = 0; i < a; i++)
    {
        cin >> L[i];
    }
    cin >> b;
    int S[b];
    for ( int i = 0; i < b; i++)
    {
        cin >> S[i];
    }
    for (int i = 0 ; i< b;i++){
        int key = S[i];
        
        cout << binary_search(L,0,a,key);
        
    }

    // for (int i = 0; i<a ; i++)
    // {cout << L[i];}
    // for (int i = 0; i<b ; i++)
    // {cout << S[i];}
    return 0;
}
