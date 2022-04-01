#pragma once
#include "Kriterium.h"
#include "UzemnaJednotka.h"

namespace structures
{
	class KriteriumUJPocetObyv : public Kriterium<int, UzemnaJednotka>
	{
	private:
		int spolu;
	public:
		int ohodnot(UzemnaJednotka* jednotka) override;
		void spocitaj(UzemnaJednotka* jednotka);
	};

	int KriteriumUJPocetObyv::ohodnot(UzemnaJednotka* jednotka)
	{
		spolu = 0;
		spocitaj(jednotka);
		return spolu;
	}
	inline void KriteriumUJPocetObyv::spocitaj(UzemnaJednotka* jednotka)
	{

		if (jednotka->getTyp() == TypUJ::OBEC)
		{
			spolu += jednotka->getData()->getPoprodObyv();
			spolu += jednotka->getData()->getPredprodObyv();
			spolu += jednotka->getData()->getProdObyv();
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
