#include "board.h"
#include <iostream>
#include <optional>
#include <utility>

using namespace std;

#define WIDTH 5
#define HEIGHT 3

Board::Board() {
    for(int x = 0; x < XSIZE; ++x) {
        height[x] = 0;
        for(int y = 0; y < YSIZE; ++y) {
            spaces[x][y] = ' ';
        }
    }
}

inline bool shouldPlace(int x, int y) {
    return x == 2 && y == 1;
}

void Board::printBoard() {
    for(int y = YSIZE-1; y>=-1; --y) {
        for (int z = 0; z < (y==-1?1:HEIGHT+1); ++z) {
            for(int x = 0; x<XSIZE+1; ++x) {
                for(int w = 0; w<(x==XSIZE?1:WIDTH+1); ++w) {
                    //cout << shouldPlace(w-1,z-1)?spaces[x][y]:z==0?w==0?'+':'-':w==0?'|':' ';
                    if(shouldPlace(w-1, z-1)) {
                        cout << spaces[x][y];
                    } else if (z==0) {
                        cout << (w==0?'+':'-');
                    } else if (w==0) {
                        cout << "|";
                    } else {
                        cout << " ";
                    }
                }
            }
            cout << "\n";
        }
    }
    cout << "   ";
    for(int x = 0; x<XSIZE; ++x) {
        cout << x+1;
        for(int w = 0; w<WIDTH; ++w) {
            cout << " ";
        }
    }
    cout << "\n";
}

bool Board::canMakeMove(char side, int col) {
    return col >= 0 && col < XSIZE && height[col] != YSIZE;
}

bool Board::find4(int x, int y) {
    typedef pair<int, int> dir;
    dir directions[] = {{1, 1}, {-1, 1}, {1, 0}, {0, 1}};
    int matches;
    int cx, cy;
    for(auto d : directions) {
        matches = 0;
        for(int i = 0; i < 2; ++i){
            cx = x;
            cy = y;
            while(cx < XSIZE && cx >= 0 && cy < YSIZE && cy >= 0 && spaces[x][y] == spaces[cx][cy]) {
                ++matches;
                cx += d.first;
                cy += d.second;
            }
            d.first *= -1;
            d.second *= -1;
        }
        if(matches >= 5) //5 because (x, y) is double counted
            return true;
    }
    return false;
}

std::optional<bool> Board::makeMove(char side, int col) {
    spaces[col][height[col]++] = side;
    if(find4(col, height[col]-1))
        return true;
    for(int i = 0; i < XSIZE; ++i) {
        if(height[i] != YSIZE)
            return {};
    }
    return false;
}