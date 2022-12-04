#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    ifstream mySample("input1.txt");
    vector<int> numbers;
    int number;

    if (mySample.is_open()) {
        while(mySample >> number)
            numbers.push_back(number);
        mySample.close();
    }
    int increasedCounter = 0;

    cout << numbers[0] << endl;
    for (int i = 1; i < numbers.size(); i++) {
        cout << numbers[i] << "\t";
        if (numbers[i] > numbers[i-1]) {
            cout << "increased\n";
            increasedCounter++;
        }
        else if (numbers[i] == numbers[i-1])
            cout << "no change\n";
        else {
            cout << "decresed\n";
        }
    }
    cout << "Increased numbers: " << increasedCounter << endl;

    vector<int> sumOfThreeElements;
    int increasedSumCounter = 0;
    int sum = 0;
    for (int i = 2; i < numbers.size(); i++) {
        sum = numbers[i-2] + numbers[i-1] + numbers[i];
        sumOfThreeElements.push_back(sum);
        sum = 0;
    }
    cout << sumOfThreeElements[0] << endl;
    for (int i = 1; i < sumOfThreeElements.size(); i++) {
        cout << sumOfThreeElements[i] << "\t";
        if (sumOfThreeElements[i] > sumOfThreeElements[i-1]) {
            cout << "increased\n";
            increasedSumCounter++;
        }
        else if (sumOfThreeElements[i] == sumOfThreeElements[i-1])
            cout << "no change\n";
        else
            cout << "decreased\n";
    }
    cout << "Increased numbers: " << increasedSumCounter << endl;

    return 0;
}
