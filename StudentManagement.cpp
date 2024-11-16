#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <limits>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

struct SinhVien {
    std::string maSV;
    std::string tenSV;
    int tuoi;
};

std::vector<SinhVien> danhSach;

void themSinhVien() {
    SinhVien sv;
    std::cout << "Nhap ma sinh vien: ";
    std::cin >> sv.maSV;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Nhap ten sinh vien: ";
    std::getline(std::cin, sv.tenSV);
    std::cout << "Nhap tuoi sinh vien: ";
    std::cin >> sv.tuoi;
    danhSach.push_back(sv);
    std::cout << GREEN << "Them sinh vien thanh cong!\n" << RESET;
}

void hienThiDanhSach() {
    if (danhSach.empty()) {
        std::cout << YELLOW << "Danh sach sinh vien trong.\n" << RESET;
        return;
    }
    std::cout << CYAN << "Danh sach sinh vien:\n" << RESET;
    for (const auto& sv : danhSach) {
        std::cout << MAGENTA << "Ma: " << sv.maSV << ", Ten: " << sv.tenSV << ", Tuoi: " << sv.tuoi << "\n" << RESET;
    }
}

void timKiemSinhVien() {
    std::string maSV;
    std::cout << "Nhap ma sinh vien can tim: ";
    std::cin >> maSV;
    for (const auto& sv : danhSach) {
        if (sv.maSV == maSV) {
            std::cout << GREEN << "Tim thay sinh vien: Ma: " << sv.maSV << ", Ten: " << sv.tenSV << ", Tuoi: " << sv.tuoi << "\n" << RESET;
            return;
        }
    }
    std::cout << RED << "Khong tim thay sinh vien voi ma: " << maSV << "\n" << RESET;
}

void xoaSinhVien() {
    std::string maSV;
    std::cout << "Nhap ma sinh vien can xoa: ";
    std::cin >> maSV;
    for (auto it = danhSach.begin(); it != danhSach.end(); ++it) {
        if (it->maSV == maSV) {
            danhSach.erase(it);
            std::cout << GREEN << "Da xoa sinh vien thanh cong!\n" << RESET;
            return;
        }
    }
    std::cout << RED << "Khong tim thay sinh vien voi ma: " << maSV << "\n" << RESET;
}

int main() {
    #if defined(_WIN32) || defined(_WIN64)
    std::setlocale(LC_ALL, "en_US.UTF-8");
    #else
    std::locale::global(std::locale("en_US.UTF-8"));
    std::cout.imbue(std::locale());
    #endif

    int luaChon;
    do {
        std::cout << "\n";
        std::cout << BLUE << "*****************************************\n" << RESET;
        std::cout << BLUE << "       QUAN LY SINH VIEN                \n" << RESET;
        std::cout << BLUE << "*****************************************\n" << RESET;
        std::cout << "| 1. Them sinh vien                     |\n";
        std::cout << "| 2. Hien thi danh sach sinh vien       |\n";
        std::cout << "| 3. Tim kiem sinh vien theo ma         |\n";
        std::cout << "| 4. Xoa sinh vien theo ma              |\n";
        std::cout << "| 5. Thoat                              |\n";
        std::cout << BLUE << "*****************************************\n" << RESET;
        std::cout << "Nhap lua chon cua ban: ";
        std::cin >> luaChon;

        switch (luaChon) {
        case 1:
            themSinhVien();
            break;
        case 2:
            hienThiDanhSach();
            break;
        case 3:
            timKiemSinhVien();
            break;
        case 4:
            xoaSinhVien();
            break;
        case 5:
            std::cout << YELLOW << "Thoat chuong trinh. Tam biet!\n" << RESET;
            break;
        default:
            std::cout << RED << "Lua chon khong hop le. Vui long thu lai.\n" << RESET;
        }
    } while (luaChon != 5);

    return 0;
}
