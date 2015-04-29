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
# include   <string>
# include   "Typedefs.hpp"

/*
 ** Main window properties
 */
const int           X_SIZE = 800;
const int           Y_SIZE = 1000;
const int           WINDOW_GAME_LIMIT = 650;
const int           FQ = 16;

/*
 ** Wall properties
 */
const std::string   PATH_WALL_SPRITE_100 = "./Sprite/Wall.png";
const int           WALL_LIFE = 100;
const float         WALL_Y_OFFSET = 850.f;
const float         WALL_LENGTH = 44.f;
const float         WALL_HEIGHT = 34.f;

/*
 ** Ship properties
 */
const std::string   PATH_SHIP_SPRITE_100 = "./Sprite/Ship.png";
const float         SHIP_SPEED = 15.f;
const float         SHIP_Y_OFFSET = 950.f;
const float         SHIP_WIDTH = 25.f;
const float         SHIP_HEIGHT = 16.f;
const float         X_SCALE_FACTOR = 1.0f;
const float         Y_SCALE_FACTOR = 1.0f;

/*
 ** Adversary properties
 */
const std::vector<std::pair<std::string, std::string>>  PATH_ADVERSARY_SPRITES_1 = {
    {"Adversary1-1-", "./Sprite/Adversary1-1.png"},
    {"Adversary1-1-", "./Sprite/Adversary1-2.png"},
};
const std::vector<std::pair<std::string, std::string>>  PATH_ADVERSARY_SPRITES_2 = {
    {"Adversary2-1-", "./Sprite/Adversary2-1.png"},
    {"Adversary2-1-", "./Sprite/Adversary2-2.png"},
};
const std::vector<std::pair<std::string, std::string>>  PATH_ADVERSARY_SPRITES_3 = {
    {"Adversary3-1-", "./Sprite/Adversary2-1.png"},
    {"Adversary3-1-", "./Sprite/Adversary2-2.png"},
};
const std::vector<std::pair<std::string, std::string>>  PATH_ADVERSARY_SPRITES_4 = {
    {"Adversary4-1-", "./Sprite/Adversary3-1.png"},
    {"Adversary4-1-", "./Sprite/Adversary3-2.png"},
};
const std::vector<std::pair<std::string, std::string>>  PATH_ADVERSARY_SPRITES_5 = {
    {"Adversary5-1-", "./Sprite/Adversary3-1.png"},
    {"Adversary5-1-", "./Sprite/Adversary3-2.png"},
};

const std::vector<std::vector<pair2s>>  PATH_ADVERSARY_SPRITES = {
    PATH_ADVERSARY_SPRITES_1,
    PATH_ADVERSARY_SPRITES_2,
    PATH_ADVERSARY_SPRITES_3,
    PATH_ADVERSARY_SPRITES_4,
    PATH_ADVERSARY_SPRITES_5
};
const int           ADVERSARY_SPEED = 2.f;
const int           ADVERSARY_PER_LINE = 11;
const float         ADVERSARY_LENGTH = 40.f;
const float         ADVERSARY_HEIGHT = 25.f;
const float         ADVERSARY_Y_OFFSET = 20.f;
const float         ADVERSARY_FALL_SPEED = 20.f;

/*
 ** Bullets properties
 */
const float         BULLET_SPEED = 5.0f;
const int           MAXBULLETS = 15;

#endif      /* !PROPERTIES_HPP_ */
