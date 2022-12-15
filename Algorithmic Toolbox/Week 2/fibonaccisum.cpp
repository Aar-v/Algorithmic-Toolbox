#include <iostream>

long long fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long fibonacci_sum_fast(long long n) {
    long long A[n];
    long long sum = 1;
    A[0] = 0;
    A[1] = 1;
   if (n==0){sum = 0;}
    for(int i=2;i<=n;++i){
        A[i] = (long long)(A[i-1] + A[i-2]) ;
        sum += A[i];
    }

    return (long long)sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n);
    for(int i = 0; i<=n;++i ){
        if (fibonacci_sum_fast(i)==fibonacci_sum_naive(i)){
            std::cout<< i<<'\n'<<"ok"<<'\n';
            
        }else{std::cout<<"N"<<'\n'<<fibonacci_sum_fast(i)<<'\n'<<fibonacci_sum_naive(i);
        break;}
    }
}
