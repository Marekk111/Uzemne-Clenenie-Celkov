#pragma once
#include "Kriterium.h"
#include "UzemnaJednotka.h"

namespace structures
{
	class KriteriumUJTyp : public Kriterium<TypUJ, UzemnaJednotka>
	{
	public:
		TypUJ ohodnot(UzemnaJednotka* jednotka) override;
	};

	TypUJ KriteriumUJTyp::ohodnot(UzemnaJednotka* jednotka)
	{

		return jednotka->getTyp();
	}
}