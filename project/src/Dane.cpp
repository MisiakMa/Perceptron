#include "Dane.hpp"
#include <iostream>
#include <cctype>
#include <cassert>

using namespace std;

void DataManager::normalize(double const &low, double const &high) {
	vector<double> wejscieMin;
	vector<double> wejscieMax;
	vector<double> wejscie1;
	vector<double> wejscie2;
	
	vector<double> wyjscieMin;
	vector<double> wyjscieMax;
	vector<double> wyjscie1;
	vector<double> wyjscie2;
	
	wejscieMin.resize(wejscia);
	wejscieMax.resize(wejscia);
	wejscie1.resize(wejscia);
	wejscie2.resize(wejscia);
	wektorWejsciowy1.resize(wejscia);
	wektorWejsciowy2.resize(wejscia);
	
	wyjscieMin.resize(wyjscia);
	wyjscieMax.resize(wyjscia);
	wyjscie1.resize(wyjscia);
	wyjscie2.resize(wyjscia);
	wektorWyjsciowy1.resize(wyjscia);
	wektorWyjsciowy2.resize(wyjscia);
	
	for(unsigned int j = 0; j < wejscia; ++j)
	{
        // ustawienie wartosci max i min z danych wejsciowych
		wejscieMin[j] = daneWejsciowe[0][j];
		wejscieMax[j] = daneWejsciowe[0][j];
	}
	
	for(unsigned int i = 1; i < sets; ++i)   // przechodzimy po kazdej kolumnie wzbiorze i szukamy najwiekszej i
                                             // najmniejszej wartosci
                                             //  w lini w danej kolumnie
	{
        // szukanie najmniejszej i najwiekszej wartosci w danych wejsciowych

		for(unsigned int j = 0; j < wejscia; ++j)
		{
			if(daneWejsciowe[i][j] < wejscieMin[j])
			{
				wejscieMin[j] = daneWejsciowe[i][j];
			}
			else if(daneWejsciowe[i][j] > wejscieMax[j])
			{
				wejscieMax[j] = daneWejsciowe[i][j];
			}
		}
	}
	
	for(unsigned int j = 0; j < wejscia; ++j)    // dla kazdej kolumny jest ustawiane dane wejscie
	{
		if(wejscieMax[j] != wejscieMin[j])
		{

            //dane wejsciowe oraz wektory danych wejsciowych
            //TODO dobrze by bylo gdzies odszukac te wzory w internetach


			wejscie1[j] =(high - low) / (wejscieMax[j] - wejscieMin[j]);
			wejscie2[j] =low - wejscieMin[j] * wejscie1[j];

            cout<<"wejscie1   "<<wejscie1[j]<<endl;
            cout<<"wejscie2   "<<wejscie2[j]<<endl;
            cout<<"wejscieMin   "<<wejscieMin[j]<<endl;
            cout<<"wejscieMax   "<<wejscieMax[j]<<endl;

            wektorWejsciowy1[j] =(wejscieMax[j] - wejscieMin[j]) / (high - low);
			wektorWejsciowy2[j] =wejscieMin[j] - low * wektorWejsciowy1[j];
            cout<<"wektorWejsciowy1:  "<<wektorWejsciowy1[j]<<endl;
            cout<<"wektorWejsciowy2:  "<<wektorWejsciowy2[j]<<endl;




		}
		else
		{
			wejscie1[j] = 1.0;
			wejscie2[j] = (low + high) * 0.5 - wejscieMin[j];
			wektorWejsciowy1[j] = 1.0;
			wektorWejsciowy2[j] = wejscieMin[j] - (low + high) * 0.5;
		}
	}
	
	for(unsigned int i = 0; i < sets; ++i)
	{
		for(unsigned int j = 0; j < wejscia; ++j)
		{
			daneWejsciowe[i][j] = wejscie1[j] * daneWejsciowe[i][j] + wejscie2[j];

		}
	}


	for(unsigned int j = 0; j < wyjscia; ++j)
	{
		wyjscieMin[j] = daneOczekiwane[0][j];
		wyjscieMax[j] = daneOczekiwane[0][j];
	}
	
	for(unsigned int i = 1; i < sets; ++i)
	{
		for(unsigned int j = 0; j < wyjscia; ++j)
		{
			if(daneOczekiwane[i][j] < wyjscieMin[j])
			{
				wyjscieMin[j] = daneOczekiwane[i][j];
			} else if(daneOczekiwane[i][j] > wyjscieMax[j])
			{
				wyjscieMax[j] = daneOczekiwane[i][j];
			}
		}
	}
	
	for(unsigned int j = 0; j < wyjscia; ++j)
	{
		if(wyjscieMax[j] != wyjscieMin[j])
		{
            //wedug mnie ustawienie wyjsc oraz wektorw wyjsciowych zatem zamiast wzoru wystarcza na
            //sztywno wrzucone dane dla  data1  oraz iris poniewaz zasze dostaja na wyjsciu 1 lub 0


			//wyjscie1[j] =(high - low) / (wyjscieMax[j] - wyjscieMin[j]);
			//wyjscie2[j] =low - wyjscieMin[j] * wyjscie1[j];
			//wektorWyjsciowy1[j] =(wyjscieMax[j] - wyjscieMin[j]) / (high - low);
			//wektorWyjsciowy2[j] =wyjscieMin[j] - low * wektorWyjsciowy1[j];

            wyjscie1[j] =1;
            wyjscie2[j] =0;
            wektorWyjsciowy1[j] =1;
            wektorWyjsciowy2[j] =0;

		}
		else
		{
			wyjscie1[j] = 1;
			wyjscie2[j] =0;//              (low + high) * 0.5 - wyjscieMin[j];
			wektorWyjsciowy1[j] = 1;
			wektorWyjsciowy2[j] = 0;//        wyjscieMin[j] - (low + high) * 0.5;
		}
	}
	
	for(unsigned int i = 0; i < sets; ++i)
	{
		for(unsigned int j = 0; j < wyjscia; ++j)
		{
			daneOczekiwane[i][j] = wyjscie1[j] * daneOczekiwane[i][j] + wyjscie2[j];
		}
	}
}

