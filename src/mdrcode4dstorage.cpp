#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include "../header/function.h"
#include "../header/mdrcode4d.h"
#include "../header/mdrcode4dstorage.h"

MDRcode4DStorage::MDRcode4DStorage(string path)
{
    storagePath = path;
}

void MDRcode4DStorage::perList(int begin, int end)
{
    int count = 1;

    ifstream in;
    in.open(storagePath);

    string line;
    while (getline(in, line)) {
        if (count > end) {
            break;
        } else if (count >= begin) {
            MDRcode4D code(strToMatrix4D(line.substr(0, 256), 4), 4);
            int per = code.permanent();
            cout << count << ") " << per << "\n";
        } 

        count += 1;
    }

    in.close();
}

void MDRcode4DStorage::mdrList(int begin, int end)
{
    int count = 1;

    ifstream in;
    in.open(storagePath);

    string line;
    while (getline(in, line)) {
        if (count > end) {
            break;
        } else if (count >= begin) {
            MDRcode4D code(strToMatrix4D(line.substr(0, 256), 4), 4);
            cout << count << " MDR code" << "\n";
            code.view();
            cout << "\n";
        }

        count += 1;
    }

    in.close();
}

void MDRcode4DStorage::symmetryList(int begin, int end)
{
    int count = 1;

    ifstream in;
    in.open(storagePath);

    string line;
    while (getline(in, line)) {
        if (count > end) {
            break;
        } else if (count >= begin) {
            MDRcode4D code(strToMatrix4D(line.substr(0, 256), 4), 4);
            cout << count << ") " << code.symmetryCheck() << "\n";
        }

        count += 1;
    }

    in.close();
}

int MDRcode4DStorage::minPermanent()
{
    int min = 10000;

    ifstream in;
    in.open(storagePath);

    string line;
    while (getline(in, line)) {
        MDRcode4D code(strToMatrix4D(line.substr(0, 256), 4), 4);
        if (min >= code.permanent()) {
            min = code.permanent();
        }
    }

    in.close();
    return min;
}

int MDRcode4DStorage::maxPermanent()
{
    int max = -10000;

    ifstream in;
    in.open(storagePath);

    string line;
    while (getline(in, line)) {
        MDRcode4D code(strToMatrix4D(line.substr(0, 256), 4), 4);
        if (max <= code.permanent()) {
            max = code.permanent();
        }
    }

    in.close();
    return max;
}

MDRcode4D MDRcode4DStorage::getCode(int index)
{
    int count = 1;

    ifstream in;
    in.open(storagePath);

    string line;
    while (getline(in, line)) {
        if (count == index) {
            MDRcode4D code(strToMatrix4D(line.substr(0, 256), 4), 4);
            return code;
        }
        
        count += 1;
    }

    string zeroline(256, '0');
    MDRcode4D code(strToMatrix4D(zeroline, 4), 4);
    return code;
}




