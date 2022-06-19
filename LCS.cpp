#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void lcsAlgo(char *S1, char *S2, int m, int n)
{
    int LCS_table[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            if (i == 0 || j == 0)
                LCS_table[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
                else LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
        }
    }
    int index = LCS_table[m][n];
    int lcs_length = index;
    char ans_arr[index];
    ans_arr[index] = '\0';

    int i = m, j = n;

    while (i > 0 && j > 0)

    {

        if (S1[i - 1] == S2[j - 1])
        {
            ans_arr[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        }

        i--;

        j--;
    }

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1]) else

        // Printing the sub sequences cout << "Input Strings:\n"<< "S1 : " << S1 << "\nS2 : " << S2
        << "\nLCS:\n" cout << "Length:" << lcs_length << "\nString: " << ans_arr << "\n";
}

int main()
{
    char S1[10];
    char S2[10];
    cout << "Enter String 1: ";
    cin >> S1;
    cout << "Enter String 2: ";
    cin >> S2;
    int m = strlen(S1);
    int n = strlen(S2);

    lcsAlgo(S1, S2, m, n);
}
