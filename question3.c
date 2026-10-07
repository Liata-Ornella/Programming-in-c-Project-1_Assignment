#include <stdio.h>

// Calculates the total distance using a loop
int calculateTotal(int distances[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total += distances[i];
    }

    return total;
}

// Calculates the average distance
float calculateAverage(int total, int n)
{
    return (float) total / n;
}

// Finds the longest route
int findLongest(int distances[], int n)
{
    int longest = distances[0];

    for (int i = 1; i < n; i++)
    {
        if (distances[i] > longest)
        {
            longest = distances[i];
        }
    }

    return longest;
}

// Counts routes greater than the specified limit
int countAboveLimit(int distances[], int n, int limit)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (distances[i] > limit)
        {
            count++;
        }
    }

    return count;
}

// Recursively calculates the sum of the distances
int recursiveSum(int distances[], int n)
{
    // Base case
    if (n == 0)
    {
        return 0;
    }

    // Recursive case
    return distances[n - 1] + recursiveSum(distances, n - 1);
}

int main()
{
    int n;
    int limit;

    printf("Enter number of routes: ");
    scanf("%d", &n);

    int distances[n];

    printf("Enter the distances in km:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Route %d: ", i + 1);
        scanf("%d", &distances[i]);
    }

    printf("Enter distance limit: ");
    scanf("%d", &limit);

    // Call the functions
    int total = calculateTotal(distances, n);
    float average = calculateAverage(total, n);
    int longest = findLongest(distances, n);
    int aboveLimit = countAboveLimit(distances, n, limit);
    int recursiveTotal = recursiveSum(distances, n);

    printf("\n===== DELIVERY DISTANCE ANALYSIS =====\n");
    printf("Total distance: %d km\n", total);
    printf("Average distance: %.2f km\n", average);
    printf("Longest route: %d km\n", longest);
    printf("Routes above %d km: %d\n", limit, aboveLimit);
    printf("Recursive sum: %d km\n", recursiveTotal);

    return 0;
}