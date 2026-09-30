#include <stdio.h>
#include <string.h>

#define MAX 100
#define HAN_MUON 14
#define TIEN_PHAT_MOI_NGAY 5000

int main() {
    char maPhieu[MAX][15];
    char tenSach[MAX][50];
    int soNgayMuon[MAX];
    int tienPhat[MAX];

    int soLuong = 0;
    int luaChon;

    do {
        printf("\n");
        printf("===============================================================\n");
        printf("      HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS)\n");
        printf("===============================================================\n");
        printf("1. Them luot muon sach moi\n");
        printf("2. Hien thi danh sach muon sach\n");
        printf("3. Cap nhat so ngay muon theo Ma phieu\n");
        printf("4. Xoa luot muon sach theo Ma phieu\n");
        printf("5. Thong ke danh sach phieu muon bi phat\n");
        printf("6. Thoat chuong trinh\n");
        printf("===============================================================\n");
        printf("Lua chon cua ban: ");

        scanf("%d", &luaChon);

        // Xoa bo dem sau khi scanf so
        while (getchar() != '\n');

        switch (luaChon) {

            // =====================================================
            // CHUC NANG 1: THEM PHIEU MUON
            // =====================================================
            case 1: {
                if (soLuong >= MAX) {
                    printf("\nHe thong day, khong the them phieu muon moi!\n");
                    break;
                }

                printf("\n=== THEM LUOT MUON SACH MOI ===\n");

                // Nhap ma phieu va kiem tra trung
                int maHopLe;

                do {
                    maHopLe = 1;

                    printf("Nhap ma phieu muon: ");
                    scanf("%14s", maPhieu[soLuong]);

                    // Xoa '\n' trong bo dem
                    while (getchar() != '\n');

                    // Kiem tra trung ma
                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], maPhieu[soLuong]) == 0) {
                            maHopLe = 0;
                            printf("Loi: Ma phieu '%s' da ton tai!\n",
                                   maPhieu[soLuong]);
                            printf("Vui long nhap ma phieu khac.\n");
                            break;
                        }
                    }

                } while (maHopLe == 0);

                // Nhap ten sach
                printf("Nhap ten sach: ");
                fgets(tenSach[soLuong], sizeof(tenSach[soLuong]), stdin);

                // Xoa ky tu '\n'
                size_t len = strlen(tenSach[soLuong]);

                if (len > 0 && tenSach[soLuong][len - 1] == '\n') {
                    tenSach[soLuong][len - 1] = '\0';
                }

                // Nhap so ngay muon
                do {
                    printf("Nhap so ngay muon thuc te: ");
                    scanf("%d", &soNgayMuon[soLuong]);

                    while (getchar() != '\n');

                    if (soNgayMuon[soLuong] <= 0) {
                        printf("Loi: So ngay muon phai lon hon 0!\n");
                    }

                } while (soNgayMuon[soLuong] <= 0);

                // Tinh tien phat
                tienPhat[soLuong] =
                    (soNgayMuon[soLuong] > HAN_MUON)
                    ? (soNgayMuon[soLuong] - HAN_MUON) * TIEN_PHAT_MOI_NGAY
                    : 0;

                printf("\n--> Tien phat tu dong tinh: %d VNĐ\n",
                       tienPhat[soLuong]);

                soLuong++;

                printf("--> Them luot muon sach thanh cong!\n");

                break;
            }

            // =====================================================
            // CHUC NANG 2: HIEN THI DANH SACH
            // =====================================================
            case 2: {
                if (soLuong == 0) {
                    printf("\nDanh sach muon sach hien dang rong!\n");
                    break;
                }

                printf("\n");
                printf("============================ DANH SACH MUON SACH ============================\n");

                printf("%-5s | %-10s | %-35s | %-10s | %-15s\n",
                       "STT",
                       "Ma Phieu",
                       "Ten Sach",
                       "So Ngay",
                       "Tien Phat (VND)");

                printf("-----------------------------------------------------------------------------\n");

                int tongTienPhat = 0;

                for (int i = 0; i < soLuong; i++) {

                    printf("%-5d | %-10s | %-35s | %-10d | %-15d\n",
                           i + 1,
                           maPhieu[i],
                           tenSach[i],
                           soNgayMuon[i],
                           tienPhat[i]);

                    tongTienPhat += tienPhat[i];
                }

                printf("-----------------------------------------------------------------------------\n");
                printf("Tong so phieu muon: %d\n", soLuong);
                printf("Tong tien phat toan he thong: %d VNĐ\n",
                       tongTienPhat);

                break;
            }

            // =====================================================
            // CHUC NANG 3: CAP NHAT SO NGAY MUON
            // =====================================================
            case 3: {
                if (soLuong == 0) {
                    printf("\nDanh sach muon sach hien dang rong!\n");
                    break;
                }

                char maNhap[15];
                int viTri = -1;

                printf("\n=== CAP NHAT SO NGAY MUON ===\n");
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%14s", maNhap);

                while (getchar() != '\n');

                // Tim kiem tuyen tinh
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        viTri = i;
                        break;
                    }
                }

                // Khong tim thay
                if (viTri == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n",
                           maNhap);
                    break;
                }

                printf("Tim thay phieu muon cua sach: %s\n",
                       tenSach[viTri]);

                printf("So ngay hien tai: %d\n",
                       soNgayMuon[viTri]);

                // Nhap so ngay moi
                do {
                    printf("Nhap so ngay muon thuc te moi: ");
                    scanf("%d", &soNgayMuon[viTri]);

                    while (getchar() != '\n');

                    if (soNgayMuon[viTri] <= 0) {
                        printf("Loi: So ngay muon phai lon hon 0!\n");
                    }

                } while (soNgayMuon[viTri] <= 0);

                // Tinh lai tien phat
                tienPhat[viTri] =
                    (soNgayMuon[viTri] > HAN_MUON)
                    ? (soNgayMuon[viTri] - HAN_MUON) * TIEN_PHAT_MOI_NGAY
                    : 0;

                printf("\n--> Tien phat moi: %d VNĐ\n",
                       tienPhat[viTri]);

                printf("--> Cap nhat so ngay muon thanh cong!\n");

                break;
            }

            // =====================================================
            // CHUC NANG 4: XOA PHIEU MUON
            // =====================================================
            case 4: {
                if (soLuong == 0) {
                    printf("\nDanh sach muon sach hien dang rong!\n");
                    break;
                }

                char maNhap[15];
                int viTri = -1;

                printf("\n=== XOA LUOT MUON SACH ===\n");
                printf("Nhap ma phieu muon can xoa: ");
                scanf("%14s", maNhap);

                while (getchar() != '\n');

                // Tim vi tri
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        viTri = i;
                        break;
                    }
                }

                // Khong tim thay
                if (viTri == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n",
                           maNhap);
                    break;
                }

                // Don mang
                for (int i = viTri; i < soLuong - 1; i++) {

                    strcpy(maPhieu[i], maPhieu[i + 1]);

                    strcpy(tenSach[i], tenSach[i + 1]);

                    soNgayMuon[i] = soNgayMuon[i + 1];

                    tienPhat[i] = tienPhat[i + 1];
                }

                soLuong--;

                printf("Xoa phieu muon thanh cong!\n");

                break;
            }

            // =====================================================
            // CHUC NANG 5: THONG KE PHIEU BI PHAT
            // =====================================================
            case 5: {
                if (soLuong == 0) {
                    printf("\nDanh sach muon sach hien dang rong!\n");
                    break;
                }

                printf("\n=== THONG KE PHIEU MUON BI PHAT ===\n");

                printf("%-5s | %-10s | %-35s | %-10s | %-15s\n",
                       "STT",
                       "Ma Phieu",
                       "Ten Sach",
                       "So Ngay",
                       "Tien Phat (VND)");

                printf("-----------------------------------------------------------------------------\n");

                int coPhieuBiPhat = 0;

                for (int i = 0; i < soLuong; i++) {

                    if (soNgayMuon[i] > HAN_MUON) {

                        printf("%-5d | %-10s | %-35s | %-10d | %-15d\n",
                               i + 1,
                               maPhieu[i],
                               tenSach[i],
                               soNgayMuon[i],
                               tienPhat[i]);

                        coPhieuBiPhat++;
                    }
                }

                printf("-----------------------------------------------------------------------------\n");

                if (coPhieuBiPhat == 0) {
                    printf("Khong co luot muon nao bi qua han phat!\n");
                } else {
                    printf("Tong so phieu bi phat: %d\n",
                           coPhieuBiPhat);
                }

                break;
            }

            // =====================================================
            // CHUC NANG 6: THOAT
            // =====================================================
            case 6:
                printf("\nCam on ban da su dung LIBRARY_WMS!\n");
                printf("Tam biet!\n");
                break;

            // =====================================================
            // LUA CHON KHONG HOP LE
            // =====================================================
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng thử lại!\n");
        }

    } while (luaChon != 6);

    return 0;
}