#pragma once

#include <deque>
#include <map>
#include <string>
#include <vector>

namespace leetcode::games
{
    /* 353. Design Snake Game.

    Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.

    The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

    You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.

    Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.

    When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

    Example:

    Given width = 3, height = 2, and food = [[1,2],[0,1]].

    Snake snake = new Snake(width, height, food);

    Initially the snake appears at position (0,0) and the food at (1,2).

    |S| | |
    | | |F|

    snake.move("R"); -> Returns 0

    | |S| |
    | | |F|

    snake.move("D"); -> Returns 0

    | | | |
    | |S|F|

    snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

    | |F| |
    | |S|S|

    snake.move("U"); -> Returns 1

    | |F|S|
    | | |S|

    snake.move("L"); -> Returns 2 (Snake eats the second food)

    | |S|S|
    | | |S|

    snake.move("U"); -> Returns -1 (Game over because snake collides with border)
    */

    /**
     * Your SnakeGame object will be instantiated and called as such:
     * SnakeGame* obj = new SnakeGame(width, height, food);
     * int param_1 = obj->move(direction);
     */

    class SnakeGame
    {
        int width_, height_;
        std::vector<std::vector<int>> food_;
        std::size_t food_index_;
        std::deque<std::pair<int, int>> snake_;

    public:
        /** Initialize your data structure here.
            @param width - screen width
            @param height - screen height
            @param food - A list of food positions
            E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
        SnakeGame( const int width, const int height, std::vector<std::vector<int>>& food )
        {
            width_ = width; height_ = height;
            food_index_ = 0;
            food_ = food;

            snake_.push_front( { 0, 0 } ); // starting position
        }

        /** Moves the snake.
            @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
            @return The game's score after the move. Return -1 if game over.
            Game over when snake crosses the screen boundary or bites its body. */
        int move( const std::string& direction )
        {
            auto [row, col] = snake_.front();

            if( direction == "U" ) row--;
            else if( direction == "D" ) row++;
            else if( direction == "L" ) col--;
            else if( direction == "R" ) col++;

            // board boundary
            if( row < 0 || row >= height_ || col < 0 || col >= width_ )
                return -1;

            const auto tmp = std::make_pair( row, col );

            // snake collision
            if( std::find( snake_.begin(), snake_.end(), tmp ) != snake_.end()
                && snake_.back() != tmp )
            {
                return -1;
            }

            if( food_index_ < food_.size() )
            {
                const auto food = food_[ food_index_ ];

                if( food[ 0 ] == row && food[ 1 ] == col )
                {
                    ++food_index_;
                }
                else
                {
                    snake_.pop_back();
                }
            }

            snake_.push_front( tmp );

            return food_index_;
        }
    };
}