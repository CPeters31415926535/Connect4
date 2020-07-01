#include <board.h>

class Game {
public:
    void play();
    void printOptions();
    void congratulate(bool side);
private:
    Board b;
    bool toMove;
};