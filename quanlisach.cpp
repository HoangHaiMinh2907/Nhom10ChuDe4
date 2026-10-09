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
