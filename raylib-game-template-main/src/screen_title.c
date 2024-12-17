/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Title Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "screens.h"

#define resourcesPath "C:/Users/cybco/OneDrive/Escritorio/SpaceInvaders/raylib-game-template-main/src/resources/"



static const int screenWidth = 800;
static const int screenHeight = 450;
//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

Texture2D textureBackground, textureLogo, textureGamepad;
//----------------------------------------------------------------------------------
// Title Screen Functions Definition
//----------------------------------------------------------------------------------

// Title Screen Initialization logic
void InitTitleScreen(void)
{
    char temparalChain[200];

    // TODO: Initialize TITLE screen variables here!
    framesCounter = 0;
    finishScreen = 0;

    //Inicializar Texturas
    strcpy(temparalChain, resourcesPath);  // Copy str1 into result
    strcat(temparalChain, "background.png");
    Image background = LoadImage(temparalChain);
    temparalChain[0] = '\0';

    ImageResize(&background, screenWidth, screenHeight);
    textureBackground = LoadTextureFromImage(background);
    UnloadImage(background);


    strcpy(temparalChain, resourcesPath);  // Copy str1 into result
    strcat(temparalChain, "logo.png");
    Image logo = LoadImage(temparalChain);
    temparalChain[0] = '\0';

    ImageResize(&logo, screenWidth/2, screenHeight/2);
    textureLogo = LoadTextureFromImage(logo);
    UnloadImage(logo);



    strcpy(temparalChain, resourcesPath);  // Copy str1 into result
    strcat(temparalChain, "gamepad.png");
    Image gamepad = LoadImage(temparalChain);
    temparalChain[0] = '\0';

    ImageResize(&gamepad, 520, 130);
    textureGamepad = LoadTextureFromImage(gamepad);
    UnloadImage(gamepad);
}

// Title Screen Update logic
void UpdateTitleScreen(void)
{
    // TODO: Update TITLE screen variables here!

    // Press enter or tap to change to GAMEPLAY screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        //finishScreen = 1;   // OPTIONS
        finishScreen = 2;   // GAMEPLAY
        PlaySound(fxCoin);
    }
}

// Title Screen Draw logic
void DrawTitleScreen(void)
{
    // TODO: Draw TITLE screen here!
    DrawTexture(textureBackground, screenWidth / 2 - textureBackground.width / 2, screenHeight / 2 - textureBackground.height / 2, WHITE);

    DrawTexture(textureLogo, screenWidth / 2 - textureLogo.width / 2, screenHeight / 2 - textureLogo.height / 2 - 100, WHITE);

    DrawTexture(textureGamepad, screenWidth / 2 - textureGamepad.width / 2, screenHeight / 2 - textureGamepad.height / 2 + 150, WHITE);
}

// Title Screen Unload logic
void UnloadTitleScreen(void)
{
    // TODO: Unload TITLE screen variables here!
}

// Title Screen should finish?
int FinishTitleScreen(void)
{
    return finishScreen;
}