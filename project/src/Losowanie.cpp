#include "Losowanie.hpp"

#include <stdint.h>

int Losowanie::randInt(int const &low, int const &high)
{
	int64_t val = rand();   // int64_t  to znak z 64 bitami
	int64_t max = RAND_MAX;
	int64_t scope = high + 1 - low;
	int ret;
	while(max < scope)
	{
		val *= ((int64_t) RAND_MAX + 1);
		val += rand();
		max *= ((int64_t) RAND_MAX + 1);
	}
	if(((val + scope - 1) / scope) * scope < max)
	{
		ret = low + val % scope;
	}
	else
	{
		ret = randInt(low, high);
	}
	return ret;
}
