#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> 
using namespace std;

int main() {
    ifstream inputFile("teleport.in");
    string line;
    int start;
    int end;
    int teleportX;
    int teleportY;
    
    while (getline(inputFile, line)) {
        istringstream iss(line);
        iss >> start >> end >> teleportX >> teleportY;
    }

    int noTeleport = abs(start - end);
    int usingX = abs(start - teleportX) + abs(teleportY - end);
    int usingY = abs(start - teleportY) + abs(teleportX - end);
    int minDistance = min(min(usingX, usingY), noTeleport);
    
    ofstream outputFile("teleport.out");
    outputFile << minDistance;
    inputFile.close();

    return 0;
}