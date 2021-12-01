#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int compare(vector<int>);
void showMessage(int);
void task(vector<int>);

int main() {

    //read numbers from file and create vector
    ifstream mySample("input1.txt");
    vector<int> numbers;
    int number;

    if (mySample.is_open()) {
        while(mySample >> number)
            numbers.push_back(number);
        mySample.close();
    }

    //part1
    task(numbers);

    //part2

    //create new vector for sum of three elements
    vector<int> sumOfThreeElements;
    for (int i = 2; i < numbers.size(); i++) {
        int sum = numbers[i-2] + numbers[i-1] + numbers[i];
        sumOfThreeElements.push_back(sum);
    }

    task(sumOfThreeElements);

    return 0;
}

int compare(vector<int> numbers) {
    int counter = 0;
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] > numbers[i-1])
            counter++;
    }
    return counter;
}

void showMessage(int counter) {
    cout << "Increased numbers: " << counter << endl;
}

void task(vector<int> numbers) {
    int increasedCounter = 0;
    increasedCounter = compare(numbers);
    showMessage(increasedCounter);
}
