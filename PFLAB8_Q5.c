#include <stdio.h>

int main()
{
    double costPrice, sellPrice, quantity;

    double *ptrCost=&costPrice;
    double *ptrSell=&sellPrice;
    double *ptrQuantity=&quantity;

    printf("Enter cost price: ");
    scanf("%lf", ptrCost);

    printf("Enter selling price: ");
    scanf("%lf", ptrSell);

    printf("Enter quantity sold: ");
    scanf("%lf", ptrQuantity);

    double totalCost, totalSales, profitLoss;

    double *ptrTotalCost=&totalCost;
    double *ptrTotalSales=&totalSales;
    double *ptrProfitLoss=&profitLoss;

    *ptrTotalCost= *ptrCost * *ptrQuantity;
    *ptrTotalSales= *ptrSell * *ptrQuantity;
    *ptrProfitLoss= *ptrTotalSales - *ptrTotalCost;

    printf("\nTotal Cost: %.2f\n", *ptrTotalCost);
    printf("Total Sales: %.2f\n", *ptrTotalSales);

    if (*ptrProfitLoss>0)
        printf("Profit\n");
    else if (*ptrProfitLoss<0)
        printf("Loss\n");
    else
        printf("No profit no loss\n");

    double percentage;
    double *ptrPercentage=&percentage;

    if (*ptrTotalSales> *ptrTotalCost)
    {
        *ptrPercentage= (*ptrProfitLoss/ *ptrTotalCost)*100;
        printf("Profit Percentage: %.2f%%\n", *ptrPercentage);
    }

    double *ptrLarger;

    if (*ptrCost> *ptrSell)
        ptrLarger=ptrCost;
    else
        ptrLarger=ptrSell;

    if (ptrLarger==ptrCost)
        printf("\nPointer points to Cost Price\n");
    else
        printf("\nPointer points to Selling Price\n");

    printf("Larger value: %.2f\n", *ptrLarger);

    printf("\nTABLE\n");

    printf("\nVARIABLE ADDRESSES\n");
    printf("Cost Price: %p\n", ptrCost);
    printf("Selling Price: %p\n", ptrSell);
    printf("Quantity: %p\n", ptrQuantity);
    printf("Total Cost: %p\n", ptrTotalCost);
    printf("Total Sales: %p\n", ptrTotalSales);
    printf("Profit/Loss: %p\n", ptrProfitLoss);
    printf("Percentage: %p\n", ptrPercentage);
    printf("Larger Value: %p\n", ptrLarger);

    printf("\nPOINTER ADDRESSES\n");
    printf("Cost Price: %p\n", &ptrCost);
    printf("Selling Price: %p\n", &ptrSell);
    printf("Quantity: %p\n", &ptrQuantity);
    printf("Total Cost: %p\n", &ptrTotalCost);
    printf("Total Sales: %p\n", &ptrTotalSales);
    printf("Profit/Loss: %p\n", &ptrProfitLoss);
    printf("Percentage: %p\n", &ptrPercentage);
    printf("Larger Value: %p\n", &ptrLarger);

    return 0;
}