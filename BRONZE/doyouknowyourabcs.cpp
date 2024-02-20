#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    string line;
    vector<int> numbers;

    getline(cin, line);
    istringstream iss(line);
    int num;
    while (iss >> num) {
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());
    
    int A = numbers[0];
    int B = numbers[1];
    int ABC = numbers[numbers.size() - 1];
    int C = ABC - A - B;

    cout << A << " " << B << " " << C;

    return 0;
}
