#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>

#include <iostream>
#include <fstream>

#include "Funkcja.hpp"

#include "Siec.hpp"
#include "Dane.hpp"
#include "Losowanie.hpp"
using namespace std;

int main(int argc, char **argv){

	// Constants
	double const normalizeLow = .0625;
	double const normalizeHigh = .9375;
	// End of constants


	// Processed command line data
    ofstream Saver;
    ofstream Setup;
    ofstream Graph;
    Saver.open("/home/pobi/Downloads/iad2-projekt/DataSet.txt");
    Setup.open("/home/pobi/Downloads/iad2-projekt/Setup.txt");
    Graph.open("/home/pobi/Downloads/iad2-projekt/Graph.txt");
    char *ZestawTreningowy ="../data/data1.in"; //"../data/data1.in";
	bool Bias = true;
	double WspolczynnikNauki = 0.2;
	double WspolczynnikMomentu = 0.0;
	int IloscEpok = 100;
    vector<unsigned int> layerSizes;
    layerSizes.push_back(4);
    layerSizes.push_back(2);
    layerSizes.push_back(4);





	double epsilon = -1;
	char *WagiWejsciowe = NULL;
	char *WagiWyjsciowe = NULL;  // zapis

	bool randomize = true;
	char *TestWejscia = NULL;
	char *logFN = NULL;
	bool verbose = true;
	int logFreq = 1;
	int syFlag = 1;
	int snFlag = 1;
	int ltFlag = 1;
	int lnFlag = 1;





	bool noErrors = true;
	//Logger *lgr;
	//lgr = new Logger(logFN, verbose);
	

	for(int i = 0; i < argc; ++i)
    {
        cout<<argv[i]<<endl;
        cout<<" "<<endl;
	}

    cout<<endl;
    cout<<" -------------------------------"<<endl;
    cout<<"|Konfiguracja\t\t\t\t\t|"<<endl;
    cout<<"|Bias: "<<Bias<<"\t\t\t\t\t\t|"<<endl;
    cout<<"|Wspolczynnik uczenia: "<<WspolczynnikNauki<<"\t\t|"<<endl;
    cout<<"|Wspolczynnik momentum: "<<WspolczynnikMomentu<<"\t\t|"<<endl;
    cout<<"|Ilosc epok: "<<IloscEpok<<"\t\t\t\t|"<<endl;
    cout<<" --------------------------------"<<endl;


    cout<<" ---------------------------------------------"<<endl;
	if(ZestawTreningowy != NULL)
    {
        cout<<"|Zestaw treningowy z pliku: "<<ZestawTreningowy<<"  |"<<endl;
	}

    cout<<"|Konfiguracja warstw: ";
	for(unsigned int i = 0; i < layerSizes.size(); ++i)
    {
        cout<<layerSizes[i]<<" ";
	}
    cout<<"\t\t\t\t  |";

    cout<<endl;
    cout<<" ---------------------------------------------"<<endl;




	// Work with the network
	if(noErrors)
    {
		Network *nn;
		DataManager *dm = NULL;
		nn = new Network(layerSizes, WspolczynnikMomentu, WspolczynnikNauki, Bias);
		
		// Preloading wagi
		if(WagiWejsciowe != NULL) {
			FILE *weightsInFile = fopen(WagiWejsciowe, "r");
			dm = new DataManager(weightsInFile, layerSizes.front(), layerSizes.back());
            nn->obciazeniaWag(weightsInFile);
			fclose(weightsInFile);
		}
		// End of preloading wagi


       // cout<<"Poczatkowy opis sieci"<<endl;
		//nn->opis(lgr);   // przechodzi do network.cpp
       // cout<<"Koniec poczatkowego opisu sieci"<<endl<<endl;

		
		// Training
		if(ZestawTreningowy != NULL)
        {

			int epoch = 0;
			double epochErr = 0; // blad w epoce
			FILE *trainingFile = fopen(ZestawTreningowy, "r");  // plikdo odczytu
			vector<unsigned int> order;
			
			// Loading training sets
			if(dm == NULL) {
				dm = new DataManager(trainingFile, layerSizes.front(), layerSizes.back(), normalizeLow, normalizeHigh);
			}
            else
            {
				dm->readTests(trainingFile);
			}
			// End of loading training sets
            cout<<"*****************************************************"<<endl;
            cout<<"*     Nauka z szybkoscia uczenia sie: "<<WspolczynnikNauki<<"\t\t\t*"<<endl;
            cout<<"*     Wspolczynnik momentu: "<<WspolczynnikMomentu<<"\t\t\t\t\t\t*"<<endl;
            cout<<"*****************************************************"<<endl;

			if(IloscEpok >= 0) {

                cout<<"Zatrzymanie w epoce: "<<IloscEpok<<endl;
				if(epsilon > 0.0)
                {
                    cout<<" lub gdy powstanie najgorszy test epoki "<<endl;
				}
                else
                {
                    cout<<endl;
				}
			}
            else
            {
                cout<<"Wykona najgorszy test epoki"<<endl;
			}


			for(unsigned int j = 0; j < dm->getSize(); ++j)
            {
				order.push_back(j);
			}
			// End of preparing sorted order
			
			// Simulating epochs
			while((epoch < IloscEpok || IloscEpok < 0) && (epochErr > epsilon))
            {
				epochErr = 0.0;
				if(randomize)
                {
					Losowanie::getInstance().shuffle(order);
				}
				if(epoch % logFreq == 0)
                {
                    Graph <<"Epoka: " << epoch;
                    Saver <<"Epoka: "<< epoch;
                    cout<<"Epoka:  "<<epoch;
				}
				for(unsigned int j = 0; j < dm->getSize(); ++j)
                {
					unsigned int cur = order[j];
					std::vector<double> output;
					double err;
					nn->simulate(dm->getInputVector(cur), output, dm->getExpectedVector(cur), true);
					err = nn->getError();
					if(err > epochErr)
                    {
						epochErr = err;
					}
					if(epoch % logFreq == 0)
                    {
						// Displaying calculation
						if(syFlag) {
                            cout<<endl;
                            Saver<<"Nasze dane wejscowe: ";
                            cout<<"Nasze dane wejsciowe:  ";
                            dm->wyswietlenieWejscZdekodowanych( dm->getInputVector(cur), Saver);

                            Saver <<"Nasz oczekiwany wynik: ";
                            cout<<"Nasz oczekiwany wynik: ";
                            dm->wyswietlenieWyjscZdekodowanych(dm->getExpectedVector(cur), Saver);

                            Saver<<"Nasz obliczony wynik: ";
                            cout<<"Nasz obliczony wynik:  ";
                            dm->wyswietlenieWyjscZdekodowanych( output, Saver);

                            Saver <<"Jak zmieniala sie siec wedlug warstw: ";
                            cout<<"Jak zmieniala sie siec wedlug warstw: ";
                            nn->pokazWyjscia( Saver);
                            cout<<endl;

						}
                        Graph << "  " << err;
                        Saver <<"\nBlad sieci: " << err << endl;
                        Saver << "\n";
                        cout<<"Blad sieci: "<<err<<endl;

						

						if(snFlag)
                        {

                           // cout<<"\n\nIteracja sieci: ";
							//nn->opis(lgr);
                           // cout<<endl;

                           // cout<<"Koniec sieci iteracyjnej"<<endl;
						}
						// End of detailed network description
					}
				}
				if(epoch % logFreq == 0)
                {
                    Saver <<"\nKoniec epoki "<< epoch <<endl;
                    cout<<"\nKoniec epoki "<< epoch<<endl;
				}
                Graph << endl;
				++epoch;

			}
			// End of simulating epochs
			
			// Training finish explaination
			if(epoch >= IloscEpok && IloscEpok >= 0 && epochErr <= epsilon)
            {
                Saver<<"Trening zakonczony poniewaz epoka doszla do numeru: "<<epoch<<"i otrzymanie bledu nie wiekszego niz: "
                    <<epsilon<<endl;
                cout<<"Trening zakonczony poniewaz epoka doszla do numeru: "<<epoch<<"i otrzymanie bledu nie wiekszego niz: "
                <<epsilon<<endl;
			} else if(epoch >= IloscEpok && IloscEpok >= 0)
            {
                Saver<<"Trening zakonczony poniewaz epoka doszla do numeru: "<<epoch<<endl;
                cout<<"Trening zakonczony poniewaz epoka doszla do numeru: "<<epoch<<endl;
			}
            else
            {
                Saver<<"Trening zakonczy siz powodu usyskania bledow"<<endl;
                cout<<"Trening zakonczy siz powodu usyskania bledow"<<endl;
			}
			// End of training finish explaination
			
			// Detailed network description
			if(lnFlag)
            {
                Saver<<"Opis sieci po szkoleniu: " << endl;
                cout<<"Opis sieci po szkoleniu: "<<endl;
				nn->opis( Setup);
                Saver <<"Koniec opisu sieci: "<<endl;
               cout<<"Koniec opisu sieci: "<<endl;
			}
			// End of detailed network description
			
			
			// Testing the whole training set once more (without WspolczynnikNauki)
			if(ltFlag)
            {
                Saver<<"Szkolenie ustala wyniki koncowe"<<endl;
                cout<<"Szkolenie ustala wyniki koncowe"<<endl;
			}
			//epochErr = 0.0;
			for(unsigned int j = 0; j < dm->getSize(); ++j) {
				unsigned int cur = j;
				std::vector<double> output;
				double err;
				nn->simulate(dm->getInputVector(cur), output, dm->getExpectedVector(cur), false);
				err = nn->getError();
				if(err > epochErr)
                {
					epochErr = err;
				}
				if(ltFlag) {
                    Saver << "\nNasze dane wejsciowe: ";
                    cout<<endl;
                    cout<<"Nasze dane wejsciowe:  ";
                    dm->wyswietlenieWejscZdekodowanych( dm->getInputVector(cur), Saver);

                    Saver<<"Nasz oczekiwany wynik: ";
                    cout<<"Nasz oczekiwany wynik: ";
                    dm->wyswietlenieWyjscZdekodowanych(dm->getExpectedVector(cur),Saver);
                    Saver<<"Nasz obliczony wynik:   ";
                    cout<<"Nasz obliczony wynik:   ";
                    dm->wyswietlenieWyjscZdekodowanych( output,Saver);

                    Saver<<"Jak zmieniala sie siec wedlug warstw: ";
                    cout<<"Jak zmieniala sie siec wedlug warstw: ";
                    nn->pokazWyjscia( Saver);
                    cout<<endl;
                    Saver<<endl;
                    Saver<<"Blad sieci: "<<err <<endl;
                    cout<<"Blad sieci: "<<err<<endl;

				}
			}

            cout<<endl;
			if(ltFlag)
            {
                Saver <<"Koniec treningu wyznacza ostateczne wynik\n"<<endl;
                cout<<"Koniec treningu wyznacza ostateczne wyniki\n"<<endl;
			}
            Saver<<"Największy błąd w zbiorze treningowym: "<<(PRInum_t,epochErr)<<endl;
            cout<<"Największy błąd w zbiorze treningowym: "<<(PRInum_t,epochErr)<<endl;

			
			fclose(trainingFile);
			
			// Weihts serialization
			if(WagiWyjsciowe != NULL) {
				FILE *weightsOutFile = fopen(WagiWyjsciowe, "w"); // tryb w tworzy plik do zapisu
                dm->serializacja(weightsOutFile);
                nn->serializujWagi(weightsOutFile);
				fclose(weightsOutFile);
			}
			// End of wagi serialization
		}
		// End of training
		
		// Test propagation
		if(TestWejscia != NULL)
        {
			FILE *testInFile = fopen(TestWejscia, "r"); // tryb r otwiera plik w trybie do odczytu
			unsigned int trainingEnd = dm->getSize();
			double epochErr = 0.0;
			
			dm->readTests(testInFile);
			
			// Processing the test set
			if(ltFlag)
            {
                cout<<"Wyniki dla zestawu testowego"<<endl;
			}
			for(unsigned int j = trainingEnd; j < dm->getSize(); ++j)
            {
				unsigned int cur = j;
				std::vector<double> output;
				double err;
				nn->simulate(dm->getInputVector(cur), output, dm->getExpectedVector(cur), false);
				err = nn->getError();
				if(err > epochErr)
                {
					epochErr = err;
				}

                cout<<endl;
                dm->wyswietlenieWejscZdekodowanych( dm->getInputVector(cur), Saver);


                cout<<"Nasze dane wejsciowe:  ";
                dm->wyswietlenieWyjscZdekodowanych( dm->getExpectedVector(cur),Saver);


                cout<<"Nasz oczekiwany wynik: ";
                dm->wyswietlenieWyjscZdekodowanych( output,Saver);


                cout<<"Jak zmieniala sie siec wedlug warstw: ";
                nn->pokazWyjscia( Saver);
                cout<<endl;

                cout<<"Blad sieci: "<<err<<endl;
			}

            cout<<endl;
			if(ltFlag)
            {
                cout<<"Koniec wynikow dla zestawu testowego"<<endl;
			}

            cout<<"Najwiekszy blad w zestawie testowym: "<<epochErr<<endl;

			
			fclose(testInFile);
		}
		// End of test propagation
		
		if(dm != NULL) delete dm;
		delete nn;
	}
    Saver.close();
    Setup.close();
    Graph.close(); }
