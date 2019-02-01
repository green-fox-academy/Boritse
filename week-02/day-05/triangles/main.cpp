#include <iostream>
#include <SDL.h>
#include <math.h>


//Screen dimension constants
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 480;

//Draws geometry on the canvas
void draw();


//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The window renderer
SDL_Renderer* gRenderer = nullptr;

void draw() {
    int startingHeight = 480;
    int startingWidth = 0;
    int endingHeight = 480;
    int endingWidth = 480;
    int a = 480 / 24;
    double root3= sqrt(3);
    int root3a= round(root3*a);
    //choose color
    for (int i = 0; i < 12; i++) {
        SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
//draw line
        SDL_RenderDrawLine(gRenderer, startingWidth + a, startingHeight - root3a/2, endingWidth - a, endingHeight - root3a/2);
        a += endingWidth / 24;}
        SDL_RenderDrawLine(gRenderer, (endingWidth / 2), (startingHeight / 2), startingWidth, endingHeight);
        a = 480/24;

        for(int i=0; i<12; i++) {
        SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
//draw line
        SDL_RenderDrawLine(gRenderer, (endingWidth / 2)+a, (startingHeight / 2)+root3a/2, startingWidth+2*a, endingHeight);
        a+=endingWidth/24;}
        SDL_RenderDrawLine(gRenderer, (endingWidth / 2), (startingHeight / 2), endingWidth, endingHeight);
        a = 480/24;

        for(int i=0; i<12; i++) {
        SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, (endingWidth / 2)-a, (startingHeight / 2)+root3a/2, endingWidth-2*a, startingHeight);
        a+=endingWidth/24;
    }
    // draw a red horizontal line to the canvas' middle.
    // draw a green vertical line to the canvas' middle.
}

bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow( "Line in the middle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == nullptr )
    {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == nullptr )
    {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    return true;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit ) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        draw();

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}#include <iostream>
#include <SDL.h>


//Screen dimension constants
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 480;

//Draws geometry on the canvas
void draw();


//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The window renderer
SDL_Renderer* gRenderer = nullptr;

void draw() {
    int startingHeight = 480;
    int startingWidth = 0;
    int endingHeight = 480;
    int endingWidth = 480;
    int a = 480 / 24;
    //choose color
    for (int i = 0; i < 12; i++) {
        SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
//draw line
        SDL_RenderDrawLine(gRenderer, startingWidth + a, startingHeight - a, endingWidth - a, endingHeight - a);
        a += endingWidth / 24;
    }
    SDL_RenderDrawLine(gRenderer, (endingWidth / 2), (startingHeight / 2), startingWidth, endingHeight);
    a = 480/24;
    for(int i=0; i<12; i++) {
        SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
//draw line
        SDL_RenderDrawLine(gRenderer, (endingWidth / 2)+a, (startingHeight / 2)+a, startingWidth+2*a, endingHeight);
        a+=endingWidth/24;
    }
    SDL_RenderDrawLine(gRenderer, (endingWidth / 2), (startingHeight / 2), endingWidth, endingHeight);
    a = 480/24;
    for(int i=0; i<12; i++) {
        SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, (endingWidth / 2)-a, (startingHeight / 2)+a, endingWidth-2*a, startingHeight);
        a+=endingWidth/24;
    }
    // draw a red horizontal line to the canvas' middle.
    // draw a green vertical line to the canvas' middle.
}

bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow( "Line in the middle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == nullptr )
    {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == nullptr )
    {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    return true;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit ) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        draw();

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}