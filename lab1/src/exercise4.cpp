/// Tittle: Exercise4
/// Description: Check if numbers are familiary - sum of divisons = another number +1

#include <cstdio>

int check_divisions(int a)
{
    int sum = 1;
    for (int div = 2; div <= a/2; div++)
        if (a % div==0)
            sum += div;

    return sum;
}

int check_familairy(int a, int b){
    if(check_divisions(b)!=a+1)
        return 0;
    
    if(check_divisions(a)!=b+1)
        return 0;

    return 1;
}

int main(int argc, char *argv[])
{
    int a=140;
    int b=195;

    if(check_familairy(a,b)){
        printf("Liczby %d i %d są skojarzone\n",a,b);
    }else{
        printf("Liczby %d i %d nie są skojarzone\n",a,b);
    }

    return 0;
}