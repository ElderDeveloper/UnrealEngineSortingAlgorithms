// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SortingAlgorithms.generated.h"



namespace SortingAlgorithms
{

	//<<<<<<<<<<<<<< Insertion >>>>>>>>>>>>>>>>>>>>>>>>
	template <class T>
	static void InsertionSort(TArray<T>& Arr , int32 Size)
	{
		int32 i, j;
		T temp;

		for (i = 1; i < Size; ++i)
		{
			temp = Arr[i];
			j = i - 1;
			while (j >= 0 && Arr[j] > temp)
			{
				Arr[j + 1] = Arr[j];
				j = j - 1;
			}
			Arr[j + 1] = temp;
		}
	}



	//<<<<<<<<<<<<<< Selection >>>>>>>>>>>>>>>>>>>>>>>>
	template <class T>
	static void SelectionSort(TArray<T>& Arr, int32 Size)
	{
		for (int32 i = 0; i < Size - 1; i++) {
        	int32 min = i;
        	for (int32 j = i + 1; j < Size; j++)
        	{
        		if (Arr[j] < Arr[min])	min = j;
        				
        		Arr.Swap(Arr[i], Arr[min]);
        	}
        }
	}


	
	//<<<<<<<<<<<<<< Bubble >>>>>>>>>>>>>>>>>>>>>>>>
	template<class T>
    static void BubbleSort(TArray<T>& Arr, int32 Size)
	{
		for(int32 i=0; i<Size-1; ++i)
		{
			for(int32 j=0; j<Size-i-1; ++j)
			{
				if(Arr[j]>Arr[j+1])
				{
					T temp = Arr[j+1];
					Arr[j+1] = Arr[j];
					Arr[j] = temp;
				}
			}
		}
	}



	//<<<<<<<<<<<<<< Merge >>>>>>>>>>>>>>>>>>>>>>>>
	template <class T>
	static void merge(TArray<T>& arr, T l, T m, T r)
	{
		T n1 = m - l + 1;
		T n2 = r - m;
		T L[n1], R[n2];
		for (T i = 0; i < n1; i++)
			L[i] = arr[l + i];
		for (T j = 0; j < n2; j++)
			R[j] = arr[m + 1 + j];
		T i = 0;
		T j = 0;
		T k = l;
 
		while (i < n1 && j < n2) {
			if (L[i] <= R[j]) {
				arr[k] = L[i];
				i++;
			}
			else {
				arr[k] = R[j];
				j++;
			}
			k++;
		}
 
  
		while (i < n1) {
			arr[k] = L[i];
			i++;
			k++;
		}
 
   
		while (j < n2) {
			arr[k] = R[j];
			j++;
			k++;
		}
	}


	template <class T>
	static void MergeSort(TArray<T>& arr, T l, T r)
	{
		if(l>=r){
			return;
		}
		T m = (l+r-1)/2;
		MergeSort(arr,l,m);
		MergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}


	
	//<<<<<<<<<<<<<< Heap >>>>>>>>>>>>>>>>>>>>>>>>
	template<class T>
	void heap(TArray<T>& Arr, std::size_t i, std::size_t delim)
	{
		std::size_t left=2*i+1, right=2*i+2;
		if (right >= delim) return;
  
		if ((Arr[left] > Arr[right]) && (Arr[left] > Arr[i]))
		{
			Arr.Swap(Arr[i], Arr[left]);
			heap(Arr, left, delim);
		}
		else if(Arr[right] > Arr[i]) 
		{
			Arr.Swap(Arr[i], Arr[right]);
			heap(Arr, right, delim);
		}
	}

	
	template<class T>
	void HeapSort(TArray<T>& Arr)
	{
		std::size_t n = Arr.size();
  
		// sort as maxheap starting from last parent node
		for (int32 i=(n/2)-1; i>=0; --i) heap(Arr, i, n-1);

		for (int32 i=n-1; i>0; --i) 
		{
			Arr.Swap(Arr[i], Arr[0]);
			heap(Arr, 0, i);
		}
	}

	

	
}



UCLASS()
class SORTINGALGORITHMSPLUGIN_API USortingAlgorithms : public UObject
{
	GENERATED_BODY()
};

