#include<iostream>
#include <fstream>
#include <vector>
#include <chrono> 
#include "AVL_Tree.cpp"
using namespace std;
using namespace std::chrono; 

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

	string filename;
    cout << "Please enter a file name: ";
    cin >> filename;
    vector<string> data = getData(filename);

    AVL_Tree tree;
    auto start = high_resolution_clock::now(); 
    for (int i=0; i<data.size(); i++) {
        tree.insert(data[i]);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << duration.count() << " microseconds" << endl;
    
    return 0;
}
