#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <sstream>

struct NgaySinh {
    int ngay;
    int thang;
    int nam;
};

struct SinhVien {
    std::string HoTen;
    NgaySinh NS; 
    std::string GioiTinh;
    double DiemTrungBinh;
};

std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return lowerStr;
}

void hienThiSinhVien(const SinhVien& sv, int stt) {
    std::ostringstream dateStream;
    dateStream << std::setfill('0') << std::setw(2) << sv.NS.ngay << "/" 
               << std::setw(2) << sv.NS.thang << "/" << sv.NS.nam;

    std::cout << std::left << std::setw(5) << stt
              << std::setw(30) << sv.HoTen
              << std::setw(15) << dateStream.str()
              << std::setw(12) << sv.GioiTinh
              << std::right << std::setw(10) << std::fixed << std::setprecision(2) << sv.DiemTrungBinh
              << std::endl;
}

void hienThiTieuDeBang() {
    std::cout << "\n--------------------------------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(5) << "STT"
              << std::setw(30) << "HO TEN"
              << std::setw(15) << "NGAY SINH"
              << std::setw(12) << "GIOI TINH"
              << std::right << std::setw(10) << "DIEM TB"
              << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
}

void hienThiMenu() {
    std::cout << "\n================ MENU QUAN LY SINH VIEN ================" << std::endl;
    std::cout << "1. Them sinh vien moi" << std::endl;
    std::cout << "2. Hien thi toan bo danh sach sinh vien" << std::endl;
    std::cout << "3. Xoa sinh vien" << std::endl;
    std::cout << "4. Sua thong tin sinh vien" << std::endl;
    std::cout << "5. Tim kiem sinh vien" << std::endl;
    std::cout << "6. Sap xep danh sach" << std::endl;
    std::cout << "0. Thoat chuong trinh" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Nhap lua chon cua ban: ";
}

