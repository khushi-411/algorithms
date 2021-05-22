#include <stdio.h>
int BS(int a[], int l, int h, int x){
    if(l == h){
        if(a[l] == h){
            return l;
        }
        else
            return -1;
    }
    else{
        int mid = (l + h)/2;
        if(a[mid] == x){
            return mid;
        }
        if(a[mid] > x){
            return BS(a, l, mid - 1, x);
        }
        if(a[mid] < x){
            return BS(a, mid + 1, h, x);
        }
    }
}
int main(){
    int a[] = {5,10, 20, 30, 35, 100, 110};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 10;
    int result = BS(a, 0, n - 1, x);
    if(result == -1){
        printf("Element is not present in array");
    }
    else{
        printf("Element is present at index %d \n\t\tOR\nAlternatively %d location of array", result, result + 1);
    }
}
