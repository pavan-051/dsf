#include<stdio.h>
int i,j,k;
void merge(int arr[],int left,int mid,int right)
{
	int n1=mid-left+1;
	int n2=right-mid;
	int leftarr[n1],rightarr[n2];
	for(i=0;i<n1;i++)
	{
		leftarr[i]=arr[left+i];
	}
	for(j=0;j<n2;j++)
	{
		rightarr[j]=arr[mid+1+j];
	}
	int i=0;j=0;k=left;
	while(i<n1 && j<n2)
	{
		if(leftarr[i]<=rightarr[i]){
			arr[k]=leftarr[i];
			i++;
		}
		else{
			arr[k]=rightarr[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k]=leftarr[i];
		i++;
		k++;
	}
	while(i<n2)
	{
		arr[k]=rightarr[j];
		j++;k++;
	}
	
}
void print(int arr[],int n){
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void mergesort(int arr[],int left,int right)
{
	if(left<right)
	{
		int mid=left+(right-left)/2;
		mergesort(arr,left,mid);
		mergesort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}
int main()
{
	int arr[]={12,53,56,23,24};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("The Original Array");
	print(arr,n);
	mergesort(arr,0,n-1);
	printf("The sorted array\n");
	print(arr,n);
	return 0;
}
