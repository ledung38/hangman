#include"BaseObject.h"


using namespace std ;


const SDL_Color RED_COLOR = {255, 0, 0};
const SDL_Color BLACK_COLOR = {0, 0, 0};
const SDL_Color YELLOW_COLOR = {255, 255, 0};

const string background= "C:\\HANGMANDUNG\\dung20020380-main\\HANGMAN_DUNG\\hinh\\background.bmp";
const string FONT_CHU= "font-times-new-roman.ttf";
const string anh1= "C:\\HANGMANDUNG\\dung20020380-main\\HANGMAN_DUNG\\hinh\\anh1.bmp";
const string anh2= "C:\\HANGMANDUNG\\dung20020380-main\\HANGMAN_DUNG\\hinh\\anh2.bmp";
const string anh3= "C:\\HANGMANDUNG\\dung20020380-main\\HANGMAN_DUNG\\hinh\\anh3.bmp";
const string anh4= "C:\\HANGMANDUNG\\dung20020380-main\\HANGMAN_DUNG\\hinh\\anh4.bmp";
const string anh5= "C:\\HANGMANDUNG\\dung20020380-main\\HANGMAN_DUNG\\hinh\\anh5.bmp";
const string anh6= "C:\\HANGMANDUNG\\dung20020380-main\\HANGMAN_DUNG\\hinh\\anh6.bmp";
const string anh8= "C:\\HANGMANDUNG\\dung20020380-main\\HANGMAN_DUNG\\hinh\\anh8.bmp";
const string anh9= "C:\\HANGMANDUNG\\dung20020380-main\\HANGMAN_DUNG\\hinh\\anh9.bmp";


bool check1(SDL_Rect a,SDL_Point mouse){
    if(mouse.x > a.x && mouse.x <a.w +a.x && mouse.y > a.y && mouse.y < a.h + a.y) return true;
    return false;
}

bool check(SDL_Rect a,SDL_Point oldMouse,SDL_Point newMouse){
    if((check1(a,oldMouse)==true && check1(a,newMouse))==true)return true;
    else return false;
}

void clearScreen(SDL_Renderer* renderer) {
    setRenderColor(renderer,BLACK_COLOR);
    SDL_RenderClear(renderer);
}

