//
// Created by Wotro on 30/09/2025.
//

#include "PointSet.h"

#include <algorithm>
#include <random>
#include <unordered_set>

PointSet::PointSet(int n) {
     random_device rd;
     mt19937 mt(rd());
     uniform_int_distribution<int> dis(0, M);

     int a = 0;

     while (a!=n) {
          int x = dis(mt), y = dis(mt);
          points.emplace_back(x, y);
     }
     computeDistances();
}

void PointSet::computeDistances() {
     for (int i = 0; i < points.size()-1; i++) {
          for (int j = i+1; j < points.size(); j++) {
               distances.push_back(points.at(i).distanceTo(points[j]));
          }
     }
}

double PointSet::maxDistance() const {
     return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
     return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
     return distances.size();
}

void PointSet::printPoints() const {
     for (auto point : points) {
          point.print();
     }
}

void PointSet::printDistances() const {
     for (double distance : distances) {
          cout<<distance<<" ";
     }
     cout << endl;
}

void PointSet::sortDistances() {
     sort(distances.begin(), distances.end());
}

void PointSet::sortPointsX() {
     sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
          return a.getX() > b.getX();
     });
}

void PointSet::sortPointsY() {
     sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
          return a.getY() > b.getY();
     });
}

int PointSet::numDistinctDistances() {
     return unordered_set<double> (distances.begin(), distances.end()).size();
}

