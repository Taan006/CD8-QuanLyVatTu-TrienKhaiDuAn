#pragma once
#include<iostream>
#include"TienichVangoaile.h"
#include"EntityVaRepository.h"
#include<string>
#include<sstream>
#include<limits>
#include<iomanip>

using namespace std;

class PhieuKho : public Entity{
    protected :
        string ngaylap;
        string maDT;
        string maVT;    
        double soluong;
        double dongia;
    public:
        string getmaVT() const {return maVT;}
        double getsoluong() const {return soluong;}

        void nhapphieukho(string doitac){
            string temp;
            cout << "MA phieu: "; 
            getline(cin,ma);
            cout << "Ngay lap: "; getline(cin,ngaylap);
            cout << doitac << ": " ;getline(cin,maDT);
            cout <<"Ma VT: ";getline(cin,maVT);
            cout << "So luong: "; getline(cin,temp); soluong=stoi(temp);
            cout <<"Don gia: "; getline(cin,temp); dongia=stod(temp);

        }
        void capnhatphieukho(string doitac){
            ngaylap = NhapChucapnhat("Sua ngay lap:", ngaylap);
            maDT = NhapChucapnhat("Sua" + doitac,maDT);
            dongia = NhapSocapnhat("Sua don gia:", dongia);
            cout << "[!] Luu y: Khong cho phep sua ma VT va Soluong VT.Hay xoa phieu nay neu nhap sai !\n";

        }
        string basetoFile() const {
            return ma + "|" + ngaylap + "|" + maDT + "|" + maVT +"|"
            + to_string(soluong) + "|" + to_string(dongia);
        }
        void basefromFile(const string& line){
            stringstream ss(line);
            string t;
            getline(ss,ma,'|');
            getline(ss,ngaylap,'|');    
            getline(ss,maDT,'|');
            getline(ss,maVT,'|');
            getline(ss,t,'|'); soluong=stoi(t);
            getline(ss,t,'|'); dongia=stod(t);

        }
        void xuatphieukho() const{
            cout << left << setw(10) << ma << "| " << setw(20) << ngaylap << "| " 
            << setw(20) << maDT << "| " << setw(20) << maVT << "| " << setw(20) 
            << soluong << "| " << setw(20) << dongia << endl;
        }

};

class phieunhap : public PhieuKho{
    public:
        void Nhap() override {nhapphieukho("Ma nha cung cap"); }
        void Capnhat() override{capnhatphieukho("Ma nha cung cap");}
        void xuat() const override{xuatphieukho();}
        string toFile() const override { return basetoFile();}
        void fromFile(const string& line) override {basefromFile(line);}
};

class phieuxuat : public PhieuKho{
    public:
        void Nhap() override {nhapphieukho("Ma doi thi cong");}
        void Capnhat() override {capnhatphieukho("Ma doi thi cong");}
        void xuat() const override {xuatphieukho();}
        string toFile() const override { return basetoFile();}
        void fromFile(const string& line) override { basefromFile(line);}
};