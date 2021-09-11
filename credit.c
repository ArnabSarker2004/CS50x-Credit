#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long originalCreditNum;
    long creditNum;
    int position = 0;
    int totalSum = 0;
    int numLength = 0;

    do
    {

         creditNum = get_long("Number: ");

         originalCreditNum = creditNum;

         while(creditNum != 0)
         {
             if (position % 2 != 0) // starting from the second last number, every other number is assigned an odd value
             {
                 int tens = 2 * (creditNum % 10);
                 if (tens > 9)
                 {
                     totalSum += (tens % 10 + tens / 10);

                 }
                 else
                 {
                     totalSum += tens;
                 }
             }
             else
             {
                  totalSum += creditNum % 10;
             }
             creditNum = creditNum / 10;
             position++;
             numLength++;
         }
    }
    while (creditNum != 0);

    if (totalSum % 10 == 0 )
    {
        long visa = originalCreditNum / pow(10, numLength - 1);
        long mastercard = originalCreditNum / pow(10, numLength - 2);
        long amex = originalCreditNum / pow(10, numLength - 2);

        if ((amex == 34 || amex == 37) && numLength == 15 )
        {
            printf("AMEX\n");
            return 0;
        }
        else if ((mastercard >= 51 && mastercard <= 55) && numLength == 16)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if ((numLength == 13 || numLength == 16) && (visa == 4  || mastercard / 10 == 4))
        {
            printf("VISA\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}