#include <iostream>
#include <SDL.h>
#include <map>
#include <vector>

//Screen dimension constants
const int SCREEN_WIDTH = 613;
const int SCREEN_HEIGHT = 613;

void fillmap(std::map<int, std::vector<int>> &boxes, int a, int red, int green,
             int blue);
void changer(int *redptr , int *greenptr , int *blueptr);

//Draws geometry on the canvas
void draw(std::map<int, std::vector<int>> *boxes);


//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = nullptr;

//The window renderer
SDL_Renderer *gRenderer = nullptr;


void draw(std::map<int, std::vector<int>> *boxes) {
    std::map<int, std::vector<int>>::iterator boxesIt = boxes->begin();
    for (; boxesIt != boxes->end(); boxesIt++) {
        std::vector<int> color = boxesIt->second;
        SDL_SetRenderDrawColor(gRenderer, boxesIt->second[0], boxesIt->second[1], boxesIt->second[2], 0xFF);
        SDL_Rect fillRect = {SCREEN_WIDTH / 2 - boxesIt->first / 2, SCREEN_HEIGHT / 2 - boxesIt->first / 2,
                             boxesIt->first,
        boxesIt->first};
        SDL_RenderDrawRect(gRenderer, &fillRect);
    }

}


bool init() {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow("Rainbow box function", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
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
    std::map<int, std::vector<int>> boxes;
    int a = 1;
    int red = 255;
    int green = 0;
    int blue = 0;



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

        changer(&red , &green , &blue);
        fillmap(boxes, a, red, green, blue);
        draw(&boxes);



        //Update screen
       SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}


void fillmap(std::map<int, std::vector<int>> &boxes, int a, int red, int green,
             int blue) {

    for (int i = 0; i <= 306; ++i) {
        std::vector<int> colors;
        boxes[a] = colors;


        if (red == 255 && blue == 0 && green != 255) {
            boxes[a].push_back(red);
            boxes[a].push_back(green);
            boxes[a].push_back(blue);
            green += 5;
            a += 2;
        } else if (green == 255 && blue == 0 && red != 0) {
            boxes[a].push_back(red);
            boxes[a].push_back(green);
            boxes[a].push_back(blue);
            red -= 5;
            a += 2;
        } else if (red == 0 && green == 255 && blue != 255) {
            boxes[a].push_back(red);
            boxes[a].push_back(green);
            boxes[a].push_back(blue);
            blue += 5;
            a += 2;
        } else if (red == 0 && blue == 255 && green != 0) {
            boxes[a].push_back(red);
            boxes[a].push_back(green);
            boxes[a].push_back(blue);
            green -= 5;
            a += 2;
        } else if (green == 0 && blue == 255 && red != 255) {
            boxes[a].push_back(red);
            boxes[a].push_back(green);
            boxes[a].push_back(blue);
            red += 5;
            a += 2;
        } else {
            boxes[a].push_back(red);
            boxes[a].push_back(green);
            boxes[a].push_back(blue);
            blue -= 5;
            a += 2;
        }
    }
}
void changer(int *redptr , int *greenptr , int *blueptr) {
    if (*redptr == 255 && *blueptr == 0 && *greenptr != 255) {
        *greenptr += 5;
    } else if (*greenptr == 255 && *blueptr == 0 && *redptr != 0) {
        *redptr -= 5;
    } else if (*redptr == 0 && *greenptr == 255 && *blueptr != 255) {
        *blueptr += 5;
    } else if (*redptr == 0 && *blueptr == 255 && *greenptr != 0) {
        *greenptr -= 5;
    } else if (*greenptr == 0 && *blueptr == 255 && *redptr != 255) {
        *redptr += 5;
    } else {
        *blueptr -= 5;
    }

}