#include <math.h>
#include <Python.h>
#include <stdlib.h>

/**
Определение функций */

int Factorial(int n) 
{
	if (n < 0) 
		return -1;
	if ((n==0)||(n==1)) 
		return 1;
	return n*Factorial(n-1);
}


int Binomial(int n, int k) 
{
	if ((n<0)||(k<0)) 
		return -1;
	return Factorial(n)/(Factorial(k)*Factorial(n-k));
} 


double BernoulliExpectation(double p)
{
	return p;
}


double BernoulliDispersion(double p)
{
	return p - pow(p, 2);
}


double BinExpectation(double n, double p)
{
	return n * p;
}


double BinDispersion(double n, double p)
{
	return n * p * (1 - p);
}


double BinProbability(double n, double p, double k)
{
	return Binomial(n, k) * pow(p, k) * pow((1 - p), n - k);
}


double PoissExpectation(double lam)
{
	return lam;
}

double PoissDispersion(double lam)
{
	return lam;
}

double PoissProbability(double lam, double k)
{
	return (exp(-lam) * pow(lam, k)) / Factorial(k);
}

double GeomExpectation(double p)
{
	return (1 - p) / p;
}

double GeomDispersion(double p)
{
	return (1 - p) / pow(p, 2);
}

double GeomProbability(double p, double k)
{
	return pow(1 - p, k) * p;
}

double NBExpectation(double n, double p)
{
	return n * p / (1 - p);
}

double NBDispersion(double n, double p)
{
	return n * p / pow((1 - p), 2);
}


double NBProbability(double n, double p, double k)
{
	return Binomial(n + k - 1, k) * pow(1 - p, n) * pow(p, k);
}



/**
Определение объектов Python
*/

static PyObject* c_factorial(PyObject* self, PyObject* args)
{
	int n;

	if (!PyArg_ParseTuple(args, "i", &n)) 
		return NULL;

	return Py_BuildValue("i", Factorial(n));
}

static PyObject* c_binomial(PyObject* self, PyObject* args)
{
	int n, k;

	if (!PyArg_ParseTuple(args, "ii", &n, &k)) /*Исключение ошибки аргумента*/
		return NULL;

	return Py_BuildValue("i", Binomial(n, k));
}

static PyObject* c_bernoulliExpectation(PyObject* self, PyObject* args)
{
	double n;

	if (!PyArg_ParseTuple(args, "d", &n)) /*Исключение ошибки аргумента*/
		return NULL;

	return Py_BuildValue("d", BernoulliExpectation(n));
}

static PyObject* c_bernoulliDispersion(PyObject* self, PyObject* args)
{
	double n;

	if (!PyArg_ParseTuple(args, "d", &n)) /*Исключение ошибки аргумента*/
		return NULL;

	return Py_BuildValue("d", BernoulliDispersion(n));
}

static PyObject* c_binExpectation(PyObject* self, PyObject* args)
{
	double n, p;

	if (!PyArg_ParseTuple(args, "dd", &n, &p)) /*Исключение ошибки аргумента*/
		return NULL;

	return Py_BuildValue("d", BinExpectation(n,p));
}

static PyObject* c_binDispersion(PyObject* self, PyObject* args)
{
	double n, p;

	if (!PyArg_ParseTuple(args, "dd", &n, &p)) /*Исключение ошибки аргумента*/
		return NULL;

	return Py_BuildValue("d", BinDispersion(n,p));
}

static PyObject* c_binProbability(PyObject* self, PyObject* args)
{
	double n, p, k;

	if (!PyArg_ParseTuple(args, "ddd", &n, &p, &k)) /*Исключение ошибки аргумента*/
		return NULL;

	return Py_BuildValue("d", BinProbability(n,p,k));
}

static PyObject* c_poissExpectation(PyObject* self, PyObject* args)
{
	double lam;

	if (!PyArg_ParseTuple(args, "d", &lam)) /*Исключение ошибки аргумента*/
		return NULL;

	return Py_BuildValue("d", PoissExpectation(lam));
}

static PyObject* c_poissDispersion(PyObject* self, PyObject* args)
{
	double lam;

	if (!PyArg_ParseTuple(args, "d", &lam)) /*Исключение ошибки аргумента*/
		return NULL;

	return Py_BuildValue("d", PoissDispersion(lam));
}

