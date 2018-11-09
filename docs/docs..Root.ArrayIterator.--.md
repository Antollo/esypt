# `--`

#### `..Root.ArrayIterator.--`

Decrements `ArrayIterator` instance (equivalent of `it.=(it.-(1))`).

* **Return value:** reference to this (decremented) `ArrayIterator`

## Child of:

[`ArrayIterator`](docs..Root.ArrayIterator.md)

## Signatures:

`NativeCallable`, `Callable`

## Example:

```c
var arr.=(Array());
arr.pushBack("abc", "def");
for (var it.=(arr.end()).!=, arr.begin(), it.--, {
    basicOut(it.-(1).get());
});
```