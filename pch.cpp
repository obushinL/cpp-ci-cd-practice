#include "pch.h"
#include <numeric>

void bubbleSort(std::vector <int>& v) {
	auto n = v.size();
	bool swapped = true;
	int i = 0;

	while (i < n - 1 && swapped) { // keep going while we swap in the unordered part
		swapped = false;

		for (int j = n - 1; j > i; j--) { // unordered part

			if (v[j] < v[j - 1]) {
				std::swap(v[j], v[j - 1]);
				swapped = true;
			}
		}
		i++;
	}
}


void insertionSort(std::vector <int>& v) {
	auto n = v.size();
	int current, pos;

	for (int i = 1; i < n; i++) {
		current = v[i];
		pos = i; // limit of the ordered part, pos not included

		// we make space
		while (pos > 0 && v[pos - 1] > current) {
			v[pos] = v[pos - 1];
			pos--;
		}

		// we move the current value to its position 
		if (pos != i)
			v[pos] = current;
	}
}