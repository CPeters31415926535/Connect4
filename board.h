#define XSIZE 7
#define YSIZE 6

#include <cstdint>

class Board {
public:
    bool canMakeMove(bool side, int col);
    /*
    * Returns true iff game is over
    */
    bool makeMove(bool side, int col);
    void printBoard();
    int getResult();
private:
    char spaces[XSIZE][YSIZE];
    uint8_t height[XSIZE];
};