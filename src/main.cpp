#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/Entity.h"

/* XPM */
static char * icon_xpm[] = {
  "32 23 3 1",
  "     c #FFFFFF",
  ".    c #000000",
  "+    c #FFFF00",
  "                                ",
  "            ........            ",
  "          ..++++++++..          ",
  "         .++++++++++++.         ",
  "        .++++++++++++++.        ",
  "       .++++++++++++++++.       ",
  "      .++++++++++++++++++.      ",
  "      .+++....++++....+++.      ",
  "     .++++.. .++++.. .++++.     ",
  "     .++++....++++....++++.     ",
  "     .++++++++++++++++++++.     ",
  "     .+++..++++++++++...++.     ",
  "     .+++++++++..+++++++++.     ",
  "     .+++++++++..+++++++++.     ",
  "     .++++++++++++++++++++.     ",
  "      .++++++++++++++++++.      ",
  "      .++...++++++++...++.      ",
  "       .++............++.       ",
  "        .++..........++.        ",
  "         .+++......+++.         ",
  "          ..++++++++..          ",
  "            ........            ",
  "                                "};

int main(int argc, char *argv[])
{
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Surface *surface;
  SDL_Texture *texture;
  int done;
  SDL_Event event;

  if (SDL_CreateWindowAndRenderer(0, 0, 0, &window, &renderer) < 0) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
        "SDL_CreateWindowAndRenderer() failed: %s", SDL_GetError());
    return(2);
  }

  surface = IMG_ReadXPMFromArray(icon_xpm);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  if (!texture) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
        "Couldn't load texture: %s", SDL_GetError());
    return(2);
  }
  SDL_SetWindowSize(window, 800, 800);

  SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
  SDL_RenderClear( renderer );
  
  Entity dummy;
  dummy.setX(50);
  dummy.setY(50);
  dummy.setW(200);
  dummy.setH(100);
  
  SDL_Rect r;
  r.x=dummy.getX();
  r.y=dummy.getY();
  r.w=dummy.getW();
  r.h=dummy.getH();
  
  done = 0;
  while (!done) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        done = 1;
    }
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
	
	// Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

    // Render rect
    SDL_RenderFillRect( renderer, &r );

    // Render the rect to the screen
    SDL_RenderPresent(renderer);
	
	
    SDL_Delay(100);
  }
  SDL_DestroyTexture(texture);

  SDL_Quit();
  return(0);
}

