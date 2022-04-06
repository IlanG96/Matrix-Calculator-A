#include<iostream>
#include<vector>
namespace zich{
class Matrix
{
private:
    std::vector<std::vector<double>> _mat;
    int _row;
    int _col;
public:
    int getrow ()const{return _row;}
    int getcol()const{return _col;}
    std::vector<std::vector<double>> getmatrix()const{return _mat;}
    Matrix(){}
    Matrix(std::vector<double> user_vec,int row,int col);
    friend Matrix &operator*(const double scalar,Matrix &x);
    int Sum_of_mat()const;
    Matrix operator*(const Matrix &other)const;
    Matrix operator+ (Matrix const &other)const;
    Matrix operator+= (Matrix const &other);
    Matrix operator- (Matrix const &other)const;
    Matrix &operator- ();
    Matrix &operator-- ();
    Matrix operator-- (int);
    void operator*= (double const scalar);
    Matrix &operator*=(const Matrix &other);
     bool operator==(const Matrix &other);
     bool operator<=(const Matrix &other);
     bool operator>=(const Matrix &other);
     bool operator!=(const Matrix &other);
     bool operator<(const Matrix &mat1);
     bool operator>(const Matrix &mat1);
    friend std::ostream &operator<<(std::ostream &COUT, const Matrix& a);
    //bool operator*(int, const Matrix &other);
    //Matrix operator* (double const scalar,int);
    //int value (int i , int j);
    //Matrix operator ++ (double const scalar ,int);
};

}