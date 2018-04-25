#ifndef __DATA_MANAGER_HPP
#define __DATA_MANAGER_HPP

#include <cstdio>
#include <vector>
#include <fstream>
#include "Funkcja.hpp"

using namespace std;
class DataManager {
	private:
		unsigned int wejscia, wyjscia, sets;
		vector<double> wektorWyjsciowy1;
		vector<double> wektorWyjsciowy2;
		vector<double> wektorWejsciowy1;
		vector<double> wektorWejsciowy2;
		vector<std::vector<double> > daneWejsciowe;
		vector<std::vector<double> > daneOczekiwane;


		
		void normalize(double const &low, double const &high);
	public:
		DataManager(FILE * const &f, unsigned int const &inputs,
					unsigned int const &outputs, double const &low, double const &high);
		
		DataManager(FILE * const &f, unsigned int const &inputs, unsigned int const &outputs);
		
		~DataManager();
		
		inline unsigned int getSize() { return sets; };
		
		inline vector<double> & getInputVector(unsigned int const &s)
        {
			return daneWejsciowe[s];
		}
		
		inline vector<double> & getExpectedVector(unsigned int const &s)
        {
			return daneOczekiwane[s];
		}
		
		void wyswietlenieWejscZdekodowanych( vector<double> const &data, ofstream &name);
		
		void wyswietlenieWyjscZdekodowanych( vector<double> const &data, ofstream &name);
		
		void serializacja(FILE *const &f);
		
		void readTests(FILE * const &f);
};

#endif
