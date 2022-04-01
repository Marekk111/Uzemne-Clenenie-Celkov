#pragma once
#include "FilterHodnota.h"
#include "KriteriumUJNazov.h"
namespace structures
{
	template <typename K>
	class FilterUJNazov : public FilterHodnota<K, std::string, UzemnaJednotka>
	{
	public:
		FilterUJNazov(std::string nazov);

	};
	template<typename K>
	inline FilterUJNazov<K>::FilterUJNazov(std::string nazov) : FilterHodnota<K, std::string, UzemnaJednotka>
		(new KriteriumUJNazov(), nazov)
	{
	}
}
