#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main() {

    //read numbers from file and create vector
    ifstream mySample("sample5.txt");
    int column = 2;
    int row = 10;
    vector<vector <string> > pos_from(row);
    vector<vector <string> > pos_to(row);
    string line;
    int clear = 0;
    int k = 0;
    if (mySample.is_open()) {
        while(getline(mySample, line)) {
            stringstream linestream(line);
            string value;
            if(getline(linestream, value, ','))
                pos_from[k].push_back(value);
            if (getline(linestream, value, ' '))
                pos_from[k].push_back(value);
            if(getline(linestream, value, ' ')) 
                clear++;
            if(getline(linestream, value, ','))
                pos_to[k].push_back(value);
            if(getline(linestream, value, '\n'))
                pos_to[k].push_back(value);
            k++;
        }
        mySample.close();
    }

    vector <int> line_to_count;
    //map <int, int> line_to_count;
    double delta = 1;
    int delta_y = 0, delta_x = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (pos_from[i][j] == pos_to[i][j]) {
                delta = 0;
                line_to_count.push_back(delta);
                //line_to_count.insert(make_pair(i, delta));
            }
        }
        delta = 1;
        line_to_count.push_back(delta);
    }
            /*if (j == 0)
                delta_x = abs(stoi(pos_to[i][j]) - stoi(pos_from[i][j]));
            if (j == 1)
                delta_y = abs(stoi(pos_to[i][j]) - stoi(pos_from[i][j]));
        }
        if (delta_x != 0) {
            delta = delta_y/delta_x;
            //cout << "delta " << delta << endl;
            if (delta == 1) {
                //line_to_count.push_back(i);
                line_to_count.insert(make_pair(i, delta));
            }
        }
    }*/

    /*map <int, int>::iterator iter;
    for (iter = line_to_count.begin(); iter != line_to_count.end(); ++iter) {
        cout << iter->first << ' ' << iter->second << endl;
    }*/

    for (int i = 0; i < line_to_count.size(); i++)
        cout << line_to_count[i] << '\n';
    cout << endl;
  
    map <string, int> pos;
    string pair;
    int i = 0;
    int it = 0;
    int begin = 0, end = 0;

    cout << line_to_count[1] << endl;

    while (i < line_to_count.size()) {
        it = line_to_count[i];
        
        if (pos_from[it][0] != pos_to[it][0]) {  //count x
            begin = stoi(pos_from[it][0]);
            end = stoi(pos_to[it][0]);
            if (end < begin) {
                begin = stoi(pos_to[it][0]);
                end = stoi(pos_from[it][0]);
            }
            while (begin <= end) {
                pair = to_string(begin) + ',' + pos_from[it][1];
                if (pos.count(pair)) {
                    pos.at(pair)++;
                }
                else {
                    pos.insert(make_pair(pair, 1));
                }
                begin++;
            }
        }
        if (pos_from[it][1] != pos_to[it][1]) {  //count y
            begin = stoi(pos_from[it][1]);
            end = stoi(pos_to[it][1]);
            if (end < begin) {
                begin = stoi(pos_to[it][1]);
                end = stoi(pos_from[it][1]);
            }
            while (begin <= end) {
                pair = pos_from[it][0] + ',' + to_string(begin);
                if (pos.count(pair)) {
                    pos.at(pair)++;
                }
                else {
                    pos.insert(make_pair(pair, 1));
                }
                begin++;
            }
        }
        i++;
    }

    int res = 0;
    map <string, int>::iterator itr;
    for (itr = pos.begin(); itr != pos.end(); ++itr) {
        if (itr->second >= 2)
            res++;
    }

    cout << "result " << res << endl;
    return 0;
}