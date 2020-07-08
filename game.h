#include "board.h"

class Game {
public:
    void play();
    void printOptions();
    void getMove();
    void congratulate(std::optional<char> side);
private:
    Board b;
};