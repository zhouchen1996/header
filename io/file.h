#ifndef _FILE_H_
#define _FILE_H_

#include <fstream>
#include <vector>

namespace LBM {

	//---------------------------------------------------------------------------------------------
	// fileReader

	template <typename T>
	class fileReader {
	public:
		fileReader() = delete;
		fileReader(T filename, char ftype = 'a');
		~fileReader();
		std::ifstream input;
	};

	//---------------------------------------------------------------------------------------------
	//STL reader

	template <typename T>
	class STLreader :public fileReader<T>{
	public:
		using fileReader<T>::input;
		STLreader() = delete;
		STLreader(T filename, char ftype = 'a');
		void binary();
		void ascii();
		~STLreader();
		struct facet {
			float normal[3];
			float vertex[3][3];
		};
		facet facetRead();
		template <typename T2> void STLwriterASCII(T2 const&);
	protected:
		unsigned int facetsNumber;
		std::vector<facet> facetsAll;
	};

}

#endif // !_FILE_H_