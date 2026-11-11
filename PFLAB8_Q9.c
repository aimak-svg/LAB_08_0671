#include <stdio.h>

void readMarks(int *m1, int *m2, int *m3)
{
    printf("Subject 1: ");
    scanf("%d", m1);

    while (*m1<0 || *m1>100)
    {
        printf("Invalid marks. Enter again: ");
        scanf("%d", m1);
    }

    printf("Subject 2: ");
    scanf("%d", m2);

    while (*m2<0 || *m2>100)
    {
        printf("Invalid marks. Enter again: ");
        scanf("%d", m2);
    }

    printf("Subject 3: ");
    scanf("%d", m3);

    while (*m3<0 || *m3>100)
    {
        printf("Invalid marks. Enter again: ");
        scanf("%d", m3);
    }
}

void calculateStats(int m1, int m2, int m3, int *total, double *average, int *highest, int *lowest)
{
    *total = m1+m2+m3;
    *average = *total/3.0;

    *highest = m1;
    *lowest = m1;

    if (m2 > *highest)
        *highest = m2;

    if (m3 > *highest)
        *highest = m3;

    if (m2 < *lowest)
        *lowest = m2;

    if (m3 < *lowest)
        *lowest = m3;
}

void swapMarks(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void addGraceMarks(int *mark, int grace)
{
    if (*mark >= 35 && *mark <= 39)
    {
        if (*mark + grace > 40)
            *mark = 40;
        else
            *mark = *mark + grace;
    }
}

void findGrade(double avg, char *grade, char remarks[])
{
    if (avg >= 80)
    {
        *grade = 'A';
        sprintf(remarks, "Excellent");
    }
    else if (avg >= 60)
    {
        *grade = 'B';
        sprintf(remarks, "Good");
    }
    else
    {
        *grade = 'C';
        sprintf(remarks, "Needs Improvement");
    }
}

void incrementByValue(int x)
{
    x++;
}

void incrementByReference(int *x)
{
    (*x)++;
}

int main()
{
    int m1, m2, m3;
    int total, highest, lowest;
    int grace, i;
    double average;
    char grade;
    char remarks[30];

    printf("Enter grace marks (0-5): ");
    scanf("%d", &grace);

    while (grace < 0 || grace > 5)
    {
        printf("Invalid grace marks. Enter 0-5: ");
        scanf("%d", &grace);
    }

    printf("\nSTUDENT RESULTS\n");
    printf("Student\tTotal\tAverage\tGrade\tRemarks\n");

    for (i = 1; i <= 5; i++)
    {
        printf("\nStudent %d\n", i);

        readMarks(&m1, &m2, &m3);

        addGraceMarks(&m1, grace);
        addGraceMarks(&m2, grace);
        addGraceMarks(&m3, grace);

        // Sort marks from highest to lowest
        if (m1 < m2)
            swapMarks(&m1, &m2);

        if (m1 < m3)
            swapMarks(&m1, &m3);

        if (m2 < m3)
            swapMarks(&m2, &m3);

        calculateStats(m1, m2, m3, &total, &average, &highest, &lowest);

        findGrade(average, &grade, remarks);

        printf("Sorted marks: %d %d %d\n", m1, m2, m3);

        printf("%d\t%d\t%.2lf\t%c\t%s\n", i, total, average, grade, remarks);
    }

    int number = 10;

    printf("\nCOMPARISON DEMO\n");
    printf("Original value: %d\n", number);

    incrementByValue(number);
    printf("After incrementByValue: %d\n", number);

    incrementByReference(&number);
    printf("After incrementByReference: %d\n", number);

    return 0;
}
