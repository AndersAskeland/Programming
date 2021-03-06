#include <stdio.h>
#include <string.h> // I can use the strlen function which counts characters

int main(void)
{
// Defines variables
    char string[999];
    int characters;
    int spaces = 0;
    int letters = 0;
    int sentences = 0;
    float score;
    float l = 0;
    float s = 0;

// Takes user input
    printf("Write some letters:");
    fgets(string, sizeof(string), stdin); // Can recieve input with spaces - However, can only be used on string

// Counts total characters
    characters = strlen(string);

// Count total spaces
    for (int i = 0; string[i] != '\0'; i++) // Itterate trough until \0
    {
        if (string[i] == ' ')
        {
            spaces++; // Spaces are also a measure for total words (+1 for the first word)
        }
    }

    // Counts sentences
    for (int j = 0; string[j] != '\0'; j++)
    {
        if (string[j] == ('.') || string[j] == ('!') || string[j] == ('?'))
        {
            sentences++;
        }
    }

    // Counts all letters
    for (int t = 0; string[t] != '\0'; t++)
    {
        if ((string[t] >= 'a' && string[t] <= 'z') || (string[t] >= 'A' && string[t] <= 'Z'))
        {
            letters++;
        }
    }

    // Calculates readability
    // Average number of letters per 100 words
    l = (((float)letters / ((float)spaces + 1)) * 100);

    // Average number of sentences per 100 words
    s = (((float)sentences / ((float)spaces + 1)) * 100);

    // Calculation
    score = (0.0588 * (float)l) - (0.296 * (float)s) - 15.8;

// Gives output
    if (score > 2 && score < 17)
    {
        printf("Grade %0.f\n", score);
    }
    else if (score < 2)
    {
        printf("Before grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}