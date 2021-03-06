#include "SalesData.h"
#include <string>
#include <iostream>


std::string SalesData::isbn() const 
{
    return m_book_number;
}

SalesData& SalesData::combine(const SalesData &rhs)
{
    m_unit_sold += rhs.m_unit_sold;
    m_revenue += rhs.m_revenue;
    return *this;
}

SalesData& SalesData::operator=(SalesData& data)
{
    m_book_number = data.m_book_number;
    m_unit_sold = data.m_unit_sold;
    m_revenue = data.m_revenue;
    return *this;
}

std::istream& read(std::istream &is, SalesData &data)
{
    std::cout << "please enter the information as isbn unit_sold price"
              << std::endl;
    is >> data.m_book_number
       >> data.m_unit_sold
       >> data.m_price;
    data.m_revenue = data.m_unit_sold * data.m_price;
    return is;
}

std::ostream& print(std::ostream &os, SalesData &data)
{
    os << "the isbn is: " << data.m_book_number << '\n';
    os << "the unit sold is: " << data.m_unit_sold << '\n';
    os << "the revenue is: " << data.m_revenue << std::endl;
    return os;
}

SalesData add(SalesData &lhs, SalesData &rhs)
{
    SalesData sum = lhs;
    sum.combine(rhs);
    return sum;  
}
SalesData operator+(const SalesData &lhs, const SalesData &rhs)
{
    SalesData sum = lhs;
    sum += rhs;
    return sum;
}
std::ostream& operator<<(std::ostream &os, SalesData &rhs)
{
    os << "book number: " << m_book_number << "\n"
       << "sold number: " << m_unit_sold << "\n" 
       << "unit price: " << m_price << "\n" 
       << "the revenue: " << m_revenue << std::endl;
    return os;
}
std::istream& operator>>(std::istream &is, SalesData &rhs)
{
    is >> m_book_number >> m_unit_sold >> m_price;
    if(is) {
        m_revenue = m_unit_sold * m_price;                    
    } else {
        rhs = SalesData();
    }
    return 0;
}

