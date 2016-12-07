#include <iostream>
#include <vector>
using namespace std;

int main(){
  std::vector<int>::iterator it;
  int n,a,b;

  while(cin >> n){
    if(n == 0) { break; }
    std::vector<int> cards(n,0);
    std::vector<int> discart(0,0);

    for(int i=0;i<n;i++){ cards[i] = i+1; }

    while(cards.size()>1){
      a = cards.at(0);
      b = cards.at(1);
      discart.push_back(a);
      cards.erase(cards.begin());
      cards.erase(cards.begin());
      cards.push_back(b);
    }

    cout << "Discarded cards:";
    for(it=discart.begin();it<discart.end();++it){
      cout << " " << *it;
      if(it != discart.end()-1){
        cout << ",";
      }
    }
    cout << "\n";

    cout << "Remaining card: " << cards.at(0) << "\n";
    cards.clear();
    discart.clear();

  }



  return 0;
}
