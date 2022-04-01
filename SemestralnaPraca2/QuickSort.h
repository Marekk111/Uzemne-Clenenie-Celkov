#pragma once
#include "Sort.h"

namespace structures
{
	template <typename K, typename T, typename O>
	class QuickSort : public Sort<K,T,O>
	{
	public:
		void sort(UnsortedSequenceTable<K, O*>* tabulka, Kriterium<T, O>* kriterium, bool vzostupne) override;
		void quick(int min, int max, bool vzostupne);

	private:
		UnsortedSequenceTable<K, O*>* tabulka_;
		Kriterium<T, O>* kriterium_;
	};
	template<typename K, typename T, typename O>
	inline void QuickSort<K, T, O>::sort(UnsortedSequenceTable<K, O*>* tabulka, Kriterium<T, O>* kriterium, bool vzostupne)
	{
		tabulka_ = tabulka;
		kriterium_ = kriterium;
		quick(0, tabulka_->size() - 1, vzostupne);
	}

	template<typename K, typename T, typename O>
	inline void QuickSort<K, T, O>::quick(int min, int max, bool vzostupne)
	{
		T pivot = kriterium_->ohodnot(tabulka_->getItemAtIndex((min + max) / 2).accessData());
		int lavy = min;
		int pravy = max;
		do
		{
			if (!vzostupne)
			{
				while (kriterium_->ohodnot(tabulka_->getItemAtIndex(lavy).accessData()) > pivot)
				{
					lavy++;
				}
				while (kriterium_->ohodnot(tabulka_->getItemAtIndex(pravy).accessData()) < pivot)
				{
					pravy--;
				}
			}
			else
			{
				while (kriterium_->ohodnot(tabulka_->getItemAtIndex(lavy).accessData()) < pivot)
				{
					lavy++;
				}
				while (kriterium_->ohodnot(tabulka_->getItemAtIndex(pravy).accessData()) > pivot)
				{
					pravy--;
				}
			}
			
			if (lavy <= pravy)
			{
				tabulka_->swap(lavy, pravy);
				lavy++;
				pravy--;
			}
		} while (lavy <= pravy);
		if (min < pravy)
		{
			quick(min, pravy, vzostupne);
		}
		if (lavy < max)
		{
			quick(lavy, max, vzostupne);
		}
	}
}