#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;
using std::cout;
using std::endl;

int DISCS = 5; 
int PEGS = 3;
int moveCount = 0;

void printPegs(const vector<list<int>>& pegs){ // Loop through pegs and disc to print out their locations.
    cout << endl << "Current state of pegs:" << endl;
    for (int i = 0; i < pegs.size(); i++){
        cout <<"Peg " << i+1 << ": ";
        for (int disk : pegs[i]){
            cout << disk << " ";
        }
        cout << endl;
    }
}

void hanoi(int discs, int source, int target, int auxiliary, vector<list<int>>& pegs){
    if(discs == 1){ // Moves the top disc from source to target. 
        pegs[target].push_front(pegs[source].front());
        pegs[source].pop_front();
        moveCount++;

        return;
    }else if(discs > 1){ //Ensures that there is at least one disc to be moved.
        hanoi(discs-1, source, auxiliary, target, pegs); // Recursively moves the n-1 disc from source to auxiliary

        pegs[target].push_front(pegs[source].front()); // Moves the nth disc from source to target
        pegs[source].pop_front();
        moveCount++;

        hanoi(discs-1, auxiliary, target, source, pegs); // Recursively moves n-1 discs from auxiliary to target
    }
}

int main() {

    vector<list<int>> pegs(PEGS);

    for (int i = DISCS; i >= 1; --i){ // Initalize the pegs so that all disc are on A. 
        pegs[0].push_front(i);
    }

    cout << "There are " << PEGS << " pegs and " << DISCS << " discs." << endl; // Prints initial setup. 
    printPegs(pegs);

    hanoi(DISCS, 0, 2, 1, pegs); // Starts algorithm to begin process. 

    printPegs(pegs);
    cout << "It took " << moveCount << " moves." << endl; // Prints final results
}