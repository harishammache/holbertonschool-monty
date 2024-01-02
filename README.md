```markdown
# Monty Project

![image](https://github.com/Matilop15/monty/blob/main/img/monty.jpg)

Stacks, Queues - LIFO, FIFO, January 2022

## Description

Monty is a language interpreter made in the C programming language to manage stacks and queues (LIFO and FIFO). The aim is to interpret Monty bytecode files. [Monty](http://montyscoconut.github.io/) is a language that aims to close the gap between scripting and programming languages.

## Compilation

To compile this project, you can use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty
```

## Option Codes

### Push opcode

The opcode `push` pushes an element to the stack.

**Usage:** `push <int>`, where *int* is an integer.

### Pall opcode

The opcode `pall` prints all the values on the stack, starting from the top of the stack.

**Usage:** `pall`. If the stack is empty, `pall` doesn’t print anything.

```bash
$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
$ ./monty bytecodes/00.m
3
2
1
```

### Pint opcode

The opcode `pint` prints the value at the top of the stack, followed by a new line.

**Usage:** `pint`. If the stack is empty, `pint` prints an error message.

```bash
$ cat bytecodes/06.m
push 1
pint
push 2
pint
push 3
pint
$ ./monty bytecodes/06.m
1
2
3
```

### Pop opcode

The opcode `pop` removes the top element of the stack.

**Usage:** `pop`. If the stack is empty, `pop` prints an error message.

```bash
$ cat bytecodes/07.m
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
$ ./monty bytecodes/07.m
3
2
1
2
1
1
```

### Swap opcode

The opcode `swap` swaps the top two elements of the stack.

**Usage:** `swap`. If the stack contains less than two elements, `swap` prints an error message.

```bash
$ cat bytecodes/09.m
push 1
push 2
push 3
pall
swap
pall
$ ./monty bytecodes/09.m
3
2
1
2
3
1
```

### Add opcode

The opcode `add` adds the top two elements of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

- The top element of the stack contains the result
- The stack is one element shorter

**Usage:** `add`. If the stack contains less than two elements, `add` prints an error message.

```bash
$ cat bytecodes/12.m
push 1
push 2
push 3
pall
add
pall
$ ./monty bytecodes/12.m
3
2
1
5
1
```

### Nop opcode

The opcode `nop` doesn’t do anything.

**Usage:** `nop`.

```bash
$ cat -e bytecodes/nop.m
nop$
push 1$
nop$
push 2$
nop$
push 3$
nop$
pall$
nop$
pall$
$ ./monty bytecodes/nop.m
3
2
1
3
2
1
```

### Sub opcode

The opcode `sub` subtracts the top element of the stack from the second top element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

- The top element of the stack contains the result
- The stack is one element shorter

**Usage:** `sub`. If the stack contains less than two elements, `sub` prints an error message.

```bash
$ cat -e bytecodes/sub.m
push 1$
push 2$
push 10$
push 3$
sub$
pall$
$ ./monty bytecodes/sub.m
7
2
1
```

### Div opcode

The opcode `div` divides the second top element of the stack by the top element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

- The top element of the stack contains the result
- The stack is one element shorter

**Usage:** `div`. If the stack contains less than two elements, `div` prints an error message.

```bash
$ cat -e bytecodes/div.m
push 1$
push 2$
push 10$
push 5$
div$
pall$
$ ./monty bytecodes/div.m
2
2
1
```

### Mul opcode

The opcode `mul` multiplies the second top element of the stack with the top element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

- The top element of the stack contains the result
- The stack is one element shorter

**Usage:** `mul`. If the stack contains less than two elements, `mul` prints an error message.

```bash
$ cat -e bytecodes/mul.m
push 1$
push 2$
push 20$
push 5$
mul$
pall$
$ ./monty bytecodes/mul.m
100
2
1
```

### Some Brainf\*ck Tasks

[Brainfck](https://en.wikipedia.org/wiki/Brainfuck) is an esoteric programming language created in 1993 by Urban Müller. Here are some testing scripts.

### Print Holberton

Write a Brainf\*ck script that prints Holberton, followed by a new line.

- All your Brainf\*ck files should be stored inside the bf sub directory
- You can install the bf interpreter to test your code: `sudo apt-get install bf`

**Source:** [1000-school.bf](https://github.com/Matilop15/monty/blob/main/bf/1000-school.bf)

```bash
$ bf 1000-school.bf
School
```

## Authors
```

Une fois que vous avez copié ce contenu dans un fichier texte local, enregistrez-le sous le nom "README.md" dans le répertoire de