#include <stdio.h>

int main() {
    FILE *file = fopen("output.html", "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "<!DOCTYPE html>\n");
    fprintf(file, "<html lang=\"en\">\n");
    fprintf(file, "<head>\n");
    fprintf(file, "    <meta charset=\"UTF-8\">\n");
    fprintf(file, "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
    fprintf(file, "    <title>Output from C Program</title>\n");
    fprintf(file, "    <link rel=\"stylesheet\" href=\"styles.css\">\n");
    fprintf(file, "</head>\n");
    fprintf(file, "<body>\n");
    fprintf(file, "    <div class=\"container\">\n");
    fprintf(file, "        <h1>Output from C Program</h1>\n");
    fprintf(file, "        <pre id=\"output\">\n");
    fprintf(file, "            Hello, this is the output from the C program.\n");
    fprintf(file, "            You can format it as you wish.\n");
    fprintf(file, "        </pre>\n");
    fprintf(file, "    </div>\n");
    fprintf(file, "</body>\n");
    fprintf(file, "</html>\n");

    fclose(file);
    printf("HTML file generated successfully.\n");

    return 0;
}
