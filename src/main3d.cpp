#include "../include/SDL2/SDL.h"
//#include <SDL2/SDL_image.h>
#include "../include/Entity.h"

/*
#include <GL/gl.h>
#include <GL/glu.h>*/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include "../include/SDL2/SDL_opengl.h"
//#include <GL/glut.h>
//#include <vector>

//using namespace std;
/*
void putt(vector< unsigned char >& pixels,int x,int y,int r,int g,int b, unsigned int tw){
  unsigned int offset = ( tw * 4 * y ) + x * 4;
            pixels[ offset + 0 ] = b;        // b
            pixels[ offset + 1 ] = g;        // g
            pixels[ offset + 2 ] = r;        // r
            pixels[ offset + 3 ] = SDL_ALPHA_OPAQUE;    // a
}
*/
/*
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
  // texture = SDL_CreateTextureFromSurface(renderer, surface);
  // if (!texture) {
  //     SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
  //     "Couldn't load texture: %s", SDL_GetError());
  //     return(2);
  // }
    SDL_SetWindowSize(window, 640, 560);

    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
    SDL_RenderClear( renderer );



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
}*/


/*

// Load the vertex shader
    const GLchar *vShaderStr =
        "attribute vec4 vPosition;    \n"
        "void main()                  \n"
        "{                            \n"
        "   gl_Position = vPosition;  \n"
        "}                            \n";
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderStr, NULL);
    glCompileShader(vertexShader);
    //Load the fragment shader
    const GLchar *fShaderStr =
        "precision mediump float;\n"\
        "void main()                                  \n"
        "{                                            \n"
        "  gl_FragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );\n"
        "}                                            \n";
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderStr, NULL);
    glCompileShader(fragmentShader);

    // Create the program object
    GLuint programObject = glCreateProgram();

    glDisable(GL_DEPTH_TEST);
    glAttachShader(programObject, vertexShader);
    glAttachShader(programObject, fragmentShader);

    // Bind vPosition to attribute 0   
    glBindAttribLocation(programObject, 0, "vPosition");

    // Link the program
    glLinkProgram(programObject);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);


    GLfloat vVertices[] = { 
        0.0f, 0.5f, 0.0f,
        1.0f, 2.0f, 3.0f,
        2.0f, 3.0f, 4.0f,
        3.0f, 4.0f, 5.0f,
        4.0f, 5.0f, 6.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f };
    GLfloat vVertices2[] = { 0.0f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f };
    GLshort ndxArray[] = { 0,5,6 };
    GLshort ndxArray2[] = { 0,1,2 };

    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Use the program object
    glUseProgram(programObject);

    // Load the vertex data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
    glEnableVertexAttribArray(0);

    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, ndxArray);
*/

/*





const GLchar* vertexSource =
    "attribute vec2 position;                     \n"
    "void main()                                  \n"
    "{                                            \n"
    "  gl_Position = vec4(position,0.0, 1.0);     \n"
    "}                                            \n";
    */

// Shader sources
/*
const GLchar* vertexSource =
    "attribute vec3 position;                     \n"
    "void main()                                  \n"
    "{                                            \n"
    "  gl_Position = vec4(position.xyz, 1.0);     \n"
    "}                                            \n";
*/


const GLchar* vertexSource = "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
    "}\0";

const GLchar* fragmentSource =
    "precision mediump float;\n"
    "void main()                                  \n"
    "{                                            \n"
    "  gl_FragColor[0] = gl_FragCoord.x/640.0;    \n"
    "  gl_FragColor[1] = gl_FragCoord.y/480.0;    \n"
    "  gl_FragColor[2] = 0.5;                     \n"
    "}                                            \n";

// an example of something we will control from the javascript side
bool background_is_black = false;

// the function called by the javascript code
//extern "C" void EMSCRIPTEN_KEEPALIVE toggle_background_color() { background_is_black = !background_is_black; }

//std::function<void()> loop;
//void main_loop() { loop(); }

