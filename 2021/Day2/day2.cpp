#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void countPosition(vector<string>, int &, int &, int);
void showMessage(int &, int &);

int main() {

    //read numbers from file and create vector
    ifstream mySample("input2.txt");
    vector<string> position;
    string place;

    if (mySample.is_open()) {
        while(mySample >> place)
            position.push_back(place);
        mySample.close();
    }

    int horizontal_position = 0;
    int depth = 0;
    cout << "*** Part 1 ***" << endl;
    countPosition(position, horizontal_position, depth, 1);
    showMessage(horizontal_position, depth);

    cout << "*** Part 2 ***" << endl;
    countPosition(position, horizontal_position, depth, 2);
    showMessage(horizontal_position, depth);

    return 0;
}

void countPosition(vector<string> position, int &horizontal_position, int &depth, int part_number) {
    horizontal_position = 0;
    depth = 0;
    int aim = 0;
    int i = 0;
    while (i < position.size()) {
        if (position[i] == "forward") {
            horizontal_position += stoi(position[i+1]);
            if (part_number == 2) {
                if (aim != 0)
                    depth += aim * stoi(position[i+1]);
            }
        }
        else if (position[i] == "down") {
            if (part_number == 1)
                depth += stoi(position[i+1]);
            else if (part_number == 2)
                aim += stoi(position[i+1]);
        }
        else if (position[i] == "up") {
            if (part_number == 1)
                depth -= stoi(position[i+1]);
            else if (part_number == 2)
                aim -= stoi(position[i+1]);
        }
        i = i+2;
    }
}

void showMessage(int &horizontal_position, int &depth) {
    cout << "Horizontal postion: " << horizontal_position << endl;
    cout << "Depth: " << depth << endl;
    cout << "Final: " << horizontal_position * depth << endl;
}
