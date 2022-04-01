#pragma once
#include "Kriterium.h"
#include "table/sorted_sequence_table.h"
namespace structures 
{
	template <typename K, typename T, typename O> //K -> kluc v tabulke, T -> navratova hodnota kriteria, O -> objekt kriteria
		class Filter
	{
	public:
		
		Table<K, O*>* vyfiltrujTabulku(Table<K, O*	>* tabulka);
		virtual bool splnaFilter(O* objekt) = 0;
		~Filter();

	protected:
		Filter(Kriterium<T, O>* kriterium);
		Kriterium<T, O>* kriterium_;
	};

	template<typename K, typename T, typename O>
	inline Filter<K, T, O>::Filter(Kriterium<T, O>* kriterium)
	{
		kriterium_ = kriterium;
	}

	template<typename K, typename T, typename O>
	inline Table<K, O*>* Filter<K, T, O>::vyfiltrujTabulku(Table<K, O*>* tabulka)
	{
		Table<K, O*>* vysledok = new SortedSequenceTable<K, O*>();
		for (auto jednotka : *tabulka)
		{
			if (splnaFilter(jednotka->accessData()))
			{
				vysledok->insert(jednotka->getKey(), jednotka->accessData());
			}
		}
		return vysledok;
	}

	template<typename K, typename T, typename O>
	Filter<K,T,O>::~Filter()
	{
		delete kriterium_;
	}
}
