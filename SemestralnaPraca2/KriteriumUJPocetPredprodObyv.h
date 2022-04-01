#pragma once
#include "Kriterium.h"
#include "UzemnaJednotka.h"

namespace structures
{
	class KriteriumUJPocetPredprodObyv : public Kriterium<int, UzemnaJednotka>
	{
	private:
		int spolu;
	public:
		int ohodnot(UzemnaJednotka* jednotka) override;
		void spocitaj(UzemnaJednotka* jednotka);
	};

	int KriteriumUJPocetPredprodObyv::ohodnot(UzemnaJednotka* jednotka)
	{
		spolu = 0;
		spocitaj(jednotka);
		return spolu;
	}
	inline void KriteriumUJPocetPredprodObyv::spocitaj(UzemnaJednotka* jednotka)
	{

		if (jednotka->getTyp() == TypUJ::OBEC)
		{
			spolu += jednotka->getData()->getPredprodObyv();
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