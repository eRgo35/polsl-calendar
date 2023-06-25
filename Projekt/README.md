# Calendar with Event Handling

## Description
This project aims to create a calendar application with event handling capabilities. 
The calendar will have a terminal-based user interface. 
It will allow users to manage events, view them in different layouts, and provide data persistence for event storage.

## Libraries

This project will utilize the `gtest` library and minor function implemantions from `ncurses` library.

## Usage

To run the program follow steps below:

0. Install required dependencies

```BASH
> paru -S g++ gtest
```

1. Clone the repository

```BASH
> git clone git@github.com:polsl-aei-pk2/daf76dcf-gr31-repo.git
```

2. Navigate to clonned directory and into `Projekt` sub-directory

```BASH
> cd daf76dcf-gr31-repo/Projekt
```

3. Compile the program from source using `g++`

```BASH
> g++ -g -lgtest -lpthread ./**/*.cpp -o bin/main
```

alternatively you can use `gcc`

```BASH
> gcc -g -lgtest -lpthread /path/to/repo/daf76dcf-gr31-repo/Projekt/**/*.cpp -o /path/to/repo/daf76dcf-gr31-repo/Projekt/bin/main
```

4. Navigate to `bin` directory

```BASH
> cd bin
```

5. Start the program
```BASH
> ./main
```

## Stats

### Summary

Date : 2023-06-25 17:42:05

Directory /home/mike/Projects/daf76dcf-gr31-repo/Projekt

Total : 25 files,  1910 codes, 420 comments, 549 blanks, all 2879 lines

### Languages
| language | files | code | comment | blank | total |
| :--- | ---: | ---: | ---: | ---: | ---: |
| C++ | 21 | 1,776 | 420 | 503 | 2,699 |
| Markdown | 4 | 134 | 0 | 46 | 180 |