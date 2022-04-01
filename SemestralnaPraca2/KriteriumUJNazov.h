#pragma once
#include "Kriterium.h"
#include "UzemnaJednotka.h"

namespace structures
{
	class KriteriumUJNazov : public Kriterium<std::string, UzemnaJednotka>
	{
	public:
		std::string ohodnot(UzemnaJednotka* jednotka) override;
	};
	
	std::string KriteriumUJNazov::ohodnot(UzemnaJednotka* jednotka) 
	{
		
		return jednotka->getNazov();
	}
}