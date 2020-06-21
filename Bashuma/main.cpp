#include <cstdio>
#include "bashuma.h"

using namespace std;

bool flag;


int main(int argv, char *argc[]) {
    string a1 = "678123405";
    string b1 = "123546780";
    Game game = Game(a1, b1);
    game.start();
    printf("¹²ÒÆ¶¯%d²½\n", game.path.size()-1);
    for(auto & i : game.path){
        printf("%s\n",i.str.c_str());
    }
    return 0;
}
