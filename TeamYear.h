#ifndef TEAMYEAR_H
#define TEAMYEAR_H
#include <string>
#include <vector>
using namespace std;

struct TeamYear{
  string teamName;
  vector<int> rushYards;
  vector<int> recYards;
  vector<int> points;
  vector<double> possTime;
  vector<pair<string, bool>> teamPlayed;
  TeamYear();
  TeamYear(string teamName, int rushYards, int recYards, int points, int week);
};

#endif