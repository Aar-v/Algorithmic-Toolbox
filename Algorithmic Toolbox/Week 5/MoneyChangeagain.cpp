#include<iostream>
#include<bits/stdc++.h>

// #define MAX_MONEY 1000
// #define MAX_NUM_COINS MAX_MONEY

using namespace std;

// typedef unsigned char UCHAR;
// typedef unsigned short UINT;

// static const UCHAR coins[] = {1, 3, 4}; 
// static const UCHAR num_coins = 3;
// static UINT change[MAX_MONEY + 1] = {0}; 
// static UINT change_LI = 0;

// UINT get_change(UINT);

// int main()
// {
//     UINT M;

//     scanf("%hu", &M);
//     printf("%hu\n", get_change(M));
//     return 0;
// }


// UINT get_change(UINT M)
// {
//     UINT i, num_coins;
   
//     if (M <= change_LI)
//         return change[M];
//     while (++change_LI <= M)
//     {
//         change[change_LI] = MAX_NUM_COINS;
//         for (i = 0; i < num_coins; i++)
//         {
//             if (change_LI >= coins[i])
//             {
//                 num_coins = change[change_LI - coins[i]] + 1;
//                 if (num_coins < change[change_LI])
//                     change[change_LI] = num_coins;
//             }
//         }
//     }
//     return change[M];
// }

int main()
{
  int val[3] = {1,3,4};
  int m;
  int a = std::numeric_limits<int>::max();
  cin >> m;

  int A[] = {0+(a*m)} ;
  for (int i = 1; i < m+1; i++)
  {
    for(int j = 0 ; j<3;j++){
      if (val[j] <= i){
        int coins = A[i-j]+1;
        if (coins < A[i])
                A[i] = coins;
      }
    }

  }
  cout << A[m];
}