# Random Maze Generator and Solver

This project is a random maze generator and solver implemented in C. The program uses depth-first search (DFS) to generate a maze and solve it.

## Table of Contents

- [Introduction](#introduction)
- [Functions](#functions)
- [How to Run](#how-to-run)

## Introduction

The program generates a random maze of a specified size, marks a start and goal point, and then solves the maze using depth-first search. The maze is displayed, and the solving process is animated on the console.

## Functions

### `dfs(int x, int y)`

This function performs a depth-first search to generate the maze. It starts from the top-left corner and creates a random path through the maze.

### `solveMazeDFS(int maze[SIZE][SIZE], int x, int y, int goalX, int goalY, int startX, int startY)`

This function uses depth-first search to solve the generated maze. It marks the path and displays the solving process.

### `initializeMaze()`

This function initializes the maze with walls.

### `printMaze(int maze[SIZE][SIZE], int startX, int startY, int goalX, int goalY)`

This function prints the maze, marking the start and goal points.

### `isValidCell(int x, int y)`

Checks if a given cell is a valid and unvisited cell.

### `hasUnvisitedNeighbors(int x, int y)`

Checks if a given cell has unvisited neighbors.

### `delay(int number_of_seconds)`

Introduces a delay for animation purposes.

### `intro_project()`

Displays an introduction screen to the project.

## How to Run

1. Clone the repository.
2. Compile the code using a C compiler (e.g., GCC).
3. Run the executable.

Upon running the program, the generated maze will be displayed, and the solving process will be animated. Follow the on-screen instructions.

Enjoy exploring and solving mazes!
