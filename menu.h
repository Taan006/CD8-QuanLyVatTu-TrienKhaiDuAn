#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "EntityVaRepository.h"
#include <limits>
#include <iomanip>
#include <memory>
#include "Phieukho.h"
#include "caclop.h"
#include <sstream>
#include "TienichVangoaile.h"

using namespace std;

template <class T>
void menuCRUD(Repository<T>& repo , string title , string headers){
    int choice;
    do {
        cout << "\n--- QUAN LY " << title << "---\n";
        cout << "1.Xem danh sach\n2. Them moi\n3. Sua\n4. Xoa\n0. Quay lai\nchon:";
        choice = NhapSoMenu();
        try{
            if(choice == 1) {
                cout << headers << endl << string(80,'-') << endl; 
                repo.displayall();
            }
            else if(choice == 2){
                shared_ptr<T> obj = make_shared<T>();
                obj->Nhap();
                repo.add(obj);
                cout << "Them thanh cong !\n";
            }
            else if(choice == 3){
                string ma; cout << "Nhap Ma:" ; getline(cin,ma);
                shared_ptr<T> obj = repo.findById(ma);
                if(obj) {
                    obj -> Capnhat();
                    repo.SaveToFile();
                    cout << "Sua thanh cong\n";
                }
                else{
                    cout << "Khong tim thay ! \n";
                }
            }
            else if(choice == 4){
                string ma ;
                cout << "Nhap ma :"; getline(cin,ma);
                repo.remove(ma);
            }
        }catch(exception& e) {
            cout << "Loi :" << e.what() << endl;
        }
    }while(choice !=0);
}

void menuphieunhap(Repository<phieunhap>& repopn, Repository<Vattu>& repovt){
    int choice;
    do{
        cout << "\n---Phieu Nhap Kho---\n";
        cout << "1.xem danh sach\n2. lap phieu xuat\n3. Xoa phieu\n0. Quay lai\nchon:";
        choice = NhapSoMenu();

        try{
            if(choice == 1){
                cout << "Ma PN  | Ngay lap   | MA NCC    | MA VT    | So luong  | Don gia   |\n"
                << string(80,'-') << endl;
                repopn.displayall();
            
            }
            else if(choice == 2){
                shared_ptr<phieunhap> pn = make_shared<phieunhap>(); 
                pn ->Nhap();
                shared_ptr<Vattu> vt = repovt.findById(pn->getmaVT());

                if (!vt) throw ValidationException("Ma vat tu khong khong ton tai!");

                vt -> setsoluong(vt->getsoluong() + pn -> getsoluong() );
                repovt.SaveToFile(); 
                repopn.add(pn);
                cout << "-> Lap phieu thanh cong ! Da cong so vao kho.\n";
            }
            else if(choice == 3){
                string ma; cout << "Nhap Ma Phieu De Xoa:"; getline(cin,ma);
                shared_ptr<phieunhap> pn = repopn.findById(ma);
                if(pn){
                    shared_ptr<Vattu> vt = repovt.findById(pn->getmaVT());

                    if(vt) {vt->setsoluong(vt->getsoluong() - pn -> getsoluong());
                         repovt.SaveToFile();repopn.remove(ma);
                        
                        }else cout << "Khong tim thay Phieu!\n";
                     
                }
            }
        }catch (exception& e) { cout << "Loi :" << e.what() << endl;}
    }while(choice != 0);
}

void menuphieuxuat(Repository<phieuxuat>& repopx , Repository<Vattu>& repovt){
    int choice;
    do{
        cout << "\n---Phieu Xuat Kho---\n";
        cout << "1. Xem danh sach\n2. Lap Phieu Xuat\n3. Xoa phieu\n0. Quay lai\nchon: ";
        choice = NhapSoMenu();
        try{
            if(choice == 1){
                cout << "MA PX  | Ngay lap   | MA DTC   | MA VT  | So luong   | Don gia \n"
                << string(80,'-') << endl;
                repopx.displayall();

            }
            else if(choice == 2){
                shared_ptr<phieuxuat> px = make_shared<phieuxuat>(); px->Nhap();
                shared_ptr<Vattu> vt = repovt.findById(px->getmaVT());
                if(!vt) throw ValidationException("Ma Vat tu khong ton tai!");

                if(vt-> getsoluong() < px-> getsoluong()){
                    throw ValidationException("kho khong du so luong de xuat! (hien co :" + to_string(vt->getsoluong())+")");
                }
                vt-> setsoluong(vt->getsoluong() - px-> getsoluong());
                repovt.SaveToFile();
                repopx.add(px);

                cout << "-> Lap phieu thanh cong! Da tru so luong kho.\n";
            }
            else if(choice == 3){
                string ma; cout << "Nhap ma Phieu Xuat de xoa:"; getline(cin,ma);
                shared_ptr<phieuxuat> px = repopx.findById(ma);
                if(px){
                    shared_ptr<Vattu> vt = repovt.findById(px->getmaVT());

                    if(vt) {
                        vt-> setsoluong(vt->getsoluong() + px-> getsoluong());
                        repovt.SaveToFile();
                    }
                    repopx.remove(ma);
                }
                else cout << "Khong tim thay phieu!\n";
            }
        }catch(exception& e) { cout << "Loi:" << e.what() << endl;}
    }while(choice !=0);
}

