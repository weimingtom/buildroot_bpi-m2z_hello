/****************
* Helloworld.cpp
*****************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(10);

    string s = "Hell! O' world, why won't my c++ code run?\n\n";
    cout << s;

    cout << vec[0];
    return 0;
}