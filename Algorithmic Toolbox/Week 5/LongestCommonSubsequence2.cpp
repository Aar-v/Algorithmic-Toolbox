#include<iostream>
#include<bits/stdc++.h>

using namespace std;


#define typeof __typeof__
#define _cmp(x, y, op) ((x) op (y) ? (x) : (y))
#define _cmp_once(x, y, op) ({      \
		typeof(x) _x = (x);         \
		typeof(y) _y = (y);         \
		_cmp(_x, _y, op); })

#define max(x, y) _cmp_once(x, y, >)
unsigned short lcs2(const int *xs, const int *ys, 
                      unsigned short n, unsigned short m)
{
    unsigned short d[100+1][100+1] = { 0 };
    unsigned short i, j;

    for (j = 1; j <= m; j++)
        for (i = 1; i <= n; i++) {
            if (xs[i-1] == ys[j-1])
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = max(d[i][j-1], d[i-1][j]);
        }
    return d[n][m];
}

int main()
{
    int xs[100], ys[100];
    unsigned short n, m;
    unsigned short i;

    scanf("%hu", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &xs[i]);
    scanf("%hu", &m);
    for (i = 0; i < m; i++)
        scanf("%d", &ys[i]);
    printf("%d\n", lcs2(xs, ys, n, m));
    return 0;
}