#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL_ttf.h>

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_Window *window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    TTF_Font *Sans = TTF_OpenFont("./font/Calibri Regular.ttf", 12);

    SDL_Color White = {255, 255, 255};

    SDL_Surface *surfaceMessage =
        TTF_RenderText_Solid(Sans, "HOP HOP HOP", White);

    // now you can convert it into a texture
    SDL_Texture *Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect Message_rect; // create a rect
    Message_rect.x = 50;   // controls the rect's x coordinate
    Message_rect.y = 50;   // controls the rect's y coordinte
    Message_rect.w = 300;  // controls the width of the rect
    Message_rect.h = 300;  // controls the height of the rect

    uint8_t isRunning = 1;
    SDL_Event event;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                isRunning = 0;
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    isRunning = 0;
                }
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
        // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