int main()
{
    SDL_Window *window;
    //SDL_Renderer *renderer; //remove for webgl?
    /*if (SDL_CreateWindowAndRenderer(0, 0, 0, &window, &renderer) < 0) {//enter nullptr instead of renderer on webgl?
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
            "SDL_CreateWindowAndRenderer() failed: %s", SDL_GetError());
        return(2);
    }*/

    window = SDL_CreateWindow("Hello Window!", 20, 40, 600, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    SDL_GL_CreateContext(window);
    //swap buffer at the monitors rate
    //SDL_GL_SetSwapInterval(1);

    //SDL_SetWindowSize(window, 640, 480);

    //added for desktop not for web
    if (glewInit() != GLEW_OK) {
        return -2;
    }
    //glViewport(0, 0, 640,480ls); 
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    glewExperimental = GL_TRUE; //$ added desktop
    
    // Create a Vertex Buffer Object and copy the vertex data to it
    /*GLuint vbo;
    glGenBuffers(1, &vbo);

    GLfloat vertices[] = {0.0f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f};

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);*/

    // Create and compile the vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, nullptr);
    glCompileShader(vertexShader);

    // Create and compile the fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
    glCompileShader(fragmentShader);

    // Link the vertex and fragment shader into a shader program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    //glEnableClientState(GL_VERTEX_ARRAY); //$ added desktop?

    // Specify the layout of the vertex data
    /*GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);

    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

    SDL_Event event;
    bool running=true;
    while (running) {
        while (SDL_PollEvent(&event)) {
           
            if(SDL_QUIT == event.type ||( SDL_KEYDOWN == event.type && SDL_SCANCODE_ESCAPE == event.key.keysym.scancode )){
                running = false;
                break;
            }
          }

        // move a vertex
        const uint32_t milliseconds_since_start = SDL_GetTicks();
        const uint32_t milliseconds_per_loop = 3000;
        //vertices[0] = ( milliseconds_since_start % milliseconds_per_loop ) / float(milliseconds_per_loop) - 0.5f;
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


        if( background_is_black )
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        else
            glClearColor(0.3f, 0.9f, 0.9f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        background_is_black=!background_is_black;
        glDrawArrays(GL_LINE_LOOP, 0, 3); //GL_TRIANGLES

        SDL_GL_SwapWindow(window);
        SDL_Delay(100); //$ desktop
    }*/
    //SDL_DestroyTexture(texture);
    
    

    //emscripten_set_main_loop(main_loop, 0, true); //$ wasm

    //return EXIT_SUCCESS;*/







    GLfloat firstTriangle[] = {
        -0.9f, -0.5f, 0.0f,  // Left 
        -0.0f, -0.5f, 0.0f,  // Right
        -0.45f, 0.5f, 0.0f,  // Top 
    };
    GLfloat secondTriangle[] = {
         0.0f, -0.5f, 0.0f,  // Left
         0.9f, -0.5f, 0.0f,  // Right
         0.45f, 0.5f, 0.0f   // Top 
    };
    GLuint VBOs[2], VAOs[2];
    glGenVertexArrays(2, VAOs);
    glGenBuffers(2, VBOs);
    // ================================
    // First Triangle setup
    // ===============================
    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);   // Vertex attributes stay the same
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    // ================================
    // Second Triangle setup
    // ===============================
    glBindVertexArray(VAOs[1]); // Note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]); // And a different VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0); // Because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out.
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    // Game loop
    SDL_Event event;
    bool running=true;
    while (running) {
        while (SDL_PollEvent(&event)) {
           
            if(SDL_QUIT == event.type ||( SDL_KEYDOWN == event.type && SDL_SCANCODE_ESCAPE == event.key.keysym.scancode )){
                running = false;
                break;
            }
          }
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        //glfwPollEvents();

        // Render
        // Clear the colorbuffer
        glClearColor(1.0f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Now when we want to draw the triangle we first use the vertex and orange fragment shader from the first program.
        //glUseProgram(shaderProgramOrange);
        // Draw the first triangle using the data from our first VAO
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);   // This call should output an orange triangle
        // Then we draw the second triangle using the data from the second VAO
        // When we draw the second triangle we want to use a different shader program so we switch to the shader program with our yellow fragment shader.
        //glUseProgram(shaderProgramYellow);
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);   // This call should output a yellow triangle
        glBindVertexArray(0);

        // Swap the screen buffers
        //glfwSwapBuffers(window);
        SDL_GL_SwapWindow(window);
    }
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2, VBOs);





















    //SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    printf("it rand\n");
return 0;
}