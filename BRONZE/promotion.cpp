#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    ifstream inputFile("promote.in");
    ofstream outputFile("promote.out");
    string line;
    vector<string> strVector;

    while (getline(inputFile, line)) {
        strVector.push_back(line);
    }
   
    inputFile.close();

    int bronze_after, silver_after, gold_after, platinum_after;
    int bronze_before, silver_before, gold_before, platinum_before;

    stringstream ss(strVector[0]);
    ss >> bronze_before >> bronze_after;

    stringstream ss2(strVector[1]);
    ss2 >> silver_before >> silver_after;

    stringstream ss3(strVector[2]);
    ss3 >> gold_before >> gold_after;

    stringstream ss4(strVector[3]);
    ss4 >> platinum_before >> platinum_after;

    int platinum_promotions = (platinum_after - platinum_before);
    int gold_promotions = (gold_after - gold_before) + platinum_promotions;
    int silver_promotions = (silver_after - silver_before) + gold_promotions;
 

    outputFile << silver_promotions << endl;
    outputFile << gold_promotions << endl;
    outputFile << platinum_promotions;

    outputFile.close();

    return 0;
}
