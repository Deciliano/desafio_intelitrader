#include <stdio.h>
#include <stdlib.h>
#define SIZE1 2
#define SIZE2 2

int findMinDistance(int arr1[], int size1, int arr2[], int size2) {
    int minDistance = abs(arr1[0] - arr2[0]);

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            int distance = abs(arr1[i] - arr2[j]); // A função abs é usada para garantir que a distancia seja sempre positiva
            if (distance < minDistance) {
                minDistance = distance;
            }
        }
    }
    
    return minDistance;
}

int main() {
    int array1[SIZE1] = {-1, 5};
    int array2[SIZE2] = {26, 6};

    int minDistance = findMinDistance(array1, SIZE1, array2, SIZE2);

    printf("A menor distância entre os dois arrays é: %d\n", minDistance);

    return 0;
}
