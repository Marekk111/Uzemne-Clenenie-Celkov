#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include "UzemneJednotky.h"
namespace structures 
{
	class Nacitanie
	{
	public:
		Nacitanie(std::string subor1, std::string subor2);
		void Nacitaj(UzemneJednotky* strom);
		~Nacitanie();

	private:
		std::ifstream subor1_;
		std::ifstream subor2_;
	};

	inline Nacitanie::Nacitanie(std::string subor1, std::string subor2)
	{
		subor1_.open(subor1);
		subor2_.open(subor2);
	}

	inline void Nacitanie::Nacitaj(UzemneJednotky* strom)
	{
		std::string riadok1;
		std::string riadok2;
		std::string slovo1;
		std::string slovo2;

		std::string kraj;
		std::string okres;
		std::string obec;
		
		Obec* data;

		int predprod;
		int prod;
		int poprod;
		double vymera;
		double zastavana;

		getline(subor1_, riadok1);
		getline(subor2_, riadok2);

		while (getline(subor1_, riadok1))
		{
			getline(subor2_, riadok2);
			std::stringstream riadokStream1(riadok1);
			std::stringstream riadokStream2(riadok2);
			std::getline(riadokStream1, slovo1, ';');
			obec = slovo1;
			std::getline(riadokStream1, slovo1, ';');
			okres = slovo1;
			std::getline(riadokStream1, slovo1, ';');
			kraj = slovo1;

			std::getline(riadokStream2, slovo2, ';');
			std::getline(riadokStream2, slovo2, ';');
			predprod = stoi(slovo2);
			std::getline(riadokStream2, slovo2, ';');
			prod = stoi(slovo2);
			std::getline(riadokStream2, slovo2, ';');
			poprod = stoi(slovo2);
			std::getline(riadokStream2, slovo2, ';');
			vymera = stod(slovo2);
			std::getline(riadokStream2, slovo2, ';');
			zastavana= stod(slovo2);


			data = new Obec(predprod, prod, poprod, vymera, zastavana);

			strom->Pridaj(kraj, okres, obec, data);
		}
	}

	inline Nacitanie::~Nacitanie()
	{
		subor1_.close();
		subor2_.close();
	}
}