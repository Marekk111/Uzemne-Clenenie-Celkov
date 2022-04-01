#pragma once
#include "table/unsorted_sequence_table.h"
#include "Kriterium.h"
namespace structures
{
	template <typename K, typename T, typename O>
	class Sort
	{
	public:
		virtual void sort(UnsortedSequenceTable<K, O*>* tabulka, Kriterium<T, O>* kriterium, bool vzostupne) = 0;
	};
}
