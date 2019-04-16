#include <iostream>
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;
int counter = 0;

//Draws geometry on the canvas
void draw();


//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = nullptr;

//The window renderer
SDL_Renderer *gRenderer = nullptr;

void draw(int ax, int ay, int bx, int by, int cx, int cy) {

    SDL_SetRenderDrawColor(gRenderer, 255, 0x00, 0x00, 0xFF);
    SDL_RenderDrawLine(gRenderer, ax, ay, bx / 2, by);
    SDL_SetRenderDrawColor(gRenderer, 0x00, 255, 0x00, 0xFF);
    SDL_RenderDrawLine(gRenderer, bx / 2, by, cx / 2, cy / 2);
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 255, 0xFF);
    SDL_RenderDrawLine(gRenderer, cx / 2, cy / 2, ax, ay);
    draw(ax, ay, bx / 2, by, cx / 2, cy / 2);

    SDL_SetRenderDrawColor(gRenderer, 255, 0x00, 0x00, 0xFF);
    SDL_RenderDrawLine(gRenderer, bx, by, (cx - ax) * 3 / 2, cy / 2);
    SDL_SetRenderDrawColor(gRenderer, 0x00, 255, 0x00, 0xFF);
    SDL_RenderDrawLine(gRenderer, (cx - ax) * 3 / 2, cy / 2, bx / 2, by);
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 255, 0xFF);
    SDL_RenderDrawLine(gRenderer, bx / 2, by, bx, by);
    draw(bx / 2, by, bx, by, (cx - ax) * 3 / 2, cy / 2);

    SDL_SetRenderDrawColor(gRenderer, 0, 0x00, 255, 0xFF);
    SDL_RenderDrawLine(gRenderer, (cx - ax) / 2, (cy - ay) / 2, (cx - ax) * 3 / 2, cy / 2);
    SDL_SetRenderDrawColor(gRenderer, 0x00, 255, 0x00, 0xFF);
    SDL_RenderDrawLine(gRenderer, (cx - ax) * 3 / 2, cy / 2, cx, cy);
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 255, 0xFF);
    SDL_RenderDrawLine(gRenderer, cx, cy, (cx - ax) / 2, (cy - ay) / 2);
    draw((cx - ax) / 2, (cy - ay) / 2, (cx - ax) * 3 / 2, cy / 2, cx, cy);

}

// draw a red horizontal line to the canvas' middle.
// draw a green vertical line to the canvas' middle.


bool init() {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow("Line in the middle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr) {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == nullptr) {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}

void close() {
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main(int argc, char *args[]) {
    //Start up SDL and create window
    if (!init()) {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while (!quit) {
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
        int ax = 0;
        int ay = 0;
        int bx = SCREEN_WIDTH;
        int by = 0;
        int cx = SCREEN_WIDTH / 2;
        int cy = SCREEN_HEIGHT - 86;

        draw(ax, ay, bx, by, cx, cy);

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}