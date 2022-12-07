#include "graph.h"
#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <string>

#define INT_MAX 2147483647;

graph::graph(string year) { this->year = year; }

void graph::addMatchupData(string fileName) {

  fstream newFile;
  // data stored in format
  // type,game_id,home_team,away_team,week,season,state_of_game,game_url,home_score,away_score
  newFile.open(fileName, ios::in);
  if (newFile.is_open()) {
    string l;
    int cnt = 0;
    string points1;
    string teamName1;
    while (getline(newFile, l)) {
      cnt++;
      string delimiter = ",";
      string token;
      int numTokens = 4;
      string year;
      string teamName;
      string week;
      string points;
      while (numTokens--) {
        token = l.substr(0, l.find(delimiter));
        l.erase(0, l.find(delimiter) + delimiter.length());
        switch (numTokens) {
        case (3): // year
          year = token;
          break;
        case (2): // team score
          week = token;
          break;
        case (1): // other team score
          teamName = token;
          break;
        case (0):
          points = token;
          break;
        default:
          break;
        }
      }
      this->data[teamName + year].points[stoi(week) - 1] = stoi(points);
      if (cnt == 2) {
        cnt = 0; 
        if (points1 > points) {
          this->data[teamName1 + year].teamPlayed[stoi(week)-1] = {
              teamName + year, true};
          this->data[teamName + year].teamPlayed[stoi(week)-1] = {
              teamName1 + year, false};
        } else {
          this->data[teamName1 + year].teamPlayed[stoi(week)-1] = {
              teamName + year, false};
          this->data[teamName + year].teamPlayed[stoi(week)-1] = {
              teamName1 + year, true};
        } 
      }
      points1 = points;
      teamName1 = teamName;
    }
    newFile.close();
  }
}

void graph::addPossTime(string fileName) {
  fstream newFile;
  // data stored in format
  // Season,week,Team,PossTime
  newFile.open(fileName, ios::in);
  if (newFile.is_open()) {
    string l;
    while (getline(newFile, l)) {
      string delimiter = ",";
      string token;
      int numTokens = 4;
      string year;
      string week;
      string teamName;
      string possTime;
      while (numTokens--) {
        token = l.substr(0, l.find(delimiter));
        l.erase(0, l.find(delimiter) + delimiter.length());
        switch (numTokens) {
        case (3):
          year = token;
          break;
        case (2):
          week = token;
        case (1):
          teamName = token;
          break;
        case (0):
          possTime = token;
          break;
        default:
          break;
        }
      }
      if (this->year == year)
        this->data[teamName + year].possTime[stoi(week) - 1] = stod(possTime);
    }
  }
}

void graph::addRecYards(string fileName) {
  fstream newFile;
  // data stored in format
  // Season,week,Team,PossTime
  newFile.open(fileName, ios::in);
  if (newFile.is_open()) {
    string l;
    while (getline(newFile, l)) {
      string delimiter = ",";
      string token;
      int numTokens = 4;
      string year;
      string week;
      string teamName;
      string recYards;
      while (numTokens--) {
        token = l.substr(0, l.find(delimiter));
        l.erase(0, l.find(delimiter) + delimiter.length());
        switch (numTokens) {
        case (3):
          year = token;
          break;
        case (2):
          week = token;
        case (1):
          teamName = token;
          break;
        case (0):
          recYards = token;
          break;
        default:
          break;
        }
      }
      if (this->year == year)
        this->data[teamName + year].recYards[stoi(week) - 1] = stod(recYards);
    }
  }
}

void graph::addRushYards(string fileName) {
  fstream newFile;
  // data stored in format
  // Season,week,Team,PossTime
  newFile.open(fileName, ios::in);
  if (newFile.is_open()) {
    string l;
    while (getline(newFile, l)) {
      string delimiter = ",";
      string token;
      int numTokens = 4;
      string year;
      string week;
      string teamName;
      string rushYards;
      while (numTokens--) {
        token = l.substr(0, l.find(delimiter));
        l.erase(0, l.find(delimiter) + delimiter.length());
        switch (numTokens) {
        case (3):
          year = token;
          break;
        case (2):
          week = token;
        case (1):
          teamName = token;
          break;
        case (0):
          rushYards = token;
          break;
        default:
          break;
        }
      }
      if (this->year == year)
        this->data[teamName + year].rushYards[stoi(week) - 1] = stod(rushYards);
    }
  }
}

