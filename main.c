#include <stdio.h>
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

#include <stdio.h>
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


#include <stdio.h>

int main() {
    int array[] = {1, 1, 1, 1, 1};
    int length = sizeof(array) / sizeof(array[0]);
    int sum = 0;

    // Calculate the sum of the array elements
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }

    printf("Sum of array elements: %d\n", sum);

    // Calculate and print the percentage of each element
    for (int i = 0; i < length; i++) {
        float percentage = ((float)array[i] / sum) * 100;
        printf("Element %d: %.2f%%\n", array[i], percentage);
    }

    return 0;
}
