#include "SortObject.h"

SortObject::SortObject(sort::SortVisualizer* visualizer, CollumnArrayObject* object) :
	visualizer(visualizer), object(object), type() { }

void SortObject::SetType(const std::string& type) {
	std::map<const std::string, SortType> typeMap{
		{"BUBBLE_SORT",		BUBBLE_SORT},
		{"SELECTION_SORT",	SELECTION_SORT},
		{"INSERTION_SORT",	INSERTION_SORT},
		{"MERGE_SORT",		MERGE_SORT},
		{"HEAP_SORT",		HEAP_SORT}
	};
	this->type = typeMap[type];
}

void SortObject::Start() {
	switch (type) {
		case BUBBLE_SORT:
			this->BubbleSort();
			type = COMPLETED;
			break;
		case SELECTION_SORT:
			this->SelectionSort();
			type = COMPLETED;
			break;
		case INSERTION_SORT:
			this->InsertionSort();
			type = COMPLETED;
			break;
		case MERGE_SORT:
			this->MergeSort(0, (int)this->object->GetVector().size() - 1);
			type = COMPLETED;
			break;
		case HEAP_SORT:
			this->HeapSort();
			type = COMPLETED;
			break;
	}
	this->visualizer->Render();
}



//Sorting algorithms
void SortObject::BubbleSort() {
	uint64_t limit{ object->GetVector().size() - 1 };
	while (type != COMPLETED) {
		int swapped_iter{};
		for (int iter{}; iter < limit; ++iter) {
			if (object->GetVector()[iter] > object->GetVector()[iter + 1]) {
				visualizer->Render(iter, iter + 1);
				std::swap(object->GetVector()[iter], object->GetVector()[iter + 1]);
				swapped_iter = iter;
			}
			visualizer->Render(iter, iter + 1);
		}
		if (!swapped_iter) 
			type = COMPLETED;
		limit = swapped_iter;
	}
}

void SortObject::SelectionSort() {
	for (int first_iter{}; first_iter < object->GetVector().size() - 1; ++first_iter) {
		int min_item{ first_iter };
		for (int second_iter{ first_iter + 1 }; second_iter < object->GetVector().size(); ++second_iter)
			if (object->GetVector()[second_iter] < object->GetVector()[min_item])
				min_item = second_iter;
		visualizer->Render(first_iter, min_item);
		if (first_iter != min_item)
			std::swap(object->GetVector()[min_item], object->GetVector()[first_iter]);
		visualizer->Render(first_iter, min_item);
	}
	type = COMPLETED;
}

void SortObject::InsertionSort() {
	for (int iter{}; iter < object->GetVector().size(); ++iter) {
		for (int in_iter{ iter }; in_iter > 0; --in_iter) {
			bool swapped{ false };
			if (object->GetVector()[in_iter] < object->GetVector()[in_iter - 1]) { 
				visualizer->Render(in_iter, in_iter - 1);
				std::swap(object->GetVector()[in_iter], object->GetVector()[in_iter - 1]); 
				swapped = true;
			}
			visualizer->Render(in_iter, in_iter - 1);
			if (!swapped)
				break;
		}
	}
	type = COMPLETED;
}

void SortObject::MergeSort(const int left, const int right) {
	visualizer->Render(left, right);
	if (left >= right)
		return;
	int mid{ (left + right) / 2 };
	this->MergeSort(left, mid);
	this->MergeSort(mid + 1, right);
	this->Merge(left, mid, right);
	visualizer->Render(left, right);
}

void SortObject::Merge(const int left, const int mid, const int right) {
	const int leftSubArray{ mid - left + 1 };
	const int rightSubArray{ right - mid };

	std::vector<int> leftArray(leftSubArray);
	std::vector<int> rightArray(rightSubArray);
	for (int it{}; it < leftSubArray; ++it)
		leftArray[it] = this->object->GetVector()[left + it];
	for (int it{}; it < rightSubArray; ++it)
		rightArray[it] = this->object->GetVector()[mid + 1 + it];

	int indexOfLeftArray{};
	int indexOfRightArray{};
	int indexOfMergedArray{ left };

	while (indexOfLeftArray < leftSubArray && indexOfRightArray < rightSubArray) {
		if (leftArray[indexOfLeftArray] <= rightArray[indexOfRightArray]) {
			this->object->GetVector()[indexOfMergedArray] = leftArray[indexOfLeftArray];
			++indexOfLeftArray;
		}
		else {
			this->object->GetVector()[indexOfMergedArray] = rightArray[indexOfRightArray];
			++indexOfRightArray;
		}
		++indexOfMergedArray;
	}
	while (indexOfLeftArray < leftSubArray) {
		this->object->GetVector()[indexOfMergedArray] = leftArray[indexOfLeftArray];
		++indexOfLeftArray;
		++indexOfMergedArray;
	}
	while (indexOfRightArray < rightSubArray) {
		this->object->GetVector()[indexOfMergedArray] = rightArray[indexOfRightArray];
		++indexOfRightArray;
		++indexOfMergedArray;
	}
}

void SortObject::HeapSort() {
	visualizer->Render(0, 1);
	for (int it{ (int)object->GetVector().size() / 2 - 1 }; it >= 0; --it)
		Heapify((int)object->GetVector().size(), it);
	for (int it{ (int)object->GetVector().size() - 1 }; it > 0; --it) {
		visualizer->Render(0, it);
		std::swap(object->GetVector()[0], object->GetVector()[it]);
		Heapify(it, 0);
		visualizer->Render(0, it);
	}
}

void SortObject::Heapify(const int size, const int node) {
	int largest{ node };

	int left{ 2 * node + 1 };
	int right{ 2 * node + 2 };
	if (left < size && this->object->GetVector()[left] > this->object->GetVector()[largest])
		largest = left;
	if (right < size && this->object->GetVector()[right] > this->object->GetVector()[largest])
		largest = right;
	if (largest != node) {
		std::swap(this->object->GetVector()[largest], this->object->GetVector()[node]);
		Heapify(size, largest);
	}
}
