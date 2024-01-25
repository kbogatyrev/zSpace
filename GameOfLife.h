#ifndef GAME_OF_LIFE_H_
#define GAME_OF_LIFE_H_

/*
        Konstantin's coding exercise for zSpace interview
        See README for build instructions
*/

namespace gol {

    const int SIZE = 8;
    const int GENERATIONS = 4;

    struct GameOfLife
    {
        bool Init(char* arg);
        int CountNeighbors(int cellIdx) const;
        bool Traverse();
        bool Update();
        void Print() const;

        char grid[SIZE*SIZE];
    };

}       // namespace gol

#endif  // GAME_OF_LIFE_H_