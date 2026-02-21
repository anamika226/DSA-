
#include<stdio.h>
int binarysearch(int arr[],int item,int low,int high)
{
    while(low<=high)
    {
       int mid=low+(high-low)/2;
       
       if(arr[mid]==item)
         return mid+1;
       else if(arr[mid]<item)
         low=mid+1;
      
       else
         high=mid-1;
    }
    return low;
}
void binaryInsertionsort(int arr[],int n)
{
    for (int i=1;i<n;i++)
    {
       int key = arr[i];
       int j=i-1;
       
       int pos=binarysearch(arr,key,0,j);
       while(j>=pos)
       {
           arr[j+1]=arr[j];
           j--;
       }
       arr[j+1]=key;
    }
}
void printArray(int arr[],int n)
{
   for(int i=0;i<n;i++)
     printf("%d ",arr[i]);
   printf("\n");
}
int main()
{
    int arr[]={5,3,13,11,21};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    binaryInsertionsort(arr,n);
    
    printf("sorted array:");
    printArray(arr,n);
    return 0;
}
        
