#include <iostream>
#include <cstring>
using namespace std;

void computeLPSArray(char* pattern, int patternLength, int lps[])
{
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while(i < patternLength)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0) len = lps[len-1];
            else { lps[i] = 0; i++; }
        }
    }
}

void KMPSearch(char* text, char* pattern)
{
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int lps[patternLength];

    computeLPSArray(pattern, patternLength, lps);

    int i=0, j=0;
    cout << "positions: ";
    while(i < textLength)
    {
        if(pattern[j] == text[i])
        {
            i++; j++;
        }

        if(j == patternLength)
        {
            cout << i - j << " ";
            j = lps[j-1];
        }
        else if(i < textLength && pattern[j] != text[i])
        {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    cout << endl;
}

int main()
{
    char text[] = "ababababc";
    char pattern[] = "abab";

    KMPSearch(text, pattern);

    return 0;
}
