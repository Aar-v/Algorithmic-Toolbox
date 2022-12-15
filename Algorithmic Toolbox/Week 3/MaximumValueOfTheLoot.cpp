#include<bits/stdc++.h>
using namespace std;

bool func(pair<int,int> p1, pair<int,int> p2)
{
    double r1= (double)p1.first / p1.second;
    double r2= (double)p2.first / p2.second;
    if(r1 > r2)
    return true;
    return false;
}

int main()
{
  int n,wt;
  cin>>n>>wt;
  vector<pair<int,int>> vec;
  while(n--)
  {
    int a,b;
    cin>>a>>b;
    vec.push_back({a,b});
  }
  sort(vec.begin(),vec.end(),func);
  double pr=0;
  for(auto i: vec)
  {
    if(i.second < wt)
    {
    pr += i.first;
    wt -= i.second;
    }
    else
    {
      pr += ((double)wt/i.second)*i.first;
      break;
    }
  }
  printf("%0.4lf",pr);
return 0;
}