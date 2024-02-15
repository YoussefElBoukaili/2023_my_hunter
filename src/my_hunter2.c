/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** my hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/header.h"

void handle_event(sfEvent event, game_t *game)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    kill_duck(event, game);
}

int kill_duck(sfEvent event, game_t *game)
{
    sfVector2i clickPosition;
    sfFloatRect bounds;
    int window_h = sfRenderWindow_getSize(game->window).y;

    if (event.type == sfEvtMouseButtonPressed){
        clickPosition = sfMouse_getPositionRenderWindow(game->window);
        bounds = sfSprite_getGlobalBounds(game->sprite);
        if (sfFloatRect_contains(&bounds, clickPosition.x, clickPosition.y)) {
            game->duck_pos.x = -110;
            game->duck_pos.y = rand() % (window_h - 100);
            game->score++;
            mini_printf("Score : %d\n", game->score);
        }
    }
    return game->score;
}

void process_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)){
        handle_event(event, game);
    }
}

void animate_duck_sprite(game_t *game)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(game->clock)) > 0.2){
        game->duck_hitbox.left += 110;
        if (game->duck_hitbox.left > 220)
            game->duck_hitbox.left = 0;
        sfSprite_setTextureRect(game->sprite, game->duck_hitbox);
        sfClock_restart(game->clock);
    }
    sfRenderWindow_drawSprite(game->window, game->sprite, NULL);
}
