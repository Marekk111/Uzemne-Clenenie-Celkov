#pragma once
#include "Kriterium.h"
#include "UzemnaJednotka.h"
namespace structures
{
	class KriteriumUJZastavanaPlocha : public Kriterium<double, UzemnaJednotka>
	{
	public:
		double ohodnot(UzemnaJednotka* jednotka) override;
		void spocitaj(UzemnaJednotka* jednotka);
	private:
		double spolu;
	};
	double KriteriumUJZastavanaPlocha::ohodnot(UzemnaJednotka* jednotka)
	{
		spolu = 0;
		spocitaj(jednotka);
		return spolu;
	}
	inline void KriteriumUJZastavanaPlocha::spocitaj(UzemnaJednotka* jednotka)
	{

		if (jednotka->getTyp() == TypUJ::OBEC)
		{
			spolu += jednotka->getData()->getZastavPlocha();
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