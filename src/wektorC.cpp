#include "wektor.cpp"

template class Wektor<double,3>;                                                           //To i wszystkie podobne powtórki po to żeby liczyć dopełnienia
template class Wektor<double,2>;

template<>
int Wektor<double,3>::ileIstnieje = 0;
template<>
int Wektor<double,3>::ileStworzono = 0;

template<>
int Wektor<double,2>::ileIstnieje = 0;
template<>
int Wektor<double,2>::ileStworzono = 0;


template std::istream & operator >> (std::istream & strm,Wektor <double,3> &W);
template std::ostream & operator << (std::ostream & strm,const Wektor <double,3> &W);