void renderGame(SDL_Renderer* renderer,const string& guessedWord, const string& badGuesses, int &badGuessCount)
{
    clearScreen(renderer);

    SDL_Rect no1,no2;

    no1.x = 0 ;
    no1.y =0 ;
    no1.w=800;
    no1.h=600;

    no2.x = 270 ;
    no2.y =170 ;
    no2.w=280;
    no2.h=300;

    TTF_Font* font = TTF_OpenFont(FONT_CHU.c_str(),30);


    string msg1 = "Secret word: " + guessedWord;
    string msg2 = "";
    string msg3 = "You are lucky to receive 1 more guess ";
    if(badGuessCount >= 1){
        msg2 = "You've made " + to_string(badGuesses.size()) + " wrong " + (badGuessCount == 1 ? "guess" : "guesses") + ": " + badGuesses ;
    }

    SDL_Surface* textSurface1 = TTF_RenderText_Solid(font,msg1.c_str(),RED_COLOR);
    SDL_Surface* textSurface2 = (msg2 == "" ? nullptr:TTF_RenderText_Solid(font,msg2.c_str(),RED_COLOR));
    SDL_Surface* textSurface3 = TTF_RenderText_Solid(font,msg3.c_str(),RED_COLOR);

    SDL_Surface* loadBkg = IMG_Load(background.c_str());
    SDL_Surface* loadAnh1 = IMG_Load(anh1.c_str());
    SDL_Surface* loadAnh2 = IMG_Load(anh2.c_str());
    SDL_Surface* loadAnh3 = IMG_Load(anh3.c_str());
    SDL_Surface* loadAnh4 = IMG_Load(anh4.c_str());
    SDL_Surface* loadAnh5 = IMG_Load(anh5.c_str());
    SDL_Surface* loadAnh6 = IMG_Load(anh6.c_str());
    SDL_Surface* loadAnh9 = IMG_Load(anh9.c_str());

    SDL_Texture* hinhnen = SDL_CreateTextureFromSurface(renderer,loadBkg);
    SDL_Texture* Anh1 = SDL_CreateTextureFromSurface(renderer,loadAnh1);
    SDL_Texture* Anh2 = SDL_CreateTextureFromSurface(renderer,loadAnh2);
    SDL_Texture* Anh3 = SDL_CreateTextureFromSurface(renderer,loadAnh3);
    SDL_Texture* Anh4 = SDL_CreateTextureFromSurface(renderer,loadAnh4);
    SDL_Texture* Anh5 = SDL_CreateTextureFromSurface(renderer,loadAnh5);
    SDL_Texture* Anh6 = SDL_CreateTextureFromSurface(renderer,loadAnh6);
    SDL_Texture* Anh9 = SDL_CreateTextureFromSurface(renderer,loadAnh9);


    SDL_Texture* text1 = SDL_CreateTextureFromSurface(renderer,textSurface1);
    SDL_Texture* text2 = (textSurface2 == nullptr ? nullptr:SDL_CreateTextureFromSurface(renderer,textSurface2));
    SDL_Texture* text3 = SDL_CreateTextureFromSurface(renderer,textSurface3);


    SDL_Rect text1Rect,text2Rect,text3Rect;
    SDL_QueryTexture(text2,nullptr,nullptr,&text2Rect.w,&text2Rect.h);
    SDL_QueryTexture(text1,nullptr,nullptr,&text1Rect.w,&text1Rect.h);

    text2Rect.x = 250;
    text2Rect.y = 570 - text2Rect.h;

    text1Rect.x = 300;
    text1Rect.y = 530 - text1Rect.h;

    SDL_RenderCopy(renderer,hinhnen,nullptr,nullptr);


    switch (badGuessCount){
    case 1 :
        SDL_RenderCopy(renderer,hinhnen,nullptr,&no1 );
        SDL_RenderCopy(renderer,Anh1,nullptr,&no2 );
        break;
    case 2 :
        SDL_RenderCopy(renderer,hinhnen,nullptr,&no1 );
        SDL_RenderCopy(renderer,Anh2,nullptr,&no2 );
        break;
    case 3 :
        SDL_RenderCopy(renderer,hinhnen,nullptr,&no1 );
        SDL_RenderCopy(renderer,Anh3,nullptr,&no2 );
        break;
    case 4 :
        SDL_RenderCopy(renderer,hinhnen,nullptr,&no1 );
        SDL_RenderCopy(renderer,Anh4,nullptr,&no2 );
        break;
    case 5 :
        SDL_RenderCopy(renderer,hinhnen,nullptr,&no1 );
        SDL_RenderCopy(renderer,Anh5,nullptr,&no2 );
        break;
    case 6 :
        SDL_RenderCopy(renderer,hinhnen,nullptr,&no1 );
        SDL_RenderCopy(renderer,Anh6,nullptr,&no2 );
        break;
    case 7 :
        int r = 1 + rand()%4 ;
        if ( r ==1) {
        SDL_QueryTexture(text3,nullptr,nullptr,&text3Rect.w,&text3Rect.h);
        text3Rect.x = 250;
        text3Rect.y = 100 - text3Rect.h;

        SDL_RenderCopy(renderer,hinhnen,nullptr,&no1 );
        SDL_Delay(850);
        SDL_RenderCopy(renderer,Anh6,nullptr,&no2 );
        SDL_RenderCopy(renderer,text3,nullptr,&text3Rect);
        badGuessCount=6;
        break ;
        }
        else {
            SDL_RenderCopy(renderer,hinhnen,nullptr,&no1 );
            SDL_RenderCopy(renderer,Anh9,nullptr,&no2 );
                break;
            }
        }
    SDL_RenderCopy(renderer,text2,nullptr,&text2Rect);
    SDL_RenderCopy(renderer,text1,nullptr,&text1Rect);


    SDL_RenderPresent(renderer);

    TTF_CloseFont(font);

    SDL_FreeSurface(loadBkg);
    SDL_FreeSurface(loadAnh1);
    SDL_FreeSurface(loadAnh2);
    SDL_FreeSurface(loadAnh3);
    SDL_FreeSurface(loadAnh4);
    SDL_FreeSurface(loadAnh5);
    SDL_FreeSurface(loadAnh6);
    SDL_FreeSurface(loadAnh9);

    SDL_DestroyTexture(hinhnen);
    SDL_DestroyTexture(Anh1);
    SDL_DestroyTexture(Anh2);
    SDL_DestroyTexture(Anh3);
    SDL_DestroyTexture(Anh4);
    SDL_DestroyTexture(Anh5);
    SDL_DestroyTexture(Anh6);
    SDL_DestroyTexture(Anh9);
}
void setRenderColor(SDL_Renderer* renderer,SDL_Color cl){
    SDL_SetRenderDrawColor(renderer,cl.r,cl.g,cl.b,cl.a);
}
void displayFinalResult(SDL_Renderer* renderer,bool won, const string& word) {
    clearScreen(renderer);

    SDL_Rect no1 ;

    no1.x = 270 ;
    no1.y =170;
    no1.w=280;
    no1.h=300;
    SDL_Surface* loadAnh8 = IMG_Load(anh8.c_str());
    SDL_Surface* loadAnh9 = IMG_Load(anh9.c_str());

    SDL_Texture* Anh8 = SDL_CreateTextureFromSurface(renderer,loadAnh8);
    SDL_Texture* Anh9 = SDL_CreateTextureFromSurface(renderer,loadAnh9);


    string result = won ? "Congratulations! You win!" : "You lost.";
    string text = "The correct word is " + word;
    string text4 = "Press any key to continue";
    TTF_Font* font = TTF_OpenFont(FONT_CHU.c_str(),30);

    SDL_Rect text1Rect,text2Rect,text3Rect;

    text1Rect.x = 265;
    text1Rect.y = 155;
    text1Rect.w = 270;
    text1Rect.h = 70;

    text2Rect.x = 265;
    text2Rect.y = 225;
    text2Rect.w = 270;
    text2Rect.h = 70;

    text3Rect.x = 265;
    text3Rect.y = 325;
    text3Rect.w = 270;
    text3Rect.h = 70;


    SDL_Surface* hinhNen = IMG_Load(background.c_str());
    SDL_Surface* text1Surface = TTF_RenderText_Solid(font,result.c_str(),RED_COLOR);
    SDL_Surface* text2Surface = TTF_RenderText_Solid(font,text.c_str(),RED_COLOR);
    SDL_Surface* text3Surface = TTF_RenderText_Solid(font,text4.c_str(),RED_COLOR);


    SDL_Texture* nen = SDL_CreateTextureFromSurface(renderer,hinhNen);
    SDL_Texture* text1 = SDL_CreateTextureFromSurface(renderer,text1Surface);
    SDL_Texture* text2 = SDL_CreateTextureFromSurface(renderer,text2Surface);
    SDL_Texture* text3 = SDL_CreateTextureFromSurface(renderer,text3Surface);

    int w,h;

    SDL_QueryTexture(text1,nullptr,nullptr,&w,&h);
    text1Rect.x += (text1Rect.w - w)/2;
    text1Rect.y += (text1Rect.h - h)/2;
    text1Rect.h = h;
    text1Rect.w = w;

    SDL_QueryTexture(text2,nullptr,nullptr,&w,&h);
    text2Rect.x += (text2Rect.w - w)/2;
    text2Rect.y += (text2Rect.h - h)/2;
    text2Rect.h = h;
    text2Rect.w = w;

    SDL_QueryTexture(text3,nullptr,nullptr,&w,&h);
    text3Rect.x += (text3Rect.w - w)/2;
    text3Rect.y += (text3Rect.h - h)/2;
    text3Rect.h = h;
    text3Rect.w = w;

    SDL_RenderCopy(renderer,nen,nullptr,nullptr);
    if(won==1){
    SDL_RenderCopy(renderer,Anh8,nullptr,&no1 );}
    else
    SDL_RenderCopy(renderer,Anh9,nullptr,&no1 );

    SDL_RenderCopy(renderer,text1,nullptr,&text1Rect);
    SDL_RenderCopy(renderer,text2,nullptr,&text2Rect);
    SDL_RenderCopy(renderer,text3,nullptr,&text3Rect);


    SDL_RenderPresent(renderer);

    TTF_CloseFont(font);
    SDL_FreeSurface(text1Surface);
    SDL_FreeSurface(text2Surface);
    SDL_FreeSurface(text3Surface);
    SDL_FreeSurface(hinhNen);

    SDL_DestroyTexture(text1);
    SDL_DestroyTexture(text2);
    SDL_DestroyTexture(text3);
    SDL_DestroyTexture(nen);
}


