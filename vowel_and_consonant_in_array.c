#include <stdio.h>
#include <ctype.h>

void count_vowels_and_consonants(const char *str, int *vowel_count, int *consonant_count)
{
    *vowel_count = 0;
    *consonant_count = 0;
    const char *ptr = str;

    while (*ptr != '\0')
    {
        char ch = tolower(*ptr);
        if (ch >= 'a' && ch <= 'z')
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                (*vowel_count)++;
            }
            else
            {
                (*consonant_count)++;
            }
        }
        ptr++;
    }
}

int main()
{
    char str[100];
    int vowels = 0, consonants = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    count_vowels_and_consonants(str, &vowels, &consonants);

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}
