#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Sach {
private:
    string maSach;
    string tenSach;
    string tacGia;
    string nhaXuatBan;
    int namXuatBan;
    int soLuongBanSao;

public:
    Sach() {
        maSach = "";
        tenSach = "";
        tacGia = "";
        nhaXuatBan = "";
        namXuatBan = 0;
        soLuongBanSao = 0;
    }

    void nhap() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Ma sach: ";
        getline(cin, maSach);

        cout << "Ten sach: ";
        getline(cin, tenSach);

        cout << "Tac gia: ";
        getline(cin, tacGia);

        cout << "Nha xuat ban: ";
        getline(cin, nhaXuatBan);

        cout << "Nam xuat ban: ";
        cin >> namXuatBan;

        cout << "So luong ban sao: ";
        cin >> soLuongBanSao;
    }

    void xuat() const {
        cout << "Ma sach: " << maSach << endl;
        cout << "Ten sach: " << tenSach << endl;
        cout << "Tac gia: " << tacGia << endl;
        cout << "Nha xuat ban: " << nhaXuatBan << endl;
        cout << "Nam xuat ban: " << namXuatBan << endl;
        cout << "So luong ban sao: " << soLuongBanSao << endl;
    }

    string getMaSach() const {
        return maSach;
    }

    string getTacGia() const {
        return tacGia;
    }

    int getNamXuatBan() const {
        return namXuatBan;
    }
};
