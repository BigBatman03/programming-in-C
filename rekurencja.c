#include <stdio.h>

//zad1--------------------------------------------------------
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

//zad2-----------------------------------------------------------
int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;        
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);
        return binarySearch(arr, mid + 1, right, target);
    }
    return -1;
}

//zad3--------------------------------------------------------------------------
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int *array, int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&array[start], &array[i]);
        permute(array, start + 1, end);
        swap(&array[start], &array[i]);
    }
}


int main() {
  //zad1--------------------------------------------------------------------
  int num;
    printf("Podaj liczbę: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Silnia nie jest zdefiniowana dla liczb ujemnych.\n");
    } else {
        printf("%d! = %llu\n", num, factorial(num));
    }

  
  //zad2------------------------------------------------------------------
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    
    printf("Podaj liczbę do wyszukania: ");
    scanf("%d", &target);
    
    int result = binarySearch(arr, 0, size - 1, target);
    
    if (result != -1)
        printf("Element %d znaleziony na indeksie %d.\n", target, result);
    else
        printf("Element %d nie znaleziony w tablicy.\n", target);

  //zad3----------------------------------------------------------------------
    int array[] = {1, 2, 3};
    int size2 = sizeof(array) / sizeof(array[0]);
    
    printf("Permutacje:\n");
    permute(array, 0, size2 - 1);
    
    return 0;
}
