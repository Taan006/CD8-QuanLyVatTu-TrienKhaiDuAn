#pragma once
#include <iostream>
#include<string>
#include<sstream>
#include<limits>
#include<iomanip>
#include"TienichVangoaile.h"
#include"EntityVaRepository.h"
#include"caclop.h"

using namespace std;

class hoadonnhap : public Entity{
    protected:
        string ten;
        string mavt;
        string ngaylap;
        double soluong;
        double dongia;
    public:
        double getsoluong() const {return soluong;}
        double getdongia() const {return dongia;}


        void Nhap() override {
            string temp;
            cout << "MA hoa don:" ;
            getline(cin,ma);
            cout <<"Ten hoa don:"; getline(cin,ten);
            cout <<"Ngay lap:"; getline(cin,ngaylap);
            cout << "Ma VT:"; getline(cin,mavt);
            cout <<"So luong:"; getline(cin,temp); soluong=stoi(temp);
            cout << "Don gia:"; getline(cin,temp); dongia=stoi(temp);
            
        }

        void Capnhat() override {
            ten = NhapChucapnhat("Sua ten hoa don:", ten);
            ngaylap= NhapChucapnhat("Sua ngay lap:", ngaylap);
            mavt = NhapChucapnhat("Sua Ma VT:", mavt);
            soluong= NhapSocapnhat("Sua tong tien:", soluong);
            dongia = NhapSocapnhat("Sua don gia:", dongia);
        }
        
        string toFile() const override  {
            return ma + "|" + ten +"|" + ngaylap +"|" + mavt + "|" + to_string(soluong) +"|" + to_string(dongia); 
        }

        void fromFile(const string& line) override {
            stringstream ss(line);
            string t;
            getline(ss,ma,'|');
            getline(ss,ten,'|');
            getline(ss,ngaylap,'|');
            getline(ss,mavt,'|');
            getline(ss,t,'|'); soluong=stoi(t);
            getline(ss,t,'|'); dongia=stod(t);
        }
        
        void xuat() const override  {
            cout << left << setw(10) << ma << "| " << setw(20) 
            << ten <<"| " << setw(20) <<"| " << ngaylap << "| "
            << setw(20) << to_string(soluong) << "| " << setw(20)
            << to_string(dongia) << "| " << setw(20) << getsoluong()*getdongia() << endl;
        }

        void xuatchitiet(Repository<Vattu>& KhoVT){
            cout << "Hoa Don:" << ten << "\n" << "(MA:" << ma << ")\n";


            shared_ptr<Vattu> da = KhoVT.findById(mavt);

            if(da != nullptr){
                cout << "---hoa don nhap vat tu ---\n";
                da-> xuat();
            }
            else{
                cout <<"khong tim thay hoa don nhap vat tu co ma:" << mavt << "trong he thong\n";
            }
        }

};

class hoadonxuat : public Entity{
    private:
        string ten;
        string mavt;
        string ngaylap;
        double soluong;
        double dongia;
    public:
        double getsoluong() const {return soluong;}
        double getdongia() const {return dongia;}

        void Nhap() override{
            string temp;
            cout << "MA hoa don:";getline(cin,ma);
            cout << "Ten hoa don:"; getline(cin,ten);
            cout << "Ngay lap:"; getline(cin,ngaylap);
            cout << "Ma VT:"; getline(cin,mavt);
            cout << "So luong:"; getline(cin,temp); soluong=stoi(temp);
            cout << "Don gia:"; getline(cin,temp); dongia=stod(temp);

        }

        void Capnhat() override{
            ten = NhapChucapnhat("Sua ten hoa don:", ten);
            ngaylap = NhapChucapnhat("Sua ngay lap:", ngaylap);
            mavt = NhapChucapnhat("Sua ma vt:", mavt);
            soluong = NhapSocapnhat("Sua so luong:", soluong);
            dongia = NhapSocapnhat("Sua don gia:", dongia);
        }

        string toFile() const override{
            return ma + "|" + ten + "|" + ngaylap + "|" + mavt + "|"
            + to_string(soluong) + "|" + to_string(dongia);
        }

        void fromFile(const string& line) override {
            stringstream ss(line);
            string t;
            getline(ss,ma,'|');
            getline(ss, ten ,'|');
            getline(ss,ngaylap,'|');
            getline(ss,mavt,'|');
            getline(ss,t,'|'); soluong=stoi(t);
            getline(ss,t,'|'); dongia=stod(t);
        }
        
        void xuat() const override {
            cout << left << setw(10) << ma << "| " << setw(20) << ten << "| "
            << setw(20) << ngaylap << "| " << setw(20) << to_string(soluong)
            << "| " << setw(20) << to_string(dongia) << "| " << getsoluong()*getdongia() << endl;
        }

        void xuatchitiet(Repository<Vattu>& KhoVT){
            cout << "hoa don xuat:" << ten << "(Ma:" << ma << ")\n";

            shared_ptr<Vattu> da = KhoVT.findById(mavt);

            if(da != nullptr){
                cout << "---hoa don xuat vat tu---\n";
                da->xuat();
            }
            else{
                cout << "Khong tim thay hoa don xuat vat tu co ma:" << mavt << " trong he thong\n";
            }
        }
};

class hoadonnhancong : public Entity{
    private:
        string ten;
        string ngaylap;
        string madtc;
        double soluong;
        double dongia;
    public:

        double getsoluong() const{return soluong;}
        double getdongia() const {return dongia;} 

        void Nhap() override {
            string temp;    
            cout << "Ma hoa don:";  getline(cin,ma);
            cout << "Ten hoa don:"; getline(cin,ten);
            cout << "Ngay lap:";    getline(cin,ngaylap);
            cout << "Ma DTC:" ;     getline(cin,madtc);
            cout << "So luong:";    getline(cin,temp); soluong=stoi(temp);
            cout << "Don gia:";     getline(cin,temp); dongia=stod(temp);
        }
        void Capnhat() override {
            ten = NhapChucapnhat("Sua ten:", ten);
            ngaylap = NhapChucapnhat("Sua ngay lap:", ngaylap);
            madtc = NhapChucapnhat("Sua Ma DTC:", madtc);
            soluong = NhapSocapnhat("Sua so luong:", soluong);
            dongia = NhapSocapnhat("Sua don gia:", dongia);
        }
    
        string toFile() const override{
            return ma + "|" + ten + "|" + ngaylap + "|" + madtc + "|" + to_string(soluong) + "|" + to_string(dongia);
        }

        void fromFile(const string& line) override{
            stringstream ss(line);
            string t;
            getline(ss,ma,'|');
            getline(ss,ten,'|');
            getline(ss,ngaylap,'|');
            getline(ss,madtc,'|');
            getline(ss,t,'|'); soluong=stoi(t);
            getline(ss,t,'|'); dongia=stod(t);
        }

        void xuat() const override {
            cout << left << setw(10) << ma <<"| " << setw(20) << ten << "| "
            << setw(20) << ngaylap << "| " << setw(20) << to_string(soluong) << "| "
            << setw(20) << to_string(dongia) << "| " << getsoluong()*getdongia(); 
        }

        void xuatchitiet(Repository<doithicong>& khothicong){
            cout << "Ten hoa don:" << ten << "(Ma:" << ma << ")\n";

            shared_ptr<doithicong> da =khothicong.findById(madtc);

            if(da !=nullptr){
                cout << "---hoa don nhan cong cua doi thi cong---\n";
                da->xuat();
            }
            else{
                cout << " khong tim thay hoa don nhan cong cua doi thi cong co ma:" << madtc << " trong he thong\n";
            }
        }


};
