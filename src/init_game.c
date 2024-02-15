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

sfRenderWindow* create_window(sfVideoMode mode)
{
    return sfRenderWindow_create(mode, "My Hunter", sfResize | sfClose, NULL);
}

void initialize_game(game_t *game)
{
    game->mode.width = 800;
    game->mode.height = 600;
    game->mode.bitsPerPixel = 32;
    game->texture = sfTexture_createFromFile("duck.png", NULL);
    game->sprite = sfSprite_create();
    game->backg_texture = sfTexture_createFromFile("background.png", NULL);
    game->backg_sprite = sfSprite_create();
    game->clock = sfClock_create();
    game->duck_hitbox.left = 0;
    game->duck_hitbox.top = 0;
    game->duck_hitbox.width = 110;
    game->duck_hitbox.height = 110;
    game->duck_pos.x = 0;
    game->duck_pos.y = 250;
    game->scale.x = 0.1;
    game->scale.y = 0.1;
    sfSprite_setTexture(game->sprite, game->texture, sfTrue);
    sfSprite_setTexture(game->backg_sprite, game->backg_texture, sfTrue);
    sfSprite_setTextureRect(game->sprite, game->duck_hitbox);
    game->window = create_window(game->mode);
}
