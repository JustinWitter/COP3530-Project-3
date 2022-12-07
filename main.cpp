#include <iostream>
#include <fstream>
#include <unordered_map>
#include "TeamYear.h"
#include "graph.h"
using namespace std;

int main() {
  //data from 2009-2017
  vector<string> gsFileNames = {"nfl_data2/GameScores2009", "nfl_data2/GameScores2010", "nfl_data2/GameScores2011", "nfl_data2/GameScores2012", "nfl_data2/GameScores2013", "nfl_data2/GameScores2014", "nfl_data2/GameScores2015", "nfl_data2/GameScores2016", "nfl_data2/GameScores2017" };
  vector<string> propFileNames = {"nfl_data2/PossTime", "nfl_data2/RecYds", "nfl_data2/RushYds"};

  graph g2009("2009");
  g2009.addMatchupData(gsFileNames[0]);
  g2009.addPossTime(propFileNames[0]);
  g2009.addRecYards(propFileNames[1]);
  g2009.addRushYards(propFileNames[2]);
  g2009.makeAdjacencyList();
  graph g2010("2010");
  g2010.addMatchupData(gsFileNames[1]);
  g2010.addPossTime(propFileNames[0]);
  g2010.addRecYards(propFileNames[1]);
  g2010.addRushYards(propFileNames[2]);
  g2010.makeAdjacencyList();
  graph g2011("2011");
  g2011.addMatchupData(gsFileNames[2]);
  g2011.addPossTime(propFileNames[0]);
  g2011.addRecYards(propFileNames[1]);
  g2011.addRushYards(propFileNames[2]);
  g2011.makeAdjacencyList();
  graph g2012("2012");
  g2012.addMatchupData(gsFileNames[3]);
  g2012.addPossTime(propFileNames[0]);
  g2012.addRecYards(propFileNames[1]);
  g2012.addRushYards(propFileNames[2]);
  g2012.makeAdjacencyList();
  graph g2013("2013");
  g2013.addMatchupData(gsFileNames[4]);
  g2013.addPossTime(propFileNames[0]);
  g2013.addRecYards(propFileNames[1]);
  g2013.addRushYards(propFileNames[2]);
  g2013.makeAdjacencyList();
  graph g2014("2014");
  g2014.addMatchupData(gsFileNames[5]);
  g2014.addPossTime(propFileNames[0]);
  g2014.addRecYards(propFileNames[1]);
  g2014.addRushYards(propFileNames[2]);
  g2014.makeAdjacencyList();
  graph g2015("2015");
  g2015.addMatchupData(gsFileNames[6]);
  g2015.addPossTime(propFileNames[0]);
  g2015.addRecYards(propFileNames[1]);
  g2015.addRushYards(propFileNames[2]);
  g2015.makeAdjacencyList();
  graph g2016("2016");
  g2016.addMatchupData(gsFileNames[7]);
  g2016.addPossTime(propFileNames[0]);
  g2016.addRecYards(propFileNames[1]);
  g2016.addRushYards(propFileNames[2]);
  g2016.makeAdjacencyList();
  graph g2017("2017");
  g2017.addMatchupData(gsFileNames[8]);
  g2017.addPossTime(propFileNames[0]);
  g2017.addRecYards(propFileNames[1]);
  g2017.addRushYards(propFileNames[2]);
  g2017.makeAdjacencyList();
  
  
  int temp = g2009.dijkstrasAlgo("MIN2009", "GB2009");
  int temp2 = g2009.dijkstrasAlgo("GB2009", "MIN2009");

  string ans = "N";
  while(ans == "N") {
    cout << "Would you like to exit (Y/N)?: " << endl;
    cin >> ans;
    if (ans == "Y") continue;
    cout << "What game would you like to predict the outcome of? Please answer in TeamYear format: " << endl;
    string team1;
    string team2;
    cin >> team1;
    cin >> team2;
  
    for (int i = 0; i < 9; i++) {
      switch(stoi(team1.substr(3,4)) - 2009) {
        case(1):
          if (g2009.dijkstrasAlgo(team1, team2) > g2009.dijkstrasAlgo(team2, team1)) {
            cout << "Dijkstras Algorithm says " << team2 << " will win!" << endl;
          } else {
            cout << "Dijkstras Algorithm says " << team1 << " will win!" << endl;
          }

          if(g2009.aStar(team1, team2) > g2009.aStar(team2, team1)){
            cout << "A* Algorithm says " << team2 << " will win!" << endl;
          }
          else{
            cout << "A* Algorithm says " << team1 << " will win!" << endl;
          }
          break;
        case(2):
          if (g2010.dijkstrasAlgo(team1, team2) > g2010.dijkstrasAlgo(team2, team1)) {
            cout << "Dijkstras Algorithm says " << team2 << " will win!" << endl;
          } else {
            cout << "Dijkstras Algorithm says " << team1 << " will win!" << endl;
          }

          if(g2010.aStar(team1, team2) > g2009.aStar(team2, team1)){
            cout << "A* Algorithm says " << team2 << " will win!" << endl;
          }
          else{
            cout << "A* Algorithm says " << team1 << " will win!" << endl;
          }
          break;
        case(3):
          if (g2011.dijkstrasAlgo(team1, team2) > g2011.dijkstrasAlgo(team2, team1)) {
            cout << "Dijkstras Algorithm says " << team2 << " will win!" << endl;
          } else {
            cout << "Dijkstras Algorithm says " << team1 << " will win!" << endl;
          }
          if(g2011.aStar(team1, team2) > g2009.aStar(team2, team1)){
            cout << "A* Algorithm says " << team2 << " will win!" << endl;
          }
          else{
            cout << "A* Algorithm says " << team1 << " will win!" << endl;
          }
          break;
        case(4):
          if (g2012.dijkstrasAlgo(team1, team2) > g2012.dijkstrasAlgo(team2, team1)) {
            cout << "Dijkstras Algorithm says " << team2 << " will win!" << endl;
          } else {
            cout << "Dijkstras Algorithm says " << team1 << " will win!" << endl;
          }
          if(g2012.aStar(team1, team2) > g2009.aStar(team2, team1)){
            cout << "A* Algorithm says " << team2 << " will win!" << endl;
          }
          else{
            cout << "A* Algorithm says " << team1 << " will win!" << endl;
          }
          break;
        case(5):
          if (g2013.dijkstrasAlgo(team1, team2) > g2013.dijkstrasAlgo(team2, team1)) {
            cout << "Dijkstras Algorithm says " << team2 << " will win!" << endl;
          } else {
            cout << "Dijkstras Algorithm says " << team1 << " will win!" << endl;
          }
          if(g2013.aStar(team1, team2) > g2009.aStar(team2, team1)){
            cout << "A* Algorithm says " << team2 << " will win!" << endl;
          }
          else{
            cout << "A* Algorithm says " << team1 << " will win!" << endl;
          }
          break;
        case(6):
          if (g2014.dijkstrasAlgo(team1, team2) > g2014.dijkstrasAlgo(team2, team1)) {
            cout << "Dijkstras Algorithm says " << team2 << " will win!" << endl;
          } else {
            cout << "Dijkstras Algorithm says " << team1 << " will win!" << endl;
          }
          if(g2014.aStar(team1, team2) > g2009.aStar(team2, team1)){
            cout << "A* Algorithm says " << team2 << " will win!" << endl;
          }
          else{
            cout << "A* Algorithm says " << team1 << " will win!" << endl;
          }
          break;
        case(7):
          if (g2015.dijkstrasAlgo(team1, team2) > g2015.dijkstrasAlgo(team2, team1)) {
            cout << "Dijkstras Algorithm says " << team2 << " will win!" << endl;
          } else {
            cout << "Dijkstras Algorithm says " << team1 << " will win!" << endl;
          }
          if(g2015.aStar(team1, team2) > g2009.aStar(team2, team1)){
            cout << "A* Algorithm says " << team2 << " will win!" << endl;
          }
          else{
            cout << "A* Algorithm says " << team1 << " will win!" << endl;
          }
          break;
        case(8):
          if (g2016.dijkstrasAlgo(team1, team2) > g2016.dijkstrasAlgo(team2, team1)) {
            cout << "Dijkstras Algorithm says " << team2 << " will win!" << endl;
          } else {
            cout << "Dijkstras Algorithm says " << team1 << " will win!" << endl;
            }
          if(g2016.aStar(team1, team2) > g2009.aStar(team2, team1)){
            cout << "A* Algorithm says " << team2 << " will win!" << endl;
          }
          else{
            cout << "A* Algorithm says " << team1 << " will win!" << endl;
          }
          break;
        case(9):
          if (g2017.dijkstrasAlgo(team1, team2) > g2017.dijkstrasAlgo(team2, team1)) {
            cout << "Dijkstras Algorithm says " << team2 << " will win!" << endl;
          } else {
            cout << "Dijkstras Algorithm says " << team1 << " will win!" << endl;
          }
          if(g2017.aStar(team1, team2) > g2009.aStar(team2, team1)){
            cout << "A* Algorithm says " << team2 << " will win!" << endl;
          }
          else{
            cout << "A* Algorithm says " << team1 << " will win!" << endl;
          }
          break;
        default:
          break;
      }
    }
  }
  
  return 0;
}
