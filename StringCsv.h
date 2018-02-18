
#ifndef STRINGCSV_H
#define STRINGCSV_H

#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>

namespace opmm {

	class StringCsv
	{
	public:
		StringCsv();
        //StringCsv(std::string str);
        StringCsv(const std::string &str, const std::string &separadorCsv = ";");

		~StringCsv();

		std::string str() const;
		void setStr(const std::string &str);

		void printVectorStringSplitted();
		void printVectorItemStringSplitted(const size_t &pos);

		std::vector<std::string> vectorStrSplitted() const;

		std::string getStrItemStringSplitted(const size_t &pos);
		void setStrItemStringSplitted(const size_t &pos, const std::string strValor);

        std::string getStrItemStringSplittedRange(const size_t &pos1, const size_t &pos2);

		unsigned short getStrCsvSize();

        std::string getSeparadorCsv() const;
        void setSeparadorCsv(const std::string &separadorCsv);

        //Capacity
        size_t size();
        bool empty();


        //Element access
        std::string operator [](const size_t &pos);
        std::string at(const size_t &pos) ;
        std::string back();
        std::string front();





    private:
        const std::string PARAMETRO_INEXISTENTE = "$PI$";


        std::string mStr;
        std::vector<std::string> mVectorStrSplitted;
		unsigned short mVectorStrSplittedSize;

        std::string mSeparadorCsv = ";";

        void splitString3();




	};


}

#endif // STRINGCSV_H
