# Functions

> A function is a group of statements that perform particular task.

>**Advantages**
>
>The advantages of breaking a program into subroutines [functions] include:
>- Decomposing a complex programming task into simpler steps: this is one of the two main tools of structured programming, along with data structures.
>- Reducing duplicate code within a program.
>- Enabling reuse of code across multiple programs.
>- Dividing a large programming task among various programmers, or various stages of a project.
>- Hiding implementation details from users of the subroutine.
>- Improving readability of code by replacing a block of code with a function call where a descriptive function name serves to describe the block of code. This makes the calling code concise and readable even if the function is not meant to be reused.
>- Improving traceability [...] by not decomposing the code into subroutines, debugging would be severely impaired.
>
>**Disadvantages**
>- Invoking a subroutine (versus using in-line code) imposes some computational overhead in the call mechanism.
>- A subroutine typically requires standard housekeeping code – both at entry to, and exit from, the function [...].
>
>[_From Wikipedia_](https://en.wikipedia.org/wiki/Subroutine)

## 1. What we call a function in Easypt

Basically we can call everything of `Callable` type. `NativeCallable` is type of function provided by the Easypt interpreter or native libraries. `BlockCallable` is type of function defined in `*.ez` source code.

## 2. Defining function

Let's begin with function literal (unnamed function):

```c
{
    basicOut("I am BlockCallable literal!");
};
```

Nothing happened. We need to call it (by call operator - `()`).

```c
{
    basicOut("I am BlockCallable literal!");
}();
```

(Code called like this above has no access to current context.)

Let's give our function a name;:

```js
var fun.=({
    basicOut("I am fun!");
});
fun();
```

## 3. Parameters

> In computer programming, a parameter  [...] is a special kind of variable, used in a subroutine [functions] to refer to one of the pieces of data provided as input to the subroutine. [...] Argument in computer science is the actual input expression passed/supplied to a function.
>
>[_From Wikipedia_](https://en.wikipedia.org/wiki/Parameter_(computer_programming))

In Easypt argumets are provided as `Array` of [references](https://en.wikipedia.org/wiki/Evaluation_strategy#Call_by_reference) to arguments named `args`. See the example:

```js
var print.=({
    basicOut(args[0].get(), args[1].get());
});
print(7, 3.14);
```

Try to run:

```js
var print.=({
    basicOut(args[0].get(), args[1].get());
});
print(7);
```

You will see out of range exception:

```
Error at: ..Root.import
Error at: ..Root.my_source_file
Error at: ..Root.my_source_file.callOperator
Error at: ..Root.my_source_file.print
Error at: ..Root.my_source_file.print.callOperator
Error at: ..Root.my_source_file.print.args
Error at: ..Root.my_source_file.print.args.readOperator
Out of range while calling ..Root.my_source_file.print.args.readOperator
```

But 

```js
print(7, 7, 7, 7, 7);
```

works fine as you expected. So what are those "references"? Run this:

```js
var myIncrement.=({
    args[0].get().++();
});
var myInt.=(5)
myIncrement(myInt);
basicOut(myInt);
```

Output is `6`. If you don't want to pass a reference, you will have to use `Object`'s `copy` method:

```js
var myIncrement.=({
    args[0].get().++();
});
var myInt.=(5)
myIncrement(myInt.copy());
basicOut(myInt);
```

Now output is `5`.

You will learn about variable number of arguments while learning about loops.

## 4. Return

Unlike _return statement_ in many languages `return` is variable in Easypt. `return` is value of function call. Assigning value to `return` doesn't make execution to leave the current function and if no value is assigned new `Object` will be returned. Example:

```js
var fun.=({
    var return.=(5);
});
basicOut(fun());
```

## 5. Exercise "Birthday Project"

Your exercise is to analyze following code:

```js
var makeGreetingsString.=({
    var return.=("Happy ");
    return.=(return.+(args[0].get().toString()));
    return.=(return.+(" birthday "));
    return.=(return.+(args[1].get()));
    return.=(return.+("!"));
});
basicOut(makeGreetingsString(51, "John"));
```

Output:

```
Happy 51 birthday John!
```

Understand the code:

- `toString` is `Basic`'s method that return new `String` object created from owner value.