void graph::makeAdjacencyList() {
  for (auto it = data.begin(); it != data.end(); it++) {
    int numWeeks = 17;
    for (int i = 0; i < numWeeks; i++) {
      int weight = it->second.points[i]*100 + it->second.possTime[i]*50 + it->second.recYards[i]*5 + it->second.rushYards[i]*3; //create function to calculate weight;
      if (it->second.teamPlayed[i].second) weight *= .3;
      else weight *= .7;
      if (it->second.teamPlayed[i].first == "") g[it->first].push_back({"ByeWeek", 9999999});
      else g[it->first].push_back({it->second.teamPlayed[i].first,weight});
    }
  }
}

void graph::BFS() {
  for(auto it = g.begin(); it != g.end(); it++) {
    int numWeeks = 17;
    for (int i = 0; i < numWeeks; i++) {
      cout << it->first << " points to " << it->second[i].first << " and weighs " << it->second[i].second << endl;
    }
    
  }
}

int graph::isEdge(string source, string destination) {
  for (int i = 0; i < g[source].size(); i++) {
    if (g[source][i].first == destination) return i;
  }
  return 0;
}


int graph::aStar(string source, string destination) {
  
  unordered_map<string, string> came_from;
  unordered_map<string, int> cost;
  map<int, string> pq;
  int temp = 0;

  came_from[source] = source;
  cost[source] = 0;
  pq[0] = source;

  while (!pq.empty()){
    string curr = pq.begin()->second;

    if (curr == destination){
      return cost[curr];
    }

    for (int i = 0; i < g[curr].size(); i++){
      int newCost = cost[curr] + g[curr].at(i).second;

      if (!cost.count(g[curr].at(i).first) || (newCost < cost[g[curr].at(i).first])){
        cost[g[curr].at(i).first] = newCost;
        for (int j = 0; i < g[g[curr].at(i).first].size(); j++){
          temp += g[g[curr].at(i).first].at(j).second;
        }
         
        int priority = newCost + temp;
        pq[priority] = g[curr].at(i).first; //goes to next team with lowest total weight
        temp = 0;
        came_from[g[curr].at(i).first] = curr;
      }
    }
    pq.erase(0);
  }
}

int graph::dijkstrasAlgo(string source, string destination) {
  //initializes visited nodes and need to be visited nodes
  set<string> s;
  set<string> v_s;
  s.insert(source);
  for (auto it = data.begin(); it != data.end(); it++) {
    if (it->first != source || it->first != "ByeWeek") v_s.insert(it->first);
  }

  //initializes predecessor map and distance map
  unordered_map<string, string> p;
  unordered_map<string, int> d;
  for(auto it = v_s.begin(); it != v_s.end(); it++) {
    p[*it] = source;
    int index = isEdge(source, *it);
    if(index) {
      d[*it] = g[source][index].second;
    } else {
      d[*it] = INT_MAX;
    }
  }

  while(!v_s.empty()) {
    auto min = d.begin();
    for (auto it = d.begin(); it != d.end(); it++) {
      if (it->second < min->second) min = it;
    }
    v_s.erase(min->first);
    s.insert(min->first);
    //for all vertices adjacent to min in v_s
    for(int i = 0; i < g[min->first].size(); i++) {
      if (v_s.find(g[min->first][i].first) != v_s.end()) {
        string v = g[min->first][i].first;
        string u = min->first;
        //i gives all vertices adjacent to min stil in v_s
        if(d[u] + g[u][i].second < d[v]) {
          d[v] = d[u] + g[u][i].second;
          p[v] = u;
        }
      }
    }
    return d[destination];
  }

}