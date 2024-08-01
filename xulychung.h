#ifndef XULYCHUNG_H_INCLUDED
#define XULYCHUNG_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
#include <SDL_image.h>

using namespace std ;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Hang man";

//namespace SDLCommonFunc
//{
    void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
    SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
    /*void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);*/
    void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
    void logSDLError(std::ostream& os,
    const std::string &msg, bool fatal = false);
    void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
    void waitUntilKeyPressed();
//}

#endif // XULYCHUNG_H_INCLUDED
