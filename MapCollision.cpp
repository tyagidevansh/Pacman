#include <array>
#include <cmath>
#include "Headers/MapCollision.hpp"
#include "Headers/Global.hpp"

bool map_collision(int i_x, int i_y, std::vector<std::string>& i_map) {
    bool output = 0;

    //Getting the exact position of the pacman
    float cell_x = i_x / static_cast<float>(CELL_SIZE);
    float cell_y = i_y / static_cast<float>(CELL_SIZE);

    //Entity can interact with 4 cells at a time
    for (int a = 0; a < 4; a++){
        int x = 0;
        int y = 0;

        switch(a)
        {
            case 0:
            {
                x = floor(cell_x);
                y = floor(cell_y);
                break;
            }
            case 1:
            {
                x = ceil(cell_x);
                y = floor(cell_y);
                break;
            }
            case 2:
            {
                x = floor(cell_x);
                y = ceil(cell_y);
                break;
            }
            case 3:
            {
                x = ceil(cell_x);
                y = ceil(cell_y);
                break;
            }
        }

        if (0 <= x && 0 <= y && x < MAP_WIDTH && y < MAP_HEIGHT){
            if (i_map[y][x] == '#'){
                output = 1;
            }
        }
    }
    printf("Collision: %d\n", output);
    return output;
}

