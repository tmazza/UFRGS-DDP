#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int  main() {
  int a,b,c,read,custo,somaParcial;
  std::vector<int> v(0,0);
  std::vector<int>::iterator it;

  while(cin >> c){
    if(c == 0){ break; }
    custo=somaParcial=0;

    for(int i=0;i<c;i++){
      cin >> read;
      v.push_back(read);
    }

    while(v.size() > 1){
        sort(v.begin(),v.end());
        a = v.at(0);
        b = v.at(1);
        somaParcial = a + b;
        custo += somaParcial;
        v.erase(v.begin());
        v.erase(v.begin());
        v.push_back(somaParcial);
    }

    v.clear();

    cout << custo << "\n";
  }
}
