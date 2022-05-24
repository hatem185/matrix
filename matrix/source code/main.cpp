#include <iostream>
#include <conio.h>
// #define MAX_S 3;
using namespace std;
float mx1[3][3];
float mx2[3][3];
float invMx2[3][3];  // mx2 لتخزين معكوس المصفوفة التانية
float resulte[3][3]; //ناتج العمليا على المصفوفتين
// دالة لتصفير عناصر المفوفة
void clearMatrix(float a[][3]);
// دالة لأدخال عناصر الى المصفوفة
void insertMatrix(float a[][3]);
//دالة لإيجاد المصفوفات الجزئية لعناصر المصفوفة الاصلية للحصول على المصفوفة المرافقة
void subMatrix(float Matrix[][3], float subMx[][3], int subRow, int subCol);
//لأيجاد محدد المصفوفة
float detMatrix(float matrix[][3], int num);
//لتحوير المصفوفة وتحويل الصفوف الى اعمدة
void TransMatrix(float matrix[][3], float Tmatrix[][3]);
//لأيجاد معكوس المصفوفة
float inversMatrix(float matrix[3][3]);
// دالة لأظهار ناتج عمليات المصفوفتين
void printMatrix(float a[][3]);
//لجمع مصفوفتين
void addMatrix();
//لطرح مصفوفتين
void subtractMatrix();
// لضرب مصفوفتين
void mulMatrix();
//قسمة مصفوفتين
float divMatrix();
void RunAPP();
//////////////////////////////////
//////////main function///////////
//////////////////////////////////
int main()
{
    RunAPP();
    return 0;
}
////////////////////////////////
//////////////////////////////////

void RunAPP()
{

    bool insert = false;
    while (1)
    {
        int choice = -1;
        system("cls");
        cout << "0 -clear the all matrixs.\n\n";
        cout << "1 -insert the matrixs.\n\n";
        cout << "2 -add 2 matrix.\n\n";
        cout << "3 -subtract 2 matrix.\n\n";
        cout << "4 -multiply 2 matrix.\n\n";
        cout << "5 -divide 2 matrix.\n\n";
        cout << "6 -determint the resulet matrix.\n\n";
        cout << "7 -exit\n\n";
        cout << "choice: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            clearMatrix(mx1);
            clearMatrix(mx2);
            clearMatrix(invMx2);
            clearMatrix(resulte);
            cout << "DONE!!\n";
            break;
        case 1:
            cout << "enter elements of matrix 1\n";
            insertMatrix(mx1);
            cout << "enter elements of matrix 2\n";
            insertMatrix(mx2);
            insert = true;
            break;
        case 2:
            if (insert)
            {
                cout << "====ADD====\n";
                addMatrix();
                printMatrix(resulte);
            }
            else
                cout << "please insert the matrixs first\n";

            break;
        case 3:
            if (insert)
            {
                cout << "====SUBTRACT====\n";
                subtractMatrix();
                printMatrix(resulte);
            }
            else
                cout << "please insert the matrixs first\n";
            break;
        case 4:
            if (insert)
            {
                cout << "====MULTIPLY====\n";
                mulMatrix();
                printMatrix(resulte);
                clearMatrix(resulte);
            }
            else
                cout << "please insert the matrixs first\n";

            break;
        case 5:
            if (insert)
            {
                cout << "====DIVIDE====\n";
                divMatrix();
                printMatrix(resulte);
                clearMatrix(resulte);
            }
            else
                cout << "please insert the matrixs first\n";
            break;
        case 6:
            cout << "determint of resulte matrix: " << detMatrix(resulte, 3) << "\n";
            break;
        case 7:
            exit(0);
            break;
        default:
            break;
        }
        system("pause");
    }
}
// دالة لتصفير عناصر المفوفة
void clearMatrix(float a[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            a[i][j] = 0;
        }
    }
}
// دالة لأدخال عناصر الى المصفوفة
void insertMatrix(float a[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
}
void subMatrix(float Matrix[][3], float subMx[][3], int subRow, int subCol)
{
    int i = 0, j = 0;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (row != subRow && col != subCol)
            {
                subMx[i][j++] = Matrix[row][col];
                if (j == 3 - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
//لأيجاد محدد المصفوفة
float detMatrix(float matrix[][3], int num)
{
    float det = 0;
    if (num == 2)
    {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    int sign = 1;
    float subMx[3][3];
    for (int i = 0; i < num; i++)
    {
        subMatrix(matrix, subMx, 0, i);
        det += sign * matrix[0][i] * detMatrix(subMx, num - 1);
        sign = -sign;
    }
    return det;
}
//لتحوير المصفوفة وتحويل الصفوف الى اعمدة
void TransMatrix(float matrix[][3], float Tmatrix[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = Tmatrix[j][i];
        }
    }
}
//لأيجاد معكوس المصفوفة
float inversMatrix(float matrix[3][3])
{
    float temp[3][3];
    float subMx[3][3];                //لتخزين المصفوفات الجزئية من كل عنصر من عناصر المصفوفة الاصلية حتى نتحصل على المصفوفة المرافقة للمصفوفة الاصلية
    float det = detMatrix(matrix, 3); //لإيجاد محدد المصفوفة
    //التحقق اذا كان محدد المصفوفة صفر يعني لا يوجد للمصفوفة معكوس وسيرجع ولن يكمل عملية ايجاد المعكوس
    if (det == 0)
        return 0;
    int sign = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            subMatrix(matrix, subMx, i, j);                            // للحصول على المصفوفة الجزئية لكل عنصر من عناصر المصفوفة عن طريق ارسال موقع العنصر المراد الحصول على مصفوفته الجزئية وارسال المصفوفة الجزئية لتخزين فيها عناصر المصفوفة الجزئية
            temp[i][j] = (1 / det) * (sign * detMatrix(subMx, 3 - 1)); //
            sign = -sign;
        }
    }
    TransMatrix(invMx2, temp);
    return 0;
}

// دالة لأظهار ناتج عمليات المصفوفتين
void printMatrix(float a[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            cout << "[" << a[j][i] << "]";
        }
        cout << "\n";
    }
}
//لجمع مصفوفتين
void addMatrix()
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            resulte[i][j] = mx1[i][j] + mx2[i][j];
        }
    }
    return;
}
//لطرح مصفوفتين
void subtractMatrix()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            resulte[i][j] = mx1[i][j] - mx2[i][j];
        }
    }
}
// لضرب مصفوفتين
void mulMatrix()
{
    for (int i = 0; i < 3; i++)
    {
        for (int t = 0; t < 3; t++)
        {
            for (int j = 0; j < 3; j++)
            {
                resulte[i][t] += mx1[i][j] * mx2[j][t];
            }
        }
    }
}
//لقسمة مصفوفتين
float divMatrix()
{
    inversMatrix(mx2);
    for (int i = 0; i < 3; i++)
    {
        for (int t = 0; t < 3; t++)
        {
            for (int j = 0; j < 3; j++)
            {
                resulte[i][t] += mx1[i][j] * invMx2[j][t];
            }
        }
    }
    // mulMatrix();
}
