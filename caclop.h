#pragma once
#include<iostream>
#include<string>
#include<limits>
#include<sstream> // stringtream 
#include<iomanip> // setw() va left
#include"EntityVaRepository.h"
#include"TienichVangoaile.h"

using namespace std;

class Vattu : public Entity {
    private :
        string ten;
        double dongia ;
        int soluong;
    public :
        int getsoluong() const {return soluong;}
        void setsoluong(int sl1) {soluong=sl1; }

        void Nhap() override {
            string temp;
            cout << "MA VT :" ; getline(cin,ma);
            cout << "Ten VT:" ; getline(cin,ten);
            cout << "Don gia:"; getline(cin,temp); dongia=stod(temp);
            cout << "so luong ton kho :"; getline(cin,temp); soluong=stoi(temp);
        }

        void Capnhat() override {
            ten = NhapChucapnhat("Sua ten VT", ten);
            dongia = NhapSocapnhat("Sua don gia", dongia);
            soluong = (int)NhapSocapnhat("Sua so luong", soluong);

        }

        void xuat() const override {
            cout<< left << setw(10) << ma << "| " 
                << setw(25) << ten << "| " 
                << setw(25) << dongia << "| " 
                << setw(25) << soluong << "| " << endl;  
        }
        string toFile() const override {
            return ma + "|" + ten + "|" + to_string(dongia) + "|" + to_string(soluong);
        }
        void fromFile(const string& line) override {
            stringstream ss(line); string t;
            getline(ss, ma, '|');
            getline(ss, ten, '|');
            getline(ss, t, '|'); dongia=stod(t);
            getline(ss, t, '|'); soluong=stoi(t);
        }
};

class Nhacungcap : public Entity {
    private :
    string diachi;
    string tenncc;
    string vattucungcap;
    public :
        void Nhap() override {
            cout << "MA NCC :" ;getline(cin,ma);
            cout << "Dia Chi :" ; getline(cin,diachi);
            cout << "Ten NCC:" ; getline(cin,tenncc);
            cout << "Vat tu cung cap:" ; getline(cin,vattucungcap);
        }

        void Capnhat() override {
            tenncc = NhapChucapnhat("Thay doi NCC",tenncc);
            vattucungcap = NhapChucapnhat("Sua doi vat tu cung cap",vattucungcap);

        }
        
        void xuat() const override {
            cout << left << setw(10) << ma <<"| " << setw(25) << diachi << "| " 
            << setw(25) << tenncc <<"| " << setw(25) << vattucungcap <<"| " << endl;

        }

        string toFile() const override {
            return ma +"|" + diachi + "|" + tenncc + "|" + vattucungcap;
        }

        void fromFile(const string& line) override{
            stringstream ss(line);
            getline(ss, ma, '|');
            getline(ss, diachi,'|');
            getline(ss, tenncc, '|');
            getline(ss, vattucungcap,'|');     
        }
};

class DuAn : public Entity {

    private :
        string ten;
        string ngaybatdau;
        string ngayketthuc;
        string trangthai;
    public :
        void Nhap() override {
            cout << "MA DA :" ; getline(cin,ma);
            cout << "Ten DA:" ; getline(cin,ten);
            cout << "Ngay bat dau:" ; getline(cin,ngaybatdau);
            cout << "Ngay ket thuc:" ; getline(cin,ngayketthuc);
            cout << "Trang thai:"; getline(cin,trangthai);
        }

        void Capnhat() override {
            ten = NhapChucapnhat("Sua ten DA",ten);
            ngaybatdau = NhapChucapnhat("Sua ngay bat dau",ngaybatdau);
            ngayketthuc = NhapChucapnhat("Sua ngay ket thuc",ngayketthuc);
            trangthai = NhapChucapnhat("Sua trang thai",trangthai);

        
        }

        void xuat() const override {
            cout << left << setw(10) << ma <<"| " << setw(25) << ten <<"| " 
            << setw(25) << ngaybatdau <<"| " << setw(25) << ngayketthuc <<"| " << setw(25) 
            << trangthai <<"| " << endl;

        }

        string toFile() const override {
            return ma + "|" + ten + "|" + ngaybatdau + "|" + ngayketthuc + "|" + trangthai;
        }

