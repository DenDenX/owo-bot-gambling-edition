#include "rastgele_sayi.h"
#include "text_edit.h"
#include "sleep.h"
#include "oyunlar.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>

using namespace std;
namespace fs = filesystem;
long int PARA;
long int RING;
ofstream yaz;
ifstream oku;
vector<pair<string, int>> commands = {
    {"bj", 1},
    {"cf", 2},
    {"cs", 3},
    {"rg", 4},
    {"gr", 5},
    {"e" , 0}
};    
int karakter_temizle(string metin) {
    string new_metin = "";
    for (char c : metin) {
        if (c >= 48 && c <= 58){
            new_metin += c;
        }
    }
    return !new_metin.empty() ? stoi(new_metin) : -1;
}
bool dosya_kontrol(){
    return fs::exists("data.txt");
}
void dosya_ac() {
    yaz.open("data.txt", ios::trunc);
    yaz << "100000" << endl;
    yaz << "0";
    yaz.close();
    
}
pair <long, long> veri_al(){
    oku.open("data.txt");
    string data;
    getline(oku, data);
    long para = stoi(data);
    getline(oku, data);
    long ring = stoi(data);

    return {para, ring};
}
void para_guncelle(long int n_para, long int ring){
    yaz.close();
    yaz.open("data.txt", ios::trunc);
    yaz << to_string(n_para) << "\n" << to_string(ring) << "\n";
}
bool para_yetiyomu(bool isRing, long money) {

    if (isRing){
        return (money <= RING);
    }
    return (money <= PARA);
}
pair <string, int> ikiye_bol(string &cmd){

    size_t pos = cmd.find(' ');
    if (pos == string::npos)
        return {cmd.substr(0, pos), 0};

    return {cmd.substr(0, pos), karakter_temizle(cmd.substr(pos+1))};
}
void ring_al(long int money){
    if (PARA >= money){
        PARA -= money;
        RING += money * 3 / 4;
        para_guncelle(PARA, RING);
    };
}
void ring_ver(long int money){
    if (money > RING){
        cout << "So sorry, you are poor. \n";
    }else{
        RING -= money;
        PARA += money;
        para_guncelle(PARA, RING);
    }
}
void karsilama_yap(){
    if (dosya_kontrol()){
        auto veri = veri_al();
        PARA = veri.first;
        RING = veri.second;
    }else{
        dosya_ac();
        PARA = 100'000;
        RING = 0;
    }

    cout << "welcome to owo bot gambling special..." << endl;
    cout << "you have *"<< __ted(2, to_string(PARA)) <<"* cwc." << endl;
    cout << endl;
    cout << "commands: \n\
        b : blackjack \n\
        c : coinflip \n\
        cs: cash \n\
        rg: buy ring\n\
        gr: sell ring\n\
        e : exit..." << endl;

    cout << "let's start..." << endl;
}; 
void komut_yurut(string &cmd) {

    pair<string, int> args = ikiye_bol(cmd);
    short int cmd_id = -1;
    
    if (args.second < 10000000 )

    {
        for (int i = 0; i < 6; i++)
        {
            if(commands.at(i).first == args.first){
                cmd_id = commands.at(i).second;
            }
        }
            
        switch (cmd_id){

        case 1: // b
            if(blackjack()){
                cout << "KAZANDIN!"  << endl;
                PARA += args.second;
                para_guncelle(PARA, RING);

            }else{
                cout << "KAYBETTIN!" << endl;
                PARA -= args.second;
                para_guncelle(PARA, RING);
            }
            break;
        case 2: // c

            if (coinflip()){
                cout << "KAZANDIN!"  << endl;
                PARA += args.second;
                para_guncelle(PARA, RING);

            }else{
                cout << "KAYBETTIN!" << endl;
                PARA -= args.second;
                para_guncelle(PARA, RING);
            }

            break;
        case 3: // cs

            cout << __ted(1, to_string(PARA)) << " cwc and" << endl
                << __ted(0, to_string(RING)) << " ring that you got!" << endl;

            break;
        case 4: // rg
            if(para_yetiyomu(false, args.second))
            {   ring_al(args.second);
                cout << __ted(1, to_string(PARA)) << " cwc and" << endl
                    << __ted(0, to_string(RING)) << " ring that you got!" << endl;
            }else{
                cout << "Ah... Where is the money?" << endl;
            }
            break;

        case 5: // rg
            if(para_yetiyomu(true, args.second))
            {   ring_ver(args.second);
                cout << __ted(1, to_string(PARA)) << " cwc and" << endl
                    << __ted(0, to_string(RING)) << " ring that you got!" << endl;
            }else{
                cout << "Ah... Where is the money?" << endl;
            }
            break;

        case 0:
            para_guncelle(PARA, RING);
            yaz.close();
            oku.close();
            exit(0);
            break;
        }

    }
    else{
        cout << "You are just poor!\n";
    }
}
int main(int argc, const char** argv) {

    try{   
        set_srand();
        karsilama_yap();

        while (true) {

            string cmd = "";
            getline(cin, cmd);
            if (cmd == "test_add_money"){
                PARA = 1'000'000;
                RING = 5000;
                para_guncelle(1'000'000, 5000);
            }
            komut_yurut(cmd);
        }
    }catch(exception &e){
        cout << "Program has crashed. Your data is going to deleted to solve this error. \n\
Do you want to continue? (y: Yes, Delete It / n: No, Keep It): ";
        string onay = "y";
        getline(cin, onay);
        if (onay == "y")
            fs::remove("data.txt");
        cout << endl << " Your data has been deleted. Please restart the program." << endl;
        yaz.close();
        oku.close();
        exit(0);
    }

    return 0;
}
