#include <iostream>
#include <cstring>
using namespace std;

#define NO_OF_CHARS 256

void preprocessBadCharacter(char* pattern, int patternLength, int badCharTable[])
{
    for(int i=0;i<NO_OF_CHARS;i++) badCharTable[i] = -1;
    for(int i=0;i<patternLength;i++) badCharTable[(int)pattern[i]] = i;
}

void boyerMooreSearch(char* dnaStrand, char* motif)
{
    int strandLength = strlen(dnaStrand);
    int motifLength = strlen(motif);
    int badCharTable[NO_OF_CHARS];
    preprocessBadCharacter(motif, motifLength, badCharTable);

    int shift = 0;
    cout << "positions: ";
    while(shift <= strandLength - motifLength)
    {
        int j = motifLength - 1;
        while(j >= 0 && motif[j] == dnaStrand[shift + j]) j--;
        if(j < 0)
        {
            cout << shift << " ";
            shift += (shift + motifLength < strandLength) ? motifLength - badCharTable[dnaStrand[shift + motifLength]] : 1;
        }
        else
        {
            shift += max(1, j - badCharTable[dnaStrand[shift + j]]);
        }
    }
    cout << endl;
}

int main()
{
    char dnaStrand[] = "ACGTACGTGACG";
    char motif[] = "ACG";

    boyerMooreSearch(dnaStrand, motif);

    return 0;
}
