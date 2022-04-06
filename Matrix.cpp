#include<iostream>
#include<vector>
#include "Matrix.hpp"
using namespace std;



/**
 * @brief Exceptions function
 * 
 */
void Inputcheck(int vecsize,int row,int col){
    if (vecsize!=row*col)
    {
        throw runtime_error("ERR: The row and col enterd to the constructor are not the same as the matrix size");  
    }
    if (row<=0 || col<=0)
    {
    throw runtime_error("ERR: Matrix cant be with negetive sizes");  
    }
      
}
void dimensions_check(int row1,int col1,int row2,int col2){
    if (row1<=0||row2<=0||col1<=0||col2<=0)
    {
        throw runtime_error("ERR: Matrix cant be with negetive sizes");
    }
    if (row1!=row2||col1!=col2)
    {
        throw runtime_error("ERR: This 2 matrices unequal dimensions");
    }
    
}


namespace zich{
Matrix::Matrix(vector<double> user_vec,int row,int col){
    Inputcheck(user_vec.size(),row,col);
    //Matrix::_mat.resize(row, vector<double>(col));
    this->_col=col;
    this->_row=row;
    vector<double> curr_row;
    int end_row_counter=0;
    for (unsigned long j = 0; j < row*col; j++){

        curr_row.push_back(user_vec.at(j));
        end_row_counter++;
        if (end_row_counter==col){
            this->_mat.push_back(curr_row);
            end_row_counter=0;
            curr_row.clear();
        }    
    }
}
    Matrix Matrix::operator+ (Matrix const &other)const{
        dimensions_check(this->getrow(),this->getcol(),other.getrow(),other.getcol());
        std::vector<double> newVec;
        for (unsigned long i = 0; i < this->getrow(); i++)
        {
           for (unsigned long j = 0; j < this->getcol(); j++)
           {
              newVec.push_back(this->_mat.at(i).at(j)+other._mat.at(i).at(j));
           }
        }
        return Matrix(newVec,this->getrow(),this->getcol());
    }
        Matrix Matrix::operator- (Matrix const &other)const{
        dimensions_check(this->getrow(),this->getcol(),other.getrow(),other.getcol());
        std::vector<double> newVec;
        for (unsigned long i = 0; i < _row; i++)
        {
           for (unsigned long j = 0; j < _col; j++)
           {
               newVec.push_back(this->_mat.at(i).at(j)-other._mat.at(i).at(j));
           }
        }
        return Matrix(newVec,this->getrow(),this->getcol());
    }

    Matrix &Matrix::operator- (){
        return *this;
    }

    Matrix &Matrix::operator-- (){
        for (unsigned long i = 0; i < _row; i++)
        {
            for (unsigned long j = 0; j < _col; j++)
            {
               _mat.at(i).at(j)-=1;
            }
            
        }
        return *this;
    }
    
    Matrix &operator*(const double scalar,Matrix &x) {
        // for (unsigned long i = 0; i < Matrix::getrow(); i++)
        // {
        //     for (unsigned long j = 0; j < Matrix::getcol(); j++)
        //     {
        //        getmat().at(i).at(j)*=scalar;
        //     }
            
        // }
        //return *this;
        return x;
    }
    // Matrix Matrix::operator*(const double scalar, Matrix &other)
    // {
    // return other * scalar;
    // }
    Matrix Matrix::operator*(const Matrix &other)const{
        return *this;
    }
    bool Matrix::operator==(const Matrix &other){
        dimensions_check(this->getrow(),this->getcol(),other.getrow(),other.getcol());
        for (uint i = 0; i < this->getrow(); i++)
        {
            for (uint j = 0; i < this->getcol(); j++)
            {
                if (this->_mat.at(i).at(j)!=other._mat.at(i).at(j))
                {
                   return false;
                }
                
            }
            
        }
        
        return true;
    }
    bool Matrix::operator<=(const Matrix &other){
        dimensions_check(this->getrow(),this->getcol(),other.getrow(),other.getcol());      
        int mat_sum1=this->Sum_of_mat();
        int mat_sum2=other.Sum_of_mat();
        if (mat_sum1>mat_sum2)
        {
            return false;
        }
        
        return true;
    }
    bool Matrix::operator>=(const Matrix &other){
        dimensions_check(this->getrow(),this->getcol(),other.getrow(),other.getcol());        
        int mat_sum1=this->Sum_of_mat();
        int mat_sum2=other.Sum_of_mat();
        if (mat_sum1<mat_sum2)
        {
            return false;
        }
        
        return true;
    }
    bool Matrix::operator>(const Matrix &other){
        dimensions_check(this->getrow(),this->getcol(),other.getrow(),other.getcol());      
        int mat_sum1=this->Sum_of_mat();
        int mat_sum2=other.Sum_of_mat();
        if (mat_sum1<=mat_sum2)
        {
            return false;
        }
        
        return true;
    }
    bool Matrix::operator<(const Matrix &other){
        dimensions_check(this->getrow(),this->getcol(),other.getrow(),other.getcol());     
        int mat_sum1=this->Sum_of_mat();
        int mat_sum2=other.Sum_of_mat();
        if (mat_sum1>=mat_sum2)
        {
            return false;
        }
        
        return true;
    }
    bool Matrix::operator!=(const Matrix &other){
        return !this->operator==(other);
    }
    void Matrix::operator*=(double const scalar){
        for (uint i = 0; i < this->getrow(); i++)
        {
            for (uint j = 0; j < this->getcol(); j++)
            {
                this->getmatrix().at(i).at(j)*=scalar;
            }
            
        }
        }
    Matrix &Matrix::operator*=(const Matrix &other){return *this;}


    ostream &operator<<(ostream &COUT, const Matrix& a){
        for (uint i = 0; i < a.getrow(); i++)
        {
            for (uint j = 0; j < a.getcol(); j++)
            {
               COUT<<a.getmatrix().at(i).at(j);
            }
            
        }  
        return COUT;
    }

    // Matrix Matrix::operator*(double scalar,int) {
    //     for (size_t i = 0; i < _row; i++)
    //     {
    //         for (size_t j = 0; j < _col; j++)
    //         {
    //            _mat.at(i).at(j)*=scalar;
    //         }
            
    //     }
    //     return *this;
    // }
    // Matrix Matrix::operator ++ (double const scalar,int) {
    //     for (size_t i = 0; i < _row; i++)
    //     {
    //         for (size_t j = 0; j < _col; j++)
    //         {
    //             this._mat.at(i).at(j)+=1;
    //         }
            
    //     }
    //     return this;
    // }

    int Matrix::Sum_of_mat() const{
        int sum=0;
        for (unsigned long i = 0; i < this->getrow(); i++)
        {
            for (unsigned long j = 0; j < this->getcol(); i++)
            {
                sum+=this->_mat.at(i).at(j);
            }
            
        }
        return sum;
    }

}
// int main(){
//     std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
//     std::vector<double> test = {1, 1, 1, 1, 1, 1, 1, 1, 1};
//     Matrix a{identity, 3, 3};  // constructor taking a vector and a matrix size
//     Matrix b{test, 3, 3};  // constructor taking a vector and a matrix size
//     a=a+b;
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             cout<<a.value(i,j)<<endl;
//         }
        
//     }
    
//     return 0;
// }