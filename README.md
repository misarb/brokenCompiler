# brokenCompiler
writing a simple compiler for fun using cpp and Rust (in the future)

To Do : for the moment i implement the following using cpp

- [ ] lexer
- [ ] parser


# structe of the projcet 
``` bash
compiler/
├── src/
│   ├── lexer/
│   │   ├── lexer.cpp
│   │   └── lexer.h
│   ├── parser/
│   │   ├── parser.cpp
│   │   └── parser.h
│   ├── semantic_analysis/
│   │   ├── analyzer.cpp
│   │   └── analyzer.h
│   ├── code_generation/
│   │   ├── code_generator.cpp
│   │   └── code_generator.h
│   └── main.cpp
├── include/
│   ├── lexer/
│   │   └── lexer.h
│   ├── parser/
│   │   └── parser.h
│   ├── semantic_analysis/
│   │   └── analyzer.h
│   └── code_generation/
│       └── code_generator.h
├── tests/
│   ├── lexer/
│   ├── parser/
│   ├── semantic_analysis/
│   └── code_generation/
├── CMakeLists.txt
└── README.md


```
