#include "TeamYear.h"
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class graph {
public:
  unordered_map<string, vector<pair<string, int>>> g;
  unordered_map<string, TeamYear> data;
  void addMatchupData(string fileName);
  void addPossTime(string fileName);
  void addRushYards(string fileName);
  void addRecYards(string fileName);
  void makeAdjacencyList();
  void BFS();
  int dijkstrasAlgo(string source, string destination);
  int aStar(string source, string destination);
  int isEdge(string source, string destination);
  string year;
  
  graph(string year);
};
