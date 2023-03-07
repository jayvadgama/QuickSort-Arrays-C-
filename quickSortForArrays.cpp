#include <iostream>
using namespace std;

//function for partitioning array

int part(int low, int high, int * a)
{
  // p = pivot
  int h = high ,l = low, p, t; 
  p = a[low];
  
  while(low < high)
  {
    while(a[l] < p)
    {
      l++;
    }
    while(a[h] > p)
    {
      h--;
    }
    if(l < h)
    {
      t = a[l];
      a[l] = a[h];
      a[h] = t;
    }
    else
    {
      t = p;
      p = a[l];
      break;
    }
  }
  return h;
}

void quick(int l, int h, int * a)
{
  int index;
  if(l < h)
  {
    index = part(l, h, a);
    quick(l,index - 1, a);
    quick(index + 1, h, a);  
  }  
}

int main() 
{
  int a[100], n, l, h, i;
  
  cout << "Enter number of elements:";
  cin >> n;
  
  cout << "Enter the elements:";
  for(i = 0; i < n; i++)
  cin >> a[i];
  
  h = n - 1;
  l = 0;
  quick(l, h, a);
  
  cout << "\nAfter Sorting:\n";
  
  for(i = 0; i < n; i++)
  {
    cout << a[i] << "\t";    
  }
  
  return 0;
}