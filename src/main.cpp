#include "../include/SDL2/SDL.h"
//#include <SDL2/SDL_image.h>
#include "../include/Entity.h"
#include <stdlib.h>
#include <vector>

using namespace std;

/* XPM */
/*static char * icon_xpm[] = {
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
*/


void putt(vector< unsigned char >& pixels,int x,int y,int r,int g,int b, unsigned int tw){
  unsigned int offset = ( tw * 4 * y ) + x * 4;
            pixels[ offset + 0 ] = b;        // b
            pixels[ offset + 1 ] = g;        // g
            pixels[ offset + 2 ] = r;        // r
            pixels[ offset + 3 ] = SDL_ALPHA_OPAQUE;    // a
}




int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    //SDL_Surface *surface;
    SDL_Texture *texture;
    bool running;
    SDL_Event event;

    //need this or keyboard will die on raspberry pi
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_CreateWindowAndRenderer(0, 0, 0, &window, &renderer) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
            "SDL_CreateWindowAndRenderer() failed: %s", SDL_GetError());
        return(2);
    }
    //SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");

//    surface = IMG_ReadXPMFromArray(icon_xpm);
    /*texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
        "Couldn't load texture: %s", SDL_GetError());
        return(2);
    }*/
    SDL_SetWindowSize(window, 640, 560);

    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
    SDL_RenderClear( renderer );
    
   /*Entity dummy;
    dummy.setX(50);
    dummy.setY(50);
    dummy.setW(200);
    dummy.setH(100);*/

    /*SDL_Rect r;
    r.x=dummy.getX();
    r.y=dummy.getY();
    r.w=dummy.getW();
    r.h=dummy.getH();*/


    const unsigned int texWidth = 160;
    const unsigned int texHeight = 144;
    unsigned int R=1,G=1,B=1;

    texture = SDL_CreateTexture
        (
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        texWidth, texHeight
        );

    vector< unsigned char > pixels( texWidth * texHeight * 4, 0 );


    //definetely want fullscreen for raspberry pi
    SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN);
    running = true;
    int count=0;
    int eval=10;
    if(argc>1){
      eval=atoi(argv[1]);
    }
    printf("%i",eval);
    while (running) {
        while (SDL_PollEvent(&event)) {


            if(SDL_QUIT == event.type ||( SDL_KEYDOWN == event.type && SDL_SCANCODE_ESCAPE == event.key.keysym.scancode )){
                running = false;
                break;
            }
            if( event.type == SDL_FINGERDOWN){ //SDL_MOUSEBUTTONDOWN == event.type ||
              if(event.button.button == SDL_BUTTON_LEFT){
                R=1;
                G=1;
                B=1;

                //int x = event.tfinger.x * texWidth;
                //int y = event.tfinger.y * texHeight;
                //currentTexture = &gTouchDownTexture;
                putt(pixels,5,5,255,0,0,texWidth);
              }
            }


	    
        }
        putt(pixels,1,1,255,0,0,texWidth);
        if(eval>0){

          count++;
          if(count>eval){running=false;break;}
        }
	
        for( unsigned int i = 0; i < 10000; i++ )
        {
            const unsigned int x = rand() % texWidth;
            const unsigned int y = rand() % texHeight;

            const unsigned int offset = ( texWidth * 4 * y ) + x * 4;
            pixels[ offset + 0 ] = rand() % B;        // b
            pixels[ offset + 1 ] = rand() % G;        // g
            pixels[ offset + 2 ] = rand() % R;        // r
            pixels[ offset + 3 ] = SDL_ALPHA_OPAQUE;    // a
        }
        if(R<255){
            R++;
            G++;
            B++;
        }
        SDL_UpdateTexture
            (
            texture,
            NULL,
            &pixels[0],
            texWidth * 4
            );

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);


        // Set render color to blue ( rect will be rendered in this color )
        SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
       // SDL_RenderFillRect( renderer, &r );
        SDL_RenderPresent(renderer);


        SDL_Delay(100);
    }
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return(0);
}

Uint32 getP( SDL_Surface *surface, int x, int y ){
    Uint32 *pixels = (Uint32 *)surface->pixels;
    return pixels[ ( y * surface->w ) + x ];
}

void putP( SDL_Surface *surface, int x, int y, Uint32 pixel ){
    Uint32 *pixels = (Uint32 *)surface->pixels;
    pixels[ ( y * surface->w ) + x ] = pixel;
}



typedef int32_t s32;

void DrawCircle(SDL_Renderer *Renderer, s32 _x, s32 _y, s32 radius)
{ 
   s32 x = radius - 1;
   s32 y = 0;
   s32 tx = 1;
   s32 ty = 1;
   s32 err = tx - (radius << 1); // shifting bits left by 1 effectively
                                 // doubles the value. == tx - diameter
   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(Renderer, _x + x, _y - y);
      SDL_RenderDrawPoint(Renderer, _x + x, _y + y);
      SDL_RenderDrawPoint(Renderer, _x - x, _y - y);
      SDL_RenderDrawPoint(Renderer, _x - x, _y + y);
      SDL_RenderDrawPoint(Renderer, _x + y, _y - x);
      SDL_RenderDrawPoint(Renderer, _x + y, _y + x);
      SDL_RenderDrawPoint(Renderer, _x - y, _y - x);
      SDL_RenderDrawPoint(Renderer, _x - y, _y + x);

      if (err <= 0)
      {
         y++;
         err += ty;
         ty += 2;
      }
      if (err > 0)
      {
         x--;
         tx += 2;
         err += tx - (radius << 1);
      }
   }
}
