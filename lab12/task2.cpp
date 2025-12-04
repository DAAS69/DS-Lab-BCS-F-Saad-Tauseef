#include <iostream>
#include <cstring>
using namespace std;

void rabinKarpSearch(char* document, char* snippet)
{
    int docLength = strlen(document);
    int snippetLength = strlen(snippet);
    int base = 256;
    int primeModulus = 101;

    long snippetHash = 0;
    long windowHash = 0;
    long highestBasePower = 1;

    for(int i=0; i<snippetLength-1; i++)
        highestBasePower = (highestBasePower * base) % primeModulus;

    for(int i=0; i<snippetLength; i++)
    {
        snippetHash = (base * snippetHash + snippet[i]) % primeModulus;
        windowHash = (base * windowHash + document[i]) % primeModulus;
    }

    cout << "positions: ";
    for(int i=0; i<=docLength-snippetLength; i++)
    {
        if(snippetHash == windowHash)
        {
            bool match = true;
            for(int j=0;j<snippetLength;j++)
            {
                if(document[i+j] != snippet[j])
                {
                    match = false;
                    cout << "\nfalse positive at index " << i;
                    break;
                }
            }
            if(match) cout << i << " ";
        }

        if(i<docLength-snippetLength)
        {
            windowHash = (base*(windowHash - document[i]*highestBasePower) + document[i+snippetLength]) % primeModulus;
            if(windowHash < 0) windowHash += primeModulus;
        }
    }
    cout << endl;
}

int main()
{
    char document[] = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    char snippet[] = "Algorithms";

    rabinKarpSearch(document, snippet);

    return 0;
}
