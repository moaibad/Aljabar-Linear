#include <iostream>

using namespace std;

int main() {
    int i, j, Jumlah_baris, Jumlah_kolom, matriks[10][10];

    cout << "Masukkan Jumlah Baris Matriks: ";
    cin >> Jumlah_baris;
    cout << "Masukkan Jumlah Kolom Matriks: ";
    cin >> Jumlah_kolom;

    cout << "Masukkan Elemen Matriks Pertama: \n";
    for(i = 0; i < Jumlah_baris; i++){
        for(j = 0; j < Jumlah_kolom; j++){
        cin >> matriks[i][j];
        }
    }

    for(i = 0; i < Jumlah_baris; i++){
        for(j = 0; j < Jumlah_kolom; j++){
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;

}


void findSolution(double matriks[7][7],double hasil[7])
{
    // Matrix d using matriks as given in cramer's rule
    double d[7][7] = {
        { matriks[0][0], matriks[0][1], matriks[0][2], matriks[0][3], matriks[0][4], matriks[0][5], matriks[0][6] },
        { matriks[1][0], matriks[1][1], matriks[1][2], matriks[1][3], matriks[1][4], matriks[1][5], matriks[1][6] },
        { matriks[2][0], matriks[2][1], matriks[2][2], matriks[2][3], matriks[2][4], matriks[2][5], matriks[2][6] },
        { matriks[3][0], matriks[3][1], matriks[3][2], matriks[3][3], matriks[3][4], matriks[3][5], matriks[3][6] },
        { matriks[4][0], matriks[4][1], matriks[4][2], matriks[4][3], matriks[4][4], matriks[4][5], matriks[4][6] },
        { matriks[5][0], matriks[5][1], matriks[5][2], matriks[5][3], matriks[5][4], matriks[5][5], matriks[5][6] },
        { matriks[6][0], matriks[6][1], matriks[6][2], matriks[6][3], matriks[6][4], matriks[6][5], matriks[6][6] },
    };
    // Matrix d1 using matriks as given in cramer's rule
    double d1[7][7] = {
        { hasil[0], matriks[0][1], matriks[0][2], matriks[0][3], matriks[0][4], matriks[0][5], matriks[0][6] },
        { hasil[1], matriks[1][1], matriks[1][2], matriks[1][3], matriks[1][4], matriks[1][5], matriks[1][6] },
        { hasil[2], matriks[2][1], matriks[2][2], matriks[2][3], matriks[2][4], matriks[2][5], matriks[2][6] },
        { hasil[3], matriks[3][1], matriks[3][2], matriks[3][3], matriks[3][4], matriks[3][5], matriks[3][6] },
        { hasil[4], matriks[4][1], matriks[4][2], matriks[4][3], matriks[4][4], matriks[4][5], matriks[4][6] },
        { hasil[5], matriks[5][1], matriks[5][2], matriks[5][3], matriks[5][4], matriks[5][5], matriks[5][6] },
        { hasil[6], matriks[6][1], matriks[6][2], matriks[6][3], matriks[6][4], matriks[6][5], matriks[6][6] },
    };
    // Matrix d2 using matriks as given in cramer's rule
    double d2[3][3] = {
        { matriks[0][0], hasil[0], matriks[0][2], matriks[0][3], matriks[0][4], matriks[0][5], matriks[0][6] },
        { matriks[1][0], hasil[1], matriks[1][2], matriks[1][3], matriks[1][4], matriks[1][5], matriks[1][6] },
        { matriks[2][0], hasil[2], matriks[2][2], matriks[2][3], matriks[2][4], matriks[2][5], matriks[2][6] },
        { matriks[3][0], hasil[3], matriks[3][2], matriks[3][3], matriks[3][4], matriks[3][5], matriks[3][6] },
        { matriks[4][0], hasil[4], matriks[4][2], matriks[4][3], matriks[4][4], matriks[4][5], matriks[4][6] },
        { matriks[5][0], hasil[5], matriks[5][2], matriks[5][3], matriks[5][4], matriks[5][5], matriks[5][6] },
        { matriks[6][0], hasil[6], matriks[6][2], matriks[6][3], matriks[6][4], matriks[6][5], matriks[6][6] },
    };
    // Matrix d3 using matriks as given in cramer's rule
    double d3[3][3] = {
        { matriks[0][0], matriks[0][1], hasil[0], matriks[0][3], matriks[0][4], matriks[0][5], matriks[0][6] },
        { matriks[1][0], matriks[1][1], hasil[1], matriks[1][3], matriks[1][4], matriks[1][5], matriks[1][6] },
        { matriks[2][0], matriks[2][1], hasil[2], matriks[2][3], matriks[2][4], matriks[2][5], matriks[2][6] },
        { matriks[3][0], matriks[3][1], hasil[3], matriks[3][3], matriks[3][4], matriks[3][5], matriks[3][6] },
        { matriks[4][0], matriks[4][1], hasil[4], matriks[4][3], matriks[4][4], matriks[4][5], matriks[4][6] },
        { matriks[5][0], matriks[5][1], hasil[5], matriks[5][3], matriks[5][4], matriks[5][5], matriks[5][6] },
        { matriks[6][0], matriks[6][1], hasil[6], matriks[6][3], matriks[6][4], matriks[6][5], matriks[6][6] },
    };

    double d4[7][7] = {
        { matriks[0][0], matriks[0][1], matriks[0][2], hasil[0], matriks[0][4], matriks[0][5], matriks[0][6] },
        { matriks[1][0], matriks[1][1], matriks[1][2], hasil[1], matriks[1][4], matriks[1][5], matriks[1][6] },
        { matriks[2][0], matriks[2][1], matriks[2][2], hasil[2], matriks[2][4], matriks[2][5], matriks[2][6] },
        { matriks[3][0], matriks[3][1], matriks[3][2], hasil[3], matriks[3][4], matriks[3][5], matriks[3][6] },
        { matriks[4][0], matriks[4][1], matriks[4][2], hasil[4], matriks[4][4], matriks[4][5], matriks[4][6] },
        { matriks[5][0], matriks[5][1], matriks[5][2], hasil[5], matriks[5][4], matriks[5][5], matriks[5][6] },
        { matriks[6][0], matriks[6][1], matriks[6][2], hasil[6], matriks[6][4], matriks[6][5], matriks[6][6] },
    };

    double d5[7][7] = {
        { matriks[0][0], matriks[0][1], matriks[0][2], matriks[0][3], hasil[0], matriks[0][5], matriks[0][6] },
        { matriks[1][0], matriks[1][1], matriks[1][2], matriks[1][3], hasil[1], matriks[1][5], matriks[1][6] },
        { matriks[2][0], matriks[2][1], matriks[2][2], matriks[2][3], hasil[2], matriks[2][5], matriks[2][6] },
        { matriks[3][0], matriks[3][1], matriks[3][2], matriks[3][3], hasil[3], matriks[3][5], matriks[3][6] },
        { matriks[4][0], matriks[4][1], matriks[4][2], matriks[4][3], hasil[4], matriks[4][5], matriks[4][6] },
        { matriks[5][0], matriks[5][1], matriks[5][2], matriks[5][3], hasil[5], matriks[5][5], matriks[5][6] },
        { matriks[6][0], matriks[6][1], matriks[6][2], matriks[6][3], hasil[6], matriks[6][5], matriks[6][6] },
    };

    double d6[7][7] = {
        { matriks[0][0], matriks[0][1], matriks[0][2], matriks[0][3], matriks[0][4], hasil[0], matriks[0][6] },
        { matriks[1][0], matriks[1][1], matriks[1][2], matriks[1][3], matriks[1][4], hasil[1], matriks[1][6] },
        { matriks[2][0], matriks[2][1], matriks[2][2], matriks[2][3], matriks[2][4], hasil[2], matriks[2][6] },
        { matriks[3][0], matriks[3][1], matriks[3][2], matriks[3][3], matriks[3][4], hasil[3], matriks[3][6] },
        { matriks[4][0], matriks[4][1], matriks[4][2], matriks[4][3], matriks[4][4], hasil[4], matriks[4][6] },
        { matriks[5][0], matriks[5][1], matriks[5][2], matriks[5][3], matriks[5][4], hasil[5], matriks[5][6] },
        { matriks[6][0], matriks[6][1], matriks[6][2], matriks[6][3], matriks[6][4], hasil[6], matriks[6][6] },
    };

    double d7[7][7] = {
        { matriks[0][0], matriks[0][1], matriks[0][2], matriks[0][3], matriks[0][4], matriks[0][5], hasil[0] },
        { matriks[1][0], matriks[1][1], matriks[1][2], matriks[1][3], matriks[1][4], matriks[1][5], hasil[1] },
        { matriks[2][0], matriks[2][1], matriks[2][2], matriks[2][3], matriks[2][4], matriks[2][5], hasil[2] },
        { matriks[3][0], matriks[3][1], matriks[3][2], matriks[3][3], matriks[3][4], matriks[3][5], hasil[3] },
        { matriks[4][0], matriks[4][1], matriks[4][2], matriks[4][3], matriks[4][4], matriks[4][5], hasil[4] },
        { matriks[5][0], matriks[5][1], matriks[5][2], matriks[5][3], matriks[5][4], matriks[5][5], hasil[5] },
        { matriks[6][0], matriks[6][1], matriks[6][2], matriks[6][3], matriks[6][4], matriks[6][5], hasil[6] },
    };
 
    // Calculating Determinant of Matrices d, d1, d2, d3
    double D = determinantOfMatrix(d);
    double D1 = determinantOfMatrix(d1);
    double D2 = determinantOfMatrix(d2);
    double D3 = determinantOfMatrix(d3);
    printf("D is : %lf \n", D);
    printf("D1 is : %lf \n", D1);
    printf("D2 is : %lf \n", D2);
    printf("D3 is : %lf \n", D3);
 
    // Case 1
    if (D != 0) {
        // matriks have a unique solution. Apply Cramer's Rule
        double x = D1 / D;
        double y = D2 / D;
        double z = D3 / D; // calculating z using cramer's rule
        printf("Value of x is : %lf\n", x);
        printf("Value of y is : %lf\n", y);
        printf("Value of z is : %lf\n", z);
    }
    // Case 2
    else {
        if (D1 == 0 && D2 == 0 && D3 == 0)
            printf("Infinite solutions\n");
        else if (D1 != 0 || D2 != 0 || D3 != 0)
            printf("No solutions\n");
    }
}

double determinantOfMatrix(double mat[3][3])
{
    double ans;
    ans = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2])
          - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
          + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
    return ans;
}