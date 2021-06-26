
char * intToRoman(int num)
{
    char* Roman = (char*)malloc(20*sizeof(Roman));
    int idx = 0;
    while(num > 0)
    {
        if(num >= 1000)
        {
            Roman[idx++] = 'M';
            num -= 1000;
        }
        else if(num >= 900)
        {
            Roman[idx++] = 'C';
            Roman[idx++] = 'M';
            num -= 900;
        }
        else if(num >= 500)
        {
            Roman[idx++] = 'D';
            num -= 500;
        }
        else if(num >= 400)
        {
            Roman[idx++] = 'C';
            Roman[idx++] = 'D';
            num -= 400;
        }
        else if(num >= 100)
        {

            Roman[idx++] = 'C';
            num -= 100;
        }
        else if(num >= 90)
        {
            Roman[idx++] = 'X';
            Roman[idx++] = 'C';
            num -= 90;
        }
        else if(num >= 50)
        {
            Roman[idx++] = 'L';
            num -= 50;
        }
        else if(num >= 40)
        {
            Roman[idx++] = 'X';
            Roman[idx++] = 'L';
            num -= 40;
        }
        else if(num >= 10)
        {
            Roman[idx++] = 'X';
            num -= 10;
        }
        else if(num >= 9)
        {
            Roman[idx++] = 'I';
            Roman[idx++] = 'X';
            num -= 9;
        }
        else if(num >= 5)
        {
            Roman[idx++] = 'V';
            num -= 5;
        }
        else if(num >= 4)
        {
            Roman[idx++] = 'I';
            Roman[idx++] = 'V';
            num -= 4;
        }
        else if(num >= 1)
        {
            Roman[idx++] = 'I';
            num -= 1;
        }
    }
    Roman[idx] = '\0';
    return Roman;
}
