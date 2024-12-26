# Assignment 2 - Integrate by Simpson's 1/3 Rule

This program integrates a function using Simpson's 1/3 rule, within a given
bounds and displays the area under the curve for every 2 partitions, up till
the number of partitions specified by the user.

It should be noted that a change was made to function g in functions.c to allow
for bounds given to include zero. Function g is sin(x)/x. Our change sets the 
function to add 1 whenever x is zero or close to it. 


## Building

Run the following to build the `integrate` program.


```
$ make all
```

## Running

The below command can be used to invoke the Simpson's rule to integrate all
the functions across specific values, and 30 partitions.

```
$ make tst_all
```

Individual functions may be tested by invoking the integrate command
directly with the desired options. For example, to integrate the function
sqrt(1-x^4) over the limits 0 and 1, and using 20 partitions, the following
command can be used

```
$ ./integrate -a -p 0 -q 1 -n 20
```
