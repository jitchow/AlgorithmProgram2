#include<iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<string> getData(string textFile) {
    vector<string> data;

    ifstream myFile;
    myFile.open(textFile);

    if(!myFile.is_open()) {
        cout << "FILE NOT FOUND" << endl;
        exit(EXIT_FAILURE);
    }
    
}

int main () {
    

    return 0;
}
