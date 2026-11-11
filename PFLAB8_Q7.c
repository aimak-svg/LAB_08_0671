#include <stdio.h>

int findMax(int *p, int n)
{
    int highest=p[0], i;

    for (i=1; i<n; i++)
    {
        if (p[i]>highest)
        {
            highest=p[i];
        }
    }
    return highest;
}

int findMin(int *p, int n)
{
    int lowest=p[0], i;

    for (i=1; i<n; i++)
    {
        if (p[i]<lowest)
        {
            lowest=p[i];
        }
    }
    return lowest;
}

double findAverage(int *p, int n)
{
    int sum=0, i;

    for (i=0; i<n; i++)
    {
        sum= sum+p[i];
    }

    return (double)sum/n;
}

int countAbove(int *p, int n, double avg)
{
    int count=0, i;

    for (i=0; i<n; i++)
    {
        if (p[i]>avg)
        {
            count++;
        }
    }
    return count;
}

void reverseArray(int *p, int n)
{
    int *start=p, *end=(p+n)-1, temp, i;

    for (i=0; i<n/2; i++)
    {
        temp=*start;
        *start=*end;
        *end=temp;

        start++;
        end--;
    }
}

int searchMark(int *p, int n, int key)
{
    int i;

    for (i=0; i<n; i++)
    {
        if (p[i]==key)
            return i;

    }
    return -1;
}

int passCount(int *p, int n)
{
    int count=0, i;

    for (i=0; i<n; i++)
    {
        if (p[i]>=40)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int marks[10], i, highest, lowest, above, passed, key, index;
    double avg;

    for (i=0; i<10; i++)
    {
        printf("Enter marks for student %d: ", i+1);
        scanf("%d", &marks[i]);

        while (marks[i]<0 || marks[i]>100)
        {
            printf("Invalid input. Enter marks between 0 and 100: ");
            scanf("%d", &marks[i]);
        }
    }
 
    highest=findMax(marks, 10);
    lowest=findMin(marks, 10);
    avg=findAverage(marks, 10);
    above=countAbove(marks, 10, avg);
    passed=passCount(marks, 10);

    printf("\nHighest marks: %d\n", highest);
    printf("Lowest marks: %d\n", lowest);
    printf("Average marks: %.2lf\n", avg);
    printf("Number of students with marks above average: %d\n", above);
    printf("Number of students who passed: %d\n", passed);

    printf("\nEnter marks to search: ");
    scanf("%d", &key);

    index=searchMark(marks, 10, key);

    if (index != -1)
        printf("Marks found at index %d\n", index+1);
    else
        printf("Marks not found\n");

    printf("\nARRAY BEFORE REVERSING: \n");
    for (i=0; i<10; i++)
    {
        printf("%d\n", marks[i]);
    }

    printf("\nARRAY AFTER REVERSING: \n");
    reverseArray(marks, 10);

    for (i=0; i<10; i++)
    {
        printf("%d\n", marks[i]);
    }
}