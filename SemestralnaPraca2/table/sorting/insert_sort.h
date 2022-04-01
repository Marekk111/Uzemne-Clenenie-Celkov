#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"

namespace structures
{

	/// <summary> Triedenie Insert sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class InsertSort : public Sort<K, T>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Insert sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
	};

	template<typename K, typename T>
	inline void InsertSort<K, T>::sort(UnsortedSequenceTable<K, T>& table)
	{
		int j;
		for (int i = 0; i < table.size() - 1; i++)
		{
			j = 0;
			if (j < i && table.getItemAtIndex(j).getKey() < table.getItemAtIndex(i).getKey())
			{
				j++;
			}
			table.insert(i, j);
			notify();
		}
	}

}