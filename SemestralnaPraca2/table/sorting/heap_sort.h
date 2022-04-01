#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"

namespace structures
{

	/// <summary> Triedenie Heap sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class HeapSort : public Sort<K, T>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Heap sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
	};

	template<typename K, typename T>
	inline void HeapSort<K, T>::sort(UnsortedSequenceTable<K, T>& table)
	{
		bool exchange = false;
		int current;
		for (int i = 0; i < table.size() - 1; i++)
		{
			current = i;
			do
			{
				exchange = false;
				int parent = (current - 1) / 2;
				if (current > 0) && (table.getItemAtIndex(current).getKey() > table.getItemAtIndex(parent).getKey())
				{
					table.swap(current, parent);
					notify();
					current = parent;
					exchange = true
				}
			} while (exchange);
		}
		for (int i = table.size() - 1; i < 1; i--)
		{
			table.swap(0, i);
			notify();
			current = 0;
			do
			{
				exchange = false;
				left = current * 2 + 1;
				right = current * 2 + 2;
				if (left < i) && (right < i)
				{
					int max = table.getItemAtIndex(left) > table.getItemAtIndex(right) ? left : right;
				}
				else
				{
					int max = left < i ? left : right;
				}
				if (max < i && table.getItemAtIndex(max).getKey() > table.getItemAtIndex(max).getKey())
				{
					table.swap(max, current);
					notify();
					current = max;
					exchange = true;
				}
			} while (exchange);
		}
	}

}