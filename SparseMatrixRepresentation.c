#include <stdio.h>

typedef struct {

    int row;

    int col;

    int val;

} SMatrix;
void insertmat(int r, int c, SMatrix* smat) {

    printf("Enter elements of sparse matrix:\n");

    int count = 0;

    for (int i = 0; i < r; i++) {

        for (int j = 0; j < c; j++) {

            int element;

            scanf("%d", &element);

            if (element != 0) {

                smat[count].row = i;

                smat[count].col = j;

                smat[count].val = element;

                count++;

            }

        }

    }

}
void displaySparseMatrix(SMatrix* smat, int count,int r,int c) {

    printf("Sparse Matrix Representation:\n");

    printf("%d\t%d\t%d\n",r,c,count);

    for (int i = 0; i < count; i++) {

        printf("%d\t%d\t%d\n", smat[i].row, smat[i].col, smat[i].val);

    }

}

int main() {

    int r, c;

    printf("Enter row and column size of sparse matrix: ");

    scanf("%d %d", &r, &c);

    SMatrix smat[100] ={{0}};

    insertmat(r, c, smat);

    int count = 0;

    for (int i = 0; i < r * c; i++) {

        if (smat[i].val != 0) {

            count++;

        } else {

            break;

        }

    }

    displaySparseMatrix(smat, count,r,c);

}

                       

