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
    string searchfile;
    vector<string> data, search; 

    cout << "Enter a file name: ";
    cin >> filename;
    data = getData(filename);

    AVL_Tree tree;

    //Start timer
    auto insertStart = high_resolution_clock::now();
    for (int i=0; i<data.size(); i++) {
        tree.insert(data[i]);
    }
    //Stop timer
    auto insertStop = high_resolution_clock::now(); 
    auto insertDuration = duration_cast<microseconds>(insertStop - insertStart);

    cout << "AVL Tree insertion took " << insertDuration.count() << " microseconds" << endl;
    cout << endl;

    cout << "Enter file to search: ";
    cin >> searchfile;
    search = getData(searchfile);

    auto searchStart = high_resolution_clock::now();
    for(int i=0; i<search.size(); i++) {
        cout << tree.search(search[i]) << endl;
    }
    auto searchStop = high_resolution_clock::now(); 
    auto searchDuration = duration_cast<microseconds>(searchStop - searchStart);

    cout << "AVL Tree search took " << searchDuration.count() << " microseconds" << endl;

    return 0;
}