void MenuChinh() {

    Repository<Vattu> repoVT("vattu.txt");
    Repository<Nhacungcap> repoNCC("nhacungcap.txt");
    
    Repository<phieunhap> repoPN("phieunhap.txt");
    Repository<phieuxuat> repoPX("phieuxuat.txt");
    
    Repository<DuAn> repoDA("duan.txt");
    Repository<doithicong> repoDTC("doithicong.txt");
    Repository<phieunghiemthu> repoPNT("phieunghiemthu.txt");
    
    Repository<hoadonnhap> repoHDN("hd_nhap.txt");
    Repository<hoadonxuat> repoHDX("hd_xuat.txt");
    Repository<hoadonnhancong> repoHDNC("hd_nhancong.txt");

    int choice;
    do {
        cout << "\n=========== HE THONG QUAN LY VAT TU VA DU AN ===========\n";
        cout << "1. Danh muc Vat Tu & Nha Cung Cap\n";
        cout << "2. Phan he thong KHO \n";
        cout << "3. Phan he thong DU AN\n";
        cout << "4. Phan he thong HOA DON\n";
        cout << "0. Thoat\nChon: ";
        choice = NhapSoMenu();

        if (choice == 1) {
            int sub;
            do {
                cout << "\n--- VAT TU & NHA CUNG CAP ---\n1. Quan ly Vat Tu\n2. Quan ly Nha Cung Cap\n0. Quay lai\nChon: "; 
                sub = NhapSoMenu();
                
                if (sub == 1) menuCRUD(repoVT, "VAT TU", "Ma VT      | Ten VT                 | Don gia        | So luong  ");
                else if (sub == 2) menuCRUD(repoNCC, "NHA CUNG CAP", "Ma NCC    | Dia chi                    | Ten NCC        | Loai VT CC           ");
            } while (sub != 0);
        }
        else if (choice == 2) {
            int sub;
            do {
                cout << "\n--- PHAN HE THONG KHO ---\n1. Phieu Nhap\n2. Phieu Xuat\n3. Kiem tra Ton Kho\n0. Quay lai\nChon: "; 
                sub = NhapSoMenu();
                
                if (sub == 1) menuphieunhap(repoPN, repoVT); 
                else if (sub == 2) menuphieuxuat(repoPX, repoVT);
                else if (sub == 3) {
                    cout << "Ma VT      | Ten VT                     | Don gia        | So luong Ton Kho\n" << string(75, '-') << endl;
                    repoVT.displayall(); 
                }
            } while (sub != 0);
        }
        else if (choice == 3) {
            int sub;
            do {
                cout << "\n--- HE THONG DU AN & THI CONG ---\n1. Quan ly Du An\n2. Quan ly Doi Thi Cong\n3. Phieu Nghiem Thu\n0. Quay lai\nChon: "; 
                sub = NhapSoMenu();
                
                if (sub == 1) menuCRUD(repoDA, "DU AN", "Ma DA      | Ten Du An                  | Ngay BD        | Ngay KT        | Trang thai");
                else if (sub == 2) menuCRUD(repoDTC, "DOI THI CONG", "Ma Doi    | Ten Doi               | So NC          | Ma DA Hien Tai");
                else if (sub == 3) menuCRUD(repoPNT, "PHIEU NGHIEM THU", "Ma Phieu  | Ten Phieu             | Ngay Lap       | Ma Du An       | Danh gia");
            } while (sub != 0);
        }
        else if (choice == 4) {
            int sub;
            do {
                cout << "\n--- HE THONG HOA DON ---\n1. Hoa don Nhap\n2. Hoa don Xuat\n3. Hoa don Nhan cong\n0. Quay lai\nChon: "; 
                sub = NhapSoMenu();
                
                if (sub == 1) menuCRUD(repoHDN, "HD NHAP", "Ma HD      | Ten HD               | Ngay Lap       | Ma NCC         | So Luong   | Don gia        | Tong Tien");
            } while (sub != 0);
        }
    } while (choice != 0);
}