        void fromFile(const string& line) override{
            stringstream ss(line);
            getline(ss, ma, '|');
            getline(ss, ten,'|');
            getline(ss, ngaybatdau, '|');
            getline(ss, ngayketthuc,'|');
            getline(ss, trangthai,'|');    
        }
}; 

class doithicong : public Entity {
        private :
            string ten;
            int soluong;
            string maDA;
        public:
            int getsoluong() const {return soluong;}
            void setsoluong(int sl2) {soluong=sl2; }

            void Nhap() override {
                string temp;
                cout << "MA Doi thi cong :" ; getline(cin,ma);
                cout << "Ten doi thi cong:";getline(cin,ten);
                cout << "So luong nhan cong: "; getline(cin,temp); soluong=stoi(temp);
                cout << "MA DA dang thi cong:"; getline(cin,maDA);
            }

            void Capnhat() override{
                ten = NhapChucapnhat("Sua ten DTC :",ten);
                soluong = NhapSocapnhat("Sua SL nhan cong:", soluong);
                maDA = NhapChucapnhat("Sua MA DA thi cong:", maDA);
            }

            void xuat() const override {
                cout << left << setw(20) << ma <<"| " << setw(20) << ten <<"| " 
                << setw(20) << soluong <<"| " << setw(20) << maDA <<"|" << endl;
            }

            string toFile() const override{
                return ma + "|" + ten + "|" + to_string(soluong) + "|" + maDA + "|";
            } 

            void fromFile(const string&line ) override{
                stringstream ss(line); string t;
                getline(ss,ma,'|');
                getline(ss,ten,'|');
                getline(ss,t,'|'); soluong=stoi(t);
                getline(ss,maDA,'|');
            }

            void xuatchitietDA (Repository<DuAn>& KhoDuAn){
                cout << "Doi thi cong :" << ten << "(MA:" << ma << ")\n";  

                shared_ptr<DuAn> da= KhoDuAn.findById(maDA);

                if(da != nullptr){
                    cout << "---MA Du An dang phu trach---\n";
                    da->xuat();
                }
                else{
                    cout << "Khong tim thay du an co MA:" << maDA << " trong he thong"; 
                }
            }

};

class phieunghiemthu : public Entity {
    private:
        string ten;
        string ngaylap;
        string maDA;
        string danhgia;
    public:
        void Nhap() override {
            cout << "MA Phieu Nghiem Thu:" ; getline(cin,ma);
            cout << "Ten Phieu Nghiem Thu:"; getline(cin,ten);
            cout << "Ngay Lap Phieu :"; getline(cin,ngaylap);
            cout << "Ma DA nghiem thu :"; getline(cin,maDA);
            cout << "Danh Gia DA:"; getline(cin,danhgia);
        }
        
        void Capnhat() override{
            ten = NhapChucapnhat("Sua ten phieu nghiem thu:", ten);
            ngaylap= NhapChucapnhat("Sua ngay lap phieu:", ngaylap);
            maDA = NhapChucapnhat("Sua ma DA nghiem thu:", maDA);
            danhgia = NhapChucapnhat("Sua danh gia:", danhgia);

        }
        
        void xuat() const override {
            cout << left << setw(10) << ma << "| " <<setw(20) << ten <<"| " <<
            setw(15) << ngaylap <<"| " 
            << setw(20) << maDA <<"| " << setw(20) << danhgia <<"| " << endl;
        }

        string toFile() const override{
            return ma + "|" + ten + "|" + ngaylap + "|" + maDA + "|" + danhgia;
        }

        void fromFile(const string& line) override{
            stringstream ss(line);
            getline(ss,ma,'|');
            getline(ss,ten,'|');
            getline(ss,ngaylap,'|');
            getline(ss,maDA,'|');
            getline(ss,danhgia,'|');
        }
        
        void xuatchitietDA(Repository<DuAn>& KhoDuAn) const {
            cout <<"Phieu nghiem thu:" << ten << "\n" <<"(MA:" << ma << ")\n" 
            << "(Ngay lap phieu:" << ngaylap << ")\n";

            shared_ptr<DuAn> da = KhoDuAn.findById(maDA);
            if(da != nullptr){
                cout << "---Phieu nghiem thu cho du an---\n";
                da->xuat();
            }
            else{
                cout << "Khong tim thay phieu nghiem thu cua du an co MA:" << maDA 
                << " trong he thong\n";
            }
        }



};

