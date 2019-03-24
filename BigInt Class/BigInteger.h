#ifndef BIGINTEGER_H_INCLUDED
#define BIGINTEGER_H_INCLUDED

#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

class BigInt
{

private:

    vector<int> my_vector;
    bool my_sign_;
    void elim_zero();
    static BigInt ZERO;
    static BigInt ONE;
    static BigInt TWO;
    static BigInt TEN;

public:

    bool paritate(const BigInt& my_value)
    {
        return my_value.my_vector[my_vector.size()-1]%2;
    }

    int sumcif(const BigInt& my_value)
    {
        int sumcif=0;
        for(int i=0; i<my_value.my_vector.size(); i++)
        {
            sumcif+=my_value.my_vector[i];
        }
        return sumcif;
    }

    int palindrom(const BigInt& my_value)
    {
        for(int i=0; i<my_value.my_vector.size()/2; i++)
        {
            if(my_value.my_vector[i]!=my_value.my_vector[my_value.my_vector.size()-1])
                return 0;
        }
        return 1;
    }

    /// Constructor cu sau fara parametrii
    BigInt();
    explicit BigInt(const int);
    explicit BigInt(const char *);
    explicit BigInt(const string &);

    /// Operatorii operatii aritmetice
    const BigInt operator++(int);
    const BigInt operator--(int);
    friend BigInt operator+(const BigInt&, const BigInt&);
    friend BigInt operator-(const BigInt&, const BigInt&);
    friend BigInt operator*(const BigInt&, const BigInt&);
    friend BigInt operator/(const BigInt&, const BigInt&);
    friend BigInt operator%(const BigInt&, const BigInt&);
    BigInt& operator++();
    BigInt& operator--();
    BigInt& operator+();
    BigInt& operator-();
    BigInt& operator+=(const BigInt&);
    BigInt& operator-=(const BigInt&);
    BigInt& operator*=(const BigInt&);
    BigInt& operator/=(const BigInt&);
    BigInt& operator%=(const BigInt&);

    /// Operator atribuire
    BigInt operator=(const BigInt&);
    BigInt operator=(const string&);

    /// Ridicare la putere
    friend BigInt pow(const BigInt&, const BigInt&);
    friend BigInt pow(const BigInt&, const int);

    /// Citire/Afisare
    friend istream& operator>>(istream&, BigInt&);
    friend ostream& operator<<(ostream&, const BigInt&);

    /// Operator comparare
    friend bool operator>(const BigInt&, const BigInt&);
    friend bool operator>=(const BigInt&, const BigInt&);
    friend bool operator<(const BigInt&, const BigInt&);
    friend bool operator<=(const BigInt&, const BigInt&);
    friend bool operator==(const BigInt&, const BigInt&);
    friend bool operator!=(const BigInt&, const BigInt&);


};

/// Utilitati predefinite
BigInt BigInt::ZERO = BigInt(0);
BigInt BigInt::ONE  = BigInt(1);
BigInt BigInt::TWO  = BigInt(2);
BigInt BigInt::TEN  = BigInt(10);


///Constructor fara parametrii
BigInt::BigInt()
{
    my_vector.clear();
    my_sign_ = true;
}

///Constructor cu int
BigInt::BigInt(int my_value)
{
    my_vector.clear();
    if (my_value >= 0)
        my_sign_ = true;
    else
    {
        my_sign_ = false;
        my_value = -my_value;
    }
    if (my_value == 0)
    {
        my_vector.push_back(0);
    }
    while (my_value > 0)
    {
        my_vector.push_back(my_value % 10);
        my_value /= 10;
    }
}

///Constructor cu sir de caractere
BigInt::BigInt(const char* my_value)
{
    my_vector.clear();
    my_sign_ = true;
    int tmp = 0;
    if (my_value[0] == '-')
    {
        my_sign_ = false;
        tmp = 1;
    }
    int len = strlen(my_value);
    for (int i = len - 1; i > 0 + tmp; --i)
    {
        my_vector.push_back(my_value[i] - '0');
    }
    my_vector.push_back(my_value[0 + tmp] - '0');
}

/// Constructor cu string
BigInt::BigInt(const string& my_value)
{
    my_vector.clear();
    my_sign_ = true;
    int tmp = 0;
    if (my_value[0] == '-')
    {
        my_sign_ = false;
        tmp = 1;
    }
    for (string::size_type i = my_value.size() - 1; i > 0 + tmp; --i)
    {
        my_vector.push_back(my_value[i] - '0');
    }
    my_vector.push_back(my_value[0 + tmp] - '0');
}

/// Operator atribuire
BigInt BigInt::operator=(const BigInt& my_value)
{
    my_vector.clear();
    my_sign_ = my_value.my_sign_;
    for (vector<int>::size_type i = 0; i < my_value.my_vector.size(); ++i)
    {
        my_vector.push_back(my_value.my_vector[i]);
    }
    return *this;
}

