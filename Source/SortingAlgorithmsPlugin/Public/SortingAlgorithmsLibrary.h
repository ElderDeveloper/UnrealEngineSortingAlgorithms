// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "SortingAlgorithmsLibrary.generated.h"


UCLASS()
class USortingAlgorithmsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:


	//<<<<<<<<<<<<< Insertion Sort >>>>>>>>>>>>>>
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Insertion Sort", CompactNodeTitle = "Insertion Sort", ArrayParm = "TargetArray", BlueprintThreadSafe), Category="Sorting|Insertion Sort")
	static void InsertionSortArrayFloat(UPARAM(ref) TArray<float>& TargetArray);

	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Insertion Sort", CompactNodeTitle = "Insertion Sort", ArrayParm = "TargetArray", BlueprintThreadSafe), Category="Sorting|Insertion Sort")
	static void InsertionSortArrayInt(UPARAM(ref) TArray<int32>& TargetArray);


	//<<<<<<<<<<<<< Selection Sort >>>>>>>>>>>>>>
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Selection Sort", CompactNodeTitle = "Selection Sort", ArrayParm = "TargetArray", BlueprintThreadSafe), Category="Sorting|Selection Sort")
	static void SelectionSortArrayFloat(UPARAM(ref) TArray<float>& TargetArray);

	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Selection Sort", CompactNodeTitle = "Selection Sort", ArrayParm = "TargetArray", BlueprintThreadSafe), Category="Sorting|Selection Sort")
	static void SelectionSortArrayInt(UPARAM(ref) TArray<int32>& TargetArray);

	
	//<<<<<<<<<<<<< Bubble Sort >>>>>>>>>>>>>>
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Bubble Sort ", CompactNodeTitle = "Bubble Sort", ArrayParm = "TargetArray", BlueprintThreadSafe), Category="Sorting|Bubble Sort")
	static void BubbleSortArrayFloat(UPARAM(ref) TArray<float>& TargetArray);

	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Bubble Sort", CompactNodeTitle = "Bubble Sort", ArrayParm = "TargetArray", BlueprintThreadSafe), Category="Sorting|Bubble Sort")
	static void BubbleSortArrayInt(UPARAM(ref) TArray<int32>& TargetArray);


	

private:






	template<class T>
	static void ShellSort(TArray<T>& Arr, int32 Size)
	{
		int32 temp;
		for(int32 i = Size/2; i > 0; i = i/2)
		{
			for(int32 j = i; j < Size; j++)
			{
				for(int32 k = j-i; k >= 0; k = k-i)
				{
					if(Arr[k+i] >= Arr[k]) break;
					else
					{
						temp = Arr[k];
						Arr[k] = Arr[k+i];
						Arr[k+i] = temp;
					}
				}
			}
		}
	}




	template<class T>
	static void merge(TArray<T>& arr, T l, T m, T r);
 

	template<class T>
	static void MergeSort(TArray<T>& arr,T l,T r);
};


