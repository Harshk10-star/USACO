#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
#include <set>
using namespace std;

class node {
public:
    int step;
    int x;
    int y;
    string block;
    node(int intValue, string stringValue, int x, int y) : step(intValue), block(stringValue), x(x), y(y) {}
};

int main() {
    ifstream inputFile("buckets.in");
    ofstream outputFile("buckets.out");
    string line;
    string grid[10][10];
    queue<node> myQueue;
    set<pair<int, int>> visited; // Visited set to keep track of squares where cows have been placed
    int row = 0;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        char chars;
        int col = 0;
        while(iss >> chars) {
            grid[row][col] = chars;
            col += 1;
        }
        row += 1;
    }
    int startx;
    int starty;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(grid[i][j] == "L") {
                startx = i;
                starty = j;
                break;
            }
        }
    }

    myQueue.push(node(0, "L", startx, starty));
    int coords[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    while(!myQueue.empty()) {
        node n = myQueue.front();
        myQueue.pop();

        for(int i = 0; i < 4; i++) {
            int x = coords[i][0];
            int y  = coords[i][1];
            int newX = x + n.x;
            int newY = y + n.y;

            if(newX >= 0 && newY >= 0 && newX < 10 && newY < 10 && !visited.count({newX, newY})) {
                visited.insert({newX, newY});
                if(grid[newX][newY] != "R") {
                    if(grid[newX][newY] == "B") {
                        outputFile << n.step;
                        inputFile.close();
                        outputFile.close();
                        return 0;
                    }
                    myQueue.push(node(n.step + 1, grid[newX][newY], newX, newY));
                }
            }
        } 
    }
    
    outputFile << -1;
    inputFile.close();
    outputFile.close();

    return 0;
}
