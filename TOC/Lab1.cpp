/* WAP to find prefix, suffix and substring from given string */

#include <iostream>
#include <string.h>
#include <set>
using namespace std;

int main()
{
    char str[100], prefix[100], suffix[100];
    int i, j, k, l, m, n, o;

    cout << "Enter a string: ";
    cin >> str;
    l = strlen(str);

    cout << "\nPrefix:\n";
    for (i = 0; i < l; i++)
    {
        for (j = 0; j <= i; j++)
        {
            prefix[j] = str[j];
        }
        prefix[j] = '\0';
        cout << prefix << "\n";
    }

    cout << "\nSuffix:\n";
    for (k = 0; k < l; k++)
    {
        for (m = k; m < l; m++)
        {
            suffix[m - k] = str[m];
        }
        suffix[m - k] = '\0';
        cout << suffix << "\n";
    }

    cout << "\nSubstring:\n";
    set<string> unique_substrings;
    for (n = 0; n < l; n++)
    {
        for (o = n; o < l; o++)
        {
            string sub = string(str).substr(n, o - n + 1);

            if (unique_substrings.find(sub) == unique_substrings.end())
            {
                unique_substrings.insert(sub);
                cout << sub << "\n";
            }
        }
    }

    return 0;
}
