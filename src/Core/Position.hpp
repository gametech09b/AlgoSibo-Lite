#pragma once

/// @brief Position struct
struct Position
{
public:
    int x;
    int y;

    Position(int x, int y);

    bool operator==(const Position &other) const;
    bool operator!=(const Position &other) const;
};
