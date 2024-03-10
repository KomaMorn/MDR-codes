#pragma once
#include <vector>
#include <string>

using namespace std;

vector<vector<vector<vector<int>>>> strToMatrix4D(string line, int order);
bool symmetryCheck2D(vector<vector<int>> matrix, int order);
void view3D(vector<vector<vector<int>>> matrix, int order);