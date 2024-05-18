#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int soHang, soCot;
    cout << "Nhập số hàng của mảng: ";
    cin >> soHang;
    cout << "Nhập số cột của mảng: ";
    cin >> soCot;

    int mang[100][100];
    cout << "Nhập các phần tử của mảng: \n";
    for (int i = 0; i < soHang; ++i) {
        for (int j = 0; j < soCot; ++j) {
            cout << "Phần tử [" << i << "][" << j << "]: ";
            cin >> mang[i][j];
        }
    }

    // Bài tập 1
    int tong = 0;
    for (int i = 0; i < soHang; ++i) {
        for (int j = 0; j < soCot; ++j) {
            tong += mang[i][j];
        }
    }
    cout << "Tổng các phần tử trong mảng: " << tong << endl;

    // Bài tập 2
    int lonNhat = mang[0][0];
    int nhoNhat = mang[0][0];
    for (int i = 0; i < soHang; ++i) {
        for (int j = 0; j < soCot; ++j) {
            if (mang[i][j] > lonNhat) {
                lonNhat = mang[i][j];
            }
            if (mang[i][j] < nhoNhat) {
                nhoNhat = mang[i][j];
            }
        }
    }
    cout << "Phần tử lớn nhất: " << lonNhat << endl;
    cout << "Phần tử nhỏ nhất: " << nhoNhat << endl;

    // Bài tập 3
    for (int i = 0; i < soHang; ++i) {
        int tongHang = 0;
        for (int j = 0; j < soCot; ++j) {
            tongHang += mang[i][j];
        }
        cout << "Tổng các phần tử của hàng " << i << ": " << tongHang << endl;
    }

    for (int j = 0; j < soCot; ++j) {
        int tongCot = 0;
        for (int i = 0; i < soHang; ++i) {
            tongCot += mang[i][j];
        }
        cout << "Tổng các phần tử của cột " << j << ": " << tongCot << endl;
    }

    // Bài tập 4
    for (int i = 0; i < soHang; ++i) {
        int maxHang = mang[i][0];
        for (int j = 0; j < soCot; ++j) {
            if (mang[i][j] > maxHang) {
                maxHang = mang[i][j];
            }
        }
        cout << "Phần tử lớn nhất của hàng " << i << ": " << maxHang << endl;
    }

    // Bài tập 5
    bool doiXung = true;
    if (soHang != soCot) {
        doiXung = false;
    }
    else {
        for (int i = 0; i < soHang; ++i) {
            for (int j = 0; j < soCot; ++j) {
                if (mang[i][j] != mang[j][i]) {
                    doiXung = false;
                    break;
                }
            }
            if (!doiXung) break;
        }
    }
    if (doiXung) {
        cout << "Ma trận là ma trận đối xứng.\n";
    }
    else {
        cout << "Ma trận không phải là ma trận đối xứng.\n";
    }

    // Bài tập 6
    int tongDuongCheoChinh = 0;
    for (int i = 0; i < min(soHang, soCot); ++i) {
        tongDuongCheoChinh += mang[i][i];
    }
    cout << "Tổng các phần tử trên đường chéo chính: " << tongDuongCheoChinh << endl;

    // Bài tập 7
    int tongSoNguyenTo = 0;
    for (int i = 0; i < soHang; ++i) {
        for (int j = 0; j < soCot; ++j) {
            if (laSoNguyenTo(mang[i][j])) {
                tongSoNguyenTo += mang[i][j];
            }
        }
    }
    cout << "Tổng các số nguyên tố trong mảng: " << tongSoNguyenTo << endl;

    // Bài tập 8
    for (int i = 0; i < soHang; ++i) {
        sort(mang[i], mang[i] + soCot);
    }
    cout << "Ma trận sau khi sắp xếp các hàng:\n";
    for (int i = 0; i < soHang; ++i) {
        for (int j = 0; j < soCot; ++j) {
            cout << mang[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
