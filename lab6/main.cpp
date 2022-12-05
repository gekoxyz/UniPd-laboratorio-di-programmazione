#include "myvector.h"
#include <iostream>
using namespace std;

int main() {
    // initialization
    myvector<double> v(10);
    
    v[5] = 6;
    
    cout << v.size() << endl;
    cout << v.get(5) << endl;
    cout << v.get(9) << endl;

    cout << "TOSTRING" << endl;
    v.to_string();
    
    cout << "OVERLOAD OPERATOR<<" << endl;
    cout << v << endl;

    cout << "CHANGING VALUE" << endl;
    v.set(5, 7);

    cout << v << endl;

    cout << "ADDRESS OF 7" << endl;
    cout << &v.at(5) << endl;
    v.at(6) = 9;

    cout << v << endl;
    
    myvector<string> vs(5);
    for (int i = 0; i < vs.size(); i++)
        vs.set(i, "___");

    vs.to_string();
    cout << vs << endl;
    
    vs.set(3, "uwu");
    cout << vs << endl;
    cout << vs.size() << endl;
    vs.push_back("MOLLY");
    cout << vs.size() << endl;
    cout << vs << endl;
    vs.pop_back();
    cout << vs << endl;

    myvector<int> boh{};
    cout << boh.size() << endl;

    return 0;
}
