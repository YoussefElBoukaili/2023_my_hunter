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

void description(void)
{
    mini_printf("Game Name :\n");
    mini_printf("-------My Hunter-------\n");
    mini_printf("Game description :\n");
    mini_printf("This game is about hunting ducks.\n");
    mini_printf("you can shoot the ducks by clicking on them.\n");
    mini_printf("ENJOYYY!!\n");
}

void game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)){
        process_event(game);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->backg_sprite, NULL);
        if (game->sprite != NULL){
            animate_duck_sprite(game);
            game->duck_pos.x += 0.1;
            reset_pos(game);
            sfSprite_setPosition(game->sprite, game->duck_pos);
        }
        sfRenderWindow_display(game->window);
    }
}

void reset_pos(game_t *game)
{
    if (game->duck_pos.x > game->mode.width)
        game->duck_pos.x = -110;
}

void cleanup(game_t *game)
{
    sfSprite_destroy(game->sprite);
    sfTexture_destroy(game->texture);
    sfSprite_destroy(game->backg_sprite);
    sfTexture_destroy(game->backg_texture);
    sfRenderWindow_destroy(game->window);
}

int main(int ac, char **av)
{
    game_t game;

    game.score = 0;
    srand(time(NULL));
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h'){
        description();
        return 0;
    }
    initialize_game(&game);
    game_loop(&game);
    cleanup(&game);
    return 0;
}
