#include "Siec.hpp"
#include <cassert>
#include <iostream>
using namespace std;

Network::Network(vector<unsigned int> const &layerSizes,
		double const &momentum, double const &learning,
		bool const &withBias) {
	    this->momentum = momentum;
	    this->learning = learning;
	    this->withBias = withBias;
	
	layers.resize(layerSizes.size());
	
	for(unsigned int i = 0; i < layers.size(); ++i) {
		layers[i] = new Layer(layerSizes[i], i == 0 ? 0 : layerSizes[i - 1], withBias);
	}
}

Network::~Network() {
	for(unsigned int i = 0; i < layers.size(); ++i) {
		delete layers[i];
	}
}

void Network::ustawWejscia(vector<double> const &input)
{
	unsigned int size = layers[0]->getSize();
	for(unsigned int i = 0; i < size; ++i)
	{
        layers[0]->ustawWyjscie(i + withBias, i < input.size() ? input[i] : 0.0);
	}
}

void Network::uzyskajWyjscie(vector<double> &output) {
	Layer *outLayer = layers.back();

	output.resize(outLayer->getSize());
	
	for(unsigned int i = 0; i < output.size(); ++i) {
		output[i] = outLayer->otrzymajWyjscie(i + withBias);
	}
}

void Network::propagacja() {
	for(unsigned int i = 1; i < layers.size(); ++i) {
		unsigned int tSize = layers[i]->getSize() + withBias;
		unsigned int ptSize = layers[i - 1]->getSize() + withBias;
		for(unsigned int j = withBias; j < tSize; ++j) {
			double sum = 0.0;
			for(unsigned int k = 0; k < ptSize; ++k) {
				sum += layers[i - 1]->otrzymajWyjscie(k) * layers[i]->otrzymajWage(j, k);
			}
            layers[i]->ustawWyjscie(j, logsig(sum));
		}
	}
}

void Network::obliczanieBleduWyjscia(vector<double> const &expected) {
	Layer *outLayer = layers.back();
	unsigned int tSize = outLayer->getSize() + withBias;
	error = 0.0;
	for(unsigned int i = withBias; i < tSize; ++i) {
		double out = outLayer->otrzymajWyjscie(i);
		double err = expected[i - withBias] - out;
		outLayer->setError(i, out * (1.0 - out) * err);
		error += err * err;
	}
	error *= 0.5;
}

void Network::propagacjaWsteczna() {
	for(unsigned int i = layers.size() - 1; i > 1; --i) {
		unsigned int tSize = layers[i]->getSize() + withBias;
		unsigned int ptSize = layers[i - 1]->getSize() + withBias;
		for(unsigned int j = withBias; j < ptSize; ++j) {
			double out = layers[i - 1]->otrzymajWyjscie(j);
			double err = 0.0;
			for(unsigned int k = withBias; k < tSize; ++k) {
				err += layers[i]->otrzymajWage(k, j) * layers[i]->getError(k);
			}
			layers[i - 1]->setError(j, out * (1.0 - out) * err);
		}
	}
}

void Network::dopasujWagi() {




	for(unsigned int i = 1; i < layers.size(); ++i) {
		unsigned int tSize = layers[i]->getSize() + withBias;
		unsigned int ptSize = layers[i - 1]->getSize() + withBias;
		for(unsigned int j = withBias; j < tSize; ++j) {
			for(unsigned int k = 0; k < ptSize; ++k) {
				double out = layers[i - 1]->otrzymajWyjscie(k);
				double err = layers[i]->getError(j);
				double weight = layers[i]->otrzymajWage(j, k);
				double dWeight = layers[i]->otrzymajWage2(j, k);
                layers[i]->ustawWage(j, k, weight + learning * err * out +
                                           momentum * dWeight);
                layers[i]->ustawWage2(j, k, learning * err * out);


			}
		}
	}
}

void Network::simulate(vector<double> const &input,
		vector<double> &output, vector<double> const &expected,
		bool const &training)
{
    ustawWejscia(input);
    propagacja();
    uzyskajWyjscie(output);
    obliczanieBleduWyjscia(expected);
	if(training) {
        propagacjaWsteczna();
        dopasujWagi();
	}
}

