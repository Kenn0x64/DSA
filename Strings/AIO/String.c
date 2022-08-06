// Char Ops

// Returns UpperCase Of The Char
int ToUpper(char x)
{
    if (x >= 'a' && x <= 'z')
        return x - 32;
    return x;
};

// Returns LowerCase Of The Char
int ToLower(char x)
{
    if (x >= 'A' && x <= 'Z')
        return x + 32;
    return x;
};

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
        if (x[i] == ' ')
            w++;
    return w;
};

// Returns Number Of Vowls in a Str
int NumOfVowels(char x[])
{
    int v = 0;
    for (int i = 0; x[i] != '\0'; i++)
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
    return v;
};
