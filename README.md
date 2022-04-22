# 0x16. C - Simple Shell
## _Simple UNIX command interpreter_


This project consisted in building a shell with basic functionality and commands 


## Installation

To install just copy and paste this command on your terminal!
```sh
git clone https://github.com/yazgiraldoa/simple_shell.git
```

## How to run it
Compile the program using the following command
```sh
 gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
Then execute it using:
```sh
./hsh
```

## Funtion Glossary

These are all the functions used to build our shell

| Function | Description |
| ------ | ------ |
| _sterlen | prints the lenght of a string |
| _strcpy |copies a string |
| _strcmp |compares two strings |
| _strcat| concatenates two stringes |
| _putchar | writes a character to stdout |
| _puts | prints a string|
| _atoi | converts str to int |
| print_num | prints number |
| arg_count |counts arguments in input |
| args_v |tokenizes arguments |
| free_array |frees double pointer|
| _exec| runs command in different process |
| path_validator | checks for executables in PATH |
| path_tk | tokenizes PATH |
| path_acc | checks if the file exits in PATH |
| fork_process| creates new process and executes command |
| system_error | displays error|

## Authors


```sh
Santiago Monsalve Pinto
```


```sh
Pablo Emilio Agudelo Garavito
```