bool menu(SDL_Renderer* renderer,bool choiLai){
    bool res = false;
    bool chay = true;
    clearScreen(renderer);

    SDL_Surface* hinhnen = IMG_Load(background.c_str());

    SDL_Texture* nen =  SDL_CreateTextureFromSurface(renderer,hinhnen);

    SDL_RenderCopy(renderer,nen,nullptr,nullptr);
//-----------------------------
    SDL_Event e;
    setRenderColor(renderer,BLACK_COLOR);
    if(choiLai == false){

        SDL_Rect tenGame,choi,thoat;
        SDL_Point oldMouse,newMouse;

        tenGame.x = 112;
        tenGame.y = 30;
        tenGame.w = 576;
        tenGame.h = 160;

        choi.x = 309;
        choi.y = 270;
        choi.w = 180;
        choi.h = 49;

        thoat.x = 309;
        thoat.y = 328;
        thoat.w = 180;
        thoat.h = 49;

        TTF_Font* font = TTF_OpenFont(FONT_CHU.c_str(),200);
        SDL_Surface* tenGameSurface = TTF_RenderText_Solid(font,"HANG MAN",YELLOW_COLOR);
        TTF_CloseFont(font);

        font = TTF_OpenFont(FONT_CHU.c_str(),50);
        SDL_Surface* choiSurface = TTF_RenderText_Solid(font,"PLAY",YELLOW_COLOR);
        SDL_Surface* thoatSurface = TTF_RenderText_Solid(font,"EXIT",YELLOW_COLOR);

        SDL_Texture* tenGameTexture = SDL_CreateTextureFromSurface(renderer,tenGameSurface);
        SDL_Texture* choiTexture = SDL_CreateTextureFromSurface(renderer,choiSurface);
        SDL_Texture* thoatTexture = SDL_CreateTextureFromSurface(renderer,thoatSurface);

        SDL_RenderFillRect(renderer,&choi);
        SDL_RenderFillRect(renderer,&thoat);

        int w,h;
        SDL_QueryTexture(choiTexture,nullptr,nullptr,&w,&h);

        choi.x += (choi.w - w)/2;
        choi.y -= (choi.h - h)/2;
        choi.w = w;
        choi.h = h;

        SDL_QueryTexture(thoatTexture,nullptr,nullptr,&w,&h);
        thoat.x += (thoat.w - w)/2;
        thoat.y -= (thoat.h - h)/2;
        thoat.w = w;
        thoat.h = h;

        SDL_RenderCopy(renderer,tenGameTexture,nullptr,&tenGame);
        SDL_RenderCopy(renderer,choiTexture,nullptr,&choi);
        SDL_RenderCopy(renderer,thoatTexture,nullptr,&thoat);


        SDL_FreeSurface(tenGameSurface);
        SDL_FreeSurface(thoatSurface);
        SDL_FreeSurface(choiSurface);
        SDL_DestroyTexture(tenGameTexture);
        SDL_DestroyTexture(choiTexture);
        SDL_DestroyTexture(thoatTexture);
        TTF_CloseFont(font);

        SDL_RenderPresent(renderer);

        choi.x = 309;
        choi.y = 270;
        choi.w = 180;
        choi.h = 49;

        thoat.x = 309;
        thoat.y = 328;
        thoat.w = 180;
        thoat.h = 49;

        while(chay){
            while(SDL_PollEvent(&e) != 0){
                switch(e.type){
                case SDL_QUIT:
                    res = false;
                    chay = false;
                    break;
                case SDL_KEYDOWN:
                    if(e.key.keysym.sym == SDLK_ESCAPE){
                        res = false;
                        chay = false;
                        break;
                    }
                    break;
                case SDL_MOUSEMOTION:
                    newMouse.x = e.motion.x;
                    newMouse.y = e.motion.y;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(e.button.button == SDL_BUTTON_LEFT){
                        oldMouse = newMouse;
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    if(e.button.button == SDL_BUTTON_LEFT){
                        if(check(choi,oldMouse,newMouse))
                            chay = false,res = true;

                        if(check(thoat,oldMouse,newMouse))
                            chay = false,res = false;
                    }
                }
            }
        }

    }
    else{
        SDL_Rect tenGame,choi,thoat;
        SDL_Point oldMouse,newMouse;

        tenGame.x = 112;
        tenGame.y = 30;
        tenGame.w = 576;
        tenGame.h = 160;

        choi.x = 309;
        choi.y = 270;
        choi.w = 180;
        choi.h = 49;

        thoat.x = 309;
        thoat.y = 328;
        thoat.w = 180;
        thoat.h = 49;

        TTF_Font* font = TTF_OpenFont(FONT_CHU.c_str(),200);
        SDL_Surface* tenGameSurface = TTF_RenderText_Solid(font,"RESTART?",YELLOW_COLOR);
        TTF_CloseFont(font);

        font = TTF_OpenFont(FONT_CHU.c_str(),50);
        SDL_Surface* choiSurface = TTF_RenderText_Solid(font,"YES",YELLOW_COLOR);
        SDL_Surface* thoatSurface = TTF_RenderText_Solid(font,"NO",YELLOW_COLOR);

        SDL_Texture* tenGameTexture = SDL_CreateTextureFromSurface(renderer,tenGameSurface);
        SDL_Texture* choiTexture = SDL_CreateTextureFromSurface(renderer,choiSurface);
        SDL_Texture* thoatTexture = SDL_CreateTextureFromSurface(renderer,thoatSurface);

        SDL_RenderFillRect(renderer,&choi);
        SDL_RenderFillRect(renderer,&thoat);

        int w,h;
        SDL_QueryTexture(choiTexture,nullptr,nullptr,&w,&h);

        choi.x += (choi.w - w)/2;
        choi.y -= (choi.h - h)/2;
        choi.w = w;
        choi.h = h;
        SDL_QueryTexture(thoatTexture,nullptr,nullptr,&w,&h);


        thoat.x += (thoat.w - w)/2;
        thoat.y -= (thoat.h - h)/2;
        thoat.w = w;
        thoat.h = h;

        SDL_RenderCopy(renderer,tenGameTexture,nullptr,&tenGame);
        SDL_RenderCopy(renderer,choiTexture,nullptr,&choi);
        SDL_RenderCopy(renderer,thoatTexture,nullptr,&thoat);


        SDL_FreeSurface(tenGameSurface);
        SDL_FreeSurface(thoatSurface);
        SDL_FreeSurface(choiSurface);
        SDL_DestroyTexture(tenGameTexture);
        SDL_DestroyTexture(choiTexture);
        SDL_DestroyTexture(thoatTexture);
        TTF_CloseFont(font);

        SDL_RenderPresent(renderer);

        choi.x = 309;
        choi.y = 270;
        choi.w = 180;
        choi.h = 49;

        thoat.x = 309;
        thoat.y = 328;
        thoat.w = 180;
        thoat.h = 49;

        while(chay){
            while(SDL_PollEvent(&e)){
                switch(e.type){
                case SDL_QUIT:
                    res = false;
                    chay = false;
                    break;
                case SDL_KEYDOWN:
                    if(e.key.keysym.sym == SDLK_ESCAPE){
                        res = false;
                        chay = false;
                        break;
                    }
                    break;
                case SDL_MOUSEMOTION:
                    newMouse.x = e.motion.x;
                    newMouse.y = e.motion.y;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    oldMouse = newMouse;
                    break;
                case SDL_MOUSEBUTTONUP:
                    if(check(choi,oldMouse,newMouse))
                        chay = false,res = true;

                    if(check(thoat,oldMouse,newMouse))
                        chay = false,res = false;
                }
            }
        }
    }

    SDL_FreeSurface(hinhnen);

    SDL_DestroyTexture(nen);

    return res;
}

