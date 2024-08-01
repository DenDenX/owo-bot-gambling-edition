#include <string>
using namespace std;

// You can use string pointers instead of string


/*  
Komutlar
    Kirmizi - 0
    Mavi - 1
    Kalin - 2
    Alti Cizili - 3
*/
string __ted(int komut, string metin) {

    string on_ek = "\033[";

    switch (komut)
    {
    case 0:
        on_ek += "33m";
        break;
    case 1:
        on_ek += "34m";
        break;
    case 2:
        on_ek += "1m";
        break;
    case 3:
        on_ek += "4m";
        break;

    
    default:
        on_ek += "1m";
        break;
    }

    return on_ek + metin + "\033[0m";
    
}
