#include <stdio.h>

void insertionSort(int a[], int n) {
    
    int i, j, temp;
	for(i=1; i<n; i++)
		{
			temp = a[i];
			for(j=i-1; j>=0 && a[j]>temp; j--)
				{
					a[j+1] = a[j];
				}
					a[j+1] = temp;
		}
}

int main() {
    int a[20], n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    insertionSort(a, n);

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
