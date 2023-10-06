
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function Prototypes 
char* reverse_string(char*str ,int len);
char* reverse_sentence(char* sentence);

// Main Function

int main() 
{
    char sentence[100];
    printf("Enter a sentence:");
    fgets(sentence, sizeof(sentence), stdin);
    printf("\nReversed sentence:\n%s", reverse_sentence(sentence));
    return 0;
}


char* reverse_string(char* str, int len)
{
    char reversed_word[len+1];
    int j = 0;
    for(int i = len - 1 ; i >=0  ; i-- , j ++)
    {
        reversed_word[j] = str[i];
    }
    reversed_word[len] = '\0';
    strcpy(str,reversed_word);
    return str;
}

char* reverse_sentence(char* sentence)
{
    char reversed_sentence[100];                // Array made to hold the reversed Sentence.
    int sentence_len = strlen(sentence);        // Gets the length of the String.
    char word[100];
    int j = 0;
    for(int i = 0 ; i < sentence_len  ; i++)
    {
        if(ispunct(sentence[i])||isalnum(sentence[i]))
        {
            word[j] = sentence[i];
            j++;
        }
        if(isspace(sentence[i]))
        {
            word[j] = '\0';                     // When there is a space in the sentence, a null character is placed in the word array - therefore terminating / ending the array.
            int word_len = strlen(word);
            strcat(reversed_sentence , reverse_string(word,word_len));
            j = 0;                              // Have to reinitialize j to 0 so that the original word is not printed again.
            strcat(reversed_sentence," ");
        }
    }
    strcpy(sentence,reversed_sentence);
    return sentence;
    
}
