#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Introduce un numero: ";
    string line;
    //cin >> n;
    getline(cin, line);
    cout << "Valor de line: " << line << endl;
}