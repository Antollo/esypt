# `ArrayIterator`

#### `..Root.ArrayIterator`

Constructs a new `ArrayIterator`, this constructor exists only for internal `Array` purposes. `ArrayIterator` is not memory safe (not aware of `Array` size). For creating `ArrayIterator` pointing to data use `Array.begin()` and `Array.end()`.

### `Object` type signatures:

`Object`, `Iterator`, `ArrayIterator` 

## Child of:

[`Root`](docs..Root.md)

## Signatures:

`NativeCallable`, `Callable`

## Members:
- [`<-`](docs..Root.ArrayIterator.<-.md)
- [`++`](docs..Root.ArrayIterator.++.md)
- [`--`](docs..Root.ArrayIterator.--.md)
- [`==`](docs..Root.ArrayIterator.==.md)
- [`get`](docs..Root.ArrayIterator.get.md)
- [`+`](docs..Root.ArrayIterator.+.md)
- [`-`](docs..Root.ArrayIterator.-.md)
- [`>`](docs..Root.ArrayIterator.>.md)
- [`<`](docs..Root.ArrayIterator.<.md)
- [`>=`](docs..Root.ArrayIterator.>=.md)
- [`<=`](docs..Root.ArrayIterator.<=.md)


## Example:

```c
var arr.=(Array());
arr.pushBack("abc", "def");
for (var it.=(arr.begin()).!=, arr.end(), it.++, {
    basicOut(it.get());
});
```