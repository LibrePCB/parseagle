# ParsEagle

This is a C++/Qt library for parsing XML files created by EAGLE.

## Build Systems

The library provides both support for qmake (Qt5) and cmake (Qt5/Qt6).

## Error Handling

- Fatal errors while parsing an EAGLE XML file (e.g. invalid numbers) will
  throw a `std::exception`.
- Non-fatal parsing errors (e.g. unknown XML nodes or unknown enum values)
  will be ignored, i.e. parsing is not aborted. Optionally, a `QStringList`
  can be provided where these error messages are appended to. Unknown
  enum attributes will be set to a special value named `Unknown`.
- Any errors after parsing (e.g. failed type conversions in getters) won't
  throw any exceptions but report their success e.g. with a boolean return
  value. So users of this library don't need to handle exceptions anymore
  once the parsing succeeded.

## License

Licensed under either of

- Apache License, Version 2.0, ([LICENSE-APACHE](LICENSE-APACHE) or
  http://www.apache.org/licenses/LICENSE-2.0)
- MIT license ([LICENSE-MIT](LICENSE-MIT) or http://opensource.org/licenses/MIT)

at your option.
