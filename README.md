# stdout-sample

## Description

Sample application testout basic input and output in C++.
Json-gen will output randomized json objects to stdout,
and json-consumer is consuming this outputing data.

To run the sample as
`json-gen | json-consumer`

## Build

- Clone project
- Initialize submodules

```
cmake -S . -B build
cmake --build build
```

Tested with VS 2022

