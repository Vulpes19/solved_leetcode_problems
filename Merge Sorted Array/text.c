#include <stdio.h>
#include <stdlib.h>

void printArr(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  
int partition (int a[], int start, int end)  
{  
    int pivot = a[end]; // pivot element
    printf("pivot: %d\n", pivot);
    int i = (start - 1);
    printf("i: %d\n", i);
  
    for (int j = start; j <= end - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (a[j] < pivot)  
        {  
            i++; // increment index of smaller element
            printf("a[i]: %d\na[j]: %d\n", a[i], a[j]);  
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }  
    }
    printArr(a, end  + 1);
    printf("\n");
    exit(1);
    int t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;
    return (i + 1);  
}  
  
/* function to implement quick sort */  
void quick(int a[], int start, int end) /* a[] = array to be sorted, start = Starting index, end = Ending index */  
{  
    if (start < end)  
    {  
        int p = partition(a, start, end); //p is the partitioning index  
        quick(a, start, p - 1);  
        quick(a, p + 1, end);  
    }  
}  
  
/* function to print an array */  
int main()  
{  
    int a[] = { 7, 0, 18, -1, 1 };  
    int n = sizeof(a) / sizeof(a[0]);  
    printf("Before sorting array elements are - \n");  
    // printArr(a, n);  
    quick(a, 0, n - 1);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a, n);  
      
    return 0;  
}  