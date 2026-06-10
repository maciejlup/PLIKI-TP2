#include "parser.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


bool test_eq(float a, float b){
    return abs(a-b) < 1e-4;
}

int main() {
    //string s = "(2+3)*(4-1)+2*(2+2/(3-2))";
    vector<pair<string,float>> s = {{"1+2/7",1.28571},{"(1+3)*(4-3)",4.0},{"(2*(4-3))/2",1.0}};
    for (const auto &i : s){
        Parser p = Parser(i.first);
        p.parse();
        float tmp = p.ast->compute();
        cout << i.first << " =  " << tmp <<"  |  "<< (test_eq(tmp,i.second) ? "PASS" : "FAIL") << endl;
    }
    return 0;
}