DataManager::DataManager(FILE * const &f, unsigned int const &inputs,
						 unsigned int const &outputs, double const &low, double const &high)
{
	this->wejscia = inputs;  // ustawienie wejscia
	this->wyjscia = outputs; // ustawienie wyjscia
	
	unsigned int dfInputs, dfOutputs;
	
	ignoreWhities(f);
	fscanf(f, "%u %u %u", &dfInputs, &dfOutputs, &sets);  // metoda fscanf odczytuje dane ze strumienia
	assert(dfInputs == inputs); // narzedzie bedu, jezeli wyrazenie jest rowne 0 to to zapisywany jest komunikat anulowania


	assert(dfOutputs == outputs);
	ignoreWhities(f);
	
	daneWejsciowe.resize(sets);  // zmienia rozmiar kontenera tak aby zawiera ustawiona ilosc elementow
	daneOczekiwane.resize(sets);

	for(unsigned int i = 0; i < sets; ++i) {
		daneWejsciowe[i].resize(inputs);
		daneOczekiwane[i].resize(outputs);
	}

	ignoreWhities(f);
	for(unsigned int i = 0; i < sets; ++i)
	{
		ignoreWhities(f);
		
		ignoreWhities(f);
		for(unsigned int j = 0; j < inputs; ++j)
		{
			fscanf(f, "%"SCNnum_t, &(daneWejsciowe[i][j]));
            // metoda fscanf odczytuje dane ze strumienia
		}
		ignoreWhities(f);
		
		ignoreWhities(f);
		for(unsigned int j = 0; j < outputs; ++j)
		{
			fscanf(f, "%"SCNnum_t, &(daneOczekiwane[i][j]));
            // metoda fscanf odczytuje dane ze strumienia
		}
		ignoreWhities(f);
		
		ignoreWhities(f);
	}
	ignoreWhities(f);
	
	normalize(low, high);
}

void DataManager::readTests(FILE * const &f)
{
	unsigned int dfInputs, dfOutputs;
	vector<double> wejscie1;
	vector<double> wejscie2;
	vector<double> wyjscie1;
	vector<double> wyjscie2;
	unsigned int oldSz = sets;
	unsigned int noweUstawienia;
	
	ignoreWhities(f);
	fscanf(f, "%u %u %u", &dfInputs, &dfOutputs, &noweUstawienia);
    // metoda fscanf odczytuje dane ze strumienia, %u unsignet int
	assert(dfInputs == wejscia);
	assert(dfOutputs == wyjscia);
	ignoreWhities(f);
	
	sets += noweUstawienia;
	
	daneWejsciowe.resize(sets);
	daneOczekiwane.resize(sets);

	for(unsigned int i = oldSz; i < sets; ++i)
	{
		daneWejsciowe[i].resize(wejscia);
		daneOczekiwane[i].resize(wyjscia);
	}
	
	ignoreWhities(f);
	for(unsigned int i = oldSz; i < sets; ++i)
	{
		ignoreWhities(f);
		
		ignoreWhities(f);
		for(unsigned int j = 0; j < wejscia; ++j)
		{
			fscanf(f, "%"SCNnum_t, &(daneWejsciowe[i][j]));// metoda fscanf odczytuje dane ze strumienia
		}
		ignoreWhities(f);
		
		ignoreWhities(f);
		for(unsigned int j = 0; j < wyjscia; ++j)
		{
			fscanf(f, "%"SCNnum_t, &(daneOczekiwane[i][j]));// metoda fscanf odczytuje dane ze strumienia
		}
		ignoreWhities(f);
		
		ignoreWhities(f);
	}
	ignoreWhities(f);
	
	wejscie1.resize(wejscia);
	wejscie2.resize(wejscia);
	for(unsigned int i = 0; i < wejscia; ++i)
	{
		wejscie1[i] = 1.0 / wektorWejsciowy1[i];
		wejscie2[i] = -wektorWejsciowy2[i] / wektorWejsciowy1[i];
	}
	
	for(unsigned int i = oldSz; i < sets; ++i) {
		for(unsigned int j = 0; j < wejscia; ++j) {
			daneWejsciowe[i][j] = wejscie1[j] * daneWejsciowe[i][j] + wejscie2[j];
		}
	}
	
	wyjscie1.resize(wyjscia);
	wyjscie2.resize(wyjscia);
	for(unsigned int i = 0; i < wyjscia; ++i) {
		wyjscie1[i] = 1.0 / wektorWyjsciowy1[i];
		wyjscie2[i] = -wektorWyjsciowy2[i] / wektorWyjsciowy1[i];
	}
	
	for(unsigned int i = oldSz; i < sets; ++i) {
		for(unsigned int j = 0; j < wyjscia; ++j) {
			daneOczekiwane[i][j] = wyjscie1[j] * daneOczekiwane[i][j] + wyjscie2[j];
		}
	}
}

