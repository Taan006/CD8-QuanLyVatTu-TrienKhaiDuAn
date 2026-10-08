#pragma once
#include <iostream>
#include <string>
#include <exception>


using namespace std;

class ValidationException : public exception {
    private:
        string message;
    public:
        ValidationException (const string& msg) : message(msg){}
        const char* what() const throw() {
            return message.c_str();
    }
};

inline string NhapChucapnhat(const string& prompt , const string& oldval){
    cout << prompt << "(Cu: " << oldval << "Nhan Enter de giu nguyen)";
    string input;
    getline(cin,input);
     return input.empty() ? oldval : input;

}

inline double NhapSocapnhat(const string& prompt , double oldval){
    cout << prompt << "(Cu: " << oldval << "Nhan Enter de giu nguyen)";
    string input;
    getline(cin,input);
    
    if(input.empty()){
        return oldval;
    }
    try{
        double newval = stod(input);

        if(newval<0){
            throw ValidationException("Gia tri khong the la so am . Vui long nhap lai");
        }
        return newval;
    }

    catch(const invalid_argument& e ){
        throw ValidationException("Gia tri khong the la chu . Vui long nhap lai");
    }

    catch(const out_of_range& e){
        throw ValidationException("Gia tri vua nhap vuot qua gioi han. Vui long nhap lai");
        // throw bao loi va dung luong hien tai 
        // cout nuot loi va tiep tuc chay
    }

}

inline int NhapSoMenu() {
    int luaChon;
    cin >> luaChon;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Loi: Ban vua nhap chu. Vui long chi nhap so!\n";
        return -1;  
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return luaChon;
}