/* Created by bbara on 18.11.2021. */

#include "Route.h"

namespace TowerDefence {

    void Route::createRoute(Landscape &landscape) {
        int H = landscape.getHeight();
        int W = landscape.getWidth();
        int grid[H][W];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (landscape.m_map[i][j] == 'P')
                    grid[i][j] = -2;
                else
                    grid[i][j] = -1;
            }
        }
        int px[H * W], py[H * W];
        int len;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int d, x, y, k;
        bool stop;
    }
}

