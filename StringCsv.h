#ifndef STRINGCSV_H
#define STRINGCSV_H

#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>


namespace opmm {


class StringCsv
{
//Friends
public:
    friend std::ostream& operator<<(std::ostream &os, const StringCsv &strCsv);

//static const
public:
    static const size_t npos = -1;

public:
    StringCsv();

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

    //Reimplementacoes/////////
    std::string csvDelimiter() const;
    void setCsvDelimiter(const std::string &value);


    //Member functions
    StringCsv &operator =(const std::string &str);

    //Capacity
    size_t size();
    size_t length();
    size_t max_size();
    void resize(const size_t &n)  throw(std::exception, std::string);
    size_t capacity();
    void reserve(const size_t &n) throw(std::length_error, std::bad_alloc, std::string);
    void clear();
    bool empty();
    void shrink_to_fit() throw(std::bad_alloc, std::string);

    //iterator


    //Element access
    std::string& operator [](const size_t &pos);
    std::string at(const size_t &pos) throw(std::out_of_range, std::string);
    std::string back();
    std::string front();

    //Modifiers
    StringCsv &operator +=(const StringCsv &strCsv);
    StringCsv &operator +=(const std::string &str);
    StringCsv operator +(const std::string &str);

    //StrCsv Operations
    bool operator ==(const StringCsv &strCsv);
    size_t find(const std::string &str, const size_t &pos = 0);
    //StringCsv substr(const size_t &pos = 0, const size_t &len = StringCsv::npos) const throw(std::out_of_range);

private:
    const std::string PARAMETRO_INEXISTENTE = "$PI$";

    std::string mStr;
    std::vector<std::string> mVectorStrSplitted;
    unsigned short mVectorStrSplittedSize;

    std::string mSeparadorCsv = ";";

    void splitString3();

};

//Non-member function overloads
StringCsv operator +(const StringCsv &lhs, const StringCsv &rhs);
StringCsv operator +(const std::string &str, const StringCsv &rhs);
std::ostream& operator<<(std::ostream &os, const StringCsv &strCsv);

}

#endif // STRINGCSV_H