BigInt BigInt::operator=(const string& my_value)
{
    my_vector.clear();
    my_sign_ = true;
    int tmp = 0;
    if (my_value[0] == '-')
    {
        my_sign_ = false;
        tmp = 1;
    }
    for (string::size_type i = my_value.size() - 1; i > 0 + tmp; --i)
    {
        my_vector.push_back(my_value[i] - '0');
    }
    my_vector.push_back(my_value[0 + tmp] - '0');
    return *this;
}

BigInt operator+(const BigInt& lhs, const BigInt& rhs)
{
    BigInt ret(lhs);
    ret += rhs;
    return ret;
}

BigInt operator-(const BigInt& lhs, const BigInt& rhs)
{
    BigInt ret(lhs);
    ret -= rhs;
    return ret;
}

BigInt operator*(const BigInt& lhs, const BigInt& rhs)
{
    BigInt ret(lhs);
    ret *= rhs;
    return ret;
}

BigInt operator/(const BigInt& lhs, const BigInt& rhs)
{
    BigInt ret(lhs);
    ret /= rhs;
    return ret;
}

BigInt operator%(const BigInt& lhs, const BigInt& rhs)
{
    BigInt ret(lhs);
    ret %= rhs;
    return ret;
}

BigInt& BigInt::operator+=(const BigInt& my_value)
{
    if (my_sign_ == my_value.my_sign_)
    {
        while (my_vector.size() <= my_value.my_vector.size())
        {
            my_vector.push_back(0);
        }
        int carry = 0;
        vector<int>::size_type i;
        for (i = 0; i < my_value.my_vector.size(); ++i)
        {
            my_vector.at(i) += carry + my_value.my_vector.at(i);
            if (my_vector[i] >= 10)
            {
                carry = 1;
                my_vector[i] -= 10;
            }
            else
                carry = 0;
        }
        for ( ; i < my_vector.size(); ++i)
        {
            my_vector.at(i) += carry + 0;
            if (my_vector[i] >= 10)
            {
                carry = 1;
                my_vector[i] -= 10;
            }
            else
                carry = 0;
        }
    }
    else
    {
        if (my_sign_ == true && my_value.my_sign_ == false)
        {
            BigInt tmp(my_value);
            tmp.my_sign_ = true;
            *this -= tmp;
        }
        else
        {
            BigInt tmp(*this);
            tmp.my_sign_ = true;
            *this = my_value - tmp;
        }
    }
    elim_zero();
    return *this;
}

BigInt& BigInt::operator-=(const BigInt& my_value)
{
    BigInt tmp;
    if (*this < my_value)
    {
        tmp = *this;
        *this = my_value;
        this->my_sign_ = false;
    }
    else
    {
        tmp = my_value;
    }
    int bor = 0;
    vector<int>::size_type i;
    for (i = 0; i < tmp.my_vector.size(); ++i)
    {
        my_vector[i] -= bor + tmp.my_vector[i];
        if (my_vector[i] < 0)
        {
            bor = 1;
            my_vector[i] += 10;
        }
        else
            bor = 0;
    }
    for ( ; i < my_vector.size(); ++i)
    {
        my_vector[i] -= bor;
        if (my_vector[i] < 0)
        {
            bor = 1;
            my_vector[i] += 10;
        }
        else
            bor = 0;
    }
    elim_zero();
    return *this;
}

BigInt& BigInt::operator*=(const BigInt& my_value)
{
    BigInt ret;
    if (this->my_sign_ == my_value.my_sign_)
        ret.my_sign_ = true;
    else
        ret.my_sign_ = false;
    for (vector<int>::size_type i = 0; i < my_vector.size(); ++i)
    {
        for (vector<int>::size_type j = 0; j < my_value.my_vector.size(); ++j)
        {
            if (i + j < ret.my_vector.size())
            {
                ret.my_vector[i + j] += my_vector[i] * my_value.my_vector[j];
            }
            else
            {
                ret.my_vector.push_back(my_vector[i] * my_value.my_vector[j]);
            }
        }
    }
    for (vector<int>::size_type i = 0; i < ret.my_vector.size(); ++i)
    {
        if (i + 1 < ret.my_vector.size())
        {
            ret.my_vector[i + 1] += ret.my_vector[i] / 10;
        }
        else if (ret.my_vector[i] >= 10)
        {
            ret.my_vector.push_back(ret.my_vector[i] / 10);
        }
        else
        {
            break;
        }
        ret.my_vector[i] %= 10;
    }
    ret.elim_zero();
    *this = ret;
    return *this;
}

