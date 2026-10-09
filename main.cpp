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
