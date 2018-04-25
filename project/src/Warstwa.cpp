#include "Warstwa.hpp"

#include "Losowanie.hpp"

Layer::Layer(size_t const &size, size_t const &pSize, bool const &withBias)
{
	unsigned int tSize = size + withBias;
	unsigned int ptSize = pSize + withBias;

	this->size = size;
	this->Bias = withBias; // ustawienie biasu
	
	wyjscie.resize(tSize);
	blad.resize(tSize);
	
	wagi = new double*[tSize];
	wagi2 = new double*[tSize];
	
	for(unsigned int i = 0; i < tSize; ++i)
	{
		wyjscie[i] = 0.0;
		blad[i] = 0.0;
	}
	
	if(withBias) {
		wyjscie[0] = 1.0;
	}
	
	for(unsigned int i = withBias; i < tSize; ++i)
	{
		wagi[i] = new double[ptSize];
		wagi2[i] = new double[ptSize];
		
		for(unsigned int j = 0; j < ptSize; ++j)
		{
			wagi[i][j] = Losowanie::getInstance().randNum(-0.5, 0.5);
			wagi2[i][j] = 0.0;
		}
	}
}

Layer::~Layer()
{
	unsigned int tSize = size + Bias;
	
	for(unsigned int i = Bias; i < tSize; ++i)
	{
		delete [] wagi[i];
		delete [] wagi2[i];
	}
	
	delete [] wagi;
	delete [] wagi2;
}
