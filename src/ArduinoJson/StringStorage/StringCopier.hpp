// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

namespace ArduinoJson {
namespace Internals {

template <typename TMemoryPool>
class StringCopier {
 public:
  StringCopier(TMemoryPool& jb) : _jb(&jb) {}

  typedef typename TMemoryPool::String String;

  String startString() {
    return _jb->startString();
  }

 private:
  TMemoryPool* _jb;
};
}  // namespace Internals
}  // namespace ArduinoJson
