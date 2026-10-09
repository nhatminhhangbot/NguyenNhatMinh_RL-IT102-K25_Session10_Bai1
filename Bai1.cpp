#include <stdio.h>
#include <string.h>

#define MAX_VE 100
#define MAX_VE_PER_ORDER 4

struct VeBan {
    int maVe;
    char tenKhuVuc[20];
    float giaGoc;
    int isEarlyBird;
};

void datVeConcert(struct VeBan dsVe[], int *soLuong, struct VeBan veMoi);
void hienThiDanhSachVe(const struct VeBan dsVe[], int soLuong);

int main() {
    struct VeBan dsVe[MAX_VE];
    int soLuong = 0;
    
    printf("=== HE THONG DAT VE CONCERT TICKETBOX ===\n\n");

    struct VeBan ve1 = {101, "VIP", 2000000.0f, 1};
    struct VeBan ve2 = {102, "Zone A", 1200000.0f, 0};
    struct VeBan ve3 = {103, "Zone A", 1200000.0f, 0};
    struct VeBan ve4 = {104, "GA", 800000.0f, 1};
    struct VeBan ve5 = {105, "GA", 800000.0f, 0};

    datVeConcert(dsVe, &soLuong, ve1);
    datVeConcert(dsVe, &soLuong, ve2);
    datVeConcert(dsVe, &soLuong, ve3);
    datVeConcert(dsVe, &soLuong, ve4);
    datVeConcert(dsVe, &soLuong, ve5);

    printf("\n>>> KET QUA KIEM TRA GIO HANG TRONG MAIN <<<\n");
    hienThiDanhSachVe(dsVe, soLuong);

    return 0;
}

void datVeConcert(struct VeBan dsVe[], int *soLuong, struct VeBan veMoi) {
    if (*soLuong >= MAX_VE) {
        printf("[LOI]: Mang luu tru ve cua he thong da day!\n");
        return;
    }

    if (*soLuong >= MAX_VE_PER_ORDER) {
        printf("[LOI]: Khong the them ve %d (%s). Moi giao dich chi duoc phep dat toi da %d ve!\n", 
               veMoi.maVe, veMoi.tenKhuVuc, MAX_VE_PER_ORDER);
        return;
    }

    if (veMoi.isEarlyBird == 1) {
        veMoi.giaGoc = veMoi.giaGoc * 0.85f;
    }

    dsVe[*soLuong] = veMoi;
    (*soLuong)++;
    printf("[THANH CONG]: Da them ve %d (%s) vao don hang.\n", veMoi.maVe, veMoi.tenKhuVuc);
}

void hienThiDanhSachVe(const struct VeBan dsVe[], int soLuong) {
    if (soLuong == 0) {
        printf("[THONG BAO]: Hien chua co ve nào duoc dat thanh cong trong he thong!\n");
        return;
    }
    
    printf("--- DANH SACH VE DA DAT (%d ve) ---\n", soLuong);
    for (int i = 0; i < soLuong; i++) {
        printf("STT: %d | Ma ve: %d | Khu vuc: %s | Gia thanh toan: %.0f VND\n",
               i + 1, dsVe[i].maVe, dsVe[i].tenKhuVuc, dsVe[i].giaGoc);
    }
}
