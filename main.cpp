#include "src/Menu/Menu.h"

int main() {
    TowerDefence::menu();
    return 0;
}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    const int H = 25;
//    const int W = 40;
//    const int WALL = -1;
//    const int BLANK = -2;
//
//    int px[H * W], py[H * W];
//    int len;
//    int grid[H][W];
//
//    int dx[4] = {1, 0, -1, 0};
//    int dy[4] = {0, 1, 0, -1};
//    int d, x, y, k;
//    bool stop;
//
//    int ax = 4, ay = 16, bx = 7, by = 19;
//
//    for (int i = 0; i < H; i++) {
//        for (int j = 0; j < W; j++) {
//            grid[i][j] = -2;
//        }
//    }
//
//    for (int i = 0; i < H; i++) {
//        grid[i][0] = -1;
//        grid[i][W - 1] = -1;
//    }
//
//    for (int i = 0; i < W; i++) {
//        grid[0][i] = -1;
//        grid[H - 1][i] = -1;
//    }
//
//    for (k = 0; k < 4; k++) {
//        int ix = bx + dx[k], iy = by + dy[k];
//        grid[ix][iy] = WALL;
//    }
//
//
//    for (int i = 0; i < H; i++) {
//        for (int j = 0; j < W; j++) {
//            if (grid[i][j] >= 0)
//                cout << ' ' << grid[i][j] << ' ';
//            else
//                cout << grid[i][j] << ' ';
//        }
//        cout << endl;
//    }
//
//    d = 0;
//    grid[ax][ay] = 0;
//    do {
//        stop = true;
//        for (x = 0; x < H; x++) {
//            for (y = 0; y < W; y++) {
//                if (grid[x][y] == d) {
//                    for (k = 0; k < 4; k++) {
//                        int ix = x + dx[k], iy = y + dy[k];
//                        if (ix >= 0 && ix < H && iy >= 0 && iy < W && grid[ix][iy] == BLANK) {
//                            stop = false;
//                            grid[ix][iy] = d + 1;
//                        }
//                    }
//                }
//            }
//        }
//        d++;
//    } while (!stop && grid[bx][by] == BLANK);
//
//    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
//
//    for (int i = 0; i < H; i++) {
//        for (int j = 0; j < W; j++) {
//            if (grid[i][j] >= 0 && grid[i][j] < 10)
//                cout << ' ' << grid[i][j] << ' ';
//            else
//                cout << grid[i][j] << ' ';
//        }
//        cout << endl;
//    }
//
//    if (grid[bx][by] == BLANK)
//        cout << "FALSE" << endl;
//
//    len = grid[bx][by];
//    x = bx;
//    y = by;
//    d = len;
//    while (d > 0) {
//        px[d] = x;
//        py[d] = y;
//        d--;
//        for (k = 0; k < 4; k++) {
//            int ix = x + dx[k], iy = y + dy[k];
//            if (ix >= 0 && ix < H && iy >= 0 && iy < W && grid[ix][iy] == d) {
//                x = x + dx[k];
//                y = y + dy[k];
//                break;
//            }
//        }
//    }
//    px[0] = ax;
//    py[0] = ay;
//
//    for (int i = 0; i < len + 1; i++)
//        cout << px[i] << ' ' << py[i] << endl;
//    return 0;
//}