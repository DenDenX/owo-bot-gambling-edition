#include <iostream>

using namespace std;

/*0 -> Yazi
1 -> Ture*/
bool coinflip(){
    if (rrr(0, 1) == 1){
        return true;
    }
    return false;
}

bool blackjack(){
    short kasa = rrr(1, 21);
    short kisi = rrr(1, 21);

    cout << "Kasa: " << kasa << endl << "Sen: " << kisi <<endl;

    while (true){
        string line;
        getline(cin, line);
        
        short cmd = stoi(line);
        if (cmd == 1){
            kisi += rrr(1,10);
            cout << "Kasa: " << kasa << endl << "Sen: " << kisi <<endl;
            if(kisi > 21)
                return false;
        }else{
            while (true) {
                if (kasa > kisi && kasa < 22)
                    return false;
                else if(kasa < 22){
                    kasa += rrr(1,10);
                    cout << "Kasa: " << kasa << endl << "Sen: " << kisi <<endl;
                }else{
                    return true;
                }
            }
        }
    }

}