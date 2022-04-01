#pragma once
#include "UzemneJednotky.h"
#include "KriteriumUJPocetObyv.h"
#include "KriteriumUJPocetPredprodObyv.h"
#include "KriteriumUJPocetProdObyv.h"
#include "KriteriumUJPocetPoprodObyv.h"
#include "KriteriumUJCelkovaVymera.h"
#include "KriteriumUJZastavanaPlocha.h"
#include "KriteriumUJZastavanost.h"
#include "table/sorted_sequence_table.h"
#include "Nacitanie.h"
#include "FilterUJNazov.h"
#include "FilterUJTyp.h"
#include "FilterUJPrislusnost.h"
#include "FilterUJPocetObyv.h"
#include "FilterUJZastavanost.h"
#include "QuickSort.h"

namespace structures
{
	class Funkcionalita
	{
	public:
		Funkcionalita(std::string nazovSuboru1, std::string nazovSuboru2);
		void cli();
		void SpustiFilterUJNazov(Table<std::string, UzemnaJednotka*>* tabulka, std::string nazov);
		void SpustiFilterUJTyp(Table<std::string, UzemnaJednotka*>* tabulka, TypUJ typ);
		void SpustiFilterUJPrislusnost(Table<std::string, UzemnaJednotka*>* tabulka, bool patri, UzemnaJednotka* nadradena);
		void SpustiFilterUJZastavanost(Table<std::string, UzemnaJednotka*>* tabulka, double min, double max);
		void SpustiFilterUJPocetObyv(Table<std::string, UzemnaJednotka*>* tabulka, int min, int max);
		void vypis(Table<std::string, UzemnaJednotka*>* tabulka);
		~Funkcionalita();

	private:
		UzemneJednotky* UzemneJednotky_;
		UnsortedSequenceTable<std::string, UzemnaJednotka*>* UzemneJednotkyUnsorted_;
	};

	Funkcionalita::Funkcionalita(std::string nazovSuboru1, std::string nazovSuboru2)
	{
		UzemneJednotky_ = new UzemneJednotky();
		Nacitanie nacitanie(nazovSuboru1, nazovSuboru2);
		nacitanie.Nacitaj(UzemneJednotky_);
		UzemneJednotkyUnsorted_ = new UnsortedSequenceTable<std::string, UzemnaJednotka*>(*UzemneJednotky_->getVsetkyUzemneJednotky());
	}

