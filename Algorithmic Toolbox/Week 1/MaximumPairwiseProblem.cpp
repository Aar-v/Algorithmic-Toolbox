#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::max;

long long MaxPairwiseProduct(const vector<long long>& numbers) {
    long long product = 0;
    long long n = numbers.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            product = max(product, numbers[i] * numbers[j]);
        }
    }
    return product;
}

long long FastMaxPairwiseProduct(const vector<long long>&numbers){
    //long long product = 0;
    int n = numbers.size();

    int index1 = -1;
    for(int i=0; i < n; ++i){
        if((index1 == -1)||(numbers[i] > numbers[index1])){
            index1 = i;
        }
    }
    int index2 = -1;
    for(int j=0; j < n; ++j){
        if((j != index1)&&((index2 == -1)||(numbers[j]>numbers[index2]))){
            index2 = j;
        }
    }
    return ((long long)numbers[index1])*numbers[index2];
}
int main() {
    int n;
    cin >> n;
    vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    long long product = FastMaxPairwiseProduct(numbers);
    cout << product << "\n";
    return 0;
}