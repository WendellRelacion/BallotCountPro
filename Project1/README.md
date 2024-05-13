# BallotCountPro

## Description

[]

## How to Run

### Running the Project

1. Navigate to the `src` folder in the terminal.

2. Use the following command to compile the project:
    ```
    make all
    ```

3. Once the compilation is finished, execute the project using the following command:
    ```
    make run
    ```
4. Once everything is up and running, input the desired csv file:
    ```
    OPL.csv
    or
    CPL.csv
    ```

### Running Tests

#### System Tests

1. Navigate to the system test directory in the terminal.

2. Compile the system tests using the following command:
    ```
    g++ -o my_tests Election_systemTest.cpp -lgtest -lgtest_main -pthread
    ```

3. Run the compiled tests using the following command:
    ```
    ./my_tests
    ```

#### Unit Tests

1. Navigate to the unit test directory in the terminal.

2. Compile the unit tests by replacing `[filename]` with the appropriate file name and using the following command format:
    ```
    g++ -o my_tests [filename] -lgtest -lgtest_main -pthread
    ```
    
3. Run the compiled tests using the following command:
    ```
    ./my_tests
    ```
 