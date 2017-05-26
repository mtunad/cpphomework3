#include <iostream>
#include <stdlib.h>
#include <time.h>

void moveTortoise( int* tortoisePtr );
void moveHare( int* harePtr );
void printPosition( const int* const tortoisePtr, const int* const harePtr );

int FINISH =70;

int main( void ){
    int tortoise = 1, hare = 1, timer = 0;
    srand( time( 0 ) );
    
    printf("BANG!!!\nAND THEY'RE OFF !!!\n\n");
    
    while(tortoise != FINISH && hare != FINISH){
        moveTortoise( &tortoise );
        moveHare( &hare );
        printPosition( &tortoise, &hare );
        timer++;
    }

    if(tortoise > hare){
        printf("TORTOISE WINS!!! YAY!!!\n");
    }
    else if(tortoise < hare){
        printf("HARE WINS!!! YUCH!!!\n");
    }
    printf("Time Elapsed: %d seconds\n", timer);
    return 0;
}

void moveTortoise( int* tortoisePtr )
{
    int i;
    i = rand() % 10;
    if(i >= 1 && i <= 5){
        *tortoisePtr += 3; 
    }
    else if(i >= 6 && i <= 7){
        *tortoisePtr -= 6; 
    }
    else
    {
        *tortoisePtr += 1; 
    }
    
    if(*tortoisePtr < 1)
        *tortoisePtr = 1;
    else if(*tortoisePtr > FINISH)
        *tortoisePtr = FINISH;
}

void moveHare( int* harePtr ){
    int i;
    
    i = rand() % 10;
    
    if(i >= 1 && i <= 2)
    {
        *harePtr = *harePtr;
    }
    else if(i >= 3 && i <= 4){
        *harePtr += 9;
    }
    else if(i == 5)
    {
        *harePtr -= 12;
    }
    else if(i >= 6 && i<= 8)
    {
        *harePtr += 1;
    }
    else
    {
        *harePtr -= 2;
    }
    if(*harePtr < 1)
        *harePtr = 1;
    else if(*harePtr > FINISH)
        *harePtr = FINISH;
}

void printPosition( const int* const tortoisePtr, const int* const harePtr ){
    int i;
    if(*tortoisePtr == *harePtr)
    {
        for(i = 1; i < *tortoisePtr; i++)
        {
            printf("%s", " " );
        }
        printf("OUCH!!!");
    }
    
    else if(*tortoisePtr < *harePtr)
    {
        for(i = 1; i < *tortoisePtr; i++ )
        {
            printf("%s", " " );
        }
        printf("T");
        
        for(i = 1; i < (*harePtr - *tortoisePtr); i++)
        {
            printf("%s", " " );
        }
        printf("H");
    }
    
    else
    {
        for(i = 1; i < *harePtr; i++)
        {
            printf("%s", " ");
        }
        printf("H");
        
        for( i = 0; i < (*tortoisePtr - *harePtr); i++)
        {
            printf("%s", " " );     
        }
        printf("T");
    }
    
    printf("\n");
}