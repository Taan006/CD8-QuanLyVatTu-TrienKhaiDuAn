#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<exception>
#include<memory> 
#include "TienichVangoaile.h"  


using namespace std;

class Entity{
    protected:
        string ma;
    public:
        Entity (string m = " ") : ma(m){}
        virtual ~Entity(){}
        const string& getMa() const {return ma;}
        virtual void setMa(const string& m ) {ma =m;}
        virtual void Nhap () = 0;
        virtual void xuat () const = 0;
        virtual void Capnhat() = 0;
        virtual string toFile() const = 0;
        virtual void fromFile (const string& line) = 0;

};

template <class T>
class Repository{
    protected:
        vector<shared_ptr<T>> data;
        string filename;
    public:
        Repository(string file ) : filename("data/" + file) {loadFromFile();}

        void loadFromFile(){
            ifstream file(filename);
            if(!file.is_open()){
                return;
            }
            string line;
            while(getline(file,line)){
                if(line.empty() || line[0] == '#') continue;
                try{
                    shared_ptr<T> obj = make_shared<T>();
                    obj ->fromFile(line);
                    data.push_back(obj);
                }
                catch(const exception& e){
                    cout << "Phat hien loi :" << line << " Da bo qua. \n";
                }
// throw bao loi va dung luong hien tai 
// cout nuot loi va tiep tuc chay

            }
            file.close();
        }

        void SaveToFile(){
            ofstream file (filename);
            if(!file.is_open()) throw ValidationException("Khong the mo file: " + filename );
            for(const auto& obj : data) file << obj->toFile() << endl;   
            file.close();
        }
        
        void add(shared_ptr<T> obj){
            if(findById(obj->getMa()) != nullptr ) throw ValidationException("Ma dinh danh da ton tai");
            data.push_back(obj);
            SaveToFile();
        }

        void remove(string ma){
            auto it = remove_if(data.begin(), data.end(), [&](shared_ptr<T> obj) {return obj->getMa() == ma;});
            if( it !=data.end()){
                data.erase(it,data.end());
                SaveToFile();
                cout << "Da xoa thanh cong";
            }
            else cout << "Khong tim thay ma de xoa!\n";

        }

        void displayall(){
            if(data.empty()){cout << "Danh sach trong!\n"; return;}
            for(const auto& obj : data) obj->xuat();

        }
        shared_ptr<T> findById(string ma){
            for(const auto& obj : data) if(obj->getMa() == ma) return obj;
            return nullptr;
        }
};