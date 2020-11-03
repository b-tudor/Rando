# Rando
Simple wrapper for standard C++ Mersenne Twister pRNG.

Quick and easy pRNG include that uses Mersennes Twister
RNG will be seeded with the clock, but can be reseeded with a different value for testing or whatever.

      Rando::rand()               returns a double [0,1] pulled from a uniform distribution
      Rando::rand_normal()        returns a double pulled from a normal distribution with average = 0
                                    and variance = 1
      Rando::seed(unsigned int S) seeds the RNG with S
