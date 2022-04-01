#pragma once
#include "UzemnaJednotka.h"
#include "table/unsorted_sequence_table.h"
namespace structures
{
	class UzemneJednotky
	{
	public:
		UzemneJednotky();
		~UzemneJednotky();
		void Pridaj(std::string kraj, std::string okres, std::string obec, Obec* data);
		SortedSequenceTable<std::string, UzemnaJednotka*>* getVsetkyUzemneJednotky();
		UzemnaJednotka* getKrajinu();
	private:
		UzemnaJednotka* krajina_;
		SortedSequenceTable<std::string, UzemnaJednotka*>* UzemneJednotky_;
	};

	UzemneJednotky::UzemneJednotky()
	{
		krajina_ = new UzemnaJednotka("Slovensko", TypUJ::KRAJINA, nullptr, nullptr);
		UzemneJednotky_ = new SortedSequenceTable<std::string, UzemnaJednotka*>;
		UzemneJednotky_->insert(krajina_->getNazov(), krajina_);

	}

	UzemneJednotky::~UzemneJednotky()
	{
		delete krajina_;
		krajina_ = nullptr;
		delete UzemneJednotky_;
		UzemneJednotky_ = nullptr;
	}
	inline void UzemneJednotky::Pridaj(std::string kraj, std::string okres, std::string obec, Obec* data)
	{
		UzemnaJednotka* current;
		current = krajina_->pridajPodradenuUJ(new UzemnaJednotka(kraj, TypUJ::KRAJ, krajina_, nullptr), UzemneJednotky_);
		current = current->pridajPodradenuUJ(new UzemnaJednotka(okres, TypUJ::OKRES, current, nullptr), UzemneJednotky_);
		current = current->pridajPodradenuUJ(new UzemnaJednotka(obec, TypUJ::OBEC, current, data), UzemneJednotky_);
	}
	inline SortedSequenceTable<std::string, UzemnaJednotka*>* UzemneJednotky::getVsetkyUzemneJednotky()
	{
		return UzemneJednotky_;
	}
	inline UzemnaJednotka* UzemneJednotky::getKrajinu()
	{
		return krajina_;
	}
}
