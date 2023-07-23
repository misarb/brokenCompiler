# brokenCompiler
writing a simple compiler for fun using cpp and Rust (in the future)

To Do : for the moment i implement the following using cpp

- [ ] lexer
- [ ] parser


# Example to what i will start to compile

``` bash
3 + 7 - (5*10) +10

```



# structe of the projcet 
``` bash
compiler/
├── src/
│   ├── lexer/
│   │   ├── lexer.cpp
│   │  
│   ├── parser/
│   │   ├── parser.cpp
│   │   
│   ├── semantic_analysis/
│   │   ├── analyzer.cpp
│   │   
│   ├── code_generation/
│   │   ├── code_generator.cpp
│   │   
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
