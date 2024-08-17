#include <stdio.h>
// #include <json-c/json.h>
#include "ascciarts/arts.c"
#include "credentials/credentials.c"


int main()
{
    struct liveuser{
        char name[50];
        char role[50];
    };
   // while (1==1) {
        IntroAscciArt();
        struct liveuser->role = Credentials();
   // }
    return 0;
}