	inline void Funkcionalita::cli()
	{
		std::cout << "Vyberte, èi chcete filtrova alebo triedi. 1 - filtrovanie 2 - triedenie" << std::endl;
		int funkcionalita;
		std::cin >> funkcionalita;
		while (funkcionalita != 1 && funkcionalita != 2)
		{
			std::cout << "Zadali ste zlý input, zadajte ho znova." << std::endl;
			std::cin >> funkcionalita;
		}
		if (funkcionalita == 1)
		{
			std::cout << "Chcete použi filter na príslušnos? 'Y' - áno 'N' - nie" << std::endl;
			std::string odpovedPrislusnost;
			std::cin >> odpovedPrislusnost;
			while (odpovedPrislusnost != "Y" && odpovedPrislusnost != "N")
			{
				std::cout << "Zadali ste zlý input, zadajte ho znova." << std::endl;
				std::cin >> odpovedPrislusnost;
			}
			if (odpovedPrislusnost == "Y")
			{
				std::cout << "Zadajte meno Územnej Jednotky, ktorá bude nadradená." << std::endl;
				std::string nazovNadradenaUJ;
				std::getline(std::cin, nazovNadradenaUJ);
				std::getline(std::cin, nazovNadradenaUJ);
				UzemnaJednotka* NadradenaUJ_;
				while (!UzemneJednotky_->getVsetkyUzemneJednotky()->tryFind(nazovNadradenaUJ, NadradenaUJ_))
				{
					std::cout << "Taká územná jednotka neexistuje." << std::endl;
					std::getline(std::cin, nazovNadradenaUJ);
				}
				std::cout << "Zadajte èi chcete pracova s Územnými jednotkami, ktoré do nej patria alebo nepatria" << std::endl;
				std::cout << "Možnosti: 1 - patria		0 - nepatria" << std::endl;
				int patria;
				std::cin >> patria;
				while (patria != 1 && patria != 0)
				{
					std::cout << "Zadali ste zlý input, zadajte ho znova." << std::endl;
					std::cin >> patria;
				}
				if (patria == 1)
				{
					SpustiFilterUJPrislusnost(UzemneJednotky_->getVsetkyUzemneJednotky(), true, NadradenaUJ_);
				}
				else
				{
					SpustiFilterUJPrislusnost(UzemneJednotky_->getVsetkyUzemneJednotky(), false, NadradenaUJ_);
				}

			}
			std::cout << "Ktorý typ územnej jednotky chcete filtrova?" << std::endl;
			std::cout << "Možnosti: 1 - OBEC, 2 - OKRES, 3 - KRAJ, 4 - KRAJINA" << std::endl;
			int typ_;
			TypUJ typ_enum;
			std::cin >> typ_;
			while (typ_ != 1 && typ_ != 2 && typ_ != 3 && typ_ != 4)
			{
				std::cout << "Zlý input, zadajte ho znova." << std::endl;
				std::cin >> typ_;
			}
			switch (typ_)
			{
			case 1:
				typ_enum = TypUJ::OBEC;
				break;
			case 2:
				typ_enum = TypUJ::OKRES;
				break;
			case 3:
				typ_enum = TypUJ::KRAJ;
				break;
			case 4:
				typ_enum = TypUJ::KRAJINA;
				break;
			default:
				break;
			}
			SpustiFilterUJTyp(UzemneJednotky_->getVsetkyUzemneJednotky(), typ_enum);

			std::cout << "Ktorý filter chcete zvoli ako posledný?" << std::endl;
			std::cout << "Možnosti: A - Filter pod¾a názvu, B - Filter pod¾a poètu obyvate¾ov, C - Filter pod¾a zastavanosti." << std::endl;
			std::string poslednyFilter;
			std::cin >> poslednyFilter;
			while (poslednyFilter != "A" && poslednyFilter != "B" && poslednyFilter != "C")
			{
				std::cout << "Zlý input, zadajte ho znova." << std::endl;
				std::cin >> poslednyFilter;
			}
			if (poslednyFilter == "A")
			{
				std::cout << "Zadajte názov, pod¾a ktorého sa bude filtrova." << std::endl;
				std::string nazov;
				std::getline(std::cin, nazov);
				std::getline(std::cin, nazov);
				SpustiFilterUJNazov(UzemneJednotky_->getVsetkyUzemneJednotky(), nazov);
			}
			if (poslednyFilter == "B")
			{
				std::cout << "Zadajte interval poètu obyvate¾ov." << std::endl;
				std::cout << "Min:" << std::endl;
				int min;
				std::cin >> min;
				std::cout << "Max:" << std::endl;
				int max;
				std::cin >> max;
				SpustiFilterUJPocetObyv(UzemneJednotky_->getVsetkyUzemneJednotky(), min, max);
			}
			if (poslednyFilter == "C")
			{
				std::cout << "Zadajte interval zastavanosti v percentách." << std::endl;
				std::cout << "Min:" << std::endl;
				double min;
				std::cin >> min;
				std::cout << "Max:" << std::endl;
				double max;
				std::cin >> max;
				SpustiFilterUJZastavanost(UzemneJednotky_->getVsetkyUzemneJednotky(), min, max);
			}
			vypis(UzemneJednotky_->getVsetkyUzemneJednotky());
		}
		if (funkcionalita == 2)
		{
			std::cout << "Chcete použi filter na príslušnos? 'Y' - áno 'N' - nie" << std::endl;
			std::string odpovedPrislusnost;
			std::cin >> odpovedPrislusnost;
			while (odpovedPrislusnost != "Y" && odpovedPrislusnost != "N")
			{
				std::cout << "Zadali ste zlý input, zadajte ho znova." << std::endl;
				std::cin >> odpovedPrislusnost;
			}
			if (odpovedPrislusnost == "Y")
			{
				std::cout << "Zadajte meno Územnej Jednotky, ktorá bude nadradená." << std::endl;
				std::string nazovNadradenaUJ;
				std::getline(std::cin, nazovNadradenaUJ);
				std::getline(std::cin, nazovNadradenaUJ);
				UzemnaJednotka* NadradenaUJ_;
				while (!UzemneJednotky_->getVsetkyUzemneJednotky()->tryFind(nazovNadradenaUJ, NadradenaUJ_))
				{
					std::cout << "Taká územná jednotka neexistuje." << std::endl;
					std::getline(std::cin, nazovNadradenaUJ);
				}
				std::cout << "Zadajte èi chcete pracova s Územnými jednotkami, ktoré do nej patria alebo nepatria" << std::endl;
				std::cout << "Možnosti: 1 - patria		0 - nepatria" << std::endl;
				int patria;
				std::cin >> patria;
				while (patria != 1 && patria != 0)
				{
					std::cout << "Zadali ste zlý input, zadajte ho znova." << std::endl;
					std::cin >> patria;
				}
				if (patria == 1)
				{
					SpustiFilterUJPrislusnost(UzemneJednotkyUnsorted_, true, NadradenaUJ_);
				}
				else
				{
					SpustiFilterUJPrislusnost(UzemneJednotkyUnsorted_, false, NadradenaUJ_);
				}

			}
			std::cout << "Ktorý typ územnej jednotky chcete zoraïova?" << std::endl;
			std::cout << "Možnosti: 1 - OBEC, 2 - OKRES, 3 - KRAJ, 4 - KRAJINA" << std::endl;
			int typ_;
			TypUJ typ_enum;
			std::cin >> typ_;
			while (typ_ != 1 && typ_ != 2 && typ_ != 3 && typ_ != 4)
			{
				std::cout << "Zlý input, zadajte ho znova." << std::endl;
				std::cin >> typ_;
			}
			switch (typ_)
			{
			case 1:
				typ_enum = TypUJ::OBEC;
				break;
			case 2:
				typ_enum = TypUJ::OKRES;
				break;
			case 3:
				typ_enum = TypUJ::KRAJ;
				break;
			case 4:
				typ_enum = TypUJ::KRAJINA;
				break;
			default:
				break;
			}
			SpustiFilterUJTyp(UzemneJednotkyUnsorted_, typ_enum);

			std::cout << "Pod¾a ktorého kritéria chcete zoraïova?" << std::endl;
			std::cout << "Možnosti: A - pod¾a názvu, B - pod¾a poètu obyvate¾ov, C - pod¾a zastavanosti." << std::endl;
			std::string sort;
			std::cin >> sort;
			while (sort != "A" && sort != "B" && sort != "C")
			{
				std::cout << "Zlý input, zadajte ho znova." << std::endl;
				std::cin >> sort;
			}
			if (sort == "A")
			{
				QuickSort<std::string, std::string, UzemnaJednotka> sort_;
				KriteriumUJNazov* kriterium_ = new KriteriumUJNazov();
				std::cout << "Chcete triedi vzostupne(1) alebo zostupne(2) ?" << std::endl;
				int smer;
				std::cin >> smer;
				while (smer != 1  && smer != 2)
				{
					std::cout << "Zlý input, skúste znova." << std::endl;
					std::cin >> smer;
				}
				if (smer == 1)
				{
					sort_.sort(UzemneJednotkyUnsorted_, kriterium_, true);
				}
				if (smer == 2)
				{
					sort_.sort(UzemneJednotkyUnsorted_, kriterium_, false);
				}
				delete kriterium_;
			}
			if (sort == "B")
			{
				QuickSort<std::string, int, UzemnaJednotka> sort_;
				KriteriumUJPocetObyv* kriterium_ = new KriteriumUJPocetObyv();
				std::cout << "Chcete triedi vzostupne(1) alebo zostupne(2) ?" << std::endl;
				int smer;
				std::cin >> smer;
				while (smer != 1 && smer != 2)
				{
					std::cout << "Zlý input, skúste znova." << std::endl;
					std::cin >> smer;
				}
				if (smer == 1)
				{
					sort_.sort(UzemneJednotkyUnsorted_, kriterium_, true);
				}
				if (smer == 2)
				{
					sort_.sort(UzemneJednotkyUnsorted_, kriterium_, false);
				}
				delete kriterium_;
			}
			if (sort == "C")
			{
				QuickSort<std::string, double, UzemnaJednotka> sort_;
				KriteriumUJZastavanost* kriterium_ = new KriteriumUJZastavanost();
				std::cout << "Chcete triedi vzostupne(1) alebo zostupne(2) ?" << std::endl;
				int smer;
				std::cin >> smer;
				while (smer != 1 && smer != 2)
				{
					std::cout << "Zlý input, skúste znova." << std::endl;
					std::cin >> smer;
				}
				if (smer == 1)
				{
					sort_.sort(UzemneJednotkyUnsorted_, kriterium_, true);
				}
				if (smer == 2)
				{
					sort_.sort(UzemneJednotkyUnsorted_, kriterium_, false);
				}
				delete kriterium_;
			}
			vypis(UzemneJednotkyUnsorted_);
		}
	}

