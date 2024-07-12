1.Compile the compiler program:
g++ -o compiler src/lexer.cpp src/parser.cpp src/code_generator.cpp src/compiler.cpp

2.Run the compiler on the test program:
./compiler test/test_program.sl

3.Check the generated assembly code:
cat generated_code.asm
