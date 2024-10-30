# Pipex

## Description

**Pipex** is a project designed to deepen understanding of UNIX pipes by creating a program that replicates the functionality of shell piping. The program takes two commands and redirects the output of the first command to the input of the second, simulating the behavior of the shell command `cmd1 | cmd2`.

---

## Features

### Mandatory Part

The `pipex` program should be executed as follows:

    ./pipex file1 cmd1 cmd2 file2

- **Arguments**:
  - `file1`: The input file.
  - `cmd1`: The first shell command with its parameters.
  - `cmd2`: The second shell command with its parameters.
  - `file2`: The output file.

- **Behavior**: The program should mimic the shell command:

      < file1 cmd1 | cmd2 > file2

  For example:

      ./pipex infile "ls -l" "wc -l" outfile

  This should behave like:

      < infile ls -l | wc -l > outfile

- **Requirements**:
  - The program must handle errors and exit gracefully without memory leaks.
  - It must use UNIX functions such as `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, and `waitpid`.
  - The Makefile should include rules for `all`, `clean`, `fclean`, and `re` targets, and it should not relink.

### Bonus Part (Optional)

Additional features for extra points:

- **Multiple Pipes**: The program can handle multiple commands, with each command’s output piped to the next. For example:

      ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

  This should behave like:

      < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

- **Here Document Mode**: The program supports `<<` and `>>` when the first parameter is `"here_doc"`. For example:

      ./pipex here_doc LIMITER cmd cmd1 file

  This should behave like:

      cmd << LIMITER | cmd1 >> file

> **Note**: The bonus part will only be evaluated if the mandatory part is fully completed and functions without errors.

---

## Compilation and Usage

Compile the program using the provided Makefile:

    make

Run the program with the specified arguments:

    ./pipex file1 cmd1 cmd2 file2

---

## Project Structure

- **src/**: Contains the source files (`.c` files).
- **include/**: Contains the header files (`*.h`).
- **Makefile**: Used for compiling the main program and bonus features.

---

## How to Use

1. **Basic Command**:
   - To redirect output of one command to another using files:
     
         ./pipex infile "grep hello" "wc -l" outfile

2. **Multiple Pipes (Bonus)**:
   - Chain multiple commands:
     
         ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

3. **Here Document Mode (Bonus)**:
   - To use here-doc with a limiter and append output:
     
         ./pipex here_doc LIMITER "cat" "wc -l" outfile

---

## Author

Project developed by [Malik](https://github.com/ma1iik) as part of the École 42 curriculum.
