#include <stdio.h>

void display()
{
    printf("\nBUS TICKETS\n");
    printf("1. Karachi to Hyderabad - Rs.800\n");
    printf("2. Karachi to Sukkur - Rs.2200\n");
    printf("3. Karachi to Multan - Rs.3500\n");
}

int routeNumber()
{
    int route;
    printf("Enter the route number (1-3): ");
    scanf("%d", &route);

    while (route<1 || route>3)
    {
        printf("Enter a number between 1 and 3\n");
        scanf("%d", &route);
    }

    return route;
}

int numberOfSeats()
{
    int seats;

    printf("Enter the number of seats you want to book (1-6): ");
    scanf("%d", &seats);

    while (seats<1 || seats>6)
    {
        printf("Enter valid number of seats (1-6)\n");
        scanf("%d", &seats);
    }

    return seats;
}

int fareOfSeat(int route)
{
    int fare=0;

    if (route==1)
        fare=800;
    else if (route==2)
        fare=2200;
    else if (route==3)
        fare=3500;

    return fare;
}

int totalFare(int fareOne, int seats)
{
    int totalFare;

    totalFare= fareOne*seats;

    return totalFare;
}

float seatTypeCharge(int total)
{
    float newTotal;
    char seatType;

    printf("enter your choice (1.'E' for Economy, 2.'B' for Business): ");
    scanf(" %c", &seatType);

    while ((seatType != 'E') && (seatType != 'e') && (seatType != 'B') && (seatType != 'b'))
    {
        printf("Invalid input\n");
        scanf(" %c", &seatType);
    }

    if (seatType=='E' || seatType=='e')
        newTotal=total;
    else if (seatType=='B' || seatType=='b')
        newTotal= total+(total*0.3);
 
    return newTotal;
}

int main()
{
    int i, route, seats, fareOne, total;
    float newTotal, totalEarnings=0;
    char seatType;

    for (i=0; i<2; i++)
    {
        display();
        route=routeNumber();
        seats=numberOfSeats();
        fareOne=fareOfSeat(route);
        total=totalFare(fareOne, seats);
        newTotal=seatTypeCharge(total);

        totalEarnings= totalEarnings+newTotal;

        if (newTotal==total)
            seatType='E';
        else
            seatType='B';

        printf("\nTICKET\n");
        printf("Route name: ");
        if (route==1)
            printf("Karachi to Hyderabad\n");
        else if (route==2)
            printf("Karachi to Sukkur\n");
        else if (route==3)
            printf("Karachi to Multan\n");

        printf("Seats: %d\n", seats);
        printf("Seat Type: ");
        if (seatType=='E')
            printf("Economy\n");
        else if (seatType=='B')
            printf("Business\n");

        printf("Total Fare: Rs.%.2f\n", newTotal);
    }

    printf("\nTotal earnings: Rs.%.2f\n", totalEarnings);

    return 0;
}

