#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int size=100000;

void insertion_sort(int arr[],int size){
int i,j,temp,k;
  for(i=1;i<size;i++){
     temp=arr[i];
     j=i-1;
     while(j>=0&&arr[j]>temp){
       arr[j+1]=arr[j];
       j-=1;
       }
    arr[j+1]=temp;
    }
    }

int partition(int arr[],int s,int e){
 int start=s,end = e ,p=arr[s],temp,temp1;
 while(start<end){
    do{
      start++;
    }while(arr[start]<=p);
    do{
      end--;
    }while(arr[end]>p);
    if(start<end){
      temp=arr[end];
      arr[end]=arr[start];
      arr[start]=temp;}}
    temp1=arr[end];
    arr[end] =arr[s];
    arr[s]=temp1;
    return end;
 }
 void quick_sort(int arr[],int s,int e){
     if(s<e){
     int piv=partition(arr,s,e);
        quick_sort(arr,s,piv);
        quick_sort(arr,piv+1,e);}
        }

int main()
{
    clock_t t;
    clock_t begin;
    int arr[size];
    int i;
    for(i=0;i<size;i++){
        arr[i]=rand();
    }
    t=clock();
   insertion_sort(arr,size);
    t = clock() - t;
   double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
   printf("The Array is sorted using insertion sort in %f \n", time_taken);
    for(i=0;i<size;i++){
        arr[i]=rand();
    }
   begin =clock();
   quick_sort(arr,0,size);
   clock_t end = clock();
    double time_taken1 =((double)end-begin)/CLOCKS_PER_SEC; // in seconds
   printf("The Array is sorted using quick sort in %f \n", time_taken1);
    return 0;

}
