#include <iostream>
#include <bits/stdc++.h>

#define NUM_OPERATIONS 3 
#define MAX_VALUE 1000000
#define MAX_NUM_OPERATIONS UINT_MAX

using namespace std; 

enum operation {
    ADD_ONE = 1,
    MULT_BY_TWO = 2,
    MULT_BY_THREE = 3
};

static unsigned int nooperations_table[MAX_VALUE + 1] = { 0 };
static unsigned int A = 1;


unsigned int nopers(unsigned int x)
{
    unsigned int j, n;

    if (x<= A)
        return nooperations_table[x];
    while (++A <= x) {
        n = nooperations_table[A] = MAX_NUM_OPERATIONS;
        for (j = 1; j <= NUM_OPERATIONS; j++) {
            switch (j) {
            case ADD_ONE:
                n = nooperations_table[A - 1] + 1;
                break;
            case MULT_BY_TWO:
                if (A % 2 == 0)
                    n = nooperations_table[A / 2] + 1;
                break;
            case MULT_BY_THREE:
                if (A % 3 == 0)
                    n = nooperations_table[A / 3] + 1;
            }
            if (n < nooperations_table[A])
                nooperations_table[A] = n;
        }
    }
    return nooperations_table[x];
}


void outval(unsigned int x)
{
    if (x< 1) {
        return;
    }
    if (x% 3 == 0 && nooperations_table[x] == nooperations_table[x/ 3] + 1) {
        outval(x/ 3);
        cout <<  x<< " ";
    } else if (x% 2 == 0 && nooperations_table[x] == nooperations_table[x/ 2] + 1) {
        outval(x/ 2);
        cout << x<< " ";
    } else {
        outval(x- 1);
        cout << x<< " ";
    }
}

int main()
{
    unsigned int n, value;

    cin >> value;
    n = nopers(value);
    cout <<  n << '\n';
    outval(value);
    putchar('\n');
    return 0;
}