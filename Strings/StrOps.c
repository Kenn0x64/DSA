#include "Headers/CharOps.h"
#include "malloc.h"
// Str Ops
// Returns Length Of String
int StrLength(char str[])
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == '\0')
            return i;
        i++;
    }
    return i;
}

// Alocate String
char *AlocateString(char *a)
{
    char *s = malloc(sizeof(char) * StrLength(a));

    for (int i = 0; i < StrLength(a); i++)
    {
        s[i] = a[i];
    }

    return s;
}

// Retruns a Upper Case Version Of The String
void StrToUpper(char x[])
{
    for (int i = 0; i < StrLength(x); i++)
        x[i] = ToUpper(x[i]);
};

// Retruns a Lower Case Version Of The String
void StrToLower(char x[])
{
    for (int i = 0; i < StrLength(x); i++)
        x[i] = ToLower(x[i]);
}

// Retruns inversed Case's of the String
void StrInverseCase(char x[])
{
    for (int i = 0; i < StrLength(x); i++)
    {
        if (x[i] >= 'a' && x[i] <= 'z')
            x[i] = ToUpper(x[i]);
        else
            x[i] = ToLower(x[i]);
    }
};

// Returns Number Of words in a Str
int NumOfWords(char x[])
{
    int w = 1;
    for (int i = 0; x[i] != '\0'; i++)
        if (x[i] == ' ' && x[i - 1] != ' ')
            w++;
    return w;
};

// Returns Number Of Vowls in a Str
int NumOfVowels(char x[])
{
    int v = 0;
    for (int i = 0; x[i] != '\0'; i++)
    {

        if ((x[i] < 'a' && x[i] > 'z') && (x[i] < 'A' && x[i] > 'Z'))
            continue;

        switch (x[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            v++;
        }
    }
    return v;
};
#include <stdio.h>

// Returns True If Str Does Not Contain Special Charecters
int IsVaildStr(char x[])
{
    for (int i = 0; i < StrLength(x); i++)
    {
        if (!(x[i] >= '#' && x[i] <= '&') &&
            !(x[i] >= '0' && x[i] <= '9') &&
            !(x[i] >= 'a' && x[i] <= 'z') &&
            !(x[i] >= 'A' && x[i] <= 'Z'))
            return 0;
    }
    return 1;
};

// Returns A Pointer To Reversed String
char *ReverseStr(char x[])
{
    int q = 0;
    char *a = malloc(sizeof(char) * StrLength(x) + 1);
    a[StrLength(x)] = '\0';

    for (int i = StrLength(x) - 1; i >= 0; i--)
        a[q++] = x[i];

    return a;
};

// Getting Index Of Char
char IndexOf(char x[], char c)
{
    for (int i = 0; i <= StrLength(x); i++)
        if (x[i] == c)
            return i;
    return -1;
};

// Print String
void PrintStr(char x[])
{
    for (int i = 0; i <= StrLength(x); i++)
    {
        if (x[i] == '\0')
            printf("\\0-->%d\n", i);
        else
            printf(" %c-->%d\n", x[i], i);
    }
    printf("-----------\nString Length:%d\n", StrLength(x));
    printf("%s\n", x);
};

// isNull?
int IsNull(char x[])
{
    for (int i = 0; x[i] != '\0'; i++)
    {
        if (x[i] != ' ')
            return 0;
    }
    return 1;
};

// Are Arrays Equal
int IsStrEqStr(char a[], char b[])
{
    StrToLower(a);
    StrToLower(b);

    int i = 0, j = 0;
    while (a[i] != '\0' || b[j] != '\0')
    {
        if (a[i] != b[j])
            return 0;

        a[i] != '\0' ? i++ : 0;
        b[j] != '\0' ? j++ : 0;
    }
    return 1;
};

// IsPlindrom?
int IsPlindrom(char *a)
{
    if (IsStrEqStr(a, ReverseStr(a)))
        return 1;

    return 0;
};

int IsThereDuplictsM1(char *a)
{
    for (int i = 0; i < StrLength(a); i++)
        for (int j = i + 1; j < StrLength(a); j++)
            if (a[i] == a[j])
                return 1;
    return 0;
};

int IsThereDuplictsM2(char *a)
{
    StrToLower(a);
    int d[26] = {0};

    for (int i = 0; i < StrLength(a); i++)
    {
        if (a[i] < 'a' && a[i] > 'z')
            continue;

        d[a[i] - 97]++;
    }

    for (int i = 0; i < 26; i++)
        if (d[i] > 1)
            return 1;

    return 0;
};

// AreTheyAnagram?
int AreTheyAnagramM1(char *a, char *b)
{
    StrToLower(a);
    StrToLower(b);

    if (StrLength(a) != StrLength(b))
        return 0;

    for (int i = 0; i < StrLength(a); i++)
    {
        if (IndexOf(b, a[i]) == -1)
            return 0;
    }

    return 1;
};

// AreTheyAnagram?
int AreTheyAnagramM2(char *a, char *b)
{
    if (StrLength(a) != StrLength(b))
        return 0;

    StrToLower(a);
    int d[26] = {0};

    for (int i = 0; i < StrLength(a); i++)
    {
        if (a[i] < 'a' && a[i] > 'z')
            continue;

        d[a[i] - 97]++;
    }

    for (int i = 0; i < StrLength(b); i++)
    {
        if (b[i] < 'a' && b[i] > 'z')
            continue;

        d[b[i] - 97]--;
    }

    for (int i = 0; i < 26; i++)
        if (d[i] < 0)
            return 0;

    return 1;
};

// Rotate Elements to Left
void LeftRotation(char A[])
{
    char r = A[0];
    for (int i = 0; i < StrLength(A); i++)
        A[i] = A[i + 1];
    A[StrLength(A)] = r;
}

// Rotate Elements to Right
void RightRotation(char A[])
{
    char r = A[StrLength(A) - 1];
    for (int i = StrLength(A) - 1; i > 0; i--)
        A[i] = A[i - 1];
    A[0] = r;
}

// Permntaion Of Sting
void PermntaionStr(char *s, int l)
{
    int h=StrLength(s);
    if (l == h-1)
        printf("%s\n", s);
    else
        for (int i = l; i < h; i++)
        {
            i!=l?SwapEle(s, s[l], s[i]):0;
            PermntaionStr(s, l + 1);
            i!=l?SwapEle(s, s[l], s[i]):0;
        }
    return;
};
