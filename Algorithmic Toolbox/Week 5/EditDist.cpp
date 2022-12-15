#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define x 100
#define typeof __typeof__
#define _cmp(x, y, op) ((x) op (y) ? (x) : (y))
#define _cmp_once(x, y, op) ({  \
		typeof(x) _x = (x);     \
		typeof(y) _y = (y);     \
		_cmp(_x, _y, op); })

#define min(x, y) _cmp_once(x, y, <)
#define min3(x, y, z) min((typeof(x))min(x, y), z)

unsigned short edit_distance(const char *str1, const char *str2)
{
    static unsigned short d[x+1][x+1];
    unsigned short n, m;
    unsigned short i, j;

    n = strlen(str1);
    m = strlen(str2);
    for (i = 0; i <= n; i++)
        d[i][0] = i;
    for (j = 1; j <= m; j++)
        d[0][j] = j;
    for (j = 1; j <= m; j++)
        for (i = 1; i <= n; i++) {
            if (str1[i-1] == str2[j-1])
                d[i][j] = min3(d[i][j-1] + 1, d[i-1][j] + 1, d[i-1][j-1]);
            else
                d[i][j] = min3(d[i][j-1] + 1, d[i-1][j] + 1, d[i-1][j-1] + 1);
        }
    return d[n][m];
}

int main()
{
    char s[x+1], t[x+1];

    cin >> s;
    cin >> t;
    cout << edit_distance(s,t);
    return 0;
}