#pragma once
#include <string>
#include "../header/mdrcode4d.h"

using namespace std;

class MDRcode4DStorage
{
    private:
        string storagePath;

    public:
        MDRcode4DStorage(string path);
        void perList(int begin, int end = 10000);
        void mdrList(int begin, int end = 10000);
        void symmetryList(int begin, int end = 10000);
        int minPermanent();
        int maxPermanent();
        MDRcode4D getCode(int index);
};