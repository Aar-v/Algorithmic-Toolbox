#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0,a=1;
    vector<int> vec;
    while(sum < n)
    {
        cout<<sum<<" "<<a<<endl;
     if(sum == n)
     break;
    if(sum +a > n)
     {
        sum -= vec[vec.size()-1];
      vec.pop_back();
     }
     else if(sum<n)
     {
        sum +=a;
     vec.push_back(a);
     }
     a++;
    }
    cout<<vec.size()<<endl;
    for(auto i:vec)
    cout<<i<<" ";
    return 0;
}