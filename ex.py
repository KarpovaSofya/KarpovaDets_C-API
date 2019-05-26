from distributions import * 

print("Factorial n = 3: " + str(c_factorial(3)))

print("Binomial n = 3 k =2: " + str(c_binomial(3, 2)))

print("Bernoulli Expectation p = 0.4: " + str(c_bernoulliExpectation(0.4)))

print("Bernoulli Dispersion p = 0.4: " + str(c_bernoulliDispersion(0.4)))

print("Binomial Expectation n = 10, p = 0.3: " + str(c_binExpectation(10, 0.3)))

print("Binomial Dispersion n = 10, p = 0.3: " + str(c_binDispersion(10, 0.3)))

print("Binomial Probability n = 10, p = 0.3, k = 3: " + str(c_binProbability(10, 0.3, 3)))

print("Poiss Expectation lam = 2: " + str(c_poissExpectation(2)))

print("Poiss Dispersion lam = 2: " + str(c_poissDispersion(2)))

print("Poiss Probability lam = 2, k = 3: " + str(c_poissProbability(2, 3)))

print("Geometric Expectation p = 0.3: " + str(c_geomExpectation(0.3)))

print("Geometric Dispersion p = 0.3: " + str(c_geomDispersion(0.3)))

print("Geometric Probability p = 0.3, k = 0.3: " + str(c_geomProbability(0.3, 0.3)))

print("Negative Binomial Expectation n = 5, p = 0.3: " + str(c_nbExpectation(5, 0.3)))

print("Negative Binomial Dispersion n = 5, p = 0.3: " + str(c_nbDispersion(5, 0.3)))

print("Negative Binomial Probability n = 5, p = 0.3, k = 3: " + str(c_nbProbability(5, 0.3, 3)))
 