#ifndef __RANDOM_UTIL_HPP
#define __RANODM_UTIL_HPP

#include <cstdlib>
#include <ctime>
#include <vector>
#include "Funkcja.hpp"
using namespace std;

class Losowanie
{
	private:
		Losowanie()
		{
			srand(time(NULL));
		}
		Losowanie(const Losowanie &);
		Losowanie & operator=(const Losowanie &);

	public:
		int randInt(int const &low, int const &high);
		
		inline double randNum(double const &low, double const &high)
		{
			return low + (high - low) * rand() / (double) RAND_MAX;
		}
		
		template<typename some_t>
		inline void shuffle(vector<some_t> &tablica)
		{
			for(unsigned int i = 0; i < tablica.size() - 1; ++i)
			{
				unsigned int e = randInt(i, tablica.size() - 1);
				some_t tmp = tablica[i];
				tablica[i] = tablica[e];
				tablica[e] = tmp;
			}
		}
		
		inline static Losowanie & getInstance()
		{
			static Losowanie instance;
			return instance;
		}
};

#endif
