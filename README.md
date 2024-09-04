Here's a README for your version of the simple shell project, inspired by the structure of the one you referenced:

---

# Simple Shell - Shell Project

## Overview

This project is a simple UNIX command-line interpreter that replicates the functionality of a shell. The shell can execute commands from the user in interactive or non-interactive modes, parse and execute built-in commands, and handle basic error scenarios. The project was built as part of the curriculum to understand the inner workings of a shell, process management, and command execution in UNIX-like operating systems.

## Features

- **Interactive Mode**: The shell runs in a loop, continuously prompting the user for commands, executing them, and returning to the prompt until the user exits.
- **Non-interactive Mode**: The shell can also take commands from a file or input stream, executing each line in turn.
- **Command Execution**: Executes built-in commands as well as external programs found in system paths.
- **Path Resolution**: Searches and executes programs using the `PATH` environment variable.
- **Error Handling**: Basic error handling and messaging for unknown commands and other invalid input.
- **Environment Variables**: Supports printing and modifying environment variables.
- **Built-in Commands**:
  - `exit`: Exits the shell.
  - `env`: Prints the current environment variables.
  - `setenv`: Modifies or adds an environment variable.
  - `unsetenv`: Removes an environment variable.
  - `cd`: Changes the current directory.

## Getting Started

### Prerequisites

To run the simple shell, you need a UNIX-like operating system with a working C compiler (`gcc`) and basic development tools.

### Installation

1. Clone the repository to your local machine:

```bash
git clone https://github.com/your-username/simple_shell.git
```

2. Compile the source code:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell
```

3. Run the shell in interactive mode:

```bash
./simple_shell
```

Alternatively, run it in non-interactive mode by piping commands:

```bash
echo "ls -l" | ./simple_shell
```

## Usage

- Once inside the shell, type any command like you would in a regular shell (e.g., `ls`, `pwd`, `cd`, etc.).
- Use the `exit` command to exit the shell.
- To display environment variables, type `env`.

### Example:

```bash
$ ./simple_shell
$ ls
file1 file2 file3
$ pwd
/home/user/simple_shell
$ exit
```

## Files

- **main.c**: Entry point for the shell, handles the main loop.
- **shell.h**: Header file containing function prototypes and necessary libraries.
- **exec.c**: Contains functions for executing commands.
- **builtins.c**: Functions that handle built-in commands like `exit`, `env`, `setenv`, and `cd`.
- **path.c**: Resolves executable commands using the `PATH` variable.
- **error.c**: Basic error handling functions.
- **utils.c**: Helper functions for string manipulation, memory management, etc.

## Compilation

To compile the project, use the provided `gcc` command:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell
```

## Project Requirements

- Your shell should handle both interactive and non-interactive modes.
- You should implement a variety of built-in commands (see features above).
- External commands should be executed by searching the directories in the `PATH` environment variable.
- Memory should be properly allocated and freed to avoid leaks.
- The project should adhere to the Betty style guide for C programming.

## Authors

- Abdulrahman sweilam  - [GitHub](https://github.com/abdelrahman21-arch)
- Nada hussein -  [GitHub](https://github.com/NadaHusein)

## License

This project is licensed under the MIT License.

---

