# pharo-vm-804
Issue #804

## Clone the repository, download the latest stable Pharo and install the code
```bash
git clone https://github.com/syrel/pharo-vm-804.git && cd pharo-vm-804
curl -L https://get.pharo.org | bash
./pharo Pharo.image st Issue804.st --save --quit
```

## Compile the library
```bash
gcc lib.c -fPIC -shared -o libIssue804.dylib
```

## Attempt to reproduce the deadlock (may require more than one attempt)
```bash
 ./pharo Pharo.image eval "Issue804 reproduce"
```

### Pharo VM is deadlocked when you see the following output:

```
Step #37
Step #38
Step #39
Step #40
Step #41
raise(SIGUSR1) #1000 
raise(SIGUSR1) #2000 
raise(SIGUSR1) #3000 
raise(SIGUSR1) #6000 
raise(SIGUSR1) #7000
```