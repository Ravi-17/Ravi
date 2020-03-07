//RAVIKUMAR A-142892 1.0

#include "main.h"
void readAll(mobile* mob,int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        readOne(&mob[i]);
    }
}

void readOne(mobile* mob)
{
    printf("\nEnter the model number\t:");
    scanf("%d",&mob->mod_no);
    printf("\nEnter OEM\t:");
    scanf("%s",mob->oem);
    printf("\nEnter display size(cm)\t:");
    scanf("%d",&mob->display);
    printf("\nEnter battery Capacity(mAh)\t:");
    scanf("%d",&mob->battery);
    printf("\nEnter size of the RAM\t:");
    scanf("%d",&mob->RAM);
    printf("\nEnter size of the ROM\t:");
    scanf("%d",&mob->ROM);
    printf("\nEnter the camera resolution\t:");
    scanf("%d",&mob->camera);
    printf("\nEnter the Price\t:");
    scanf("%lf",&mob->price);

}

void displayAll(const mobile* mob,int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        displayOne(&mob[i]);
    }
}

void displayOne(const mobile* mob)
{
    printf("\nmodel-number\t:  %d\nOEM\t: %s\ndisplay size(cm)\t: %d\nbattery_Capacity(mAh)\t: %d\nRAM(GB)\t: %d \nROM(GB)\t: %d \ncamera(MP)\t: %d\nprice\t: %lf  ",mob->mod_no,mob->oem,mob->display,mob->battery,mob->RAM,mob->ROM,mob->camera,mob->price);

}

void search_by_mod_no(const mobile* mob,const int* mod,int n)
{
        int i;

        for(i=0;i<n;i++)
        {
           if((mob+i)->mod_no != mod)
            {
                displayOne(&mob[i]);

            }
        }


}

double avg_price1(const mobile* mob,int n)
{
    double sum=0;
    int i;
    for(i=0;i<n;i++)
    {
        sum+=(mob+i)->price;
    }
    return (sum/n);
}



void max_battery(const mobile* mob,int n)
{
    unsigned int max=0;
    int i;
    for(i=0;i<n;i++)
    {
        if(max<((mob+i)->battery))
            max=(mob+i)->battery;
    }
    printf("\nMaximum battery Capacity of mobile is:%d",max);
}


void min_storage(const mobile* mob,int n)
{
    unsigned int min=1266;
    int i;
    for(i=0;i<n;i++)
    {
        if(min>((mob+i)->ROM))
            min=(mob+i)->ROM;
    }
    printf("\nminimum storage  is:%d",min);
}





int main()
{
    int mod[10];
    double avg_price;
    int choice;
    int loop=1;
    printf("\t\t\t\tWelcome To mobile stock\n");
    mobile varr[MAX_SIZE];
    printf("\nEnter %d numbers of mobile ",MAX_SIZE);
    readAll(varr,MAX_SIZE);
    printf("\nEnter option");
    printf("\n1.Display All mobile record");
    printf("\n2.Display mobiles by particular model number ");
    printf("\n3.Average price of mobiles");
    printf("\n4.Maximum battery Capacity mAh");
    printf("\n5.minimum storage");
    printf("\n6.Exit");


    while(loop)
    {
    printf("\nEnter Your choice :");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: displayAll(varr,MAX_SIZE);
                break;
        case 2:printf("\nType the model number search\n");
                scanf("%d",mod);
                search_by_mod_no(varr,mod,MAX_SIZE);
                break;
        case 3:avg_price=avg_price1(varr,MAX_SIZE);
                printf("\nAverage price mobiles=%lf",avg_price);
                break;
        case 4: max_battery(varr,MAX_SIZE);
                break;
        case 5: min_storage(varr,MAX_SIZE);
                break;
        case 6:loop=0;
                printf("Thank You");
                exit(0);
            break;
        default:printf("Invalid Option ");
            break;
    }
    }
    return 0;
}
