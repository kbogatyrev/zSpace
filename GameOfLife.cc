#include <iostream>
#include <cstring>
#include <cstdio>
#include "GameOfLife.h"

using namespace gol;

bool GameOfLife::Init(char* arg)
{
    for (int i = 0; i < strlen(arg); ++i) {
        arg[i] = toupper(arg[i]);
    }

    if (0 == strcmp("BLINKER", arg)) {
        char g[] = { "............................X.......X.......X..................." };
        //            0123456701234567012345670123456701234567012345670123456701234567        
        //            0       1       2       3       4       5       6       7
        memcpy(grid, g, SIZE*SIZE);
        return true;
    }

    if (0 == strcmp("TOAD", arg)) {
        char g[] = { "...........................XXX....XXX..........................." };
        //            0123456701234567012345670123456701234567012345670123456701234567        
        //            0       1       2       3       4       5       6       7
        memcpy(grid, g, SIZE*SIZE);
        return true;
    }

    if (0 == strcmp("BEACON", arg)) {
        char g[] = { ".............XX......XX....XX......XX..........................." };
        //            0123456701234567012345670123456701234567012345670123456701234567        
        //            0       1       2       3       4       5       6       7
        memcpy(grid, g, SIZE * SIZE);
        return true;
    }

    if (0 == strcmp("RANDOM", arg)) {
        for (int i = 0; i < SIZE*SIZE; ++i) {
            grid[i] = '.';
        }
        srand(static_cast<unsigned int>(time(NULL)));
        int max_count = rand()%(SIZE*SIZE);
        for (int cell = 0; cell < max_count; ++cell) {
            grid[rand()%(SIZE*SIZE)] = 'X';
        }
        return true;
    }

    // Extra pattern stolen from zSpace for testing purposes
/*
    if (0 == strcmp("TEST", arg)) {
        char g[] = { "...XX.XX...XXXX..XXXX.X..XX...XX..X.XXXXXXX.XXXXXXXX.XX.X.X....X" };
        //           0123456701234567012345670123456701234567012345670123456701234567        
        //           0       1       2       3       4       5       6       7
        memcpy(grid, g, SIZE * SIZE);
        return true;
    }
*/

    return false;

}        // Init()

int GameOfLife::CountNeighbors(int idx) const
{
    int cellX = idx % SIZE;
    int cellY = idx / SIZE;
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int neighborX = (cellX + j + SIZE) % SIZE;
            int neighborY = (cellY + i + SIZE) % SIZE;
            char neighbor = grid[neighborX + SIZE*neighborY];
            if (neighbor == 'X' || neighbor == 'D') {
                if (!(i == 0 && j == 0)) {
                    ++count;
                }
            }
        }
    }
    return count;
}

bool GameOfLife::Traverse()
{
    for (int i = 0; i < SIZE*SIZE; ++i) {
        int count = CountNeighbors(i);
            if ('.' == grid[i]) {
                if (3 == count) {
                    grid[i] = 'B';
                }
            }
            else {
                if (count < 2 || count > 3) {
                    grid[i] = 'D';
                }
            }
    }
    return true;
}

bool GameOfLife::Update()
{
    for (int i = 0; i < SIZE*SIZE; ++i) {
        if ('B' == grid[i]) {
            grid[i] = 'X';
        }
        else if ('D' == grid[i]) {
            grid[i] = '.';
        }
    }
    return true;
}

void GameOfLife::Print() const
{
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col)
        {
            std::cout << grid[SIZE*row + col];
        }
        std::cout << '\n';
    }
    std::cout << "\n\n";
}

int main(int argc, char* argv[])
{
    GameOfLife gol;
    bool ready = false;

    if (argc > 1) {
        ready = gol.Init(argv[1]);
    }
    else {
        char arg[] = "RANDOM";
        ready = gol.Init(arg);
    }

    if (!ready) {
        std::cout << "Invalid input.\n Press Enter to exit...";
        std::getc(stdin);
        return 0;
    }
    else
    {
        for (int i = 0; i < GENERATIONS; ++i) {
            gol.Print();
            gol.Traverse();
            gol.Update();
        }
    }

    std::cout << "Done. Press Enter to exit...";
    std::getc(stdin);
    return 0;
}
