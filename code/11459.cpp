#include <iostream>
#include <sstream>
using namespace std;

int  main() {
  int qtd,a,b,c,rolled,jogando,acabou;
  cin >> qtd;
  for(int i=0;i<qtd;i++){
    cin >> a >> b >> c;
    int players[a];
    for(int j=0;j<a;j++){ players[j]=1; }

    // inicios e finais de cada bloco
    int blocos[b][2];
    for(int j=0;j<b;j++){
      int start,end;
      cin >> start >> end;
      if(start != end){
        blocos[j][0] = start;
        blocos[j][1] = end;
      }
    }

    // valor ao jogar dado
    jogando=0;
    acabou = false;
    for(int j=0;j<c;j++){
      cin >> rolled;
      if(!acabou){
        players[jogando] = players[jogando]+rolled;
        for(int k=0;k<b;k++){
          if(blocos[k][0] == players[jogando]){
            players[jogando] = blocos[k][1];
          }
        }
        if(players[jogando] > 100){
          players[jogando] = 100;
        }
        if(players[jogando]==100){
          acabou = true;
        }
        jogando++;
        jogando=jogando%a;
      }
    }
    for(int j=0;j<a;j++){
      cout << "Position of player " << (j+1) << " is " << players[j] << ".\n";
    }
  }

}
