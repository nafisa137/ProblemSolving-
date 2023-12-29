// File name: A3_SheetPb6_20220854
// Purpose:Game of life
// Author(s): Nafisa Abdalrahman Mohamed
// ID(s): 20220854
// Section: 1
// Date: 8/12/2023

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

// Define the size of the grid
const int r = 20;
const int c = 50;

// Define the symbols for dead and alive cells
const char DEAD = '.';
const char ALIVE = 'O';

// Define a class called Universe
class Universe {
private:
    vector<vector<char>> grid;
    vector<vector<char>> next_grid;

    // Function to generate a random layout
    void generateLayout() {
        srand(static_cast<unsigned>(time(nullptr)));

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                grid[i][j] = rand() % 2 == 1 ? ALIVE : DEAD;
            }
        }
    }

    // Function to count the number of alive neighbors of a given cell
    int countNeighbors(int row, int col) {
        int count = 0;

        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j) {
                if (i == row && j == col) {
                    continue;
                }

                if (i >= 0 && i < r && j >= 0 && j < c && grid[i][j] == ALIVE) {
                    ++count;
                }
            }
        }

        return count;
    }

public:
    // Constructor
    Universe() : grid(r, vector<char>(c)), next_grid(r, vector<char>(c)) {
        generateLayout();
    }

    // Function to reset the grid
    void reset() {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                grid[i][j] = DEAD;
            }
        }
    }

    // Function to produce the next generation of the grid
    void nextGeneration() {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                char state = grid[i][j];
                int neighbors = countNeighbors(i, j);

                if ((state == ALIVE && neighbors >= 2 && neighbors <= 3) ||
                    (state == DEAD && neighbors == 3)) {
                    next_grid[i][j] = ALIVE;
                } else {
                    next_grid[i][j] = DEAD;
                }
            }
        }

        grid = next_grid;
    }

    // Function to display the grid
    void display() {
        cout << "\033[2J\033[H";  // Clear the console screen

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << grid[i][j] << ' ';
            }
            cout << '\n';
        }

        // Pause for a short duration (adjust as needed)
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    // Function to run the game for a certain number of iterations
    void run(int iterations) {
        for (int i = 0; i < iterations; ++i) {
            display();
            nextGeneration();
        }
    }
};

