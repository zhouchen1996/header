#ifndef _FILE_HH_
#define _FILE_HH_

#include "file.h"
#include <iostream>
#include <string>
#include <memory>

namespace LBM {

	//---------------------------------------------------------------------------------------------
	// fileReader

	template <typename T>
	fileReader<T>::fileReader(T filename, char ftype) {
		if (ftype == 'b')
			input = std::ifstream(filename, std::ifstream::in | std::ifstream::binary);
		else
			input = std::ifstream(filename, std::ifstream::in);
		if (input)
			std::cout << "The file \"" << std::string(filename) 
			<< "\" has been OPEN! OK!" << std::endl;
		else {
			std::cout << "The file \"" << std::string(filename)
				<< "\" cannot open! ERROR!" << std::endl;
			exit(0);
		}
	}

	template <typename T>
	fileReader<T>::~fileReader() {
		input.close();
	}

	//---------------------------------------------------------------------------------------------
	// STLreader

	template <typename T>
	STLreader<T>::STLreader(T filename, char ftype) :fileReader<T>(filename, ftype) {
		if (ftype == 'b') binary();
		else ascii();
	}

	template <typename T>
	typename STLreader<T>::facet STLreader<T>::facetRead() {
		facet facet_temp{};
		float f = 0;
		float* p = &f;
		for (int i = 0; i < 3; i++) {
			input.read((char*)p, 4);
			facet_temp.normal[i] = *p;
		}
		for (int i = 0; i < 3; i++) 
			for (int j = 0; j < 3; j++) {
				input.read((char*)p, 4);
				facet_temp.vertex[i][j] = *p;
			}
		input.seekg(2, std::ios_base::cur);
		return facet_temp;
	}

	template <typename T>
	void STLreader<T>::binary() {
		//std::cout << "binary()" << std::endl;
		int* facetsNumber_p = new int;
		input.seekg(80);
		input.read((char*)facetsNumber_p, 4);
		facetsNumber = *facetsNumber_p;
		delete facetsNumber_p;
		std::cout << "Number of triangular facets: " << facetsNumber << std::endl;

		unsigned int n = facetsNumber;
		while (n >= 1) {
			facetsAll.push_back(facetRead());
			n--;
		}
	}

	template <typename T>
	void STLreader<T>::ascii() {
		std::cout << "ascii() has not defined!" << std::endl;
	}

	template <typename T>
	template <typename T2>
	void STLreader<T>::STLwriterASCII(T2 const& filename) {
		using namespace std;
		std::ofstream of(filename);
		of << "solid demo" << endl << endl;
		for (unsigned int i = 0; i < facetsNumber; i++) {
			of << "facet normal" << " " << facetsAll[i].normal[0] << " " << facetsAll[i].normal[1] << " " << facetsAll[i].normal[2] << endl;
			of << "	outer loop" << endl;
			for (int j = 0; j < 3; j++) {
				of << "		vertex" << " " << facetsAll[i].vertex[j][0] << " " << facetsAll[i].vertex[j][1] << " " << facetsAll[i].vertex[j][2] << endl;
			}
			of << "	endloop" << endl;
			of << "endfacet" << endl << endl;
		}
		of << "endsolid" << endl;
		of.close();
	}

	template <typename T>
	STLreader<T>::~STLreader() {}

}

#endif // !_FILE_HH_