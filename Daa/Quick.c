#include<stdio.h>
int i,j;
void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
int partition(int arr[],int low,int high)
{
	int pivot=arr[high];
	int i=low-1;
	for(j=low;j<high;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr,i+1,high);
	return i+1;
}
void quicksort(int arr[],int low,int high)
{
	if(low<high)
	{
	int pi=partition(arr,low,high);
	quicksort(arr,low,pi-1);
	quicksort(arr,pi+1,high);
}
}
void print(int arr[],int n)
{
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[]={10,34,23,45,67};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("\nThe original Array");
	print(arr,n);
	quicksort(arr,0,n-1);
	printf("The Sorted Array");
	print(arr,n);
	return 0;
}
