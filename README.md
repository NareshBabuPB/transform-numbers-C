# Number To Words Convertor

A **C Program** to convert a given number to words.

Re-write of [transform-numbers](https://github.com/NareshBabuPB/transform-numbers/) originally written in Java.

### Run the project:
```
make all
./app
```

#### Using Docker container:
```docker run -it --rm --security-opt seccomp=unconfined -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:12.4.0 make run```

### Run tests:
```make all test```