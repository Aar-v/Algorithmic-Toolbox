// Full knapsack without repuititon
#include<bits/stdc++.h>

using namespace std;

#define limit 10000   
#define NEL_MAX 300    

#define typeof __typeof__
#define _cmp(x, y, op) ((x) op (y) ? (x) : (y))
#define _cmp_once(x, y, op) ({      \
		typeof(x) _x = (x);         \
		typeof(y) _y = (y);         \
		_cmp(_x, _y, op); })

#define max(x, y) _cmp_once(x, y, >)
unsigned int max_weight(unsigned int *weights, unsigned int nel, unsigned int lim)
{
    static unsigned int val[limit + 1][NEL_MAX + 1] = { 0 };
    unsigned int i, w;
    unsigned int weight, tmp;
    
    for (i = 1; i <= nel; i++)
        for (w = 1; w <= lim; w++) {
            val[w][i] = val[w][i - 1];
            if ((weight = weights[i - 1]) <= w) {
                tmp = val[w - weight][i - 1] + weight;
                val[w][i] = max(tmp, val[w][i]);
            }
        }
    return val[lim][nel];
}

int main()
{
    unsigned int lim, nel, weights[NEL_MAX];
    unsigned int i;

    cin >> lim >>nel;
    for (i = 0; i < nel; i++)
        cin >> weights[i];
    cout << max_weight(weights, nel, lim);
    return 0;
}