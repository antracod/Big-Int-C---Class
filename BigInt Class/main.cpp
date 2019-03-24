#include <iostream>
#include "BigInteger.h"
#include <cassert>
using namespace std;

bool test_afisare(BigInt x)
{
    cout<<x;
    return 1;
}

bool test_citire()
{
    BigInt x;
    cin>>x;
    cout<<"A fost citit: ";
    test_afisare(x);
    cout<<"\n";
    return 1;
}

bool test_operatii(BigInt x,BigInt y)
{
    cout<<"Primul nr :"<<x<<"\nAl 2 lea:"<<y<<'\n';
    cout<<"Operator x+y "<<x+y<<'\n';
    cout<<"Operator x-y "<<x-y<<'\n';
    cout<<"Operator x*y "<<x*y<<'\n';
    cout<<"Operator x/y "<<x/y<<'\n';

    return 1;
}

bool test_putere(BigInt x,int pw_count)
{
    cout<<"Nr ridicat la putere este: "<<pow(x,pw_count)<<'\n';

    return 1;
}

bool test_paritate(BigInt x)
{
    if(x.paritate(x)==1)
    {
        cout<<"Impar";
    }
    else
    {
        cout<<"Par";
    }

    return 1;
}

bool test_palindrom(BigInt x)
{
    if(x.palindrom(x)==0)
    {
        cout<<"Nu este Palindrom";
    }
    else
    {
        cout<<"Este palindrom";
    }

    return 1;
}

bool test_suma(BigInt x)
{
    cout<<"Suma cifrelor"<<x.sumcif(x)<<'\n';
    return 1;
}

int main()
{
    /// Test declararea
    BigInt big_one(992388), big_two("123"), big_three, big_four;

    /// Test atribuirea =
    big_three = "123483";
    big_four = big_one+big_two;

    /// Test citire
    assert(test_citire());

    /// Test operatori artimetici
    assert(test_operatii(big_one,big_two));

    /// Test ridicare la putere
    assert(test_putere(big_one,5));

    /// Test paritate
    assert(test_paritate(big_one));
    /// Test palindrom
    assert(test_palindrom(big_one));
    /// Test suma cifrelor
    assert(test_suma(big_one));
    return 0;
}
