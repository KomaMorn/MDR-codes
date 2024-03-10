#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "../header/function.h"
#include "../header/mdrcode4d.h"

using namespace std;

MDRcode4D::MDRcode4D(vector<vector<vector<vector<int>>>> matrix, int order)
{
    this->matrix = matrix;
    this->order = order;
}

void MDRcode4D::view()
{
    for (int i = 0; i < order; ++i) {
        for (int j = 0; j < order; ++j) {
            for (int k = 0; k < order; ++k) {
                for (int h = 0; h < order; ++h) {
                    cout << matrix[i][j][k][h] << " ";
                }
                cout << "      ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    cout << "-------------------------------------------------" << "\n";
}

MDRcode4D MDRcode4D::minor(int elemX, int elemY, int elemZ, int elemT)
{
    int offsetX = 0;
    int offsetY = 0;
    int offsetZ = 0;
    int offsetT = 0;

    vector<vector<vector<vector<int>>>> newMatrix;

    for (int i = 0; i < order - 1; ++i) {
        if (i == elemX) {
            offsetX = 1;
        }

        offsetY = 0;
        offsetZ = 0;
        offsetT = 0;
        newMatrix.push_back(vector<vector<vector<int>>>());
        for (int j = 0; j < order - 1; ++j) {
            if (j == elemY) {
                offsetY = 1;
            }

            offsetZ = 0;
            offsetT = 0;
            newMatrix[i].push_back(vector<vector<int>>());
            for (int k = 0; k < order - 1; ++k) {
                if (k == elemZ) {
                    offsetZ = 1;
                }

                offsetT = 0;
                newMatrix[i][j].push_back(vector<int>());
                for (int h = 0; h < order - 1; ++h) {
                    if (h == elemT) {
                        offsetT = 1;
                    }

                    newMatrix[i][j][k].push_back(matrix[i + offsetX][j + offsetY][k + offsetZ][h + offsetT]);
                }
            }
        }
    }

    MDRcode4D minorCode(newMatrix, order - 1);
    return minorCode;
}

int MDRcode4D::permanent()
{
    int permanent = 0;

    if (order == 2) {
        permanent += matrix[0][0][0][0] * matrix[1][1][1][1];
        permanent += matrix[0][0][0][1] * matrix[1][1][1][0];
        permanent += matrix[0][0][1][0] * matrix[1][1][0][1];
        permanent += matrix[0][0][1][1] * matrix[1][1][0][0];
        permanent += matrix[0][1][0][0] * matrix[1][0][1][1];
        permanent += matrix[0][1][0][1] * matrix[1][0][1][0];
        permanent += matrix[0][1][1][0] * matrix[1][0][0][1];
        permanent += matrix[0][1][1][1] * matrix[1][0][0][0];
        return permanent;
    } else {
        for (int i = 0; i < order; ++i) {
            for (int j = 0; j < order; ++j) {
                for (int k = 0; k < order; ++k) {
                    permanent += matrix[0][i][j][k] * this->minor(0, i, j, k).permanent();
                }
            }
        }
    }

    return permanent;
}

bool MDRcode4D::symmetryCheck()
{
    bool check = true;

    for (int i = 0; i < order; ++i) {
        for (int j = 0; j < order; ++j) {
            for (int k = 0; k < order; ++k) {
                for (int h = 0; h < order; ++h) {
                    if (!(matrix[i][j][k][h] == matrix[i][j][h][k] && 
                          matrix[i][j][k][h] == matrix[i][h][k][j] &&
                          matrix[i][j][k][h] == matrix[i][h][j][k] &&
                          matrix[i][j][k][h] == matrix[i][k][h][j] &&
                          matrix[i][j][k][h] == matrix[i][k][j][h] &&
                          matrix[i][j][k][h] == matrix[j][i][h][k] &&
                          matrix[i][j][k][h] == matrix[j][i][k][h] &&
                          matrix[i][j][k][h] == matrix[j][k][i][h] &&
                          matrix[i][j][k][h] == matrix[j][k][h][i] &&
                          matrix[i][j][k][h] == matrix[j][h][i][k] &&
                          matrix[i][j][k][h] == matrix[j][h][k][i] &&
                          matrix[i][j][k][h] == matrix[k][j][i][h] &&
                          matrix[i][j][k][h] == matrix[k][j][h][i] &&
                          matrix[i][j][k][h] == matrix[k][i][j][h] &&
                          matrix[i][j][k][h] == matrix[k][i][h][j] &&
                          matrix[i][j][k][h] == matrix[k][h][i][j] &&
                          matrix[i][j][k][h] == matrix[k][h][j][i] &&
                          matrix[i][j][k][h] == matrix[h][k][i][j] &&
                          matrix[i][j][k][h] == matrix[h][k][j][i] &&
                          matrix[i][j][k][h] == matrix[h][i][k][j] &&
                          matrix[i][j][k][h] == matrix[h][i][j][k] &&
                          matrix[i][j][k][h] == matrix[h][j][i][k] &&
                          matrix[i][j][k][h] == matrix[h][j][k][i])) {
                            check = false;
                    }
                }
            }
        }
    }

    return check;
}

void MDRcode4D::symmetryHypergraneCheck()
{
    for (int i = 0; i < order; ++i) {
        for (int j = 0; j < order; ++j) {
            for (int k = 0; k < order; ++k) {
                for (int h = 0; h < order; ++h) {
                    cout << matrix[i][j][k][h] << " ";
                }

                cout << "\n";
            }

            if (symmetryCheck2D(matrix[i][j], order)) {
                cout << "грань симметрична" << "\n";
            } else {
                cout << "грань не симетрична" << "\n";
            }
        }
    }
}

vector<vector<vector<int>>> MDRcode4D::getHyperGrane3D(int direction, int index)
{
    vector<vector<vector<int>>> hyperGrane;

    for (int i = 0; i < order; ++i) {
        hyperGrane.push_back(vector<vector<int>>());
        for (int j = 0; j < order; ++j) {
            hyperGrane[i].push_back(vector<int>());
            for (int k = 0; k < order; ++k) {
                if (direction == 0) {
                    hyperGrane[i][j].push_back(matrix[index][i][j][k]);
                } else if (direction == 1) {
                    hyperGrane[i][j].push_back(matrix[i][index][j][k]);
                } else if (direction == 2) {
                    hyperGrane[i][j].push_back(matrix[i][j][index][k]);
                } else if (direction == 3) {
                    hyperGrane[i][j].push_back(matrix[i][j][k][index]);
                }
            }
        }
    }

    return hyperGrane;
}