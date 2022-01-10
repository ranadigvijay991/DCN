#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Adding
int Sum(int x, int y)
{
    static int carry = 0;
    if (x == 1 && y == 1 && carry == 0)
    {
        carry = 1;
        return 0;
    }
    else if (x == 1 && y == 1 && carry == 1)
    {
        carry = 1;
        return 1;
    }
    else if (x == 1 && y == 0 && carry == 0)
    {
        carry = 0;
        return 1;
    }
    else if (x == 1 && y == 0 && carry == 1)
    {
        carry = 1;
        return 0;
    }
    else if (x == 0 && y == 1 && carry == 0)
    {
        carry = 0;
        return 1;
    }
    else if (x == 0 && y == 1 && carry == 1)
    {
        carry = 1;
        return 0;
    }
    else if (x == 0 && y == 0 && carry == 0)
    {
        carry = 0;
        return 0;
    }
    else
    {
        carry = 0;
        return 1;
    }
}
//Generate  Code
void generateCode(int arr1[] , int arr2[] , int data[] , int n)
{
    int l = n*3 ;
    int code[l] ;

    for (int i = 0; i < n; i++)
    {
        code[i] = arr1[i] ;
    }
    for (int i = 0; i < n; i++)
    {
        int j = i + l/3 ;
        code[j] = arr2[i] ;
    }
    for (int i = 0; i < n; i++)
    {
        int j = i + (n*2);
        code[j] = data[i] ;
    }
    printf("\n\nCodeword Sent : \n") ;
    for (int i = 0; i < l; i++)
    {
       printf("%d " , code[i]) ;
    }
}

void compliment(int arr1[] , int arr2[] , int data[] , int n)
{
    for (int i = 0; i < n; i++)
    {
        if(data[i] == 1)
        {
            data[i] = 0 ;
        }
        else
            data[i] = 1 ;
    }

    printf("\nCompliment : \n") ;
    for (int i = 0; i < n; i++)
    {
       printf("%d " , data[i]) ;
    }

    generateCode(arr1 , arr2 , data , n) ;
}
//Dividing
void divison(int msg[] , int n)
{
    int l = n/2 , i = 0 ;
    int arr1[l] , arr2[l] ;

    for (int i = 0; i < l; i++)
    {
        arr1[i] = msg[i] ;
    }
    for (int i = 0; i < l; i++)
    {
        int j = i + l ;
        arr2[i] = msg[j] ;
    }

    printf("\n\nframe 1 : \n" ) ;
    for (int i = 0; i < l; i++)
    {
        printf("%d " , arr1[i]) ;
    }
    printf("\nframe 2 : \n" ) ;
    for (int i = 0; i < l; i++)
    {
       printf("%d " , arr2[i]) ;
    }

    int data[l] ;
    for (i = l - 1; i >= 0; i--)
    {
        data[i] = Sum(arr1[i], arr2[i]) ;
    }

    printf("\n\nAddition of frames : \n") ;
    for (int i = 0; i < l; i++)
    {
       printf("%d " , data[i]) ;
    }

    compliment(arr1 , arr2 , data , l) ;
}


int main()
{
    int n ;
    printf("Message length : ") ;
    scanf("%d" , &n) ;

    int msg[n] ;

    printf("Enter the message : ") ;

    for (int i = 0; i < n; i++)
    {
        scanf("%d" , &msg[i]) ;
    }

    printf("Your message : ") ;
    for (int i = 0; i < n; i++)
    {
       printf("%d " , msg[i]) ;
    }

    divison(msg , n)  ;

    return 0;
}
