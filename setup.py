from distutils.core import setup, Extension

module1 = Extension('distributions', sources = ['distributions.c'])

setup (name = 'distributions',
	version = '1.1',
	description = 'Модуль для работы с дискретными распределениями вероятностей',
	ext_modules = [module1])