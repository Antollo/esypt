# `StringIterator`

#### `..Root.StringIterator`

Constructs a new `StringIterator`, this constructor exists only for internal `String` purposes. `StringIterator` is not memory safe (not aware of `String` size). For creating `StringIterator` pointing to data use `String.begin()` and `String.end()`.

### `StringIterator` type signatures:

`Object`, `Iterator`, `StringIterator` 

## Child of:

[`Root`](docs..Root.md)

## Signatures:

`NativeCallable`, `Callable`

## Members:
- [`<-`](docs..Root.StringIterator.<-.md)
- [`++`](docs..Root.StringIterator.++.md)
- [`--`](docs..Root.StringIterator.--.md)
- [`==`](docs..Root.StringIterator.==.md)
- [`get`](docs..Root.StringIterator.get.md)
- [`+`](docs..Root.StringIterator.+.md)
- [`-`](docs..Root.StringIterator.-.md)
- [`>`](docs..Root.StringIterator.>.md)
- [`<`](docs..Root.StringIterator.<.md)
- [`>=`](docs..Root.StringIterator.>=.md)
- [`<=`](docs..Root.StringIterator.<=.md)

## Example:

```c
var str.=("Hello world!");
for (var it.=(str.begin()).!=, str.end(), it.++, {
    basicOut(it.get());
});
```