#include <iostream>
#include <string>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;




vector<int> readData(const string& filename) {
    ifstream file(filename);
    vector<int> data;
    string line;

    if(file.is_open()) {
        getline(file,line);
        stringstream ss(line);
        string item;
        while(getline(ss, item, ' ')) {
            data.push_back(stoi(item));

        }
    }else {
        cout << "File could not be opened" << endl;

    }
    return data;

}
double calcMedian(const vector<int>& data) {
    int size = data.size();
    if(size % 2 == 1) {
        return data[size/2];
    }else {
        return (data[size/2] + data[size/2 - 1]) / 2;
    }
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    vector<int> data;
    string line;


    while (getline(file, line)) {
        stringstream ss(line);
        string value;
        while (getline(ss, value, ',')) {
            data.push_back(stoi(value));
        }
    }

    file.close();

    double median = calcMedian(data);
    cout << "The median of the dataset is " << median << endl;

    return 0;
}
