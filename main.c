// Write a C program that prompts the user to input the number of rows and columns to create a 2D array. The program should then offer the option to represent the array in either Row Major or Column Major order. Additionally, the program should ask the user to input a specific target sum and find all subsets of the array whose sum equals that target. This process should repeat until the user decides to stop. Afterward, the program should ask the user if they want to run the entire program again. Use two while loops: one to repeat the specific tasks (Row Major, Column Major, or finding subsets) and another to allow the user to restart the program. Utilize a switch statement to select between displaying the array in Row Major, Column Major order, or finding the subsets with a sum equal to the specified number.

#include <stdio.h>

void findSubsets(int arr[], int n, int targetSum, int subset[], int subsetSize,
                 int start) {
  int sum = 0;

  for (int i = 0; i < subsetSize; i++) {
    sum += subset[i];
  }

  if (sum == targetSum) {
    printf("Number in array with sum %d: ", targetSum);
    for (int i = 0; i < subsetSize; i++) {
      printf("%d ", subset[i]);
    }
    printf("\n");
  }

  for (int i = start; i < n; i++) {
    subset[subsetSize] = arr[i];
    findSubsets(arr, n, targetSum, subset, subsetSize + 1, i + 1);
  }
}

void convert2Dto1D(int rows, int cols, int matrix[rows][cols], int oneD[]) {
  int k = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      oneD[k++] = matrix[i][j];
    }
  }
}

void findSubarrays(int rows, int cols, int matrix[rows][cols], int targetSum) {
  int oneD[rows * cols];
  int subset[rows * cols];

  convert2Dto1D(rows, cols, matrix, oneD);
  findSubsets(oneD, rows * cols, targetSum, subset, 0, 0);
}

void printArray(int rows, int cols, int matrix[rows][cols], char order) {
  if (order == 'R') {
    printf("Row Major Order\n");
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        printf("%d ", matrix[i][j]);
      }
      printf("\n");
    }
  } else if (order == 'C') {
    printf("Column Major Order\n");
    for (int i = 0; i < cols; i++) {
      for (int j = 0; j < rows; j++) {
        printf("%d ", matrix[j][i]);
      }
      printf("\n");
    }
  } else {
    printf("Invalid input\n");
  }
}

void initializeArray() {
  int rows, cols;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  int matrix[rows][cols];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("Value of element at row %d, column %d: ", i + 1, j + 1);
      scanf("%d", &matrix[i][j]);
    }
  }

  char choice, repeat;
  do {
    printf("\nChoose an option:\n"
           "R for Row Major order\n"
           "C for Column Major order\n"
           "P to find subsets with a given sum:\n");
    scanf(" %c", &choice);

    if (choice == 'P') {
      int targetSum;
      printf("Enter the target sum: ");
      scanf("%d", &targetSum);
      findSubarrays(rows, cols, matrix, targetSum);
    } else {
      printArray(rows, cols, matrix, choice);
    }

    printf("\nDo you want to repeat (y/n)? ");
    scanf(" %c", &repeat);
  } while (repeat == 'y');
}

int main(void) {
  char repeat;
  do {
    initializeArray();
    printf("Do you want to repeat the program (Y/N)? ");
    scanf(" %c", &repeat);
  } while (repeat == 'Y' || repeat == 'y');
  printf("Program exited.\n");
  return 0;
}

