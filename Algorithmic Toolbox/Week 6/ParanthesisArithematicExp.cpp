// Code to get maximum value for a given expression py placing paranthesis'()' in the expression.
#include<bits/stdc++.h>
using namespace std;

#define N_MAX 14
#define EXPRSIZ_MAX (2 * N_MAX - 1)
#define typeof __typeof__
#define _cmp(a, b, op) ((a) op (b) ? (a) : (b))
#define _cmp_once(a, b, op) ({      \
		typeof(a) _a = (a);         \
		typeof(b) _b = (b);         \
		_cmp(_a, _b, op); })

#define min(a, b) _cmp_once(a, b, <)
#define min3(a, b, c) min((typeof(a))min(a, b), c)
#define min5(a, b, c, d, e) min((typeof(a))min3(a, b, c), (typeof(d))min(d, e))
#define max(x, y) _cmp_once(x, y, >)
#define max3(x, y, z) max((typeof(x))max(x, y), z)
#define max5(a, b, c, d, e) max((typeof(a))max3(a, b, c), (typeof(d))max(d, e))
long digit(char *expression, unsigned int index)
{
    char c;
    
    if (!isdigit(c = expression[index])) {
        fprintf(stderr, "error: expression[%u] is not a digit\n", index);
        exit(1);
    }
    return c - '0';
}

long eval(long x, char op, long y)
{
        switch (op) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        default:
            
            cout << stderr << "The symbol" << op << "is not an operator";
            exit(1);
        }
}

long maxval(char *expression)
{
    static long m[EXPRSIZ_MAX][EXPRSIZ_MAX], M[EXPRSIZ_MAX][EXPRSIZ_MAX];
    unsigned int i, j, k, n, s;
    long a, b, c, d;

    n = (strlen(expression) + 1) / 2;
    for (i = 0; i < n; i++) {
        m[i][i] = digit(expression, 2 * i);
        M[i][i] = digit(expression, 2 * i);
    }
    for (s = 1; s < n; s++)
        for (i = 0; i < (n - s); i++) {
            j = i + s;
            m[i][j] = LONG_MAX;
            M[i][j] = LONG_MIN;
            for (k = i; k < j; k++) {
                a = eval(M[i][k], expression[2 * k + 1], M[k + 1][j]);
                b = eval(M[i][k], expression[2 * k + 1], m[k + 1][j]);
                c = eval(m[i][k], expression[2 * k + 1], M[k + 1][j]);
                d = eval(m[i][k], expression[2 * k + 1], m[k + 1][j]);
                m[i][j] = min5(a, b, c, d, m[i][j]);
                M[i][j] = max5(a, b, c, d, M[i][j]);
            }
        }
    return M[0][n-1];
}

int main()
{
    char expression[EXPRSIZ_MAX];

    cin >> expression;
    cout <<  maxval(expression);
    return 0;
}