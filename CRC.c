#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void display(char msg[] , char rem[])
{
    int l1 = strlen(msg) ;
    int l2 = strlen(rem) ;
    int j = 0 ;
    char Data[20] ;

    for (int i = 0; i < l1 ; i++)
    {
        Data[i] = msg[i] ;
    }
    for (int i = l1 ; i < l1 + l2  ; i++)
    {
        Data[i] = rem[j] ;
        j++ ;
    }

    printf("\n\nRemainder: %s", rem);
    int l3 = strlen(Data) ;
    printf("\nDATA : ");
    
    for (int i = 0; i < l3 ; i++)
    {
        if (Data[i] == '0' || Data[i] == '1')
        {
            printf("%c", Data[i]);
        }
    }
    printf("\n\n");

}

void Div(char msg[] , const char* newmsg , char key[], int len1, int len2)
{
    char temp1[30], temp2[100], rem[30], temp3[30];
    strcpy(temp3, key);

    for (int i = 0; i < len2; i++)
        temp1[i] = newmsg[i];

    for (int i = 0; i < len1; i++)
    {
        temp2[i] = temp1[0];
        if (temp2[i] == '0')
            for (int j = 0; j < len2; j++)
                key[j] = '0';
        else
            for (int j = 0; j < len2; j++)
                key[j] = temp3[j];
        for (int j = len2 - 1; j > 0; j--)
        {
            if (temp1[j] == key[j])
                rem[j - 1] = '0';
            else
                rem[j - 1] = '1';
        }
        rem[len2 - 1] = newmsg[i + len2];
        strcpy(temp1, rem);
    }
    strcpy(rem, temp1);
    display(msg , rem) ;
}

const char *Append(char msg[], int len1, int len2)
{
    for (int i = 0; i < len2 - 1; i++)
    {
        msg[len1 + i] = '0';
    }
    return msg;
}

int main()
{
    char msg[50], pnm[25];
    char temp[50] ;

    printf("\nenter msg : ");
    gets(msg);
    strcpy(temp , msg) ;

    printf("\nenter key : ");
    gets(pnm);

    int len1 = strlen(msg);
    int len2 = strlen(pnm);
    printf("\n\n\nentered msg : %s", msg);
    const char *newmsg = Append(msg, len1, len2);
    printf("\nentered key : %s", pnm);
    printf("\nUpdated msg : %s", newmsg);

    Div(temp , newmsg, pnm, len1, len2);

    return 0;
}
