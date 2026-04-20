#ifndef GAME_H
#define GAME_H

typedef enum {MD_MAIN_MENU,
              MD_PLAYING,
              MD_GAMEOVER,
              MD_QUIT
            } GameState;
extern GameState GameMode;

#endif //GAME_H