#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(int a, int b){
    int c = a%b;
    if(c==0){return b;}
    else{ 
        gcd_fast(b,c);
    }
}

long long lcm_fast(int a,int b){
    int n = gcd_fast(a,b);
    a/=n;
    return (long long) a*b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  //if (lcm_naive(a,b) == lcm_fast(a,b)){std::cout << "True";}
  return 0;
}