static PyObject* c_poissProbability(PyObject* self, PyObject* args)
{
	double lam, k;

	if (!PyArg_ParseTuple(args, "dd", &lam, &k)) /*Исключение ошибки аргумента*/
		return NULL;

	return Py_BuildValue("d", PoissProbability(lam,k));
}

static PyObject* c_geomExpectation(PyObject* self, PyObject* args)
{
	double p;

	if (!PyArg_ParseTuple(args, "d", &p)) /*Исключение ошибки аргумента*/
		return NULL;

	return Py_BuildValue("d", GeomExpectation(p));
}


static PyObject* c_geomDispersion(PyObject* self, PyObject* args)
{
	double p;

	if (!PyArg_ParseTuple(args, "d", &p)) /*Исключение ошибки аргумента*/
		return NULL;

	return Py_BuildValue("d", GeomDispersion(p));
}


static PyObject* c_geomProbability(PyObject* self, PyObject* args)
{
	double p, k;

	if (!PyArg_ParseTuple(args, "dd", &p, &k)) /*Исключение ошибки аргумента*/
		return NULL;

	return Py_BuildValue("d", GeomProbability(p, k));
}


static PyObject* c_nbExpectation(PyObject* self, PyObject* args)
{
	double n, p;

	if (!PyArg_ParseTuple(args, "dd", &n, &p)) /*Исключение ошибки аргумента*/
		return NULL;

	return Py_BuildValue("d", NBExpectation(n, p));
}


static PyObject* c_nbDispersion(PyObject* self, PyObject* args)
{
	double n, p;

	if (!PyArg_ParseTuple(args, "dd", &n, &p)) /*Исключение ошибки аргумента*/
		return NULL;

	return Py_BuildValue("d", NBDispersion(n, p));
}


static PyObject* c_nbProbability(PyObject* self, PyObject* args)
{
	double n, p, k;

	if (!PyArg_ParseTuple(args, "ddd", &n, &p, &k)) /*Исключение ошибки аргумента*/
		return NULL;

	return Py_BuildValue("d", NBProbability(n, p, k));
}


static PyMethodDef distributions_methods[] = {
	{"c_factorial",            c_factorial,            METH_VARARGS, "Возвращает факториал числа n"},
	{"c_binomial",             c_binomial,             METH_VARARGS, "Возвращает число сочетаний"},
	{"c_bernoulliExpectation", c_bernoulliExpectation, METH_VARARGS, "Возвращает математическое ожидание распределения Бернулли"},
	{"c_bernoulliDispersion",  c_bernoulliDispersion,  METH_VARARGS, "Возвращает дисперсию распределения Бернулли"},
	{"c_binExpectation",       c_binExpectation,       METH_VARARGS, "Возвращает математическое ожидание биномиального распределения"},
	{"c_binDispersion",        c_binDispersion,        METH_VARARGS, "Возвращает дисперсию биномиального распределения"},
	{"c_binProbability",       c_binProbability,       METH_VARARGS, "Возвращает вероятность случайной величине быть равной k для биномиального распределения"},
	{"c_poissExpectation",     c_poissExpectation,     METH_VARARGS, "Возвращает математическое ожидание распределения Пуассона"},
	{"c_poissDispersion",      c_poissDispersion,      METH_VARARGS, "Возвращает дисперсию распределения Пуассона"},
	{"c_poissProbability",     c_poissProbability,     METH_VARARGS, "Возвращает вероятность случайной величине быть равной k для распределения Пуассона"},
	{"c_geomExpectation",      c_geomExpectation,      METH_VARARGS, "Возвращает математическое ожидание геометрического распределения"},
	{"c_geomDispersion",       c_geomDispersion,       METH_VARARGS, "Возвращает дисперсию геометрического распределения"},
	{"c_geomProbability",      c_geomProbability,      METH_VARARGS, "Возвращает вероятность случайной величине быть равной k для геометрического распределения"},
	{"c_nbExpectation",        c_nbExpectation,        METH_VARARGS, "Возвращает математическое ожидание отрицательного биномиального распределения"},
	{"c_nbDispersion",         c_nbDispersion,         METH_VARARGS, "Возвращает дисперсию отрицательного биномиального распределения"},
	{"c_nbProbability",        c_nbProbability,        METH_VARARGS, "Возвращает вероятность случайной величине быть равной k для отрицательного биномиального распределения"},
	{NULL, NULL, 0, NULL}

};


PyMODINIT_FUNC initdistributions(void)
{
    Py_InitModule("distributions", distributions_methods);
}