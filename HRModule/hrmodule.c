#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    int age;
    char designation[50];
} Employee;

void saveData(Employee *employees, int numEmployees)
{
    FILE *file = fopen("employees.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < numEmployees; i++)
    {
        fprintf(file, "%s,%d,%s\n", employees[i].name, employees[i].age, employees[i].designation);
    }

    fclose(file);
}

void loadData(Employee *employees, int *numEmployees)
{
    FILE *file = fopen("employees.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    *numEmployees = 0;
    while (fscanf(file, "%[^,],%d,%[^\n]\n", employees[*numEmployees].name, &employees[*numEmployees].age, employees[*numEmployees].designation) == 3)
    {
        (*numEmployees)++;
    }

    fclose(file);
}

int main()
{
    Employee employees[100];
    int numEmployees = 0;

    // Saving data
    strcpy(employees[0].name, "John Doe");
    employees[0].age = 35;
    strcpy(employees[0].designation, "Teacher");

    strcpy(employees[1].name, "Jane Smith");
    employees[1].age = 42;
    strcpy(employees[1].designation, "Academic Staff");

    numEmployees = 2;
    saveData(employees, numEmployees);
    printf("Data saved successfully.\n");

    // Loading data
    loadData(employees, &numEmployees);
    printf("Loaded %d employees:\n", numEmployees);
    for (int i = 0; i < numEmployees; i++)
    {
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
        printf("Designation: %s\n", employees[i].designation);
        printf("\n");
    }

    return 0;
}