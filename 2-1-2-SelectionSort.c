#include <stdio.h>
void selectionSort(int arr[], int n) {
    
	for(int i=0; i<n; i++)
		{
			int max = i;
			for(int j=i+1; j<n; j++)
			{
				if(arr[j] > arr[max]) max = j;
			}
			int temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp;
		}
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}