#include <iostream>
#include "../header/function.h"
#include "../header/mdrcode4d.h"
#include "../header/mdrcode4dstorage.h"

using namespace std;

int main()
{
    MDRcode4DStorage storage("/home/murad/Projects/Diploma/2-MDR-codes/2-MDR-codes/2-mds-codes4.txt");
    MDRcode4D code = storage.getCode(2);
    code.view();
    cout << "\n";
    view3D(code.getHyperGrane3D(2, 0), 4);

    return 0;
}