	inline void Funkcionalita::SpustiFilterUJNazov(Table<std::string, UzemnaJednotka*>* tabulka, std::string nazov)
	{
		FilterUJNazov<std::string> filter(nazov);
		Table<std::string, UzemnaJednotka*>* tabulka_ = tabulka;
		tabulka_ = filter.vyfiltrujTabulku(tabulka_);
		*tabulka = *tabulka_;
		delete tabulka_;
	}

	inline void Funkcionalita::SpustiFilterUJTyp(Table<std::string, UzemnaJednotka*>* tabulka, TypUJ typ)
	{
		FilterUJTyp<std::string> filter(typ);
		Table<std::string, UzemnaJednotka*>* tabulka_ = tabulka;
		tabulka_ = filter.vyfiltrujTabulku(tabulka_);
		*tabulka = *tabulka_;
		delete tabulka_;
	}

	inline void Funkcionalita::SpustiFilterUJPrislusnost(Table<std::string, UzemnaJednotka*>* tabulka, bool patri, UzemnaJednotka* nadradena)
	{
		FilterUJPrislusnost<std::string> filter(patri, nadradena);
		Table<std::string, UzemnaJednotka*>* tabulka_ = tabulka;
		tabulka_ = filter.vyfiltrujTabulku(tabulka_);
		*tabulka = *tabulka_;
		delete tabulka_;
	}

