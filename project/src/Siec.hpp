#ifndef __NETWORK_HPP
#define __NETWORK_HPP

#include <vector>
#include "Funkcja.hpp"
#include "Warstwa.hpp"
#include  <iostream>

#include <fstream>
using namespace std;

class Network {
	private:
		vector<Layer *> layers;
		double momentum;
		double learning;
		double error;
		bool withBias;
	public:
		Network(vector<unsigned int> const &layerSizes,
				double const &momentum, double const &learning,
				bool const &withBias);
		~Network();
		
		inline double getError() { return error; }
		
		void ustawWejscia(vector<double> const &input);
		
		void uzyskajWyjscie(vector<double> &output);
		
		void propagacja();
		
		void obliczanieBleduWyjscia(vector<double> const &expected);
		
		void propagacjaWsteczna();
		
		void dopasujWagi();
		
		void simulate(vector<double> const &input,
				vector<double> &output, vector<double> const &expected,
				bool const &training);
				
		void opis(ofstream &name);
		
		void pokazWyjscia(ofstream &name);
		
		void serializujWagi(FILE *const &f);
		
		void obciazeniaWag(FILE *const &f);
};

#endif
