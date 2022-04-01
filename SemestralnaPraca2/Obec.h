#pragma once
namespace structures 
{
	class Obec
	{
	public:
		Obec(int PredprodObyv, int ProdObyv, int PoprodObyv, double vymera, double ZastavPlocha);
		int getPredprodObyv();
		int getProdObyv();
		int getPoprodObyv();
		double getVymera();
		double getZastavPlocha();
		~Obec();

	private:
		int PredprodObyv_;
		int ProdObyv_;
		int PoprodObyv_;
		double Vymera_;
		double ZastavPlocha_;
	};

	inline Obec::Obec(int PredprodObyv, int ProdObyv, int PoprodObyv, double vymera, double ZastavPlocha)
	{
		PredprodObyv_ = PredprodObyv;
		ProdObyv_ = ProdObyv;
		PoprodObyv_ = PoprodObyv;
		Vymera_ = vymera;
		ZastavPlocha_ = ZastavPlocha;
	}

	inline int Obec::getPredprodObyv()
	{
		return PredprodObyv_;
	}

	inline int Obec::getProdObyv()
	{
		return ProdObyv_;
	}

	inline int Obec::getPoprodObyv()
	{
		return PoprodObyv_;
	}

	inline double Obec::getVymera()
	{
		return Vymera_;
	}

	inline double Obec::getZastavPlocha()
	{
		return ZastavPlocha_;
	}

	Obec::~Obec()
	{
		PredprodObyv_ = 0;
		ProdObyv_ = 0;
		PoprodObyv_ = 0;
		Vymera_ = 0;
		ZastavPlocha_ = 0;
	}
}