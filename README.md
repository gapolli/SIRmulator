# SIRmulator

SIRmulator is a small command line epidemiological simulator written in C based on the SIR (Susceptible, Infected and Recovered) Model for analyzing the spread of an infectious disease.

## How to run (Unix)

- Compile the source with:

  `$ make all`

- Execute the program and provide the necessary parameters

  `$ ./sir n x a t d`
  
  Where:
  n is the number of subjects (population)
  x is the number of iterations that the program must perform
  a is the infection probability per iteration
  t is the average period of infection per subject
  d is the grade average of relations for each subject
  
  Example:
  `$ ./sir n=100 x=1000 a=20 t=14 d=5`
  
  If you do not provide any parameters, the program should display a help screen.

## Contributors (sorted alphabetically):

- [Gustavo Adrien Polli](https://github.com/gapolli)
- [Victor Gomes Sampaio](https://github.com/VictorGom3s)

## Possible future implementations:
- Graph plotting
