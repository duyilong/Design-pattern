#include <iostream>
#include "singleton_early.h"
using namespace std;
using namespace myspace;

int main()
{
    singleton_early *psingle = singleton_early::GetInstance();
    psingle->test();

//  system("pause");
    return 0;
}
