#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>
#include "TienichVangoaile.h"
#include "Entity&Repository.h"

using namespace std;

class Vattu : public Entity{
	private:
		string ten, donvi;
		int soluong;
		double dongia;
	public:
		int getsoluong() const {return soluong;}
		void setsoluong(int sl1) {soluong = sl1;
		}
		void Nhap() override{
			string temp;
			cout << "Ma VT:"; getline(cin, ma);
			cout << "Ten VT:"; getline(cin, ten);
			cout << "So luong VT:"; getline(cin, temp); soluong = stoi(temp);
			cout << "Don vi:"; getline(cin, donvi);
			cout << "Don gia:"; getline(cin, temp); dongia = stod(temp);
		}
		
		void Capnhat() override{
			ten = NhapChucapnhat("Ten VT",ten);
			soluong =(int) NhapSocapnhat("So luong VT", soluong);
			donvi = NhapChucapnhat("Don vi", donvi);
			dongia = NhapSocapnhat("Don gia", dongia);
		}
		
		void xuat() const override{
			cout << fixed << setprecision(0) << left << setw(10) << ma << "| "
			<< setw(20) << ten << "| "
			<< setw(15) << soluong << "| "
			<< setw(10) << donvi << "| "
			<< setw(15) << dongia << "| " << endl;
		}
		
		string toFile() const override{
			return ma + "|" + ten + "|" + to_string(soluong) + "|" + donvi + "|" +to_string((long long)(dongia));
		}
		
		void fromFile(const string& line) override{
			stringstream ss(line);
			string t;
			getline(ss, ma, '|');
			getline(ss, ten, '|');
			getline(ss, t, '|'); soluong = stoi(t);
			getline(ss, donvi, '|');
			getline(ss, t, '|'); dongia = stod(t);
		} 
};

class Nhacungcap : public Entity{
	private :
		string tenncc, diachi, vattucungcap;
	public :
		void Nhap() override{
			cout << "Ma NCC:"; getline(cin, ma);
			cout << "Ten NCC:"; getline(cin, tenncc);
			cout << "Dia chi:"; getline(cin, diachi);
			cout << "Vat tu cung cap:"; getline(cin, vattucungcap);
		}
		
		void Capnhat() override{
			tenncc = NhapChucapnhat("Sua ten NCC", tenncc);
			diachi = NhapChucapnhat("Sua dia chi", diachi);
			vattucungcap = NhapChucapnhat("Sua vat tu cung cap", vattucungcap);
		}
		
		void xuat() const override {
			cout << left << setw(10) << ma << "| "
			<< setw(20) << tenncc << "| "
			<< setw(20) << diachi << "| "
			<< setw(20) << vattucungcap << "| " << endl;
		}
		
		string toFile() const override{
			return ma + "|" + tenncc + "|" + diachi + "|" + vattucungcap;
		}
		
		void fromFile(const string& line) override{
			streamstring ss(line);
			getline(ss, ma, '|');
			getline(ss, tenncc, '|');
			getline(ss, diachi, '|');
			getline(ss, vattucungcap, '|');
		} 
};
