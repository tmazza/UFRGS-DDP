
#include <iostream>
#include <functional>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int  main() {
  // const clock_t begin_time = clock();
  int c;
  std::vector<int> f(5,0);
  std::map<string,int> ids;
  while(cin >> c){
    if(c == 0){ break; }

    for(int i=0;i<c;i++){
      cin >> f[0] >> f[1] >> f[2] >> f[3] >> f[4];
      sort(f.begin(),f.end());
      std::stringstream ss;
      ss << f[0] << "." << f[1] << "." << f[2] << "." << f[3] << "." << f[4];
      std::string s = ss.str();
      if(ids.find(s) == ids.end()){
        ids.insert ( std::pair<string,int>(s,1) );
      } else {
        ids[s] = ids[s] + 1;
      }
    }

    std::map<string,int>::iterator it;
    int maior = 0;
    for (it=ids.begin(); it!=ids.end(); ++it){
      if(it->second>maior){
        maior = it->second;
      }
    }
    int sum = 0;
    for (it=ids.begin(); it!=ids.end(); ++it){
      if(it->second==maior){
        sum+=maior;
      }
    }
    cout << sum << "\n";
    ids.clear();
  }
  // cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "\n";
}
