/*
* File: vigenere.c
* Programmer: Zander Møysal
* Date: 16.10.2015
*
* Encrypts a string with the vigenere cipher.
* Takes 1 commandline argument(a word) as a key.
*
* How to use example:
*
* username(~/vigenere): ./vigenere bacon
* Meet me at the park at eleven am
* Negh zf av huf pcfx bt gzrwep oz
*
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Set key to cmd line arg 2
    string key = argv[1];
    
    // If no or more than one cmd-line arg is entered, give error
    if (argc != 2)
    {
        printf("You have to input a single cmd line arg \n");
        return 1;
    }
    
    
    /* 
    * Loop through every character in cmd-line arg
    * to check if all chars are indeed alphabetic
    */
    for (int n = 0; n < strlen(key); n++)
    {
        // If the argument contains a non alphabetic character, give error
        if (!isalpha(argv[1][n]))
        {
            printf("You've typed in non alpha character(s)\n");
            return 1;
        }
    }
    
    // Prompt user for a word or sentence
    char word[100];
    fgets(word, 100, stdin);    
    
    int counter = 0;
    
    
    for (int i = 0; i < strlen(word); i++)
    {    
        // If letter in word is an alphabetic character
        if (isalpha(word[i]))
        { 
            
            int ikey = counter % strlen(key);
            
            // If letter in word is lowercase
            if (islower(word[i]))
            {
                // If letter in key is lowercase
                if (islower(key[ikey]))
                {
                    word[i] = ((word[i] - 'a' + key[ikey] - 97) % 26) + 97;
                    printf("%c", word[i]);
                }
                // Else letter in key is uppercase
                else
                {
                    word[i] = ((word[i] - 'a' + key[ikey] - 65) % 26) + 97;
                    printf("%c", word[i]);
                }
            }
            
            // Else if letter in word is uppercase
            else if (isupper(word[i]))
            {
               // If letter in key is lowercase
               if (islower(key[counter]))
                {
                    word[i] = ((word[i] - 'A' + key[ikey] - 97) % 26) + 65;
                    printf("%c", word[i]);
                }
                // Else letter in key is uppercase
                else
                {
                    word[i] = ((word[i] - 'A' + key[ikey] - 65) % 26) + 65;
                    printf("%c", word[i]);
                }
            }
            // Increment counter by 1
            counter++; 
        }   
        
        // else (it's not an alphabetic character I.E: '!', ' ', or '2'), print 
        else
        {
            printf("%c", word[i]);
        }  
    }
    
    
    // No errors
    return 0;
}
