# Brainfuck Interpreter

Brainfuck Interpreter is a simple, yet powerful tool that allows you to interpret Brainfuck code. It's written in C and can interpret Brainfuck code from both user input and files.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Known Bugs](#bugs)
- [Contributing](#contributing)
- [License](#license)

## Installation

To install the Brainfuck Interpreter, clone the repository and compile the `main.c` file with a C compiler of your choice.

```bash
git clone https://github.com/Kuttesch/BrainfuckInterpreter.git
cd BrainfuckInterpreter
gcc main.c -o brainfuck
```

## Usage

After compiling, you can run the program. It will ask you if you have a file (y/n). If you select 'n', you can enter your Brainfuck code directly. If you select 'y', you will be prompted to enter the file path to a file containing Brainfuck code.

Here's an example of how to use it:

```bash
./brainfuck
```

In this example, the program will start and wait for your input.

## Bugs

Currently, there are no known bugs. If you find any, please open an issue in the GitHub repository.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

[MIT](https://choosealicense.com/licenses/mit/)