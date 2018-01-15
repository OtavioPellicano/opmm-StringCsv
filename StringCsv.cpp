
#include "StringCsv.h"

namespace opmm {

	StringCsv::StringCsv()
	{

	}


    StringCsv::StringCsv(const std::string &str, const std::string &separadorCsv)
    {
        setSeparadorCsv(separadorCsv);
        setStr(str);

    }

	StringCsv::~StringCsv()
	{
		return;
	}

	std::string StringCsv::str() const
	{
		return mStr;
	}

	void StringCsv::setStr(const std::string &str)
	{
		mStr = str;
		mVectorStrSplitted.clear();
        splitString3();
        mVectorStrSplittedSize = mVectorStrSplitted.size();
	}

	void StringCsv::printVectorStringSplitted()
	{
        unsigned short pos = 0;
		for (std::vector<std::string>::iterator itVec = mVectorStrSplitted.begin(); itVec != mVectorStrSplitted.end(); ++itVec)
        {
            std::cout << "[" << pos++ << "] " << *itVec << std::endl;
		}
	}

	void StringCsv::printVectorItemStringSplitted(const size_t &pos)
	{
		std::cout << mVectorStrSplitted[pos] << std::endl;
	}

	std::vector<std::string> StringCsv::vectorStrSplitted() const
	{
		return mVectorStrSplitted;
	}

	std::string StringCsv::getStrItemStringSplitted(const size_t & pos)
	{
        if (pos < StringCsv::getStrCsvSize())
            return mVectorStrSplitted[pos];
        else
            return PARAMETRO_INEXISTENTE;

	}

	void StringCsv::setStrItemStringSplitted(const size_t & pos, const std::string strValor)
	{
        mVectorStrSplitted[pos] = strValor;
    }

    std::string StringCsv::getStrItemStringSplittedRange(const size_t &pos1, const size_t &pos2)
    {
        if ((pos1 > pos2) || pos2 >= StringCsv::getStrCsvSize())
        {
            return PARAMETRO_INEXISTENTE;
        }

        std::string strTemp("");
        for(size_t i = pos1; i <= pos2; ++i)
        {
            if(i != pos2)
                strTemp += mVectorStrSplitted[i] + ",";
            else
                strTemp += mVectorStrSplitted[i];
        }

        return strTemp;

    }

	unsigned short StringCsv::getStrCsvSize()
	{
		return mVectorStrSplittedSize;
    }

    std::string StringCsv::getSeparadorCsv() const
    {
        return mSeparadorCsv;
    }

    void StringCsv::setSeparadorCsv(const std::string &separadorCsv)
    {
        mSeparadorCsv = separadorCsv;
    }


    void StringCsv::splitString3()
    {
        std::string::iterator itStrBeginWord = mStr.begin();
        for (std::string::iterator itStrEndWord = mStr.begin(); itStrEndWord < mStr.end(); ++itStrEndWord)
        {
            if (itStrEndWord != mStr.end())
            {
                //if (*itStrEndWord == ',' || *itStrEndWord == ';')
                if(*itStrEndWord == mSeparadorCsv[0])
                {
                    mVectorStrSplitted.push_back(std::string(itStrBeginWord, itStrEndWord));
                    itStrBeginWord = itStrEndWord + 1;
                    if(*itStrBeginWord  == '\"')
                    {
                        ++itStrEndWord;
                        while(*(++itStrEndWord) != '\"');
                        if(itStrEndWord == (mStr.end() - 1))
                        {
                            --itStrEndWord;
                            itStrBeginWord = itStrEndWord;
                        }
                    }
                }
                else if (itStrEndWord == (mStr.end() - 1))
                {
                    mVectorStrSplitted.push_back(std::string(itStrBeginWord, mStr.end()));
                }
            }
        }
    }



}
