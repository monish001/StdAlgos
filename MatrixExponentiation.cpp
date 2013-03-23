//Matrix Exponentiation in cpp
#include<iostream>
#include<utility>
#include<string>
#include<cmath>
#include<cassert>
#include<vector>
#define MOD 10000007
using namespace std;
//Class Matrix
class Matrix {
    unsigned _row, _col;
    string _name;
    int** _mat;
public:
	//default ctor
	Matrix():_row(0), _col(0),_name("UnInit"){}
	//cleans up any memory taken by _mat and allocates afresh as per row and col value.
	void init(unsigned rw, unsigned cl, const string& name="NoName"){
		//cout<<"DEBUG: In init. name="<<name<<endl;
		if(_row > 0){
			if(_col > 0){
				for(unsigned r=0; r<_row; r++)
					delete[] _mat[r];
			}
			delete[] _mat;
		}
		_name = name;
		_row = rw;
		_col = cl;
        _mat = new int*[_row]; //TODO: use exception handling
        for (unsigned r=0; r<_row; r++)
            _mat[r] = new int[_col];
    }
	//copy ctor
    Matrix(const Matrix& mat):Matrix(){
		init(mat._row, mat._col, "CreatedInCopyCtor");
        for (unsigned i=0; i<mat._row; i++)
            for (unsigned j=0; j<mat._col; j++)
                _mat[i][j] = mat._mat[i][j];
    }
    void operator=(const Matrix& mat){
		init(mat._row, mat._col, "Copy of "+mat._name);
        for (unsigned i=0; i<mat._row; i++)
            for (unsigned j=0; j<mat._col; j++)
                _mat[i][j] = mat._mat[i][j];
    }
	//Creates and returms mat^expo in LOG(expo) time. :)
	static Matrix* power(const Matrix& mat, unsigned expo) {
        vector<Matrix*> cache;//eg. cache[0] = (mat)^1, cache[3] = (mat)^8
        Matrix* ansMat = new Matrix();
        ansMat->operator=(mat);
		expo--;//as ansMat already is assigned as mat
        //cout<<"DEBUG: Entered power\n";
		Matrix* cacheMat = new Matrix(); cacheMat->operator=(mat);
        cache.push_back(cacheMat);
        //cout<<"DEBUG: cache.pushed()\n";
        //find max 2 ki power needed for finding ansMat. let it be 'count'. Ex. for expo=31 (11111), 'count' is 4.
        const unsigned count = log(expo)/log(2);
        //cout<<"DEBUG:count = "<<log(expo)<<"/"<<log(2)<<" = "<<count<<endl;
        for (unsigned i=1; i<=count; i++) {
            Matrix* tmpMat = new Matrix();
			tmpMat->operator=(*cache[i-1]);
			tmpMat->operator=(*(tmpMat->multiply(cache[i-1])));
            cache.push_back(tmpMat);
            //cout<<"DEBUG:\n";            tmpMat->print(cout);
        }
        for (unsigned bit=0; bit<=count; bit++)
            if (1<<bit & expo) {
                //cout<<"DEBUG:bit "<<bit<<" is set.\n";
				Matrix* tmpMat = ansMat->multiply(cache[bit]);
                //cout<<"DEBUG:tmpMat create for bit "<<bit<<" \n";
                ansMat->operator=(*tmpMat);
                //cout<<"DEBUG:ansMat *= tmpMat DONE for bit="<<bit<<".\n";
            }
		for(unsigned i=0; i<cache.size(); i++)
			delete cache[i];
        return ansMat;
    }
    Matrix* multiply(const Matrix* mat) {
        assert(this->_col == mat->_row);
		assert(mat != NULL);
        Matrix* ans = new Matrix();
		ans->init(this->_row, mat->_col, "CreatedInMultiply");
        for (unsigned row=0; row<this->_row; row++)
            for (unsigned col=0; col<mat->_col; col++) {
                ans->_mat[row][col] = 0;
                for (unsigned index=0; index<this->_col; index++)
                    ans->_mat[row][col] += this->_mat[row][index]*mat->_mat[index][col];
            }
        return ans;
    }	
    void setColumn(unsigned colIndex, int value) {
        for (unsigned i=0; i<_row; i++)
            _mat[i][colIndex] = value;
    }
    int& getElement(unsigned rowIndex/*1 based*/, unsigned colIndex/*1 based*/) {
        assert(rowIndex<_row);
        assert(colIndex<_col);
        return _mat[rowIndex][colIndex];
    }
    void print(ostream& cout) {
        cout<<endl;
        for (unsigned r=0; r<_row; r++) {
            for (unsigned c=0; c<_col; c++)
                cout<<_mat[r][c]<<"\t";
            cout<<endl;
        }
        cout<<endl;
	}
    ~Matrix() {
        //cout<<"DEBUG: In dtor for "<<this->_name<<endl;
        for (unsigned r=0; r<_row; r++)
            delete[] _mat[r];
        delete[] _mat;
    }
};

//Use Case
int main()
{
    cout<<"DEBUG:power(mat, 1):\n";
    int size = 4;
    Matrix mat;
	mat.init(size, size, "CreatedInMain");//inits all elems with 0;
    mat.setColumn(0, 1);//sets column 0 as 1
    for (int colIndex=1; colIndex<size; colIndex++)
        mat.getElement(colIndex-1,colIndex) = 1;
    mat.print(cout);
    
    cout<<"DEBUG:power(mat, 2):\n";
    Matrix* mat2 = Matrix::power(mat, 2);
    mat2->print(cout);
	delete mat2;
    
    cout<<"DEBUG:power(mat, 3):\n";
	Matrix* mat3 = Matrix::power(mat, 3);
	mat3->print(cout);
	delete mat3;
    
    cout<<"DEBUG:power(mat, 10):\n";
	Matrix* mat10 = Matrix::power(mat, 10);
	mat10->print(cout);
	delete mat10;

    cout<<"DEBUG:power(mat, 20):\n";
    Matrix* mat20 = Matrix::power(mat, 20);
	mat20->print(cout);
	delete mat20;

    cout<<"DEBUG:power(mat, 50):\n";
    Matrix* mat50 = Matrix::power(mat, 50);
	mat50->print(cout);
	delete mat50;
    return 0;

}