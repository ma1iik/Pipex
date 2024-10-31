
# pipex

## Description

**pipex** is a C program that emulates the Unix pipe `|` operation, allowing for the redirection of output from one command as input to another. This project was developed as part of the École 42 curriculum to practice file descriptor management, process creation, and pipe handling in a Unix-based environment.

## Features

- Simulates the behavior of the Unix pipe `|` to link outputs and inputs of commands.
- Executes two commands sequentially, redirecting the output of the first command as input to the second.
- Manages file redirection for input and output.
- Includes error handling for invalid commands, inaccessible files, and system calls.

## Compilation and Usage

To compile `pipex`, use the provided Makefile by running:

```bash
make
```

## Project Structure

- **pipex.h**: Contains the structure `t_pipex` for managing pipes and file descriptors, and function prototypes.
- **pipex.c**: Main program that sets up pipes, processes commands, and manages forking of child processes.
- **utils.c**: Provides utility functions including `command`, `error_msg`, `close_pipe`, `child_proccess1`, and `child_proccess2` for command execution and pipe handling.
- **libft/**: Directory containing custom helper functions like `ft_split`, `ft_strdup`, and `ft_strjoin`.
- **Makefile**: Manages compilation of the program.

## How to Use

Once compiled, run the `pipex` program with the following format:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

- **infile**: The file from which the first command will read input.
- **cmd1**: The first command to execute.
- **cmd2**: The second command to execute, using the output from cmd1.
- **outfile**: The file where the output from cmd2 will be written.

### Example

```bash
./pipex infile "ls -l" "grep pipex" outfile
```

In this example, `pipex` will execute `ls -l`, filter the output through `grep pipex`, and write the result to `outfile`.

## Author

Project developed by [Malik](https://github.com/ma1iik) as part of the École 42 curriculum.

