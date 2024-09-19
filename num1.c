#include <stdio.h>

void displayArray(int arr[], int size);
void displayArrayReverse(int arr[], int size);
void displayEvenIndices(int arr[], int size);
void displayOddIndices(int arr[], int size);
void rotateRight(int arr[], int size, int k);
void rotateLeft(int arr[], int size, int k);

int main()
{
    int arr[10];
    int choice, k;

    printf("Enter 10 integers: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1)
    {

        printf("\nMenu:\n");
        printf("1. Display the numbers\n");
        printf("2. Display it in reverse order\n");
        printf("3. Display values of even indices\n");
        printf("4. Display values of odd indices\n");
        printf("5. Rotate array by k (Forward)\n");
        printf("6. Rotate array by k (Backward)\n");
        printf("choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayArray(arr, 10);
            break;
        case 2:
            displayArrayReverse(arr, 10);
            break;
        case 3:
            displayEvenIndices(arr, 10);
            break;
        case 4:
            displayOddIndices(arr, 10);
            break;
        case 5:
            printf("offset: ");
            scanf("%d", &k);
            rotateRight(arr, 10, k);
            displayArray(arr, 10);
            break;
        case 6:
            printf("offset: ");
            scanf("%d", &k);
            rotateLeft(arr, 10, k);
            displayArray(arr, 10);
            break;
        default:
            printf("Invalid choice. Exiting.\n");
            return 0;
        }
    }

    return 0;
}

void displayArray(int arr[], int size)
{
    printf("number: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void displayArrayReverse(int arr[], int size)
{
    printf("number: ");
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void displayEvenIndices(int arr[], int size)
{
    printf("number: ");
    for (int i = 0; i < size; i += 2)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void displayOddIndices(int arr[], int size)
{
    printf("number: ");
    for (int i = 1; i < size; i += 2)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void rotateRight(int arr[], int size, int k)
{
    k = k % size;
    int temp[k];

    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[size - k + i];
    }

    for (int i = size - 1; i >= k; i--)
    {
        arr[i] = arr[i - k];
    }

    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}

void rotateLeft(int arr[], int size, int k)
{
    k = k % size;
    int temp[k];

    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = 0; i < size - k; i++)
    {
        arr[i] = arr[i + k];
    }

    for (int i = 0; i < k; i++)
    {
        arr[size - k + i] = temp[i];
    }
}
