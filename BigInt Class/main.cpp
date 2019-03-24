#include <iostream>
#include "BigInteger.h"

using namespace std;

void test_afisare(BigInt x)
{
    cout<<x;
}

void test_citire()
{
    BigInt x;
    cin>>x;
    cout<<"ESTE"<<x.sumcif(x)<<" ";
    cout<<"A fost citit: ";
    test_afisare(x);
    cout<<"\n";
}

void test_operatii(BigInt x,BigInt y)
{
    cout<<"Primul nr :"<<x<<"\nAl 2 lea:"<<y<<'\n';
    cout<<"Operator x+y "<<x+y<<'\n';
    cout<<"Operator x-y "<<x-y<<'\n';
    cout<<"Operator x*y "<<x*y<<'\n';
    cout<<"Operator x/y "<<x/y<<'\n';
}

void test_putere(BigInt x,int pw_count)
{
    cout<<"Nr ridicat la putere este: "<<pow(x,pw_count)<<'\n';
}

int main()
{
    /// Test declararea
    BigInt big_one(992388), big_two("123"), big_three, big_four;

    /// Test atribuirea =
    big_three = "123483";
    big_four = big_one+big_two;

    /// Test citire
    test_citire();

    /// Test operatori artimetici
    test_operatii(big_one,big_two);

    /// Test ridicare la putere
    test_putere(big_one,5);

    /// Test paritate

    /// Test palindrom

    /// Test suma cifrelor

    return 0;
}
