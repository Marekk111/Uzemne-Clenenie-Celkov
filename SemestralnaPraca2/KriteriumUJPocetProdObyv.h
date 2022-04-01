#pragma once
#include "Kriterium.h"
#include "UzemnaJednotka.h"

namespace structures
{
	class KriteriumUJPocetProdObyv : public Kriterium<int, UzemnaJednotka>
	{
	private:
		int spolu;
	public:
		int ohodnot(UzemnaJednotka* jednotka) override;
		void spocitaj(UzemnaJednotka* jednotka);
	};

	int KriteriumUJPocetProdObyv::ohodnot(UzemnaJednotka* jednotka)
	{
		spolu = 0;
		spocitaj(jednotka);
		return spolu;
	}
	inline void KriteriumUJPocetProdObyv::spocitaj(UzemnaJednotka* jednotka)
	{
		if (jednotka->getTyp() == TypUJ::OBEC)
		{
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