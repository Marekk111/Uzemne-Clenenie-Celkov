#pragma once
#include "Kriterium.h"
#include "Filter.h"
namespace structures
{
	template <typename K, typename T, typename O>
	class FilterInterval : public Filter<K, T, O>
	{
	public:
		FilterInterval(Kriterium<T, O>* kriterium, T min, T max);
		bool splnaFilter(O* objekt) override;

	private:
		T min_ = 0;
		T max_ = 0;
	};

	template<typename K, typename T, typename O>
	inline FilterInterval<K, T, O>::FilterInterval(Kriterium<T, O>* kriterium, T min, T max) : Filter<K, T, O>(kriterium)
	{
		min_ = min;
		max_ = max;
	}

	template<typename K, typename T, typename O>
	inline bool FilterInterval<K, T, O>::splnaFilter(O* objekt)
	{
		T hodnota = this->kriterium_->ohodnot(objekt);
		return min_ <= hodnota && hodnota <= max_;
	}
}