DataManager::DataManager(FILE * const &f, unsigned int const &inputs, unsigned int const &outputs)
{
	this->wejscia = inputs; // zapisanie wejscia
	this->wyjscia = outputs;//zapisanie wyjscia
	this->sets = 0;
	
	unsigned int dfInputs, dfOutputs;
	
	ignoreWhities(f);
	
	ignoreWhities(f);
	fscanf(f, "%u %u", &dfInputs, &dfOutputs);// metoda fscanf odczytuje dane ze strumienia
	assert(dfInputs == inputs);
	assert(dfOutputs == dfOutputs);
	ignoreWhities(f);

	wektorWejsciowy1.resize(inputs);
	wektorWejsciowy2.resize(inputs);
	
	ignoreWhities(f);
	for(unsigned int i = 0; i < inputs; ++i) {
		ignoreWhities(f);
		fscanf(f, "%"SCNnum_t" %"SCNnum_t, &(wektorWejsciowy1[i]), &(wektorWejsciowy2[i]));
        // metoda fscanf odczytuje dane ze strumienia
		ignoreWhities(f);
	}
	ignoreWhities(f);
	
	wektorWyjsciowy1.resize(outputs);
	wektorWyjsciowy2.resize(outputs);

	ignoreWhities(f);
	for(unsigned int i = 0; i < outputs; ++i) {
		ignoreWhities(f);
		fscanf(f, "%"SCNnum_t" %"SCNnum_t, &(wektorWyjsciowy1[i]), &(wektorWyjsciowy2[i]));
        // metoda fscanf odczytuje dane ze strumienia
		ignoreWhities(f);
	}
	ignoreWhities(f);

	ignoreWhities(f);
}

DataManager::~DataManager() {}

void DataManager::wyswietlenieWejscZdekodowanych(vector<double> const &data, ofstream &name) {
    name<<"( ";
    for(unsigned int i = 0; i < data.size(); ++i) {

        name<<" "<<(wektorWejsciowy1[i]*data[i]+wektorWejsciowy2[i]);
    }

    name<<" )"<<endl;
	name<<"( ";
    cout<<"( ";
	for(unsigned int i = 0; i < data.size(); ++i) {

		cout<<" "<<(wektorWejsciowy1[i]*data[i]+wektorWejsciowy2[i]);
	}

	cout<<" )"<<endl;
}

void DataManager::wyswietlenieWyjscZdekodowanych(vector<double> const &data, ofstream &name) {


    name<<"( ";
    for(unsigned int i = 0; i < data.size(); ++i) {

        name<<" "<<(wektorWyjsciowy1[i]*data[i]+wektorWyjsciowy2[i]);

    }

    name<<" )"<<endl;

	cout<<"( ";
	for(unsigned int i = 0; i < data.size(); ++i) {


		cout<<" "<<(wektorWyjsciowy1[i]*data[i]+wektorWyjsciowy2[i]);
		//(wektorWyjsciowy1[i]*data[i]+wektorWyjsciowy2[i]);

	}

	cout<<" )"<<endl;
}

void DataManager::serializacja(FILE *const &f) {

	cout<<f<<endl;

	cout<<f<<"\t"<<wejscia<<wyjscia<<endl;
	

	cout<<f<<endl;
	for(unsigned int i = 0; i < wejscia; ++i)
	{

		cout<<f<<PRInum_t,wektorWejsciowy1[i], wektorWejsciowy2[i];
	}

	cout<<f<<" )"<<endl;


	cout<<f<<"\t";
	for(unsigned int i = 0; i < wyjscia; ++i) {

		cout<<f<<PRInum_t,wektorWyjsciowy1[i], wektorWyjsciowy2[i];
	}

	cout<<f<<" )"<<endl;


	cout<<f<<" )"<<endl;


}
