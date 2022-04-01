#pragma once
#include "Kriterium.h"
#include "UzemnaJednotka.h"

namespace structures
{
	class KriteriumUJPocetPoprodObyv : public Kriterium<int, UzemnaJednotka>
	{
	private:
		int spolu;
	public:
		int ohodnot(UzemnaJednotka* jednotka) override;
		void spocitaj(UzemnaJednotka* jednotka);
	};

	int KriteriumUJPocetPoprodObyv::ohodnot(UzemnaJednotka* jednotka)
	{
		spolu = 0;
		spocitaj(jednotka);
		return spolu;
	}
	inline void KriteriumUJPocetPoprodObyv::spocitaj(UzemnaJednotka* jednotka)
	{

		if (jednotka->getTyp() == TypUJ::OBEC)
		{
			spolu += jednotka->getData()->getPoprodObyv();
		}
		else
		{
			for (auto uj : *jednotka->getPodradeneUJ())
			{
				spocitaj(uj->accessData());
			}
		}
	}
}