#pragma once
#include "FilterHodnota.h"
#include "KriteriumUJPrislusnost.h"
namespace structures
{
	template <typename K>
	class FilterUJPrislusnost: public FilterHodnota<K, bool, UzemnaJednotka>
	{
	public:
		FilterUJPrislusnost(bool patri, UzemnaJednotka* nadradenaUJ);

	};
	template<typename K>
	inline FilterUJPrislusnost<K>::FilterUJPrislusnost(bool patri, UzemnaJednotka* nadradenaUJ) : FilterHodnota<K, bool, UzemnaJednotka>
		(new KriteriumUJPrislusnost(nadradenaUJ), patri)
	{
	}
}