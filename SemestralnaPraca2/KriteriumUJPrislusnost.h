#pragma once
#include "Kriterium.h"
#include "UzemnaJednotka.h"

namespace structures
{
	class KriteriumUJPrislusnost : public Kriterium<bool, UzemnaJednotka>
	{
	private:
		UzemnaJednotka* nadradenaUJ_;
	public:
		KriteriumUJPrislusnost(UzemnaJednotka* nadradenaUJ);
		bool ohodnot(UzemnaJednotka* jednotka) override;
	};

	inline KriteriumUJPrislusnost::KriteriumUJPrislusnost(UzemnaJednotka* nadradenaUJ)
	{
		nadradenaUJ_ = nadradenaUJ;
	}

	bool KriteriumUJPrislusnost::ohodnot(UzemnaJednotka* jednotka)
	{
		while ((jednotka = jednotka->getNadradenuUJ()) != nullptr)
		{
			if (jednotka == nadradenaUJ_)
			{
				return true;
			}
		}
		return false;
	}
}