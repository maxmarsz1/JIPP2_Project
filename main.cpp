#include "Menu.h"
#include "Datetime.h"

using namespace std;

int main(){
    Datetime x;
    x.setDatetime(time(0) + 24*60*60);
    x.print();
    // Menu m;
}
