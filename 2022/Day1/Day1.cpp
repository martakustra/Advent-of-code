#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


int main() {

    //read numbers from file and create vector
    ifstream mySample("input1.txt");
    int sum = 0;
    vector <int> sum_all;
    string line;

    if (mySample.is_open()) {
        while(getline(mySample, line)){
            if (line == "") {
                sum_all.push_back(sum);
                sum = 0;
            }
            else {
                sum += stoi(line);
            }    
        }
        mySample.close();
    }

    int max = 0;
    max = *max_element(sum_all.begin(), sum_all.end());
    cout << max << endl;

    sort(sum_all.begin(), sum_all.end(), greater<int>());
    int part2 = 0;
    part2 = sum_all[0] + sum_all[1] + sum_all[2];
    cout << part2 << endl;

    return 0;
}

