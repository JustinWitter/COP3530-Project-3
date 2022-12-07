#include "TeamYear.h"
#include <string>

TeamYear::TeamYear() {
  teamName = "";
  int numWeeks = 17;
  while (numWeeks--) {
    this->rushYards.push_back(0);
    this->recYards.push_back(0);
    this->points.push_back(0);
    this->possTime.push_back(0);
    this->teamPlayed.push_back({"", false});
  }
}
/*
TeamYear::TeamYear(string teamName, int rushYards, int passYards, int points,
                   int week) {
  this->teamName = teamName;
  int numWeeks = 17;
  while (numWeeks--) {
    this->rushYards.push_back(0);
    this->recYards.push_back(0);
    this->points.push_back(0);
    this->possTime.push_back(0);
  }
  this->rushYards[week] = rushYards;
  this->recYards[week] = passYards;
  this->points[week] = points;
}*/