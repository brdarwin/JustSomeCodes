#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Cell {
public: 
	string name_;
	double value_;
	double weight_;
	bool included_;
	shared_ptr<Cell> ptr0_;
	shared_ptr<Cell> ptr1_;
Cell (string name,double value, double weight){
	name_ = name;
	value_ = value;
	weight_ = weight;
	ptr0_ = nullptr;
	ptr1_ = nullptr;

}
void initializingMatrix (vector<vector<shared_ptr<Cell>>>& matrix, int row, int col){
	matrix.resize(row);
	for(int i = 0; i < row; i++){
		matrix[i].resize(col);
	}
	for(int r = 0; r < row; r++){
		for (int c = 0; c < col; c++){
			matrix[r][c] = make_shared<Cell>("",0,0);
		}
	
	}

}
void atributeValues(vector<vector<shared_ptr<Cell>>>& matrix,vector<shared_ptr<Cell>>&objs){
		int i =  0;
		for( int  row  = 1; row < matrix.size(); row++){
		   for(int col = 0;col < matrix[row].size(); col++){
		      if(objs[i]->weight_ > col){
			  matrix[row][col]->value_ = matrix[row-1][col]->value_;
		     }else{
			  double value0 = matrix[row-1][col] -> value_;
			  double nCol = col - objs[i] ->weight_;
			  double value1 = objs[i] -> value_;
			  value1 = value1 + matrix[row-1][nCol]->value_;
			  if(value1 > value0){
			    matrix[row][col] ->value_ = value1;
			    matrix[row][col]->ptr0_ = matrix[row-1][nCol];
		 }else{
			    matrix[row][col]->value_ = value0;	
			}
			}
		      }
		i++;
		}
}          
void isIncluded (vector<vector<shared_ptr<Cell>>>& matrix, vector<shared_ptr<Cell>>& objs){
	int row = matrix.size() -1;
	int col = matrix[row].size() -1;
	for(int i = objs.size() - 1; i > 0; i--){
		if (matrix[row-1][col] ->value_ == matrix[row][col]->value_){
		 	objs[i] -> included_ = false;
			row--;
		}else{
			objs[i] -> included_ = true;
			shared_ptr<Cell> index = matrix[row][col]->ptr0_;
			while (matrix[row -1][col] != index){
				col--;
			}
			row--;
		}
		
	}	
}
double printingValues(vector<shared_ptr<Cell>>& objs){
	int totalValue = 0;
	for (int i = 0; i < objs.size( ); i++){
		cout<<objs[i]->name_<<" "<<objs[i]->value_<<" "<<objs[i]->weight_<<" ";
		cout<<objs[i]->included_<<endl;
		if(objs[i]->included_ == true){
			totalValue = totalValue + objs[i] -> value_;
		}
	}
	return totalValue;
}
};

int main (void){
	shared_ptr<Cell> nullCell = nullptr;
	int row = 6;
	int col =8;
	vector<vector<shared_ptr<Cell>>> matrix;
	nullCell -> initializingMatrix(matrix, row, col);
	vector <shared_ptr<Cell>> objs;
	objs.push_back(make_shared<Cell>("joia",2,3));
	objs.push_back(make_shared<Cell>("celular",2,1));
	objs.push_back(make_shared<Cell>("tablet",4,3));
	objs.push_back(make_shared<Cell>("notebook",5,4));
	objs.push_back(make_shared<Cell>("som",3,2));
	nullCell -> atributeValues(matrix, objs);
	nullCell -> isIncluded(matrix, objs);
	double totalValue =nullCell -> printingValues(objs);
	cout <<totalValue<<endl;
	return 0;
}
