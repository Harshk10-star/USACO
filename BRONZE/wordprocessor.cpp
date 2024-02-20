#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    ifstream inputFile("word.in");
    ofstream outputFile("word.out");
    string line;
    vector<string> strVector;

    int N, K;
    while(getline(inputFile, line)) {
        strVector.push_back(line);
    }
    
    istringstream numbers(strVector[0]);
    numbers >> N >> K;

    istringstream words(strVector[1]);
    
    string word;
    string currentLine = "";
    while (words >> word) {
        if (currentLine.empty()) {
            currentLine = word;
        } else if (currentLine.size() + word.size() <= K) { 
            currentLine += " "; 
            currentLine += word;
        } else { 
            outputFile << currentLine << endl;
            currentLine = word; 
        }
    }


    if (!currentLine.empty()) {
        outputFile << currentLine;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
