#include <stdio.h>
#include "ascciarts/arts.c"
#include "credentials/credentials.c"

/*
int main() {
//    FILE *file;
//    file = fopen("nonexistentfile.txt", "r");
//
//    if (file == NULL) {
//        printf(stderr, "Error: Could not open file\n");
//        return 1;
//    }
//
//    // Further file operations
//    fclose(file);



    return 0;
}
*/

//
//int main() {
//    char strArray[256]; // Declare a strArray with a size of 256 bytes
//
//    // Read data into the strArray from stdin
//    printf("Enter some text: ");
//    fgets(strArray, sizeof(strArray), stdin); // Reading from stdin to strArray
//
//    // Output the data stored in the strArray
//    printf("You entered: %s", strArray); // Writing from strArray to stdout
//
//    return 0;
//}


int main() {
    IntroAscciArt();
    Credentials();
    return 0;
}