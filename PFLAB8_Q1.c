#include <stdio.h>

void display()
{
    printf("\nRECHARGE PACKS\n");
    printf("1. Rs.100\n");
    printf("2. Rs.200\n");
    printf("3. Rs.500\n");
    printf("4. Rs.1000\n");
}

int packNumber()
{
    int pack;
    printf("Enter the pack number (1-4): ");
    scanf("%d", &pack);

    while (pack<1 || pack>4)
    {
        printf("Enter a number between 1 and 4\n");
        scanf("%d", &pack);
    }

    return pack;
}

long long mobileNumber()
{
    long long number;
    printf("Enter your mobile number (11 digits): ");
    scanf("%lld", &number);
    return number;
}

int amount(int pack)
{
    int amount=0;

    switch(pack)
    {
        case 1: printf("You have selected Rs.100 pack\n");
                amount=100;
                break;

        case 2: printf("You have selected Rs.200 pack\n");
                amount=200; 
                break;

        case 3: printf("You have selected Rs.500 pack\n");
                amount=500;
                break;

        case 4: printf("You have selected Rs.1000 pack\n");
                amount=1000;
                break;

        default: printf("Invalid pack number\n");
    }

    return amount;
}

float tax(int amount)
{
    float tax;

    tax= amount*0.15;

    return tax;
}

float bonus(int amount)
{
    float bonus=0;

    if (amount>=500)
        bonus= amount*0.10;

    return bonus;
}


int main()
{
    int i, pack, Amount;
    float Tax, Bonus, totalBalance, totalSpent=0;
    long long number;  

    for (i=0; i<3; i++)
    {
        display();
        
        pack=packNumber();
        number=mobileNumber();
        Amount=amount(pack);
        Tax=tax(Amount);
        Bonus=bonus(Amount);

        totalBalance =Amount+Bonus;
        totalSpent= totalSpent+Amount+Tax;

        printf("\nRECHARGE SLIP\n");
        printf("Mobile Number: %lld\n", number);
        printf("Recharge Amount: Rs.%d\n", Amount);
        printf("Tax: Rs.%.2f\n", Tax);
        printf("Bonus: Rs.%.2f\n", Bonus);
        printf("Total Balance: Rs.%.2f\n", totalBalance);
    }
    printf("\nTotal Spent: Rs.%.2f\n", totalSpent);

    return 0;
}