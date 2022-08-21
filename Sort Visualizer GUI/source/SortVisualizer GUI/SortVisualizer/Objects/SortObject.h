#pragma once
#include "../Visualizer/SortVisualizer.h"
#include "CollumnArrayObject.h"

#include <vector>

class SortObject {
public:
	enum SortType {
		BUBBLE_SORT,
		SELECTION_SORT,
		INSERTION_SORT,
		MERGE_SORT,
		HEAP_SORT,
		COMPLETED
	};

	SortObject(sort::SortVisualizer* visualizer, CollumnArrayObject* object);

	void SetType(const std::string& type);

	void Start();
private:
	sort::SortVisualizer* visualizer;
	CollumnArrayObject* object;
	SortType type;

	void BubbleSort();
	void InsertionSort();
	void SelectionSort();
	void MergeSort(const int left, const int right);
	void Merge(const int left, const int mid, const int right);
	void HeapSort();
	void Heapify(const int size, const int node);
};