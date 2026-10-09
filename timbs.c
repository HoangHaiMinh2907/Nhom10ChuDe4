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
