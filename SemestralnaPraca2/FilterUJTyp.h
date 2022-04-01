#pragma once
#include "FilterHodnota.h"
#include "KriteriumUJTyp.h"
namespace structures
{
	template <typename K>
	class FilterUJTyp : public FilterHodnota<K, TypUJ, UzemnaJednotka>
	{
	public:
		FilterUJTyp(TypUJ typ);

	};
	template<typename K>
	inline FilterUJTyp<K>::FilterUJTyp(TypUJ typ) : FilterHodnota<K, TypUJ, UzemnaJednotka>
		(new KriteriumUJTyp(), typ)
	{
	}
}