#include"xulychung.h"
#include"BaseObject.h"

using namespace std ;

const char DATA_FILE[]= "C:\\HANGMANDUNG\\dung20020380-main\\HANGMAN_DUNG\\data\\Ogden_Picturable_200.txt" ;
const int MAX_BAD_GUESSES =7;
const string music = "music.mp3";

string getLowerCaseString(const string& s);
string chooseWord(const char* fileName);
char readAGuess();
bool contains(const string& word ,char guess);
void  update( string& guessedWord, const string& word ,char guess);
int main(int argc, char* argv[])
{

    srand(time(0));
    SDL_Renderer* renderer;
	SDL_Window* window;
    initSDL(window, renderer);

    TTF_Init();

    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);

    Mix_Music* mus = Mix_LoadMUS(music.c_str());

    Mix_PlayMusic(mus,-1);

    bool thua = false;
    bool win = false;
    bool clai = false;

    SDL_Event e;

    while(menu(renderer,clai)){
        thua = false;
        win = false;
        clai = true;
        string word = chooseWord(DATA_FILE);
        if (word.length() < 1) {
            cout << "Error reading vocabulary file " << DATA_FILE;
            return -1;
        }
        int badGuessCount = 0 ;
        string guessedWord = string(word.length(), '-');
        string badGuesses = "";

        renderGame(renderer,guessedWord, badGuesses,badGuessCount);

        while(!thua) {
            char guess = '!';

            while(SDL_PollEvent(&e)){
                switch(e.type){
                case SDL_QUIT:
                    thua = true;
                    break;
                case SDL_KEYDOWN:
                    switch(e.key.keysym.sym){
                    case SDLK_ESCAPE:
                        thua = true;
                        break;
                    default:
                        guess = (char)e.key.keysym.sym;
                        //cout<<guess;
                        if((guess >= 'a' && guess <= 'z') || (guess >= 'A' && guess <= 'Z')){
                            guess = ::tolower(guess);
                        }else{
                            guess = '!';
                        }
                        break;


                    }
                    break;
                }

            }
            if(guess != '!'){
                if (contains(word, guess))
                    update(guessedWord, word, guess);
                else {
                    badGuesses += guess;
                    badGuessCount++ ;
                }
                //cout<<getHigherCaseString(badGuesses)<<endl;
                renderGame(renderer,guessedWord, badGuesses, badGuessCount);
                if (badGuessCount==7) SDL_Delay(1200);
                }
            if (badGuessCount >= MAX_BAD_GUESSES || word == guessedWord){
                thua = true;
                win = true;
            }
        }
        SDL_Delay(100);
        displayFinalResult(renderer,(win && ( badGuessCount < MAX_BAD_GUESSES)), word);
        waitUntilKeyPressed();
    }


    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

    SDL_Quit();
    TTF_Quit();

	return 0;
}

void  update( string& guessedWord,const string& word ,char guess)
{
	for (int i = word.length() - 1; i >= 0; i--) {
        if (word[i] == guess) {
            guessedWord[i] = guess;
        }
    }
}

bool contains(const string& word ,char c)
{
    return (word.find_first_of(c) != string::npos);
}
string getLowerCaseString(const string& s)
{
    string res = s;
    transform(s.begin(), s.end(), res.begin(), ::tolower);
    return res;
}
string chooseWord(const char* fileName)
{

	vector<string> wordList;
	ifstream file(fileName);
  	if (file.is_open()) {
	    string word;
		while (file >> word) {
            wordList.push_back(word);
        }
    	file.close();
  	}
  	if (wordList.size() > 0) {
  		int randomIndex = rand() % wordList.size();
    	return getLowerCaseString(wordList[randomIndex]);
	} else return "";
}
char readAGuess()
{
	SDL_Event e;
    while(1){
        if ( SDL_WaitEvent(&e) != 0 && e.type == SDL_KEYDOWN){
          return (char)e.key.keysym.sym;
        }
    }
}
