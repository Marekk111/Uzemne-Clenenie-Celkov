#pragma once
#include <string>
#include "../SemestralnaPraca2/table/sorted_sequence_table.h"
#include "TypUJ.h"
#include "Obec.h"
namespace structures 
{
	class UzemnaJednotka
	{
	public:
		UzemnaJednotka(std::string nazov, TypUJ typ, UzemnaJednotka* nadradenaUJ, Obec* data);
		std::string getNazov();
		TypUJ getTyp();
		UzemnaJednotka* getNadradenuUJ();
		UzemnaJednotka* pridajPodradenuUJ(UzemnaJednotka* jednotka, Table<std::string, UzemnaJednotka*>* tabulka);
		SortedSequenceTable<std::string, UzemnaJednotka*>* getPodradeneUJ();
		Obec* getData();
		~UzemnaJednotka();

	private:
		std::string nazov_;
		TypUJ typ_;
		UzemnaJednotka* nadradenaUJ_;
		SortedSequenceTable<std::string, UzemnaJednotka*>* podradeneUJ_;
		Obec* data_;
	};

	inline UzemnaJednotka::UzemnaJednotka(std::string nazov, TypUJ typ, UzemnaJednotka* nadradenaUJ, Obec* data)
	{
		nazov_ = nazov;
		typ_ = typ;
		nadradenaUJ_ = nadradenaUJ;
		podradeneUJ_ = new SortedSequenceTable<std::string, UzemnaJednotka*>;
		data_ = data;
	}

	inline std::string UzemnaJednotka::getNazov()
	{
		return nazov_;
	}

	inline TypUJ UzemnaJednotka::getTyp()
	{
		return typ_;
	}

	inline UzemnaJednotka* UzemnaJednotka::getNadradenuUJ()
	{
		return nadradenaUJ_;
	}

	inline UzemnaJednotka* UzemnaJednotka::pridajPodradenuUJ(UzemnaJednotka* jednotka, Table<std::string, UzemnaJednotka*>* tabulka)
	{
		UzemnaJednotka* UJ;
		if (podradeneUJ_->tryFind(jednotka->getNazov(), UJ))
		{
			delete jednotka;
		}
		else
		{
			UJ = jednotka;
			podradeneUJ_->insert(UJ->getNazov(), UJ);
			tabulka->insert(UJ->getNazov(), UJ);
		}
		return UJ;
	}

	inline SortedSequenceTable<std::string, UzemnaJednotka*>* UzemnaJednotka::getPodradeneUJ()
	{
		return podradeneUJ_;
	}

	inline Obec* UzemnaJednotka::getData()
	{
		return data_;
	}

	inline UzemnaJednotka::~UzemnaJednotka()
	{
		for (auto UJ : *podradeneUJ_)
		{
			delete UJ->accessData();
		}
		delete podradeneUJ_;
		podradeneUJ_ = nullptr;
		delete data_;
		data_ = nullptr;
	}
}