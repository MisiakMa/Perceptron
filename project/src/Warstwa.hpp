#ifndef __LAYER_HPP
#define __LAYER_HPP

#include <vector>
#include "Funkcja.hpp"

class Layer
{
	private:
		unsigned int size;
		std::vector<double> wyjscie;
		std::vector<double> blad;
		double **wagi;
		double **wagi2;
		bool Bias;
	public:
		Layer(size_t const &size, size_t const &pSize, bool const &withBias);
		~Layer();
		
		inline unsigned int getSize() { return size; }
		
		inline double otrzymajWyjscie(unsigned int const &p) { return wyjscie[p]; }
		
		inline void ustawWyjscie(unsigned int const &p, double const &v)
		{
			wyjscie[p] = v;
		}
		
		inline double otrzymajWage(unsigned int const &n, unsigned int const &i)
		{
			return wagi[n][i];
		}
		
		inline void ustawWage(unsigned int const &n, unsigned int const &i,
							  double const &v) {
			wagi[n][i] = v;
		}
		
		inline double otrzymajWage2(unsigned int const &n, unsigned int const &i)
		{
			return wagi2[n][i];
		}
		
		inline void ustawWage2(unsigned int const &n, unsigned int const &i, double const &v)
		{
			wagi2[n][i] = v;
		}
		
		inline double getError(unsigned int const &p) { return blad[p]; }
		
		inline void setError(unsigned int const &p, double const &v)
		{
			blad[p] = v;
		}
};

#endif
