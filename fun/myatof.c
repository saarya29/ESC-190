#include <stdio.h>
#include <string.h>


//Goal is to implement another version of myatof.
double myatof(const char *string)
{
    //2 constraints, if you have a negative sign and if you have a decimal at any place. 
    int decimal = 0;
    int count = 0;
    int i = 0;
    int res = 0;
    int sign = 1; //you only have to check it once so you're good. 
    if (string[i] == '-')
    {
        sign = -1;
        i++;
    }
    //Idea is to loop through the whole string and then use isdigit to see if it is or not. And then if you're going to reach a decimal anywhere, you're going to have a dummy light pop up, and then from there on, you're going to have to be divided by some amount or something. 
    while (string[i] != '\0')
    {
       if (isdigit(string[i])) //if it is then you're going to just
       {
        int res = res * 10 + string[i] - '0';
       }
       else{
        if (string[i] == '.')  //this is only going to get triggered once so we're kind of good.. we're only really going to implement it in the end. If there is no decimal, the dummy is never going to be awaken. 
        {
            decimal = 1;
            count = i //the index at which the decimal was seen... afterwards. What you do is just i - count because i is always going to change but the count is not. 
        }
       }
       i++;
    }
    if (decimal == 1)
    {
        int exp = i - count;
        int divisor = pow(10, exp); //i guess in this case, 10^4
        int res = res / divisor; //i'm pretty sure this should be allowed?
    }
    return res * sign; //in case you're positive or negative. 
}

int main()
{
    char *floater = "23.445";
    double answer = myatof(&floater);
    printf("%lf\n", answer);
    return 0;

}