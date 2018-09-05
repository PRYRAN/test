
#include <stdio.h>
void bubble_sort(int *input, int n)
{
    
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if (*(input+j) > *(input+(j+1)))
            {
                int temp = *(input+j);
                *(input+j) = *(input+(j+1));
                *(input+(j+1)) = temp;
            }
        }
    }
    
}

int main()
{
    int a[] = {1,5,2, 7, 2, 6, 7, 1};
    
    bubble_sort(&a, sizeof(a)/sizeof(int));
    for (int i = 0; i < sizeof(a)/sizeof(int); i++) {
        printf("%d\n",a[i]);
    }


    return 0;
}
