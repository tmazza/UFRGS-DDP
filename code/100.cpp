#include <iostream>
#include <sstream>
using namespace std;


int f(int n,int count){
  if(n==1){
    return count;
  } else if(n%2==0){
    return f(n/2,count+1);;
  } else {
    return f(3*n+1,count+1);
  }
}

int  main() {
  int i,j,cicles,maior,a,b;
  while(cin >> i >> j){
    a=i;b=j;
    if(j<i)
      swap(i,j);
    maior = 0;
    for(int k=i;k<=j;k++){
      cicles = f(k,1);
      if(cicles > maior)
        maior = cicles;
    }
    cout << a << " " << b << " " << maior  << "\n";
  }
}
