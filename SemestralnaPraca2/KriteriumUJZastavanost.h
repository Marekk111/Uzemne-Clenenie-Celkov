#pragma once
#include "Kriterium.h"
#include "UzemnaJednotka.h"
namespace structures
{
	class KriteriumUJZastavanost : public Kriterium<double, UzemnaJednotka>
	{
	public:
		double ohodnot(UzemnaJednotka* jednotka) override;
		void spocitaj(UzemnaJednotka* jednotka);
	private:
		double vymera;
		double zastavanaPlocha;
	};
	double KriteriumUJZastavanost::ohodnot(UzemnaJednotka* jednotka)
	{
		vymera = 0;
		zastavanaPlocha = 0;
		spocitaj(jednotka);
		return (zastavanaPlocha / vymera) * 100;
	}
	inline void KriteriumUJZastavanost::spocitaj(UzemnaJednotka* jednotka)
	{

		if (jednotka->getTyp() == TypUJ::OBEC)
		{
			vymera += jednotka->getData()->getVymera();
			zastavanaPlocha += jednotka->getData()->getZastavPlocha();
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