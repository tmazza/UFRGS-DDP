#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
using namespace std;

#define RIG 0
#define TOP 1
#define LEF 2
#define BOT 3

int b,w,posx,posy,direcao,moveu;

void moveTop(){ posx--; direcao = TOP; }
void moveBot(){ posx++; direcao = BOT; }
void moveLef(){ posy--; direcao = LEF; }
void moveRig(){ posy++; direcao = RIG; }

bool canMoveTop(int *m){
  // if(posx == 2 and posy == 4){
  //   cout << (posx-1) << "->" << m[(posx-1)*w+(posy)] << "|---\n";
  // }
  return (posx-1 >= 0 && m[(posx-1)*w+(posy)] == 0);


}
bool canMoveBot(int *m){ return (posx+1 < b  && m[(posx+1)*w+(posy)] == 0); }
bool canMoveRig(int *m){ return (posy+1 < w  && m[(posx)*w+(posy+1)] == 0); }
bool canMoveLef(int *m){ return (posy-1 >= 0 && m[(posx)*w+(posy-1)] == 0); }

void daUmaPasso(int *m){
    if(direcao == RIG){
      if(canMoveBot(m)){ moveBot(); }
      else if(canMoveRig(m)){ moveRig(); }
      else if(canMoveTop(m)){ moveTop(); }
      else if(canMoveLef(m)){ moveLef(); }
    } else if(direcao == TOP){
      if(canMoveRig(m)){ moveRig(); }
      else if(canMoveTop(m)){ moveTop(); }
      else if(canMoveLef(m)){ moveLef(); }
      else if(canMoveBot(m)){ moveBot(); }
    } else if(direcao == LEF){
      if(canMoveTop(m)){ moveTop(); }
      else if(canMoveLef(m)){ moveLef(); }
      else if(canMoveBot(m)){ moveBot(); }
      else if(canMoveRig(m)){ moveRig(); }
    } else if(direcao == BOT){
      if(canMoveLef(m)){ moveLef(); }
      else if(canMoveBot(m)){ moveBot(); }
      else if(canMoveRig(m)){ moveRig(); }
      else if(canMoveTop(m)){ moveTop(); }
    }
}


int  main() {
  string linha;
  while(cin >> b >> w){
    if(b==0 and w==0){
        break;
    } else {
      int maze[b][w];
      int passos[b][w];

      getline(cin,linha);
      for(int i=0;i<b;i++){
        getline(cin,linha);
        for(int j=0;j<w;j++){
          maze[i][j] = (int) linha[j] == '1' ? 1 : 0;
          passos[i][j] = 0;
        }
      }
      direcao = RIG;
      posx = b-1;
      posy = 0;
      // cout << posx << "-" << posy << "|" << direcao << "\n";
      do {
          daUmaPasso((int *) maze);
          // cout << posx << "-" << posy << "|" << direcao << "\n";
          passos[posx][posy]++;
      } while(!(posx == (b-1) and posy == 0));

      int qtd,zero=0,um=0,dois=0,tres=0,quatro=0;

      for(int i=0;i<b;i++){
        for(int j=0;j<w;j++){
          if(maze[i][j]==0){
            qtd = passos[i][j];
            switch(qtd){
              case 0: zero++;  break;
              case 1: um++;    break;
              case 2: dois++;  break;
              case 3: tres++;  break;
              case 4: quatro++;  break;
            }
          }
        }
      }
      printf("%3d%3d%3d%3d%3d\n",zero,um,dois,tres,quatro);
    }
  }

}
