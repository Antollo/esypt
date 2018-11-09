# `pushBack`

#### `..Root.Array.pushBack`

Appends given variables to array (as references).

* **Parameters:** any number of variables

* **Return value:** reference to this `Array`

## Child of:

[`Array`](docs..Root.Array.md)

## Signatures:

`NativeCallable`, `Callable`

## Example:

```c
var arr.=(Array());
arr.pushBack(1, 7, 3.14, "abc", "def");
for (var it.=(arr.begin()).!=, arr.end(), it.++, {
    basicOut(it.get());
});
```