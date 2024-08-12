#include <stdio.h>

void storeActivities(const char *filename, const char *activities)
{
    FILE *file = fopen(filename, "a");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s\n", activities);
    fclose(file);
}

void viewActivities(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    fclose(file);
}

int main()
{
    const char *filename = "activities.txt";

    storeActivities(filename, "Football");
    storeActivities(filename, "Basketball");
    storeActivities(filename, "Chess");

    viewActivities(filename);

    return 0;
}