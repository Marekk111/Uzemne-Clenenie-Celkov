#pragma once
#include "Kriterium.h"
#include "Filter.h"
namespace structures 
{
	template <typename K, typename T, typename O>
	class FilterHodnota : public Filter<K,T,O>
	{
	public:
		FilterHodnota(Kriterium<T,O>* kriterium, T hodnota);
		bool splnaFilter(O* objekt) override;

	private:
		T hodnota_;
	};

	template<typename K, typename T, typename O>
	inline FilterHodnota<K, T, O>::FilterHodnota(Kriterium<T, O>* kriterium, T hodnota) : Filter<K,T,O>(kriterium)
	{
		hodnota_ = hodnota;
	}

	template<typename K, typename T, typename O>
	inline bool FilterHodnota<K, T, O>::splnaFilter(O* objekt)
	{
		return hodnota_ == this->kriterium_->ohodnot(objekt);
	}
}