void themSinhVien(std::vector<SinhVien>& ds) {
    SinhVien sv;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n--- THEM SINH VIEN MOI ---" << std::endl;
    
    std::cout << "Nhap Ho ten: ";
    std::getline(std::cin, sv.HoTen);

    std::cout << "Nhap Ngay sinh (Ngay): ";
    while (!(std::cin >> sv.NS.ngay) || sv.NS.ngay < 1 || sv.NS.ngay > 31) {
        std::cout << "Ngay khong hop le (1-31). Nhap lai: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    std::cout << "Nhap Ngay sinh (Thang): ";
    while (!(std::cin >> sv.NS.thang) || sv.NS.thang < 1 || sv.NS.thang > 12) {
        std::cout << "Thang khong hop le (1-12). Nhap lai: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Nhap Ngay sinh (Nam): ";
    while (!(std::cin >> sv.NS.nam) || sv.NS.nam < 1900 || sv.NS.nam > 2025) {
        std::cout << "Nam khong hop le (1900-2025). Nhap lai: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    std::cout << "Nhap Gioi tinh: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, sv.GioiTinh);

    std::cout << "Nhap Diem trung binh: ";
    while (!(std::cin >> sv.DiemTrungBinh) || sv.DiemTrungBinh < 0 || sv.DiemTrungBinh > 10) {
        std::cout << "Diem khong hop le (0-10). Nhap lai: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    ds.push_back(sv);
    std::cout << "=> Da them sinh vien '" << sv.HoTen << "' vao danh sach." << std::endl;
}

void hienThiDanhSach(const std::vector<SinhVien>& ds) {
    if (ds.empty()) {
        std::cout << "\n=> Danh sach sinh vien hien dang rong." << std::endl;
        return;
    }
    
    std::cout << "\n--- DANH SACH SINH VIEN ---" << std::endl;
    hienThiTieuDeBang();
    for (size_t i = 0; i < ds.size(); ++i) {
        hienThiSinhVien(ds[i], i + 1);
    }
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
}

void xoaSinhVien(std::vector<SinhVien>& ds) {
    if (ds.empty()) {
        std::cout << "\n=> Danh sach rong, khong the xoa." << std::endl;
        return;
    }
    
    std::cout << "\n--- XOA SINH VIEN ---" << std::endl;
    std::cout << "Chon cach xoa (1: Theo ten, 2: Theo chi so STT): ";
    int luaChon;
    if (!(std::cin >> luaChon)) {
        std::cout << "Lua chon khong hop le." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (luaChon == 1) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string tenCanXoa;
        std::cout << "Nhap Ho ten sinh vien can xoa: ";
        std::getline(std::cin, tenCanXoa);
        
        std::string tenLower = toLower(tenCanXoa);
        
        size_t soLuongTruoc = ds.size();
        ds.erase(std::remove_if(ds.begin(), ds.end(), 
            [&tenLower](const SinhVien& sv) {
                return toLower(sv.HoTen) == tenLower;
            }), 
            ds.end());
            
        if (ds.size() < soLuongTruoc) {
            std::cout << "=> Da xoa thanh cong " << (soLuongTruoc - ds.size()) 
                      << " sinh vien co ten '" << tenCanXoa << "'." << std::endl;
        } else {
            std::cout << "=> Khong tim thay sinh vien co ten '" << tenCanXoa << "'." << std::endl;
        }

    } else if (luaChon == 2) {
        int stt;
        std::cout << "Nhap STT (tu 1 den " << ds.size() << ") cua sinh vien can xoa: ";
        if (std::cin >> stt && stt >= 1 && stt <= ds.size()) {
            std::string tenBiXoa = ds[stt - 1].HoTen;
            ds.erase(ds.begin() + stt - 1);
            std::cout << "=> Da xoa thanh cong sinh vien STT " << stt << " (" << tenBiXoa << ")." << std::endl;
        } else {
            std::cout << "=> STT khong hop le." << std::endl;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } else {
        std::cout << "Lua chon khong hop le." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void suaThongTinSinhVien(std::vector<SinhVien>& ds) {
    if (ds.empty()) {
        std::cout << "\n=> Danh sach rong, khong the sua." << std::endl;
        return;
    }
    
    std::cout << "\n--- SUA THONG TIN SINH VIEN ---" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string tenCanSua;
    std::cout << "Nhap Ho ten sinh vien can sua thong tin: ";
    std::getline(std::cin, tenCanSua);
    
    std::string tenLower = toLower(tenCanSua);
    int soLuongTimThay = 0;
    
    for (size_t i = 0; i < ds.size(); ++i) {
        if (toLower(ds[i].HoTen) == tenLower) {
            soLuongTimThay++;
            
            std::cout << "\nTim thay sinh vien STT " << (i + 1) << " (" << ds[i].HoTen << ").";
            
            std::cout << "\nNhap thong tin moi cho sinh vien nay:";
            
            std::cout << "\n   Ho ten moi (" << ds[i].HoTen << "): ";
            std::string tempHoTen;
            std::getline(std::cin, tempHoTen);
            if (!tempHoTen.empty()) ds[i].HoTen = tempHoTen;

            std::cout << "   Ngay sinh moi (Ngay/" << ds[i].NS.ngay << "): ";
            int tempNgay;
            std::string line;
            if (std::getline(std::cin, line) && !line.empty()) {
                try { tempNgay = std::stoi(line); if (tempNgay > 0 && tempNgay < 32) ds[i].NS.ngay = tempNgay; } catch (...) { }
            }

            std::cout << "   Ngay sinh moi (Thang/" << ds[i].NS.thang << "): ";
            if (std::getline(std::cin, line) && !line.empty()) {
                try { int tempThang = std::stoi(line); if (tempThang > 0 && tempThang < 13) ds[i].NS.thang = tempThang; } catch (...) { }
            }
            
            std::cout << "   Ngay sinh moi (Nam/" << ds[i].NS.nam << "): ";
            if (std::getline(std::cin, line) && !line.empty()) {
                try { int tempNam = std::stoi(line); if (tempNam >= 1900 && tempNam <= 2025) ds[i].NS.nam = tempNam; } catch (...) { }
            }
            
            std::cout << "   Gioi tinh moi (" << ds[i].GioiTinh << "): ";
            std::string tempGioiTinh;
            std::getline(std::cin, tempGioiTinh);
            if (!tempGioiTinh.empty()) ds[i].GioiTinh = tempGioiTinh;
            
            std::cout << "   Diem trung binh moi (" << ds[i].DiemTrungBinh << "): ";
            std::string tempDiem;
            std::getline(std::cin, tempDiem);
            if (!tempDiem.empty()) {
                try {
                    ds[i].DiemTrungBinh = std::stod(tempDiem);
                } catch (const std::exception& e) {
                    std::cout << "Gia tri diem nhap khong hop le, giu lai diem cu." << std::endl;
                }
            }
            std::cout << "=> Da cap nhat thong tin cho sinh vien " << ds[i].HoTen << "." << std::endl;
        }
    }

    if (soLuongTimThay == 0) {
        std::cout << "\n=> Khong tim thay sinh vien co ten '" << tenCanSua << "' de sua." << std::endl;
    }
}

void timKiemSinhVien(const std::vector<SinhVien>& ds) {
    if (ds.empty()) {
        std::cout << "\n=> Danh sach rong, khong co gi de tim kiem." << std::endl;
        return;
    }
    
    std::cout << "\n--- TIM KIEM SINH VIEN ---" << std::endl;
    std::cout << "Chon tieu chi tim kiem (1: Theo ten, 2: Theo khoang diem trung binh): ";
    int luaChon;
    if (!(std::cin >> luaChon)) {
        std::cout << "Lua chon khong hop le." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::vector<const SinhVien*> ketQua;
    
    if (luaChon == 1) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string tenCanTim;
        std::cout << "Nhap ten sinh vien hoac mot phan ten can tim: ";
        std::getline(std::cin, tenCanTim);
        std::string tenLower = toLower(tenCanTim);
        
        for (const auto& sv : ds) {
            if (toLower(sv.HoTen).find(tenLower) != std::string::npos) {
                ketQua.push_back(&sv);
            }
        }
        
    } else if (luaChon == 2) {
        double minDiem, maxDiem;
        std::cout << "Nhap diem trung binh thap nhat (min): ";
        while (!(std::cin >> minDiem)) {
            std::cout << "Diem khong hop le. Nhap lai: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "Nhap diem trung binh cao nhat (max): ";
        while (!(std::cin >> maxDiem)) {
            std::cout << "Diem khong hop le. Nhap lai: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        for (const auto& sv : ds) {
            if (sv.DiemTrungBinh >= minDiem && sv.DiemTrungBinh <= maxDiem) {
                ketQua.push_back(&sv);
            }
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        std::cout << "Lua chon khong hop le." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (!ketQua.empty()) {
        std::cout << "\n=> TIM THAY " << ketQua.size() << " SINH VIEN: " << std::endl;
        hienThiTieuDeBang();
        for (size_t i = 0; i < ketQua.size(); ++i) {
            hienThiSinhVien(*ketQua[i], i + 1); 
        }
        std::cout << "--------------------------------------------------------------------------------" << std::endl;
    } else {
        std::cout << "\n=> Khong tim thay sinh vien nao thoa man tieu chi." << std::endl;
    }
}

void sapXepDanhSach(std::vector<SinhVien>& ds) {
    if (ds.empty()) {
        std::cout << "\n=> Danh sach rong, khong the sap xep." << std::endl;
        return;
    }
    
    std::cout << "\n--- SAP XEP DANH SACH ---" << std::endl;
    std::cout << "Chon tieu chi sap xep (1: Diem TB Giam Dan, 2: Ten A-Z): ";
    int luaChon;
    if (!(std::cin >> luaChon)) {
        std::cout << "Lua chon khong hop le." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    
    if (luaChon == 1) {
        std::sort(ds.begin(), ds.end(), [](const SinhVien& a, const SinhVien& b) {
            return a.DiemTrungBinh > b.DiemTrungBinh;
        });
        std::cout << "=> Da sap xep danh sach theo Diem Trung Binh GIAM DAN." << std::endl;
    } else if (luaChon == 2) {
        std::sort(ds.begin(), ds.end(), [](const SinhVien& a, const SinhVien& b) {
            return toLower(a.HoTen) < toLower(b.HoTen);
        });
        std::cout << "=> Da sap xep danh sach theo Ten tu A-Z." << std::endl;
    } else {
        std::cout << "Lua chon khong hop le." << std::endl;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<SinhVien> danhSachSinhVien;
    int luaChon;

    do {
        hienThiMenu();
        if (!(std::cin >> luaChon)) {
            std::cout << "\nLoi nhap lieu. Vui long nhap mot so tu 0 den 6." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            luaChon = -1;
            continue;
        }

        switch (luaChon) {
            case 1:
                themSinhVien(danhSachSinhVien);
                break;
            case 2:
                hienThiDanhSach(danhSachSinhVien);
                break;
            case 3:
                xoaSinhVien(danhSachSinhVien);
                break;
            case 4:
                suaThongTinSinhVien(danhSachSinhVien);
                break;
            case 5:
                timKiemSinhVien(danhSachSinhVien);
                break;
            case 6:
                sapXepDanhSach(danhSachSinhVien);
                break;
            case 0:
                std::cout << "\n=> Chuong trinh ket thuc. Tam biet!" << std::endl;
                break;
            default:
                std::cout << "\n=> Lua chon khong hop le. Vui long chon lai." << std::endl;
                break;
        }

    } while (luaChon != 0);

    return 0;
}