	inline void Funkcionalita::vypis(Table<std::string, UzemnaJednotka*>* tabulka)
	{
		UzemnaJednotka* pomocna;
		for (auto UJ : *tabulka)
		{
			pomocna = UJ->accessData();
			std::cout << KriteriumUJNazov().ohodnot(pomocna) << " < ";
			while (pomocna->getNadradenuUJ() != nullptr)
			{
				pomocna = pomocna->getNadradenuUJ();
				if (pomocna->getTyp() == TypUJ::KRAJINA)
				{
					std::cout << KriteriumUJNazov().ohodnot(pomocna);
				}
				else
				{
					std::cout << KriteriumUJNazov().ohodnot(pomocna) << " < ";

				}
			}
			std::cout << std::endl;
			std::cout << "Pocet obyvatelov: " << KriteriumUJPocetObyv().ohodnot(UJ->accessData()) << std::endl;
			std::cout << "Pocet predproduktivnych obyvatelov: " << KriteriumUJPocetPredprodObyv().ohodnot(UJ->accessData()) << std::endl;
			std::cout << "Pocet produktivnych obyvatelov: " << KriteriumUJPocetProdObyv().ohodnot(UJ->accessData()) << std::endl;
			std::cout << "Pocet poproduktivnych obyvatelov: " << KriteriumUJPocetPoprodObyv().ohodnot(UJ->accessData()) << std::endl;
			std::cout << "Zastavanost: " << KriteriumUJZastavanost().ohodnot(UJ->accessData()) << " %" << std::endl;
			std::cout << "Celkova vymera: " << KriteriumUJCelkovaVymera().ohodnot(UJ->accessData()) << " m2" << std::endl;
			std::cout << "Zastavana plocha: " << KriteriumUJZastavanaPlocha().ohodnot(UJ->accessData()) << " m2" << std::endl;
			std::cout << std::endl;
		}
	}

	void Funkcionalita::SpustiFilterUJZastavanost(Table<std::string, UzemnaJednotka*>* tabulka, double min, double max)
	{
		FilterUJZastavanost<std::string> filter(min, max);
		Table<std::string, UzemnaJednotka*>* tabulka_ = tabulka;
		tabulka_ = filter.vyfiltrujTabulku(tabulka_);
		*tabulka = *tabulka_;
		delete tabulka_;
	}

	void Funkcionalita::SpustiFilterUJPocetObyv(Table<std::string, UzemnaJednotka*>* tabulka, int min, int max)
	{
		FilterUJPocetObyv<std::string> filter(min, max);
		Table<std::string, UzemnaJednotka*>* tabulka_ = tabulka;
		tabulka_ = filter.vyfiltrujTabulku(tabulka_);
		*tabulka = *tabulka_;
		delete tabulka_;
	}

	inline Funkcionalita::~Funkcionalita()
	{
		delete UzemneJednotky_;
		delete UzemneJednotkyUnsorted_;
	}
	
}