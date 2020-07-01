#define XSIZE 7
#define YSIZE 6

#include <cstdint>

class Board {
public:
private:
    char spaces[XSIZE][YSIZE];
    uint8_t height[XSIZE];
};