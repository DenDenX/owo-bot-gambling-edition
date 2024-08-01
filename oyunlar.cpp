#include <iostream>

using namespace std;

// New games will be added.

/*0 -> Heads
1 -> Tails*/
bool coinflip(){
    // This code does not support to select heads or tails.
    // You can fix that.
    if (rrr(0, 1) == 1){
        return true;
    }
    return false;
}

bool blackjack(){
    // This code is not serves an actual blackjack game.
    // You can fix that.
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
