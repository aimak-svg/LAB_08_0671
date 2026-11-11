#include <stdio.h>

void display()
{
    printf("\nTAXI COMPANY\n");
    printf("FARE RULES\n");
    printf("Base fare - Rs. 150\n");
    printf("First 10km - Rs. 60/km\n");
    printf("After the first 10km - Rs. 45/km\n");
}

float getDistance()
{
    float distance;

    printf("Enter the distance travelled in km (not more than 200km): ");
    scanf("%f", &distance);

    while (distance<=0 || distance>200.0)
    {
        printf("Invalid distance (more than 0 and upto 200km)\n");
        scanf("%f", &distance);
    }

    return distance;
}

int waitingTime()
{
    int time;

    printf("Enter the waiting time in minutes (0-120): ");
    scanf("%d", &time);

    while (time<0 || time>120)
    {
        printf("Invalid waiting time (0-120 minutes)\n");
        scanf("%d", &time);
    }

    return time;
}

float distanceCharge(float distance)
{
    float distanceCharge=0;

    if (distance<=10)
        distanceCharge= distance*60;
    else
        distanceCharge= (10*60) + ((distance-10)*45);

    return distanceCharge;
}

float waitingCharge(int time)
{
    float waitingCharge=0;

    if (time>5)
        waitingCharge= (time-5)*10;

    return waitingCharge;
}

float nightCharge(float totalFare)
{
    float nightCharge=0;
    int hour;

    printf("enter the hour of the trip (0-23): ");
    scanf("%d", &hour);

    while (hour<0 || hour>23)
    {
        printf("Invalid hour (0-23)\n");
        scanf("%d", &hour);
    }

    if (hour>=22 || hour<6)
        nightCharge= totalFare*0.25;

    return nightCharge;
}

int main()
{
    int i, time;
    float distance, totalEarnings=0, distCharge, waitCharge, totalFare, nightChargeAmount, highestFare=0;

    for (i=0; i<3; i++)
    {
        display();
        distance=getDistance();
        time=waitingTime();
        distCharge=distanceCharge(distance);
        waitCharge=waitingCharge(time);

        totalFare= distCharge+waitCharge+150;

        nightChargeAmount=nightCharge(totalFare);
        totalFare= totalFare+nightChargeAmount;

        totalEarnings= totalEarnings+totalFare;

        if (totalFare>highestFare)
            highestFare=totalFare;

        printf("\nTRIP RECEIPT\n");
        printf("Distance: %.2f km\n", distance);
        printf("Waiting time: %d minutes\n", time);
        printf("Final fare: Rs. %.2f\n", totalFare);
    }

    printf("\nTotal earnings: %.2f\n", totalEarnings);
    printf("Highest fare of the day: %.2f\n", highestFare);

    return 0;
}