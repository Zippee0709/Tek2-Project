/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** IndieStudioData
*/

#ifndef INDIESTUDIODATA_HPP_
#define INDIESTUDIODATA_HPP_
#include <iostream>
#include <map>
#include "../../irrlicht-1.8.4/include/irrlicht.h"

namespace IndieStudio {
    enum gameState {
        SPLASHSCREEN,
        MENU,
        SELECTMENU,
        GAME,
        INGAMEMENU,
        SAVEMENU,
        SETTINGS,
        CREDITS,
        GAMEOVER,
        PLAYER1,
        PLAYER2,
        EXIT,
    };
    enum menuButton{
        PLAY,
        LOAD,
        OPTIONS,
        QUIT
    };
    enum selectMenuButton{
        PLAYER1LEFT,
        PLAYER1SELECT,
        PLAYER1RIGHT,
        PLAYER1LOCK,
        PLAYER2LEFT,
        PLAYER2SELECT,
        PLAYER2RIGHT,
        PLAYER2LOCK,
        SELECTPLAY,
        SELECTHOME
    };
    enum settingButton {
        MORE,
        LESS,
        QUIT_SETTING,
        RETURN_IN_GAME,
    };
    enum gameOverButton {
        REMATCH,
        BACKTOMENU
    };
    enum skinSelected {
        BIG,
        CLAIRE,
        DESBIANS,
        KAYA,
        MICHELLE,
        MOUSEY,
        TIMMY
    };
    enum inGameMenuButtons {
        RESUME,
        SAVE,
        OPTIONINGAME,
        QUITINGAME
    };

    struct selectMenuConfig {
        bool haveTwoPlayer = false;
        irr::core::stringc playersSkinImage[2];
        irr::core::stringc playersSkinDae[2];
    };
    struct menuSettingConfig {
        int volume = 50;
    };

    struct playerKeyBinding
    {
        irr::EKEY_CODE moveUp;
        irr::EKEY_CODE moveDown;
        irr::EKEY_CODE moveLeft;
        irr::EKEY_CODE moveRight;
        irr::EKEY_CODE plantBomb;
    };

    struct playerOneKeyBinding : playerKeyBinding {
        playerOneKeyBinding() : playerKeyBinding { irr::KEY_KEY_Z, irr::KEY_KEY_S, irr::KEY_KEY_Q, irr::KEY_KEY_D, irr::KEY_SPACE } {};
    };

    struct playerTwoKeyBinding : playerKeyBinding {
        playerTwoKeyBinding() : playerKeyBinding { irr::KEY_UP, irr::KEY_DOWN, irr::KEY_LEFT, irr::KEY_RIGHT, irr::KEY_RSHIFT } {};
    };

}
#endif /* !INDIESTUDIODATA_HPP_ */
