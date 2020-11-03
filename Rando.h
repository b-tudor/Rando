//  Quick and easy pRNG include that uses Mersennes Twister
//  RNG will be seeded with the clock, but can be reseeded with a different value for testing or whatever...
//  I don't care why you are seeding it and you don't have to justify your decisions to me.
//      Rando::rand()               returns a double [0,1] pulled from a uniform distribution
//      Rando::rand_normal()        returns a double pulled from a normal distribution with average = 0
//                                    and variance = 1
//      Rando::seed(unsigned int S) seeds the RNG with S

#pragma once
#ifndef RANDO_H
#define RANDO_H

#include <chrono>
#include <random>
#include <time.h>

class Rando
{
	public:
		static void seed( unsigned int seed ) { mt.seed(seed); }

		static double rand()        { return uniform_distribution(mt); }
		static double rand_normal() { return  normal_distribution(mt); }
	
	private:
		static std::mt19937 mt;
		static std::      normal_distribution<double>  normal_distribution;
		static std::uniform_real_distribution<double> uniform_distribution;
};

// If trying to optimize compile times, move the 'chrono' and 'time.h' headers to a new file (Rando.cpp) along
// with the following:
std::normal_distribution<double>       Rando::normal_distribution(0.0, 1.0);
std::uniform_real_distribution<double> Rando::uniform_distribution( 0.0, 1.0 );
std::mt19937 Rando::mt((unsigned int) std::chrono::high_resolution_clock::now().time_since_epoch().count() );

#endif