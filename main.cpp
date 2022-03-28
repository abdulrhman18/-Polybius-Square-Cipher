#include <iostream>
#include <string>
using namespace std;
char arr[6][6] = { {' ', ' ', ' ', ' ', ' ', ' '},
               {' ', 'A', 'B', 'C', 'D', 'E'},
               {' ', 'F', 'G', 'H', 'I', 'K'},
               {' ', 'L', 'M', 'N', 'O', 'P'},
               {' ', 'Q', 'R', 'S', 'T', 'U'},
               {' ', 'V', 'W', 'X', 'Y', 'Z'}};
char a, b, c, d, e;
string str;
void input()
{
    cout << "\nPlease enter the sequence : ";
    cin >> a >> b >> c >> d >> e;
    arr[0][1] = a;
    arr[0][2] = b;
    arr[0][3] = c;
    arr[0][4] = d;
    arr[0][5] = e;

    arr[1][0] = a;
    arr[2][0] = b;
    arr[3][0] = c;
    arr[4][0] = d;
    arr[5][0] = e;
    cin.ignore();
}



void encode()
{
    for (int i = 0; i < str.size(); i++)
    {
        char ch = toupper(str[i]);
        if (ch == 'j')
        {
            ch = i;
        }
        if (ch != ' ')
        {
            for (int j = 0; j < 6; j++)
            {
                for (int k = 0; k < 6; k++)
                {
                    if (ch == arr[j][k])
                    {
                        cout << arr[j][0] << arr[0][k];
                    }
                }
            }
        }
        else
        {
            cout << " ";
        }
    }
}

void decode()
{
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] != ' ')
        {
            if (str[i] == 'j')
            {
                str[i] == 'i';
            }
            char row = str[i];
            char column = str[i + 1];
            int realRow, realColumn;
            for (int j = 0; j < 6; j++)
            {
                for (int k = 0; k < 6; k++)
                {
                    if (row == arr[j][0])
                    {
                        realRow = j;
                    }
                    if (column == arr[0][k])
                    {
                        realColumn = k;
                    }
                }
            }
            cout << arr[realRow][realColumn];
            i++;
        }
        else
        {
            cout << " ";
        }
    }
}

int main()
{
    while (true)
    {
        int sys;
        cout << "\nTo encode please press 1:\n" << "To decode please press 2:\n" << "To exit press any number else:\n";
        cin >> sys;
        cin.ignore();
        if (sys != 1 && sys != 2)
        {
            break;
        }

        input();

        if (sys == 1)
        {
            cout << "\nPlease enter the text you want to encode: ";
            getline(cin, str);
            encode();
        }
        else if (sys == 2)
        {
            cout << "\nPlease enter the code you want to decode: ";
            getline(cin, str);
            decode();
        }
    }
}
