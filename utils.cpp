#include <iostream>
#include <string>
#include <fstream>
#include "utils.h"
using namespace std;

vector<int> stringToVector(string arrayString){
	string delimiter = ",";
	size_t pos = 0;
	string token;
	string line = arrayString;
	vector<int> arr;
	while ((pos = line.find(delimiter)) != string::npos) {
		token = line.substr(0, pos);
		arr.push_back(stoi(token));
	  line = line.substr(pos + delimiter.length());
	}
	token = line.substr(0, pos);
	arr.push_back(stoi(token));

	return arr;
}

vector<vector<int>> readArrays(char* pathToFile){
	ifstream infile(pathToFile);
	string arrayString;
	vector<vector<int>> arrays;
	while (getline(infile, arrayString)){
		arrays.push_back(stringToVector(arrayString));
	}
	return arrays;
}

void printVector(vector<int> vec){
	for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i){
    cout << *i << ' ';
	}
}

// void pprintBinaryTree(Node* root){
// 	if (root == NULL){
// 		cout << "NULL TREE";
// 		return;
// 	}

	
// }

// int main(int argc, char **argv){
// 	vector<vector<int>> arrays = readArrays(argv[1]);
// 	for (vector<vector<int>>::const_iterator i = arrays.begin(); i != arrays.end(); ++i){
// 		cout << "This array";
// 		printVector(*i);
// 	}
// 	return 0;
// }