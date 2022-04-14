#include "myurl.h"

MyUrl::MyUrl()
{
    base_url = "https://r15atm2022.herokuapp.com";
}

QString MyUrl::getBase_url() const
{
    return base_url;
}
