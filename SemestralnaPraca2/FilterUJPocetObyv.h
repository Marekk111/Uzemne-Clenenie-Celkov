#pragma once
#include "FilterInterval.h"
#include "KriteriumUJPocetObyv.h"
namespace structures
{
	template <typename K>
	class FilterUJPocetObyv : public FilterInterval<K, int, UzemnaJednotka>
	{
	public:
		FilterUJPocetObyv(int min, int max);

	};
	template<typename K>
	inline FilterUJPocetObyv<K>::FilterUJPocetObyv(int min, int max) : 
	FilterInterval<K, int, UzemnaJednotka>(new KriteriumUJPocetObyv(), min, max)
	{
	}
}