#include <stdio.h>
void marge(int arr[],int left,int mid,int right)
{
   int i,j,k;
   int n1=mid-left+1;
   int n2=right-mid;
   
   int L[n1],R[n2];
   
   for(i=0;i<n1;i++)
   L[i]=arr[left+i];
   for(j=0;j<n2;j++)
   R[j]=arr[mid+1+j];
   
   i=0;
   j=0;
   k=left;
   
   while(i<n1 && j<n2)
   {
     if(L[i]<=R[j])
     {
       arr[k]=L[i];
       i++;
     }
     else{
       arr[k]=R[j];
       j++;
     }
     k++;
  }
  while(i<n1)
  {
    arr[k]=L[i];
    i++;
    k++;
  }
  while(i<n2)
  {
    arr[k]=L[i];
    j++;
    k++;
  }
}
void margesort(int arr[],int left,int right)
{
   if(left<right)
   {
      int mid=left+(right-left)/2;
      
      margesort (arr,left,mid);
      margesort(arr,mid+1,right);
      
      marge(arr,left,mid,right);
   }
}
int main()
{
   int arr[]={23,43,8,6,9,1};
   int n=sizeof(arr) / sizeof(arr[0]);
   
   margesort(arr, 0, n-1);
   
   printf("sorted array:");
   for(int i=0;i<n;i++)
   printf("%d ",arr[i]);
   return 0;
}
   