BigInt& BigInt::operator/=(const BigInt& my_value)
{
    if (*this == my_value)
    {
        *this = BigInt::ONE;
        return *this;
    }
    BigInt ret(0);
    if (my_sign_ == my_value.my_sign_)
        ret.my_sign_ = true;
    else
        ret.my_sign_ = false;

    BigInt divider(my_value);

    this->my_sign_ = true;
    divider.my_sign_ = true;

    if (*this < divider)
    {
        *this = BigInt::ZERO;
        return *this;
    }

    int cnt = 0;
    while (*this > BigInt::ZERO)
    {
        if (*this >= divider)
        {
            *this -= divider;
            ret += pow(BigInt::TEN, cnt);
            divider *= BigInt::TEN;
            cnt++;
        }
        else
        {
            divider = my_value;
            cnt = 0;
            if (*this < divider)
            {
                ret.elim_zero();
                *this = ret;
                return *this;
            }
        }
        divider.my_sign_ = true;
    }

    ret.elim_zero();
    *this = ret;
    return *this;
}

BigInt& BigInt::operator%=(const BigInt& my_value)
{
    *this = *this - (*this / my_value) * my_value;
    return *this;
}

BigInt& BigInt::operator++()
{
    *this += BigInt::ONE;
    return *this;
}

BigInt& BigInt::operator--()
{
    *this -= BigInt::ONE;
    return *this;
}

const BigInt BigInt::operator++(int)
{
    BigInt temp = *this;
    ++(*this);
    return BigInt(temp);
}

const BigInt BigInt::operator--(int)
{
    BigInt temp = *this;
    --(*this);
    return BigInt(temp);
}

BigInt& BigInt::operator+()
{
    return *this;
}

BigInt& BigInt::operator-()
{
    this->my_sign_ = !(this->my_sign_);
    return *this;
}

bool operator>(const BigInt& lhs, const BigInt& rhs)
{
    return (lhs != rhs) && (rhs < lhs);
}

bool operator>=(const BigInt& lhs, const BigInt& rhs)
{
    return !(lhs < rhs);
}

bool operator<(const BigInt& lhs, const BigInt& rhs)
{
    if (lhs.my_sign_ == false && rhs.my_sign_ == true)
        return true;
    if (lhs.my_sign_ == true && rhs.my_sign_ == false)
        return false;
    if (lhs.my_sign_)
    {
        if (lhs.my_vector.size() < rhs.my_vector.size())
            return true;
        else if (lhs.my_vector.size() > rhs.my_vector.size())
            return false;
    }
    else
    {
        if (lhs.my_vector.size() < rhs.my_vector.size())
            return false;
        else if (lhs.my_vector.size() > rhs.my_vector.size())
            return true;
    }
    for (vector<int>::size_type i = lhs.my_vector.size() - 1; i > 0; --i)
    {
        if (lhs.my_vector[i] < rhs.my_vector[i])
        {
            if (lhs.my_sign_)
                return true;
            else
                return false;
        }
        else if (lhs.my_vector[i] > rhs.my_vector[i])
        {
            if (lhs.my_sign_)
                return false;
            else
                return true;
        }
    }
    if (lhs.my_vector[0] < rhs.my_vector[0])
    {
        if (lhs.my_sign_)
            return true;
        else
            return false;
    }
    return false;
}

bool operator<=(const BigInt& lhs, const BigInt& rhs)
{
    return !(lhs > rhs);
}

bool operator==(const BigInt& lhs, const BigInt& rhs)
{
    if (lhs.my_sign_ != rhs.my_sign_
            || lhs.my_vector.size() != rhs.my_vector.size())
        return false;
    for (vector<int>::size_type i = 0; i < lhs.my_vector.size(); i++)
    {
        if (lhs.my_vector.at(i) != rhs.my_vector.at(i))
            return false;
    }
    return true;
}

bool operator!=(const BigInt& lhs, const BigInt& rhs)
{
    return !(lhs == rhs);
}

istream& operator>>(istream& in, BigInt& o_val)
{
    string tmp;
    in >> tmp;
    o_val = tmp;
    return in;
}

ostream& operator<<(ostream& out, const BigInt& my_value)
{
    if (my_value.my_vector.size() == 0)
    {
        out << "0";
    }
    else
    {
        if (my_value.my_sign_ == false)
            out << '-';
        for (vector<int>::size_type i = my_value.my_vector.size() - 1; i > 0; --i)
        {
            out << my_value.my_vector[i];
        }
        out << my_value.my_vector[0];
    }
    return out;
}

BigInt pow(const BigInt& my_value, const BigInt& i_exp)
{
    if (i_exp == BigInt::ZERO || my_value == BigInt::ONE)
    {
        return BigInt::ONE;
    }
    if (my_value == BigInt::ZERO)
    {
        return BigInt::ZERO;
    }

    BigInt i(0);
    BigInt ret(my_value);
    BigInt exp(i_exp);

    exp -= BigInt::ONE;

    while (i < exp)
    {
        ret *= my_value;
        ++i;
    }

    return ret;
}

BigInt pow(const BigInt& my_value, const int i_exp)
{
    BigInt exp(i_exp);
    return pow(my_value, exp);
}

void BigInt::elim_zero()
{
    while (my_vector.size() > 1 && my_vector[my_vector.size() - 1] == 0)
        my_vector.pop_back();
}

#endif
