#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {

    //read numbers from file and create vector
    ifstream mySample("input4.txt");
    vector<string> lotery; //numbers for bingo game 
    vector<string> board;  //boards in size 5x5
    string line;
    int check = 0;

    if (mySample.is_open()) {
        while(getline(mySample, line)) {
            stringstream linestream(line);
            string value;
            while(getline(linestream, value, ',')) {
                if (check < 2)
                    lotery.push_back(value);
                else
                    board.push_back(value);
            }
            if (getline(linestream, value) == 0) {
                check++;
            }
        }
        mySample.close();
    }

    int raw = board.size();
    vector<vector<int> > data(raw);  //vector board transform from string to int
    int number;
    
    for (int i = 0; i < board.size(); i++) {
        line = board[i];
        stringstream iss(line);
        while(iss >> number)
            data[i].push_back(number);
    }

   
    vector<int> check_board;  //check if all boards have bingo
    int column = 5;
    int number_of_board = data.size()/column;
    for (int i = 0; i < number_of_board; i++) {
        check_board.push_back(0);
    }

    int raw_sum = 0;
    int col_sum = 0;
    int lotery_win = 0;
    int board_counter = 1;
    int board_raw_counter = 1;
    bool found_all = false;
    int winner_raw = 0;
    int winner_col_raw = 0;
    int sum_z = 0;
    
    
    for (int i = 0; i < lotery.size(); i++) { 
        for (int j = 0; j < data.size(); j++) {
            for (int k = 0; k < column; k++) {
                if (data[j][k] == stoi(lotery[i])) {
                    data[j][k] = -1;
                }
                raw_sum = raw_sum + data[j][k];
            }
            if (j >= column * board_raw_counter) {
                board_raw_counter++;
            }
            if (raw_sum == -5) {
                    lotery_win = stoi(lotery[i]);
                    winner_raw = j;
                    check_board[board_raw_counter-1] = 1;
                    sum_z = 0;
                    for (int z = 0; z < check_board.size(); z++) {
                        sum_z = sum_z+check_board[z];
                    }
                    if (sum_z == number_of_board) {
                        cout << " -------------- all found!!!" << endl;
                        found_all = true;
                        winner_col_raw = 0;
                        break;
                    }
            }
            raw_sum = 0;
        }
        if (found_all == true)
            break;
        board_raw_counter = 1;
        for (int m = 0; m < column; m++) {
            for (int p = 0; p < data.size(); p++) {
                if (p >= column * board_counter) {
                    board_counter++;
                    col_sum = 0;
                }
                col_sum = col_sum + data[p][m];
                if (p == ((column * board_counter) - 1)) {
                    if (col_sum == -5) {
                        lotery_win = stoi(lotery[i]);
                        winner_col_raw = p;
                        check_board[board_counter-1] = 1;
                        sum_z = 0;
                        for (int z = 0; z < check_board.size(); z++) {
                            sum_z = sum_z+check_board[z];
                        }
                        if (sum_z == number_of_board) {
                            cout << " -------------- all found!!!" << endl;
                            found_all = true;
                            winner_raw = 0;
                            break;
                        }
                    }
                }
            }
            if (found_all == true) 
                break;
            else {
                board_counter = 1;
                col_sum = 0;
            }
        }
        if (found_all == true) 
            break;
    }

    int unmarked_sum = 0;
    if (winner_raw != 0) {
        int start = (board_raw_counter * column) - column;
        for (int i = start; i < board_raw_counter * column ; i++) {
            for (int j = 0; j < column; j++) {
                if (data[i][j] != -1) {
                    unmarked_sum = unmarked_sum + data[i][j];
                }
            }
        }
    }

    if (winner_col_raw != 0) {
        int start = (board_counter * column) - column;
        for (int i = start; i < board_counter * column ; i++) {
            for (int j = 0; j < column; j++) {
                if (data[i][j] != -1) {
                    unmarked_sum = unmarked_sum + data[i][j];
                }
            }
        }
    }
    cout << "Sum: " << unmarked_sum << endl;

    int result = 0;
    result = unmarked_sum * lotery_win;

    cout << "Result " << result << endl;
    
    return 0;
}
