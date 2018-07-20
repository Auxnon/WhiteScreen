#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/Entity.h"

int main (int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    SDL_Window* window = NULL;
    window = SDL_CreateWindow
    (
        "yep", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_SHOWN
    );

    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );

    // Clear winow
    SDL_RenderClear( renderer );

    // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.

    Entity* dummy =new Entity();
    //Entity dummy;
    dummy->setX(50);
    dummy->setY(50);
    dummy->setW(200);
    dummy->setH(100);
    /*dummy.setX(60);
    dummy.setY(100);
    dummy.setH(300);
    dummy.setW(100);*/
    SDL_Rect r;
    r.x = dummy->getX();
    r.y = dummy->getY();
    r.w = dummy->getW();
    r.h = dummy->getH();
//    r.x=dummy.getX();
//    r.y=dummy.getY();
//    r.w=dummy.getW();
//    r.h=dummy.getH();

    delete dummy;

    SDL_Surface *image= IMG_Load("texture/coon.png");

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

    // Render rect
    SDL_RenderFillRect( renderer, &r );

    // Render the rect to the screen
    SDL_RenderPresent(renderer);

    // Wait for 5 sec
    SDL_Delay( 2000 );

    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
