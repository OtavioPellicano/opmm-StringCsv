#include "StringCsv.h"

namespace opmm {

StringCsv::StringCsv()
    :mSeparadorCsv(";")
{

}

StringCsv::StringCsv(const std::string &str, const std::string &separadorCsv)
    :mSeparadorCsv(separadorCsv)
{
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

std::string StringCsv::csvDelimiter() const
{
    return this->mSeparadorCsv;
}

void StringCsv::setCsvDelimiter(const std::string &value)
{
    this->mSeparadorCsv = value;
}

std::string StringCsv::operator [](const size_t &pos)
{
    if(mVectorStrSplitted.empty())
        return PARAMETRO_INEXISTENTE;

    if (pos < StringCsv::size())
        return mVectorStrSplitted[pos];
    else
        return PARAMETRO_INEXISTENTE;
}

std::string StringCsv::at(const size_t &pos) throw(std::out_of_range, std::string)
{
    try{
        return mVectorStrSplitted.at(pos);
    } catch (std::out_of_range)
    {
        throw;
    } catch(...)
    {
        throw std::string ("unknown exception");
    }
}

std::string StringCsv::back()
{
    if(!mVectorStrSplitted.empty())
        return mVectorStrSplitted[StringCsv::size() - 1];
    else
        return PARAMETRO_INEXISTENTE;
}

std::string StringCsv::front()
{
    if(!mVectorStrSplitted.empty())
        return mVectorStrSplitted[0];
    else
        return PARAMETRO_INEXISTENTE;

}

StringCsv &StringCsv::operator +=(const StringCsv &strCsv)
{
    size_t pos = this->vectorStrSplitted().size();
    try {
        this->mVectorStrSplitted.resize(this->mVectorStrSplitted.size() + strCsv.mVectorStrSplitted.size());
    } catch (...) {
        throw;
    }

    for(std::vector<std::string>::const_iterator itVec = strCsv.mVectorStrSplitted.begin();
        itVec != strCsv.mVectorStrSplitted.end(); ++itVec)
    {
        this->mVectorStrSplitted[pos++] = *itVec;
    }

    return *this;

}

StringCsv &StringCsv::operator +=(const std::string &str)
{
    try {
        this->mVectorStrSplitted.push_back(str);
    } catch (...) {
        throw;
    }

    return *this;
}

StringCsv &StringCsv::operator =(const std::string &str)
{
    this->setStr(str);
    return *this;
}

StringCsv &StringCsv::operator +(const std::string &str)
{
    this->setStr(this->mStr + this->mSeparadorCsv + str);
    return *this;
}


bool StringCsv::operator ==(const StringCsv &strCsv)
{
    if (this->mVectorStrSplitted.size() != strCsv.mVectorStrSplitted.size())
    {
        return false;
    }

    for(size_t pos = 0; pos < this->mVectorStrSplitted.size(); ++pos)
    {
        if(this->mVectorStrSplitted[pos] != strCsv.mVectorStrSplitted[pos])
        {
            return false;
        }
    }

    return true;
}

size_t StringCsv::size()
{
    return mVectorStrSplitted.size();
}

size_t StringCsv::length()
{
    return mVectorStrSplitted.size();
}

bool StringCsv::empty()
{
    if(mVectorStrSplitted.empty())
        return true;
    else
        return false;
}

void StringCsv::shrink_to_fit() throw(std::bad_alloc, std::string)
{
    try {
        mVectorStrSplitted.shrink_to_fit();
    } catch (std::bad_alloc) {
        throw;
    } catch(...)
    {
        throw std::string ("unknown exception");
    }
}

size_t StringCsv::max_size()
{
    return mVectorStrSplitted.max_size();
}

void StringCsv::resize(const size_t &n) throw(std::bad_alloc, std::string)
{
    try{
        mVectorStrSplitted.resize(n);
    } catch(std::bad_alloc)
    {
        throw;
    } catch(...)
    {
        throw std::string ("unknown exception");
    }
}

size_t StringCsv::capacity()
{
    return mVectorStrSplitted.capacity();
}

void StringCsv::reserve(const size_t &n) throw(std::length_error, std::bad_alloc, std::string)
{
    try{
        mVectorStrSplitted.reserve(n);
    } catch(std::length_error)
    {
        throw;
    } catch(std::bad_alloc)
    {
        throw;
    } catch(...)
    {
        throw std::string ("unknown exception");
    }
}

void StringCsv::clear()
{
    mVectorStrSplitted.clear();
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

std::ostream &operator<<(std::ostream &os, const StringCsv &strCsv)
{
    for(std::vector<std::string>::const_iterator itVec = strCsv.mVectorStrSplitted.begin();
        itVec != strCsv.mVectorStrSplitted.end(); ++itVec)
    {
        try {
            if(itVec != strCsv.mVectorStrSplitted.end() - 1)
            {
                os << *itVec << strCsv.mSeparadorCsv;
            }
            else
            {
                os << *itVec;
            }
        } catch (...) {
            throw;
        }
    }
    return os;
}

StringCsv operator +(const StringCsv &lhs, const StringCsv &rhs)
{
    StringCsv strCsv(lhs.str(), lhs.csvDelimiter());
    strCsv += rhs;
    return strCsv;
}

StringCsv operator +(const std::string &str, const StringCsv &rhs)
{
    StringCsv strCsv(str, rhs.csvDelimiter());
    strCsv += rhs;
    return strCsv;
}


}
