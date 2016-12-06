#include <iostream>
#include <sstream>
using namespace std;

int  main() {
  int N,B,H,W,menor,p,a,temQuartos,custo,quartos;

  while(cin >> N >> B >> H >> W){
    menor = B + 1; 
    for(int i=0;i<H;++i){
      cin >> p;
      custo = p * N;
      quartos=0;
      for(int j=0;j<W;j++){ 
        cin >> a;
        quartos = quartos + a;
      }
      if(quartos>N){
        if(custo<menor){
          menor = custo;
        }
      }
      // cout << custo << " \n";
    }
    if(menor <= B){
      cout << menor << endl;
    } else {
      cout << "stay home" << endl;
    }
  }
}
