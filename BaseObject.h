#ifndef BASEOBJECT_H_INCLUDED
#define BASEOBJECT_H_INCLUDED

#include "xulychung.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL.h>

using namespace std;

void renderGame(SDL_Renderer* renderer,const string& guessedWord, const string& badGuesses, int & badGuessCount);
void displayFinalResult(SDL_Renderer* renderer,bool won, const string& word);
void setRenderColor(SDL_Renderer* renderer,SDL_Color cl);
bool menu(SDL_Renderer* renderer,bool choiLai);

#endif // BASEOBJECT_H_INCLUDED
