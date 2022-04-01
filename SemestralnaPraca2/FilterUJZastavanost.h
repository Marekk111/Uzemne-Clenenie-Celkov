#pragma once
#include "FilterInterval.h"
#include "KriteriumUJZastavanost.h"
namespace structures
{
	template <typename K>
	class FilterUJZastavanost : public FilterInterval<K, double, UzemnaJednotka>
	{
	public:
		FilterUJZastavanost(double min, double max);

	};
	template<typename K>
	inline FilterUJZastavanost<K>::FilterUJZastavanost(double min, double max) : FilterInterval<K, double, UzemnaJednotka>
		(new KriteriumUJZastavanost(), min, max)
	{
	}
}