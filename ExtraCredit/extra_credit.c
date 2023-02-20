#include <stdio.h>
#define ROWS 10
#define COLS 5

int main()
{
    char name[20];
    printf("Enter name of file: ");
    scanf("%s", name);

    int array[10][5];
    
    FILE *fp; 

    fp = fopen(name, "r");

    if (fp == NULL)
    {
        printf("Error\n");
    }

    for (int row=0; row < ROWS; row++)
    {
        for (int col=0; col < COLS; col++)
        {
            fscanf(fp, "%d", &array[row][col]);
        }
    }


    for (int row=0; row < ROWS; row++)
    {
        for (int col=0; col < COLS; col++)
        {
            printf("%d ", array[row][col]);
        }
        printf("\n");
    }

// first 5 rows contains number 1 prio of company 
// last 5 rows contain prio of programmers
// first check company wishes

int company_selected[5];

for (int col=0; col < 5; col++)
{
    for (int row=0; row < 5; row++)
    {
        if (company_selected[col] == 0)
        {
            company_selected[col] = array[row][col];
            for (int k=0; k < 5; k++)
            {
                if ((company_selected[col] == company_selected[k]) && (col!= k))
                {
                    // here would be the subroutine to check what the programmer prefers
                    for (int j=5; j < 10; j++)
                    {
                        if (col == array[j][array[row][col]-1]-1)
                        {
                            company_selected[k] = 0;
                            col = k-1;
                            break;
                        }
                        else if (k == array[j][array[row][col]-1]-1)
                        {
                            company_selected[col] = 0;
                            break;
                        }
                    }
                }
            }
        }
        
    }
}


for (int i=0; i < 5; i++)
{
    printf("%d ", company_selected[i]);
}


}