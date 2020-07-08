#define XSIZE 7
#define YSIZE 6

#include <cstdint>
#include <optional>

class Board {
public:
    bool canMakeMove(char side, int col);
    std::optional<bool> makeMove(char side, int col);
    void printBoard();

    Board();
private:
    char spaces[XSIZE][YSIZE];
    uint8_t height[XSIZE];

    bool find4(int x, int y);
};