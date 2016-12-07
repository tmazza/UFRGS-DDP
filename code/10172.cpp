#include <iostream>
#include <map>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int sets,N,S,Q,qtd,ID,station,feito,count,iteracoes,tempo=0,ultimoTempo=0;
  stack<int> truck;

  cin >> sets;
  // S - limite a ser transportado
  // Q - limite de carga em todas as plataformas B

  for(int i=0;i<sets;i++){
    cin >> N >> S >> Q;
    map< int,queue<int> > stB;

    // Inclui todas as cargas iniciais na plataforma B de cada estacao
    for(int j=0;j<N;j++){
      cin >> qtd;
      for(int k=0;k<qtd;k++){
        cin >> ID;
        stB[j+1].push(ID);
      }
    }

    station=0; 
    count=0;
    iteracoes=0;
    tempo=0;
    feito = false;
    while(!feito) {
      ultimoTempo = tempo;
      station = count + 1;
      //cout << "\nestacao: " << station << " \n";

      // verificar cada carga do caminhao se pertence a estação atual empilhando em B se não pertencer (respeitar limite Q da plataforma B)
      while(!truck.empty() && (stB[station].size() < Q || truck.top() == station)){
        ID = truck.top();
        if(ID != station){
          //cout << "  load " << station << "B: " << ID << "\n";
          stB[station].push(ID);
        } else {
          //cout << "  unlo " << station << "A: " << ID << "\n";
        }
        truck.pop();
        tempo+=1;
      }

      // carregar no caminha cargas em B (respeitar limite S do caminhao)
      while(truck.size() < S && stB[station].size() > 0){
        ID = stB[station].front();
        stB[station].pop();
        //cout << "  load truck " << ID << "\n";
        truck.push(ID);
        tempo+=1;
      }

      feito = truck.empty();
      if(feito){
        for(int j=0;j<N;j++){
          if(!stB[j].empty()){
            feito = false;
          }
        }
      }

      tempo+=2;

      count++;
      count = count % N;
      iteracoes++;
      //cout << "Tempo: " << (tempo - ultimoTempo) << "\n";
    } 
     cout << tempo-2 << "\n";

    stB.clear();
  }




  return 0;
}
