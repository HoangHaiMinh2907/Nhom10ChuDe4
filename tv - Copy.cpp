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

class QuanLySach {
private:
    Sach ds[200];
    int n;

public:
    QuanLySach() {
        n = 0;
    }

    void nhapDanhSach() {
        do {
            cout << "Nhap so luong sach (1 - 199): ";
            cin >> n;
        } while (n <= 0 || n >= 200);

        for (int i = 0; i < n; i++) {
            cout << "\nNhap thong tin sach thu " << i + 1 << ":\n";
            ds[i].nhap();
        }
    }

    void xuatDanhSach() const {
        if (n == 0) {
            cout << "Danh sach rong.\n";
            return;
        }

        cout << "\n===== DANH SACH SACH =====\n";

        for (int i = 0; i < n; i++) {
            cout << "\nSach thu " << i + 1 << ":\n";
            ds[i].xuat();
        }
    }

    void sapXep() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (ds[i].getNamXuatBan() >
                    ds[j].getNamXuatBan()) {
                    Sach temp = ds[i];
                    ds[i] = ds[j];
                    ds[j] = temp;
                }
            }
        }

        cout << "Da sap xep theo nam xuat ban tang dan.\n";
    }

    void timKiemMaSach() const {
        if (n == 0) {
            cout << "Danh sach rong.\n";
            return;
        }

        string ma;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nhap ma sach can tim: ";
        getline(cin, ma);

        bool timThay = false;

        for (int i = 0; i < n; i++) {
            if (ds[i].getMaSach() == ma) {
                cout << "\nThong tin sach tim thay:\n";
                ds[i].xuat();
                timThay = true;
                break;
            }
        }

        if (!timThay) {
            cout << "Khong tim thay sach co ma " << ma << ".\n";
        }
    }

    void timKiemTacGia() const {
        if (n == 0) {
            cout << "Danh sach rong.\n";
            return;
        }

        string tacGia;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nhap ten tac gia can tim: ";
        getline(cin, tacGia);

        bool timThay = false;

        for (int i = 0; i < n; i++) {
            if (ds[i].getTacGia() == tacGia) {
                cout << "\nSach cua tac gia " << tacGia << ":\n";
                ds[i].xuat();
                cout << "--------------------------\n";
                timThay = true;
            }
        }

        if (!timThay) {
            cout << "Khong tim thay sach cua tac gia "
                 << tacGia << ".\n";
        }
    }

    void boSung() {
        if (n >= 199) {
            cout << "Danh sach da day.\n";
            return;
        }

        int viTri;

        cout << "Nhap vi tri can bo sung (1 - "
             << n + 1 << "): ";
        cin >> viTri;

        if (viTri < 1 || viTri > n + 1) {
            cout << "Vi tri khong hop le.\n";
            return;
        }

        for (int i = n; i >= viTri; i--) {
            ds[i] = ds[i - 1];
        }

        cout << "\nNhap thong tin sach can bo sung:\n";
        ds[viTri - 1].nhap();

        n++;

        cout << "Bo sung sach thanh cong.\n";
    }

    void xoa() {
        if (n == 0) {
            cout << "Danh sach rong.\n";
            return;
        }

        int viTri;

        cout << "Nhap vi tri can xoa (1 - " << n << "): ";
        cin >> viTri;

        if (viTri < 1 || viTri > n) {
            cout << "Vi tri khong hop le.\n";
            return;
        }

        for (int i = viTri - 1; i < n - 1; i++) {
            ds[i] = ds[i + 1];
        }

        n--;

        cout << "Xoa sach thanh cong.\n";
    }
};

int main() {
    QuanLySach ql;
    int luaChon;

    do {
        cout << "\n===== QUAN LY SACH THU VIEN =====\n";
        cout << "1. Nhap danh sach sach\n";
        cout << "2. In danh sach sach\n";
        cout << "3. Sap xep theo nam xuat ban tang dan\n";
        cout << "4. Tim kiem theo ma sach\n";
        cout << "5. Tim kiem theo ten tac gia\n";
        cout << "6. Bo sung sach vao vi tri cho truoc\n";
        cout << "7. Xoa sach o vi tri cho truoc\n";
        cout << "0. Thoat\n";
        cout << "=================================\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                ql.nhapDanhSach();
                break;

            case 2:
                ql.xuatDanhSach();
                break;

            case 3:
                ql.sapXep();
                break;

            case 4:
                ql.timKiemMaSach();
                break;

            case 5:
                ql.timKiemTacGia();
                break;

            case 6:
                ql.boSung();
                break;

            case 7:
                ql.xoa();
                break;

            case 0:
                cout << "Ket thuc chuong trinh.\n";
                break;

            default:
                cout << "Lua chon khong hop le.\n";
        }

    } while (luaChon != 0);

    return 0;
}
