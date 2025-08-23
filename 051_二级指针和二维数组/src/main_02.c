#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_Node_Num 100
#define Max_Row 11
#define Max_Col 11

typedef struct{
	unsigned int row;  //行号
	unsigned int col;  //列号
	int data;  //元素值
}Struct_DataNode;  //数据结点结构体

typedef struct{
	Struct_DataNode DataNode[Max_Node_Num];
	unsigned int MatrixRow, MatrixCol, TotalDataNodeNum;  //二维数组行数，列数，非零元素个数
}Struct_SparseArr;  //稀疏矩阵结构体

#if 0
int main() {
	//定义稀疏矩阵、转置稀疏矩阵
	Struct_SparseArr OriSparseArr, TraSparseArr;
	//定义期间要用到的变量 -> i/j/temp:循环变量
	int i, j, temp;

	//初始化稀疏矩阵、转置稀疏矩阵
	memset(&OriSparseArr, 0x00, sizeof(OriSparseArr));
	memset(&TraSparseArr, 0x00, sizeof(TraSparseArr));

	//定义二维数组
	int Ori2DArr[Max_Row][Max_Col] = {
		{0, 0, 2, 0, 0, 0, 4, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	//将二维数组行数、列数赋值给稀疏矩阵结构体
	OriSparseArr.MatrixRow = Max_Row;
	OriSparseArr.MatrixCol = Max_Col;

	//遍历二维数组 -> 打印二维数组、将二维数组有效数据存入稀疏矩阵
	printf("原始二维数组：\n");
	for(i = 0; i < Max_Row; i++){
		for(j = 0; j < Max_Col; j++){
			printf("%3d",Ori2DArr[i][j]);

			//如果二维数组元素值不为0，存入稀疏矩阵中
			if(Ori2DArr[i][j]){
				OriSparseArr.DataNode[OriSparseArr.TotalDataNodeNum].row = i;
				OriSparseArr.DataNode[OriSparseArr.TotalDataNodeNum].col = j;
				OriSparseArr.DataNode[OriSparseArr.TotalDataNodeNum].data = Ori2DArr[i][j];
				OriSparseArr.TotalDataNodeNum++;  //二维数组非零元素个数加一
			}
		}
		printf("\n");
	}

	//打印稀疏矩阵
	printf("稀疏矩阵：\n");
	for(i = 0; i < OriSparseArr.TotalDataNodeNum; i++){
		printf("[%d,%d,%d]\n", OriSparseArr.DataNode[i].row, OriSparseArr.DataNode[i].col, OriSparseArr.DataNode[i].data);
	}

	//转置稀疏矩阵
	//稀疏矩阵行号 -> 转置稀疏矩阵列号；稀疏矩阵列号 -> 转置稀疏矩阵行号；非零元素个数赋值
	TraSparseArr.MatrixCol = OriSparseArr.MatrixRow;
	TraSparseArr.MatrixRow = OriSparseArr.MatrixCol;
	TraSparseArr.TotalDataNodeNum = OriSparseArr.TotalDataNodeNum;

	//遍历稀疏矩阵进行转置操作
	//稀疏矩阵个数非0时进行转置操作
	//保证转置稀疏矩阵第一列升序排列
	printf("转置稀疏矩阵：\n");
	if(OriSparseArr.TotalDataNodeNum){
		for(i = 0, temp = 0; i < TraSparseArr.MatrixRow; i++){
			for(j = 0; j < TraSparseArr.TotalDataNodeNum; j++){
				if(i == OriSparseArr.DataNode[j].col){
					TraSparseArr.DataNode[temp].row = OriSparseArr.DataNode[j].col;
					TraSparseArr.DataNode[temp].col = OriSparseArr.DataNode[j].row;
					TraSparseArr.DataNode[temp].data = OriSparseArr.DataNode[j].data;
					printf("[%d,%d,%d]\n", TraSparseArr.DataNode[temp].row, TraSparseArr.DataNode[temp].col, TraSparseArr.DataNode[temp].data);
					temp++;
				}
			}
		}
	}

	//将转置稀疏矩阵 转 转置二维数组
	printf("转置二维数组：\n");
	for(i = 0, temp = 0; i < TraSparseArr.MatrixRow; i++){
		for(j = 0; j < TraSparseArr.MatrixCol; j++){
			if(i == TraSparseArr.DataNode[temp].row && j == TraSparseArr.DataNode[temp].col){
				printf("%3d",TraSparseArr.DataNode[temp].data);
				temp++;
			}
			else
				printf("%3d", 0);
		}
		printf("\n");
	}
	return 0;
}
#endif
