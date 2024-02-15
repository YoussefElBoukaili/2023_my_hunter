/*
** EPITECH PROJECT, 2023
** my
** File description:
** my header
*/

#ifndef HEADER_H_
    #define HEADER_H_
        #include <stdarg.h>
        #include <unistd.h>
        #include <stdio.h>
        #include <stdlib.h>
        #include <SFML/Graphics.h>

typedef struct game_s {
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *backg_texture;
    sfSprite *backg_sprite;
    sfClock *clock;
    sfIntRect duck_hitbox;
    sfVector2f duck_pos;
    sfVector2f scale;
    sfVideoMode mode;
    int score;
} game_t;

int my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(int nb);

int switch_flag(const char *format, va_list ap);

int mini_printf(const char *format, ...);

void handle_event(sfEvent event, game_t *game);

int kill_duck(sfEvent event, game_t *game);

void description(void);

void process_event(game_t *game);

void animate_duck_sprite(game_t *game);

void initialize_game(game_t *game);

void game_loop(game_t *game);

void reset_pos(game_t *game);

void cleanup(game_t *game);

#endif
