**Binary Clock**

**Description**

The Binary Clock is a terminal-based application that displays the current time in binary format using an 8x8 grid. The application leverages the `ncurses` library for graphical output and updates the display every second.

**Installation**

To run the Binary Clock, follow these steps:
1. Clone the repository:
   ```bash
   git clone https://github.com/juanbarbecho/binary-clock.git
   cd binary-clock
2. Install dependencies: Make sure you have ncurses installed on your system. On macOS, you can install it using Homebrew:
   ```bash
   brew install ncurses
3. Build the project: Run the make command to compile the code:
   ```bash
   make
   
**Usage**

To run the Binary Clock, use the following command:
```bash
   bash ./clock.sh | ./clock
```
This will start the clock and display the current time in binary format.

**Manually Entering Time**

You can also manually input the time in HH:MM:SS format directly into the terminal after starting the program:
```bash
./clock
```
**Contributing**

If you'd like to contribute to this project, feel free to fork the repository, make your changes, and submit a pull request.

**Acknowledgments**

Thank you to the creators of the ncurses library for providing an easy way to handle terminal graphics.
