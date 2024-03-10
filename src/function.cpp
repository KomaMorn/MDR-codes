#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<vector<vector<vector<int>>>> strToMatrix4D(string line, int order)
{
    vector<vector<vector<vector<int>>>> matrix;

    for (int i = 0; i < order; ++i) {
        matrix.push_back(vector<vector<vector<int>>>());
        for (int j = 0; j < order; ++j) {
            matrix[i].push_back(vector<vector<int>>());
            for (int k = 0; k < order; ++k) {
                matrix[i][j].push_back(vector<int>());
                for (int h = 0; h < order; ++h) {
                    matrix[i][j][k].push_back(static_cast<int>(line[i * pow(4, 3) + j * pow(4, 2) + k * 4 + h] - '0'));
                }
            }
        }
    }

    return matrix;
}

bool symmetryCheck2D(vector<vector<int>> matrix, int order)
{
    bool check = true;

    for (int i = 0; i < order; ++i) {
        for (int j = 0; j < order; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                check = true;
            }
        }
    }

    return check;
}

void view3D(vector<vector<vector<int>>> matrix, int order)
{
    for (int i = 0; i < order; ++i) {
        for (int j = 0; j < order; ++j) {
            for (int k = 0; k < order; ++k) {
                cout << matrix[i][j][k] << " ";
            }
            cout << "      ";
        }

        cout << "\n";
    }

    cout << "-------------------------------------------------" << "\n";
}