# Pipex

## Project Complexity

The Pipex project is a complex project that involves creating a program that mimics the behavior of the shell pipe (`|`). The project requires a deep understanding of process creation and management, inter-process communication, and file handling in Unix-like operating systems. The project also involves working with system calls such as `fork`, `pipe`, `dup2`, and `execve`, which are essential for creating and managing processes and their communication.

## Instructions

To use the Pipex project, follow these steps:

1. Clone the repository:
   ```sh
   git clone https://github.com/nuketayev/pipex.git
   cd pipex
   ```

2. Compile the project:
   ```sh
   make
   ```

3. Run the project with the following syntax:
   ```sh
   ./pipex <file1> <cmd1> <cmd2> <...> <file2>
   ```

   - `<file1>`: The input file.
   - `<cmd1>`, `<cmd2>`, `<...>`: The commands to be executed.
   - `<file2>`: The output file.

4. Alternatively, you can use the "here_doc" feature:
   ```sh
   ./pipex here_doc <LIMITER> <cmd> <...> <file>
   ```

   - `here_doc`: Indicates the use of the here document feature.
   - `<LIMITER>`: The limiter string.
   - `<cmd>`, `<...>`: The commands to be executed.
   - `<file>`: The output file.

## Examples

Here are four examples of how to run the project and its expected output:

### Example 1

```sh
./pipex infile "ls -l" "grep pipex" outfile
```

- This command will take the contents of `infile`, execute `ls -l`, pipe the output to `grep pipex`, and write the final output to `outfile`.

Expected output in `outfile`:
```
-rw-r--r--  1 user  group  1234 Jan  1 12:34 pipex
```

### Example 2

```sh
./pipex infile "cat" "wc -l" outfile
```

- This command will take the contents of `infile`, execute `cat`, pipe the output to `wc -l`, and write the final output to `outfile`.

Expected output in `outfile`:
```
42
```

### Example 3

```sh
./pipex here_doc LIMITER "cat" "wc -l" outfile
```

- This command will read input until `LIMITER` is encountered, execute `cat`, pipe the output to `wc -l`, and write the final output to `outfile`.

Expected output in `outfile`:
```
42
```

### Example 4

```sh
./pipex infile "grep foo" "sort" "uniq" outfile
```

- This command will take the contents of `infile`, execute `grep foo`, pipe the output to `sort`, then pipe the output to `uniq`, and write the final output to `outfile`.

Expected output in `outfile`:
```
foo
foo bar
foo baz
```
