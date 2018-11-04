/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    sort(values, n);
    int min = values[0];
    int max = values[n - 1];
    
    for (int i = 0; i < n ; i++)
    {
        if(values[n / 2] == value)
            return true;
        else if(values[n / 2] > value)
        {
            max = values[n / 2 - 1];
            if (values[n / 2 - 1] == value)
                return true;
        }
        else
        {
            min = values[n / 2 + 1];
            if (values[n / 2 + 1] == value)
                return true;
        }
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for (int i = 0; i < n; i++)
    {
        int swapDone = 0;
        
        for (int j = 1; j < n - i; j++)
        {
            if(values[j] < values[j - 1])
            {
                int temp;
                temp = values[j];
                values[j] = values[j - 1];
                values[j - 1] = temp;
                swapDone++;
            }
        }
        if(swapDone == 0)
            return;
    }
    return;
}
