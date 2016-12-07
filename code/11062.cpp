#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(){
  string linha;
  string temp;
  string::iterator it;
  map<string,string> words;
  map<string,string>::iterator wIt;

  int count = 0;
  int newPlv = true, endPlv = false;
  int val;
  // while(getline(cin,linha)) {
  std::stringstream ss;
  while(getline(cin,linha)){
    for(it=linha.begin();it<linha.end();++it){
      val = (int) *it;
      if(val == 13){
        //cout << "<<<<\n";
      } else if(val == 32){
        endPlv = true;
      } else if((val>=65 && val<=90) || (val>=97 && val<=122) || val == 45) {
        ss << *it;
      } else {
        endPlv = true;
      }

      if(endPlv){
        temp = ss.str();
        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        words[temp] = temp;
        ss.str("");
        // cout << words[count] << "----";
        count++;
        endPlv=false;
      }
    }
    temp = ss.str();
    it = temp.begin() + temp.size() - 1;
    val = (int) *it;
    if(val != 45){ // hifen
      ss.str("");
      std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
      words[temp] = temp;
      count++;
    } else {
      ss.str("");
      ss << temp.substr(0,temp.size() - 1);
    }
  }
  wIt = words.begin();
  if(wIt->second == ""){
    words.erase(words.begin());
  }
  // std::sort(words.begin(), words.end(), myobject);
  for(wIt=words.begin();wIt!=words.end();++wIt){
    cout << wIt->second << "\n";
  }

  return 0;
}
