#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void showMessage(int &, int &);

int main() {

    //read numbers from file and create vector
    ifstream mySample("input3.txt");
    vector<string> data;
    string raw;

    if (mySample.is_open()) {
        while(mySample >> raw)
            data.push_back(raw);
        mySample.close();
    }

    string gamma;
    string epsilon;
    int power = 0;

    string line;
    char bit = 0;
    int zero_counter = 0;
    int one_counter = 0;

    vector<string> newdata;
    newdata = data;
    vector<string> after_remove;
    vector<string> co2_vec;

    for(int i = 0; i < newdata[i].size(); i++) {
        for (int j = 0; j < newdata.size(); j++) {
            cout << newdata[j][i] << ' ';
            if (newdata[j][i] == '0') {
                zero_counter++;
            }
            else if (newdata[j][i] == '1')
                one_counter++;
        }
        cout << "zero: " << zero_counter << " one: " << one_counter << endl;
        if (zero_counter > one_counter) {
            bit = '0';
        }
        else {
            bit = '1';
        }
        for (int k = 0; k < newdata.size(); k++) {
            if (newdata[k][i] == bit) {
                cout << "Add this line: " << newdata[k] << endl;
                after_remove.push_back(newdata[k]);
            }
        }
        newdata = after_remove;
        after_remove.clear();
        //cout << "line: " << gamma << endl;
        zero_counter = 0;
        one_counter = 0;

        //cout << endl;
        
    }
    string oxygen;
    oxygen = newdata[0];
    cout << "Oxygen: " << oxygen << endl;
    int oxygen_dec = stoi(oxygen, 0, 2);
    cout << "Oxygen dec: " << oxygen_dec << endl;

    newdata = data; 
    for(int i = 0; i < newdata[i].size(); i++) {
        for (int j = 0; j < newdata.size(); j++) {
            cout << newdata[j][i] << ' ';
            if (newdata[j][i] == '0') {
                zero_counter++;
            }
            else if (newdata[j][i] == '1')
                one_counter++;
        }
        cout << "zero: " << zero_counter << " one: " << one_counter << endl;
        if (zero_counter > one_counter) {
            bit = '0';
        }
        else {
            bit = '1';
        }
        for (int k = 0; k < newdata.size(); k++) {
            if (newdata[k][i] != bit) {
                cout << "Add this line: " << newdata[k] << endl;
                co2_vec.push_back(newdata[k]);
            }
        }
        newdata = co2_vec;
        co2_vec.clear();
        //cout << "line: " << gamma << endl;
        zero_counter = 0;
        one_counter = 0;

        //cout << endl;
    }
    string co2;
    co2 = newdata[0];
    cout << "CO2: " << co2 << endl;
    int co2_dec = stoi(co2, 0, 2);
    cout << "CO2 dec: " << co2_dec << endl;

    cout << "Final: " << oxygen_dec * co2_dec << endl;

 /*
    cout << "Gamma: " << gamma << endl;
    int gamma_dec = stoi(gamma, 0, 2);
    cout << "Epsilon: " << epsilon << endl;
    int epsilon_dec = stoi(epsilon, 0, 2);

    cout << "Gamma dec: " << gamma_dec << endl;
    cout << "Epsilon dec: " << epsilon_dec << endl;
    cout << "Power: " << gamma_dec * epsilon_dec << endl;
    */
    

    /*for(int i = 0; i < data[i].size(); i++) {
        for (int j = 0; j < data.size(); j++) {
            cout << data[j][i] << ' ';
            if (data[j][i] == '0') {
                zero_counter++;
            }
            else if (data[j][i] == '1')
                one_counter++;
        }
        cout << "zero: " << zero_counter << " one: " << one_counter << endl;
        if (zero_counter > one_counter) {
            gamma = gamma + '0';
            epsilon = epsilon + '1';
        }
        else {
            gamma = gamma + '1';
            epsilon = epsilon + '0';
        }
        cout << "line: " << gamma << endl;
        zero_counter = 0;
        one_counter = 0;

        cout << endl;
        
    }

    cout << "Gamma: " << gamma << endl;
    int gamma_dec = stoi(gamma, 0, 2);
    cout << "Epsilon: " << epsilon << endl;
    int epsilon_dec = stoi(epsilon, 0, 2);

    cout << "Gamma dec: " << gamma_dec << endl;
    cout << "Epsilon dec: " << epsilon_dec << endl;
    cout << "Power: " << gamma_dec * epsilon_dec << endl;
    */

    return 0;
}

void showMessage(int &horizontal_position, int &depth) {
    cout << "Horizontal postion: " << horizontal_position << endl;
    cout << "Depth: " << depth << endl;
    cout << "Final: " << horizontal_position * depth << endl;
}
