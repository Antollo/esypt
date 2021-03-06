# `Exception`

#### `..Root.Exception`

Constructs new `Exception` which is thrown when unrecognized error was encountered.

* **Parameters:** any number of `String` type variables

* **Return value:** new `Exception`

## Child of:

[`Root`](docs..Root.md)

## Signatures:

`NativeCallable`, `Callable`

## Examples:

```c
try({
    throw(Exception("Error!"));
}, {
    log(args[0].get());
});
```

```c
auto block.=({
    throw(Exception("Error!"));
});

try(block, {
    log(args[0].get());
});
```