#include<stdio.h>
#include<string.h>
void subnetmask(const char* class, char ip[])
{
    char net[20];
    int j=0;
    if (class == "A")
    {
        while(ip[j]!='.'){
            net[j]=ip[j];
            j++;
        }
        printf("\nSubnet Mask : 255.0.0.0");
        printf("\nNetwork ID : %s",net);
    }
    else if (class == "B")
    {
        int c = 0;
        while(c<2)
        {
            net[j]=ip[j];
            if (ip[j] == '.')
                c++;
            j++;
        }
        printf("\nSubnet Mask : 255.225.0.0");
        printf("\nNetwork ID : %s",net);
    }
    else if (class == "C")
    {
        int c = 0;
        while(c<3)
        {
            net[j] = ip[j];
            if (ip[j] == '.')
                c++;
            j++;
        }
        printf("\nSubnet Mask : 255.255.255.0");
        printf("\nNetwork ID : %s",net);
    }
    else if (class == "D"){
    	int c = 0;
        while(c<4)
        {
            net[j] = ip[j];
            if (ip[j] == '.')
                c++;
            j++;
        }
        printf("\nSubnet Mask : 255.255.255.255");
        printf("\nNetwork ID : %s",net);
    }
    else
        printf("Subnet Mask : NOT FOUND!!");
}
const char * ipclass(char ip[])
{
    int i = 0;
    int a =0;
    while(ip[i]!='.')
    {
        a = (a+(ip[i]-'0'))*10;
        i++; 
    }
    a = a/10;
    if(a>=0 && a<127)
        return "A";
    else if (a>=128 && a<191)
        return "B";
    else if (a>=192 && a<223)
        return "C";
    else if (a>=224 && a<239)
        return "D";
    else if (a>=240 && a<=255)
        return "NOT FOUND";  
	else
	    return "INVALID";  
}
int main()
{
   char ip[20];
   printf("Enter IP adress:");
   gets(ip);
   printf("IP Address : %s", ip);
   const char* class = ipclass(ip);
   printf("\nIt belongs to class %s\n",class);
   subnetmask(class,ip);
}