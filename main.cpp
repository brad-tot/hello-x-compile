/* --------------- Copyright (c) Takeoff Technical LLC 2022 -------------------
 * Purpose: Just a sample project that uses SDL to demonstrate linking a cross-
 *          compile setup to a dynamic library installed via aptitude.
 * Refer:   https://takeofftechnical.com/x-compile-cpp-bbb
 * License: MIT
 * ----------------------------------------------------------------------------
*/
#include <SDL.h>
#include <stdio.h>

int main(void)
{
    printf("Hello SDL from Takeoff Technical!\n");

    if( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        printf("SDL failed to initialize! [%s]\n",
            SDL_GetError()
        );
        return 1;
    }

    // Your code here

    SDL_Quit();
    
    return 0;
}
