#include<stdio.h>
#include<math.h>
void main()
{

    //declaring variables 
    short m , h , n , extra , date , nod[12]={31,30,31,30,31,31,30,31,30,31,31,28}; 
    int y ;
    char d[7][3]={"Mo","Tu","We","Th","Fr","Sa","Su"};
    
    //taking inputs
    printf("Enter year : ");
    scanf("%d",&y); 
    printf("Enter month (1-12): ");
    scanf("%d",&m); 
    
    //formatting as the required display
    printf("\n");
    printf("==============================\n");
    (m/10==0)?printf("\t%d-0%d\n",y,m):printf("\t%d-%d\n",y,m);
    printf("==============================\n");

    if(m == 1 || m == 2)
    m+=12;
    
    //Applying Zeler's formula
    if ( m == 13 || m == 14 )
    y=y-1;
    h=((1+(short)(floor(2.6*(m+1)))+(short)(y%100)+(short)(floor(((short)(y%100))/4))+(short)(floor(((short)(y/100))/4))-2*((short)(y/100))))%7;
    
    //leap year condition
    nod[11] = ((y + 1) % 4 == 0) ? (((y + 1) % 100 == 0 && (y + 1) % 400 == 0) || ((y + 1) % 100 != 0)) ? 29 : 28 : 28;

    // Calculating spaces and total days in the month 
    extra=((h-2)>=0)? h-2+1 : (((h-2)==-2) ? 6 : 0);
    n= nod[m-3]+extra;

    //printing the day names
    printf("Sun Mon Tue Wed Thu Fri Sat");
    printf("\n");

    //re-using y and h
    y=0;
    date=1;

    //printing the dates like a calender of the month as entered
    for(int i=0; i<((int)(ceil(n/7.0))); i++)
    {
        h=0;

        //printing spaces 
        while(y<extra && h<7){
        printf("    ");
        y++;
        h++;}

        //printing dates
        while(date<=nod[m-3] && h<7)
        {
            if(date/10==0)
            printf(" %d  ",date);
            else
            printf("%d  ",date);
            date++;
            h++;
        }

        printf("\n");
        
    }
}