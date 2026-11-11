#include <stdio.h>

void display()
{
    printf("\nHOSPITAL\n");
    printf("ROOM CHARGES\n");
    printf("1. General Ward - Rs.1500/day\n");
    printf("2. Semi-Private - Rs.3500/day\n");
    printf("3. Private - Rs.6000/day\n");
}

int roomType()
{
    int room;
    printf("Enter the room type (1-3): ");
    scanf("%d", &room);

    while (room<1 || room>3)
    {
        printf("Enter a number between 1 and 3\n");
        scanf("%d", &room);
    }

    return room;
}

int daysStayed()
{
    int days;

    printf("Enter the number of days stayed: ");
    scanf("%d", &days);

    while (days<1 || days>30)
    {
        printf("Enter valid number of days (1-30)\n");
        scanf("%d", &days);
    }

    return days;
}

int roomCharges(int room, int days)
{
    int charges=0;

    switch(room)
    {
        case 1: charges=1500*days;
                break;

        case 2: charges=3500*days;
                break;

        case 3: charges=6000*days;
                break;

        default: printf("Invalid room type\n");
    }

    return charges;
}

float medicineCharge(float charges)
{
    float MedicineCharge;

    MedicineCharge=charges+ (charges*0.05);

    return MedicineCharge;
}

float discount(int days, int charges,float MedicineCharge)
{
    float discount=0, finalAmount;

    finalAmount=charges+MedicineCharge;

    if(days>=7)
        discount=finalAmount*0.08;
    else
        discount=0;
    
    finalAmount=finalAmount-discount;

    return finalAmount;
}


int main()
{
    int room, days, charges;
    float MedicineCharge, finalAmount;
    char seniorCitizen;

    display();
    room=roomType();
    days=daysStayed();
    charges=roomCharges(room, days);

    printf("Enter medicine bill: Rs.");
    scanf("%f", &MedicineCharge);

    MedicineCharge = medicineCharge(MedicineCharge);
    finalAmount=discount(days, charges,MedicineCharge);

    printf("Is the patient a senior citizen? (y/n): ");
    scanf(" %c", &seniorCitizen);
    
    while ((seniorCitizen != 'y') && (seniorCitizen != 'Y') && (seniorCitizen != 'n') && (seniorCitizen != 'N'))
    {
        printf("Invalid input\n");
        scanf(" %c", &seniorCitizen);
    }

    if (seniorCitizen == 'y' || seniorCitizen == 'Y')
    {
        finalAmount= finalAmount-1000.0;
        if (finalAmount<0)
            finalAmount=0;
    }

    printf("\nFinal Bill\n");

    printf("Room Type: ");
    if (room==1)
        printf("General Ward\n");
    else if (room==2)
        printf("Semi-Private\n");
    else if (room==3)
        printf("Private\n");

    printf("Days Stayed: %d\n", days);
    printf("Room Charges: Rs. %d\n", charges);
    printf("Medicine Charges: Rs. %.2f\n", MedicineCharge);
    printf("Final Amount: Rs. %.2f\n", finalAmount);

    return 0;
}