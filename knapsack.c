// KnapSack
#include <stdio.h>
#include <math.h>

struct knapSack {
    int item;
    float weight, profit, ratio;
};

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(struct knapSack arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    /* create temp arrays */
    struct knapSack L[n1], R[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i].ratio >= R[j].ratio) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(struct knapSack arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    float maxWeight;
    printf("Enter the max weight: ");
    scanf("%f", &maxWeight);

    struct knapSack s[n], temp;
    for(int i = 0; i < n; i++) {
        printf("Enter the item number: ");
        scanf("%d", &s[i].item);
        printf("Enter the weight: ");
        scanf("%f", &s[i].weight);
        printf("Enter the profit: ");
        scanf("%f", &s[i].profit);
        s[i].ratio = 1.0*s[i].profit/s[i].weight;
    }

    printf("\n");

    mergeSort(s, 0, n - 1);

    int x = 0;
    float totalProfit = 0;
    int sequence[n]; 
    float ratio[n];

    for(int i  = 0; i < n; i++) {
        ratio[i] = 0;
    }

    while(maxWeight > 0) {
        if(maxWeight > s[x].weight) {
            totalProfit += s[x].profit;
            sequence[x] = s[x].item;
            ratio[x] = 1;
            maxWeight -= s[x].weight;
        } else {
            totalProfit += (maxWeight/s[x].weight)*s[x].profit;
            sequence[x] = s[x].item;
            ratio[x] = (float) maxWeight/s[x].weight;
            maxWeight = 0;
        }
        x++;
    }

    printf("Sequence is: ");
    for(int i = 0; i < sizeof(sequence)/sizeof(sequence[0]); i++) {
        if(sequence[i] != 0) {
            printf("%d ", sequence[i]);
        }
    }

    printf("\nThe total profit is: %.2f", totalProfit);

    printf("\nComposition is: ");
    for(int i = 0; i < n; i++) {
        if(i == n-1) {
            printf("%.2f", ratio[i]);
        } else {
            printf("%.2f : ", ratio[i]);
        }
    }

    return 0;
}