#include<stdio.h>
struct a
{
    struct b
    {
        struct c
        {
            struct d
            {
                struct e
                {
                    int x;
                }e;
            }d;
        }c;

    }b;
}a;

int main()
{
    struct a a;
    scanf("%d",&a.b.c.d.e.x);
    printf("%d",a.b.c.d.e.x);
}
