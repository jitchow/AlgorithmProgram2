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



<<<<<<< HEAD
    AVL_Tree tree;

    //Start timer
    //auto start = high_resolution_clock::now();

    for (int i=0; i<data.size(); i++) {
        cout << data[i] << endl;
        tree.insert(data[i]);
    }
    //Stop timer
    //auto stop = high_resolution_clock::now(); 

    //auto insertDuration = duration_cast<microseconds>(stop - start);
    //cout << "AVL Tree insertion took " << insertDuration.count() << " microseconds" << endl;

=======
>>>>>>> parent of 2a491a3... Done inser function (i think)
    return 0;
}
