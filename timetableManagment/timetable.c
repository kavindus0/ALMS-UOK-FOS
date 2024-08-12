void editSubjectDetails(Subject *subject)
{
    printf("Enter new subject name: ");
    scanf("%s", subject->name);
    printf("Enter new teacher name: ");
    scanf("%s", subject->teacher);
}
