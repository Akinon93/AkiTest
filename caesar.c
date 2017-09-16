/**********
Must accept a singe command-line argument, a non-negative integer
If excuted without a command-line argument, or with multiple, print error message and return from main with a value of 1 immediately
Assume the argument provided will be a non-negative integer
Do not assume the argument will be less than or equal to 26.  Proper wrap around from A-Z and back around
In ciphertext: output, non-alphabetical characters should be unchanged
after outputting ciphertext line, you should print a newline.  Exite by returning 0 from main
***********/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define betweenNum(val, min, max) (val > min && val < max)

void CipherText(char* cText, int shiftAmount);
char ForcePosInt(char x);

int main(int argc, string argv[]){

    if(argc > 2)
        return 1;

    //Will be the int passed through command-line
    //Declares how far to shift individual characters in cipher
    char* plainText;
    int userInt = atoi(argv[1]);

    printf("plaintext: ");
    plainText = get_string();

    printf("ciphertext: ");
    CipherText(plainText,userInt);
    printf("\n");


    return 0;
}

//This function is used to sift through our text string
//It applies the cipher and prints out the ciphered character
void CipherText(char* cText, int shiftAmount){

    //Cache the string length of our cText variable
    int cTextLength = strlen(cText);

    //Loop through cText
    //Each character instance, cipher the character, and print the ciphered character
    //To cipher, first check for upper or lower case
    //Afterwards, add additional values if after a basic cipher, we need to wrap around
    //Additional values are based upon ASCII table, A being 65 and a being 97
    //Subtract 1 from each in order to make the cipher begin counting at the letter A/a instead of B/b
    for(int i = 0; i < cTextLength; i++){

        if(betweenNum(cText[i],64,91) || betweenNum(cText[i],96,123)){

            if(isupper(cText[i])){

                if(!betweenNum(cText[i]+shiftAmount,64,91)){

                    printf("%c",shiftAmount-(90-cText[i])+64);  //will return proper, unless it needs to loop through the alphabet more than once

                }else{
                    printf("%c",(cText[i]+shiftAmount));
                }
            }else if(islower(cText[i])){

                if(!betweenNum(cText[i]+shiftAmount,96,123)){
                    printf("%c",(cText[i]+shiftAmount)%26);  //returns a 7, blank space
                }else{
                    printf("%c",(cText[i]+shiftAmount));
                }
            }
        }else
            printf("%c",cText[i]);
    }
}

char ForcePosInt(char x){

    if(x < 0)
        x *= -1;

    return x;

}
