# nand2tetris

My implementation of the projects from the [nand2tetris](https://nand2tetris.org) project-oriented course.

The objective of the course is to first build a simple computer from the elementary logic gate NAND, and then to develop an high-level language (jack), developing a compiler, an assembly and a software hierarchy.

## Hardware Layer

The hardware is simulated with an hardware simulator, each part being coded in a .hdl file.

 * In [logic_gates](https://github.com/mtrazzi/nand2tetris/tree/master/logic_gates) we build elementary logic gates from a NAND gate
 * In [ALU](https://github.com/mtrazzi/nand2tetris/tree/master/logic_gates) an Arithmetic Logic Unit using half-adders, full-adders and an incrementer that we built from the logic gates
 * In [memory_hardware](https://github.com/mtrazzi/nand2tetris/tree/master/memory_hardware) we build sequential gates, a counter, a register, and a RAM, the implemention of a Flip-Flop being given
 * In [Computer](https://github.com/mtrazzi/nand2tetris/tree/master/Computer) I present my implementation of the "Hack Computer", the top most layer of the Hardware Architecture, which contains a CPU, a RAM, a ROM

## Software Layer

The purpose of the software layer is to provide a software hierarchy, with an assembly, a VM translator and a compiler, that let you write program for the computer you built in the Hardware part, using a high-level language : jack.
 * In [assembly](https://github.com/mtrazzi/nand2tetris/tree/master/assembly) I provide my implementation in C of an assembly that translates hack code (assembly code for this course) into machine language (only characters 0 and 1 in a text file)
 * In [VM_translator](https://github.com/mtrazzi/nand2tetris/tree/master/VM_translator) I built a VM translator in python that translates VM language (intermediary language using a stack similar to bytecode in java) into hack language
