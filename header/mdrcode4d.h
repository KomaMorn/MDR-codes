#pragma once
#include <vector>

using namespace std;

class MDRcode4D
{
    private:
        vector<vector<vector<vector<int>>>> matrix;
        int order;
    
    public:
        MDRcode4D(vector<vector<vector<vector<int>>>> matrix, int order);
        void view();
        MDRcode4D minor(int elemX, int elemY, int elemZ, int elemT);
        int permanent();
        bool symmetryCheck();
        void symmetryHypergraneCheck();
        vector<vector<vector<int>>> getHyperGrane3D(int direction, int index);
    
};