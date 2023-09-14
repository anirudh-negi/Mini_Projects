package main

import "fmt"

func printboard(sudokuboard [][]int) {
	fmt.Println()
	fmt.Println("***SUDOKU SOLVER 2023*****")
	fmt.Println()
	for rows := range sudokuboard {
		if rows == 3 || rows == 6 {
			fmt.Println("--------------------------")
		}
		for data := range sudokuboard[rows] {
			if data == 3 || data == 6 {
				fmt.Print(" " + "|" + " " + " ")
			}
			fmt.Print(sudokuboard[rows][data], " ")
		}

		fmt.Println()
	}
	fmt.Println()
	fmt.Println("***SUDOKU SOLVER 2023*****")
}

func isvalid(sudokuboard [][]int, n int, row int, col int) bool {
	for elements := range sudokuboard {
		if n == sudokuboard[row][elements] && elements != col {
			return false
		}
	}
	for elements := range sudokuboard {
		if n == sudokuboard[elements][col] && elements != col {
			return false
		}
	}
	for k := 0; k < 3; k++ {
		for l := 0; l < 3; l++ {
			if (sudokuboard[row-row%3+k][col-col%3+l] == n) && (row-row%3+k != row || col-col%3+l != col) {
				return false
			}
		}
	}
	return true
}

func getEmptySpace(sudokuboard [][]int) (int, int) {
	puzzcols := len(sudokuboard[0])
	for i := 0; i < len(sudokuboard); i++ {
		for j := 0; j < puzzcols; j++ {
			if sudokuboard[i][j] == 0 {
				return i, j
			}
		}
	}
	return -1, -1
}

func solveBoard(sudokuboard [][]int) bool {
	row, column := getEmptySpace(sudokuboard)
	if row == -1 {
		return true
	}

	for i := 1; i <= 9; i++ {
		if isvalid(sudokuboard, i, row, column) {
			sudokuboard[row][column] = i

			if solveBoard(sudokuboard) {

				return true
			}
			sudokuboard[row][column] = 0

		}
	}
	return false
}

func main() {
	var sudokuboard = [][]int{
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9},
	}
	printboard(sudokuboard)
	fmt.Println()
	solveBoard(sudokuboard)
	printboard(sudokuboard)

}
