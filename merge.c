#include <cs50.h>
#include<stdio.h>


void merge(int array[], int n);
int main(void) 
{
    int arr[]={1,3,4,6,0,2,5,9};

    merge(arr, 8);

    for(int i=0; i<8; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}


void merge(int array[], int n)
{
    // if there is only one number left from getting half, then return
    if(n<=1)
    {
        return;
    }

    // ELSE

    //store left and right;
    int left[n/2];
    int right[n/2];

        //loop for storing
        for (int i=0; i< (n/2); i++)
        {
            left[i]=array[i];
            right[i] = array[i+n/2];
        }

    //merge left and right array
    merge(left, n/2);
    merge(right, n/2);

    int k=0;
    int i=0;
    int j=0;
    while (k<n)
    {

        if (i>=n/2) // if there's no more numbers to be compared with left side
        {
            //put the rest of the right array in the original array in order
            while(k<n)
            {
                array[k]=right[j];
                j++;
                k++;
            }
            return;
        }
        else if (j>=n/2)
        {
            while(k<n)
            {
                array[k] = left[i];
                i++;
                k++;
            }
            return;
        }
        
        if(left[i]>right[j])
        {
            array[k]=right[j]; //change the array into the lesser one
            j++; //move the right side
        }
        else if( right[j] > left[i])
        {
            array[k]=left[i];
            i++;
        }

        k++; //move to the next place of the main array

    }
    return;
}