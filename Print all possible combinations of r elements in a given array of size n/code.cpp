#include<iostream>
using namespace std;

void combinationHelper(int *arr,int *data,int start,int end,int index,int r)
{
    //Base case
    if(index == r)
    {
        //Print
        for(int k = 0;k<r;k++)
        cout<<data[k]<<" ";
        cout<<endl;
        return;
    }

    for(int i = start;i<=end && end-i+1 >= r-index ;i++)
    {
        data[index] = arr[i];
        combinationHelper(arr,data,i+1,end,index+1,r);

        //To remove Duplicates
        while(arr[i] == arr[i+1])
        i++;
    }
}
/****  Recursive Approach ****/
void printAllCombinationsOfrElements(int arr[],int n,int r)
{
    if(n<r)
    return;
    //To Store the combinations
    int *data = new int[r];
    combinationHelper(arr,data,0,n-1,0,r);
    
    delete []data;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printAllCombinationsOfrElements(arr, n, r);

    return 0;
}
