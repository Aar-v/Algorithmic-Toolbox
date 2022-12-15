#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
long long get_fibonacci_huge_fast(long long n, long long m){
    long long A[n];
    A[0] = 0;
    A[1] = 1;
    for(long long i=2;i<=n;++i){
        A[i] = ((long long)A[i-1] + (long long)A[i-2])% m  ;
       
    }

    return (long long) A[n] ;
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
