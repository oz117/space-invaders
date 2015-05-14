/*
** File: [Properties.hpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-13 19:35
**
*/

#ifndef     PROPERTIES_HPP_
# define    PROPERTIES_HPP_

# include   <vector>
# include   <map>
# include   <string>
# include   "Typedefs.hpp"

// { General Game properties
const int           TEXTURE_COUNT = 5;
const int           SPRITE_COUNT = 61;
//}

// { Main window properties
const int           X_SIZE = 800;
const int           Y_SIZE = 1000;
const int           WINDOW_GAME_LIMIT = 650;
const int           FQ = 16;
// }

// { Wall properties
const std::string   PATH_WALL_SPRITE = "./Sprite/Wall.png";
const int           WALL_LIFE = 100;
const int           WALL_COUNT = 5;
const float         WALL_Y_OFFSET = 850.f;
const float         WALL_LENGTH = 44.f;
const float         WALL_HEIGHT = 32.f;
const float         WALL_SPRITES[5][4] = {
    {0.f, 0.f, 44.f, 32.f},
    {44.f, 0.f, 88.f, 32.f},
    {88.f, 0.f, 132.f, 32.f},
    {132.f, 0.f, 176.f, 32.f},
    {176.f, 0.f, 220.f, 32.f}
};
// }

// { Ship properties
const std::string   PATH_SHIP_SPRITE = "./Sprite/Ship.png";
const float         SHIP_SPEED = 15.f;
const float         SHIP_Y_OFFSET = 950.f;
const float         SHIP_WIDTH = 26.f;
const float         SHIP_HEIGHT = 16.f;
const float         X_SCALE_FACTOR = 1.0f;
const float         Y_SCALE_FACTOR = 1.0f;
const float         SHIPSPRITES[2][4] = {
    {0.f, 0.f, 26.f, 16.f},
    {26.f, 0.f, 52.f, 16.f}
};
// }

// { Adversary properties
const std::string   PATH_ADVERSARY_SPRITE_0 = "./Sprite/Adversary0.png";
const std::string   PATH_ADVERSARY_SPRITE_1 = "./Sprite/Adversary1.png";
const std::string   PATH_ADVERSARY_SPRITE_2 = "./Sprite/Adversary2.png";
const int           ADVERSARY_PER_LINE = 11;
const int           ADVERSARY_ROW_COUNT = 5;
const int           ADVERSARY_SPEED = 15.f;
const float         ADVERSARY_LENGTH = 40.f;
const float         ADVERSARY_HEIGHT = 25.f;
const float         ADVERSARY_Y_OFFSET = 20.f;
const float         ADVERSARY_FALL_SPEED = 20.f;
const float         ADVERSARY_SPRITES_0[3][4] = {
    {0.f, 0.f, 16.f, 16.f},
    {16.f, 0.f, 16.f, 16.f},
    {32.f, 0.f, 26.f, 16.f}
};
const float         ADVERSARY_SPRITES_1[3][4] = {
    {0.f, 0.f, 22.f, 16.f},
    {22.f, 0.f, 22.f, 16.f},
    {44.f, 0.f, 26.f, 16.f}
};
const float         ADVERSARY_SPRITES_2[3][4] = {
    {0.f, 0.f, 24.f, 16.f},
    {24.f, 0.f, 24.f, 16.f},
    {48.f, 0.f, 26.f, 16.f}
};
// }

/*
 ** Bullets properties
 */
const float         BULLET_SPEED = 5.0f;
const int           MAXBULLETS = 15;

#endif      /* !PROPERTIES_HPP_ */
