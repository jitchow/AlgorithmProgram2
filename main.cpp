#include<iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> getData(string textFile) {
    vector<string> data;
    ifstream myFile;

    myFile.open(textFile);

    if(!myFile.is_open()) {
        cout << "FILE NOT FOUND" << endl;
        exit(EXIT_FAILURE);
    }
    else {
    	string s;

        while(getline(myFile, s,',')) {
		  data.push_back(s);
		}
    }

    myFile.close();
    return data;
}

int main () {
    vector<string> data = getData("Set_A.txt");

    for (int i=0; i<data.size(); i++) {
    	cout << data[i] << endl;
    }

    return 0;
}
