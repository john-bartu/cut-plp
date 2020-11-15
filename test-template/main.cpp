#include <stdio.h>

 void swap(int *a, int *b)
 {
    printf("%d %d\n",*a,*b);
    *a ^= *b;
    printf("%d %d\n",*a,*b);
    *b ^= *a;
    printf("%d %d\n",*a,*b);
    *a ^= *b;
    printf("%d %d\n",*a,*b);
 }

int main(){
    int a = 15;
    int b = 7;

    int*pa = &a;
    int*pb = &b;

    printf("%d , %d\n", *pa, *pb);

    swap(pa,pb);
    
    printf("%d , %d\n", *pa, *pb);


    return 0;
}