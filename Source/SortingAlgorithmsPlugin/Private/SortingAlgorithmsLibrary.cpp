// Copyright Epic Games, Inc. All Rights Reserved.

#include "SortingAlgorithmsLibrary.h"
#include "SortingAlgorithms.h"
#include "Kismet/KismetMathLibrary.h"


USortingAlgorithmsLibrary::USortingAlgorithmsLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}



void USortingAlgorithmsLibrary::InsertionSortArrayFloat(TArray<float>& TargetArray)
{
	SortingAlgorithms::InsertionSort(TargetArray , TargetArray.Num());
}

void USortingAlgorithmsLibrary::InsertionSortArrayInt(TArray<int32>& TargetArray)
{
	SortingAlgorithms::InsertionSort(TargetArray , TargetArray.Num());
}




void USortingAlgorithmsLibrary::SelectionSortArrayFloat(TArray<float>& TargetArray)
{
	SortingAlgorithms::SelectionSort(TargetArray,TargetArray.Num());
}

void USortingAlgorithmsLibrary::SelectionSortArrayInt(TArray<int32>& TargetArray)
{
	SortingAlgorithms::SelectionSort(TargetArray,TargetArray.Num());
}




void USortingAlgorithmsLibrary::BubbleSortArrayFloat(TArray<float>& TargetArray)
{
	SortingAlgorithms::BubbleSort(TargetArray,TargetArray.Num());
}

void USortingAlgorithmsLibrary::BubbleSortArrayInt(TArray<int32>& TargetArray)
{
	SortingAlgorithms::BubbleSort(TargetArray,TargetArray.Num());

}









