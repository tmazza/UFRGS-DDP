#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INSERT 1
#define REMOVE 2

int  main() {
  int c,mayS,mayQ,mayP,ope,val,valS,valQ,valP,posP,possiveis;
  std::vector<int> s(0,0); // stack
  std::vector<int> q(0,0); // queue
  std::vector<int> p(0,0); // priority queue
  std::vector<int>::iterator it;

  while(cin >> c){
    mayS=mayQ=mayP=true;
    for(int i=0;i<c;i++){
      cin >> ope >> val;
      if(ope == INSERT){
        s.push_back(val);
        q.push_back(val);
        p.push_back(val);
      } else if(ope == REMOVE) {
        if(mayS){
          if(s.size()>0 && s.at(s.size()-1) == val){
            s.erase(s.begin()+(s.size()-1));
          } else {
            mayS=false;
          }
          // cout << valS << "s ";
        }
        if(mayQ){
          if(q.size()>0 && q.at(0) == val) {
            q.erase(q.begin());
          } else {
            mayQ=false;
          }
          // cout << valQ << "q ";
        }
        if(mayP){
          if(p.size()>0) {
            it = max_element(p.begin(),p.end());
            posP = distance(p.begin(),it);
            if(p.at(posP) == val){
              p.erase(p.begin()+posP);
            } else {
              mayP=false;
            }
          } else {
            mayP=false;
          }
          // cout << p.at(posP) << "p--\n ";
        }
      } else {
        cout << "OPERACAO INVALIDA";
      }

    }

    possiveis=0;
    if(mayS){ possiveis++; }
    if(mayQ){ possiveis++; }
    if(mayP){ possiveis++; }

    if(possiveis==0){
      cout << "impossible";
    } else if(possiveis>1){
      cout << "not sure";
    } else {
      if(mayS){ cout << "stack"; }
      if(mayQ){ cout << "queue"; }
      if(mayP){ cout << "priority queue"; }
    }
    cout << "\n";

    s.clear();
    q.clear();
    p.clear();

  }
  return 0;
}