void Network::opis( ofstream  &name)
{  // opis warstw w kazdej epoce
    name<<"\nIlosc warstw: "<<layers.size()<<endl;
    cout<<"\nIlosc warstw: "<<layers.size()<<endl;
	
	for(unsigned int i = 0; i < layers.size(); ++i)
    {
		unsigned int tSize = layers[i]->getSize() + withBias;

        name<<"Warstwa."<<i+1<<" :"<<layers[i]->getSize()<<" Neurony"<<endl;
        cout<<"Warstwa."<<i+1<<" :"<<layers[i]->getSize()<<" Neurony"<<endl;
		for(unsigned int j = withBias; j < tSize; ++j)
        {
            name<<"Neuron "<<i+1<<"."<<j-withBias+1<<endl;
            cout<<"Neuron "<<i+1<<"."<<j-withBias+1<<endl;
			if(i == 0)
            {

                name<<"Funkcja aktywacji"<<endl;
                cout<<"Funkcja aktywacji"<<endl;

			} else
            {
				unsigned int ptSize = layers[i - 1]->getSize() + withBias;

                name<<"Funkcja aktywacji"<<endl;
                cout<<"Funkcja aktywacji"<<endl;


                name<<"Wagi wektora: ";
                cout<<"Wagi wektora: ";
				for(unsigned int k = withBias; k < ptSize; ++k)
                {
                    name<<"("<<(PRInum_t, layers[i]->otrzymajWage(j, k))<<")";
                    cout<<"("<<(PRInum_t, layers[i]->otrzymajWage(j, k))<<")";
				}

                cout<<endl;
				if(withBias)
                {
                    name<<"Bias: "<< layers[i]->otrzymajWage(j, 0);
                    cout<<"Bias: "<< layers[i]->otrzymajWage(j, 0);
				}
                name<<endl;
                cout<<endl;
			}
		}

        name<<endl;
	}
}

void Network::pokazWyjscia( ofstream &name)
{
    name<<"( ";
    for(unsigned int i = 0; i < layers.size(); ++i) {
        unsigned int tSize = layers[i]->getSize() + withBias;

        name<<"( ";
        for(unsigned int j = withBias; j < tSize; ++j) {


            name<<( layers[i]->otrzymajWyjscie(j))<<" ";
        }

        name<<")";
    }

    name<<" )";

    cout<<"( ";
	for(unsigned int i = 0; i < layers.size(); ++i) {
		unsigned int tSize = layers[i]->getSize() + withBias;

        cout<<"( ";
		for(unsigned int j = withBias; j < tSize; ++j) {


            cout<<( layers[i]->otrzymajWyjscie(j))<<" ";
		}

        cout<<")";
	}

    cout<<" )";
}

void Network::serializujWagi(FILE *const &f)
{

    cout<<endl;

    cout<<endl;
	for(unsigned int i = 0; i < layers.size(); ++i)
    {

        cout<<f<<layers[i]->getSize();
	}

    cout<<f<<" )"<<endl;
	

    cout<<f<<"\t"<<withBias<<endl;
	
	for(unsigned int i = 1; i < layers.size(); ++i)
    {
		unsigned int tSize = layers[i]->getSize() + withBias;

        cout<<f<<"\t"<<endl;
		for(unsigned int j = withBias; j < tSize; ++j)
        {
			unsigned int ptSize = layers[i - 1]->getSize() + withBias;

            cout<<f<<"\t\t( ";
			for(unsigned int k = 0; k < ptSize; ++k)
            {


                cout<<f<<PRInum_t, layers[i]->otrzymajWage(j, k);
                cout<<f<<PRInum_t, layers[i]->otrzymajWage2(j, k);

			}

            cout<<f<<" )"<<endl;
		}

        cout<<f<<"\t)";
	}

    cout<<f<<"\t)";
}

void Network::obciazeniaWag(FILE *const &f)
{
	ignoreWhities(f);
	
	ignoreWhities(f);
	for(unsigned int i = 0; i < layers.size(); ++i)
    {
		unsigned int s;
		fscanf(f, "%u", &s);
		assert(s == layers[i]->getSize());
	}
	ignoreWhities(f);
	
	ignoreWhities(f);
	unsigned int b;
	fscanf(f, "%u", &b);
	assert(bool(b) == withBias);
	ignoreWhities(f);

	for(unsigned int i = 1; i < layers.size(); ++i)
    {
		unsigned int tSize = layers[i]->getSize() + withBias;
		
		ignoreWhities(f);
		for(unsigned int j = withBias; j < tSize; ++j)
        {
			unsigned int ptSize = layers[i - 1]->getSize() + withBias;
			ignoreWhities(f);
			for(unsigned int k = 0; k < ptSize; ++k)
            {
				double w, dw;
				ignoreWhities(f);
				fscanf(f, "%"SCNnum_t" %"SCNnum_t, &w, &dw);
                layers[i]->ustawWage(j, k, w);
                layers[i]->ustawWage2(j, k, dw);
				ignoreWhities(f);
			}
			ignoreWhities(f);
		}
		ignoreWhities(f);
	}

	ignoreWhities(f);
}
