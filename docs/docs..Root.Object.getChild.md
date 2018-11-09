# `getChild`

#### `..Root.Object.getChild`

Returns child (member, note: variables are treated as tree nodes) of this object named mem.

* **Parameters:** `String` mem

* **Return value:** reference to child

## Child of:

[`Object`](docs..Root.Object.md)

## Signatures:

`NativeCallable`, `Callable`

## Example:

```c
var father;
father.var son.=("I'm son");
basicOut(father.getChild("son"));
```