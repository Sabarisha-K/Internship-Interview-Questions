#include <stdio.h>

// Function to find length of string
int stringlen(const char *str) 
{
    int length = 0;
    while (str[length] != '\0') 
    {
        length++;
    }
    return length;
}

 //Function to reverse the string
void Reverse_String(char *str1)  
{  
      
    static int i, len, temp;  
    len = stringlen(str1); 
      
    if (i < len/2) 
    {  
       
        temp = str1[i];  
        str1[i] = str1[len-i-1];  
        str1[len-i-1] = temp;  
        i++;  
        Reverse_String(str1); // Here we recursively call the Reverse_String() function  
    }  
}  
      
int main()  
{  
    char str1[100];
    printf("Enter the string to be reversed: ");  
    gets(str1); 
          
    printf("\nBefore reversing the string: %s\n", str1);  
          
    // call Reverse_String() function   
    Reverse_String(str1);  
    printf("After reversing the string: %s", str1);  
    return 0;
}