
#include "ascciarts/arts.c"
#include "credentials/credentials.c"


int main()
{
    struct User temp;
   // while (1==1) {
        IntroAscciArt();
        temp = Credentials();
        if (temp.role == "Teacher") {
            printf("Welcome Teacher %s\n", temp.username);
        } else if (temp.role == "Student") {
            printf("Welcome Student %s\n", temp.username);
        } else if (temp.role == "Staff Member") {
            printf("Welcome Staff Member %s\n", temp.username);
        } else if(temp.role == null) {
            printf("Please Retry %s\n", temp.username);
        }

    return 0;
}
