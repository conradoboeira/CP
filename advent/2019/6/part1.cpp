#include<iostream>
#include<boost/algorithm/string.hpp>
#include<string>
#include<map>
#include<vector>

using namespace std;

int main(){
    //map<string, vector<string> > orbits;
    //map<string, int> num_orbits;
    
    string planet1;
    string planet2;
    string line;
    while(cin>> line){
      vector<string> planets;
      boost::split(planets, line, [](char c){return c == ')';});
      planet1 = planets[0];
      planet2 = planets[1];
      cout << planet1 << " "<< planet2 << endl;
      //if(orbits.count(planet1) == 1) orbits[planet1].push_back(planet2);
      //else orbits[planet1] = vector<string>{planet2};
    }

}
