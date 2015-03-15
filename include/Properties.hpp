/*
** Created by André Paulos
** 4ndr3p4ul0s@gmail.com
** Space Invaders like game
*/
#ifndef     PROPERTIES_HPP_
# define    PROPERTIES_HPP_

/*
 ** Main window properties
 */
const int   X_SIZE = 700;
const int   Y_SIZE = 780;
const int   WINDOW_GAME_LIMIT = 650;
const int   FQ = 16;

/*
 ** Wall properties
 */
const int   WALL_LIFE = 100;
const float WALL_Y_OFFSET = 630.f;
const float WALL_LENGTH = 66.f;
const float WALL_HEIGHT = 30.f;

/*
 ** Ship properties
 */
const float SHIP_SPEED = 10.f;
const float Y_OFFSET = 740.f;
const float SHIP_WIDTH = 52.f;
const float SHIP_HEIGHT = 22.f;
const float X_SCALE_FACTOR = 2.0f;
const float Y_SCALE_FACTOR = 2.0f;

/*
 ** Adversary properties
 */
const int   ADVERSARY_SPEED = 1.f;
const float ADVERSARY_LENGTH = 40.f;
const float ADVERSARY_HEIGHT = 25.f;
const float ADVERSARY_Y_OFFSET = 20.f;
const float ADVERSARY_FALL_SPEED = 20.f;

/*
 ** Bullets properties
 */
const float BULLET_SPEED = 3.0f;
const int   MAXBULLETS = 15;

#endif      /* !PROPERTIES_HPP_ */
