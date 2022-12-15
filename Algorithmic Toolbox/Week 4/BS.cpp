#include<bits/stdc++.h>
using namespace std;
int binarySearch(int L[], int low, int high, int key)
{
    if (high >= low) {
       // int mid = l + (r - l) / 2;
       int mid= (int)(low+((high-low)/2));
 
    
        if (L[mid] == key)
            return mid;
        if (key<L[mid])
            return binarySearch(L, low, mid - 1, key);
 
        return binarySearch(L, mid + 1, high, key);
    }
    return -1;
}
 
int main()
{
    int a,b;
    cin >> a;
    int L[a];
    for ( int i = 0; i < a; i++)
    {
        cin >> L[i];
    }
    cin >> b;
    int S[b];
    for ( int i = 0; i < b; i++)
    {
        cin >> S[i];
    }
    for (int i = 0 ; i< b;i++){
        int key = S[i];
        cout<<binarySearch(L,0,a,key)<< " ";
    }

    // for (int i = 0; i<a ; i++)
    // {cout << L[i];}
    // for (int i = 0; i<b ; i++)
    // {cout << S[i];}
    return 0;
}