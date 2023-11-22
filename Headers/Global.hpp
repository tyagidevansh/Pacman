#pragma once

constexpr unsigned char CELL_SIZE = 16;
constexpr unsigned char FONT_HEIGHT = 16;
constexpr unsigned char MAP_HEIGHT = 21;
constexpr unsigned char MAP_WIDTH = 21;
constexpr unsigned char SCREEN_RESIZE = 2;

enum Cell
{
    Door,
    Empty,
    Energizer,
    Pellet,
    Wall
};

struct Position
{
    short x;
    short y;

    bool operator==(const Position& i_position){
        return this->x == i_position.x && this->y == i_position.y;
    }
};