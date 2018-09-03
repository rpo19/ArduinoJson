// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#include <ArduinoJson.h>
#include <catch.hpp>

using namespace Catch::Matchers;

TEST_CASE("Undefined JsonArray") {
  JsonArray array;

  SECTION("SubscriptFails") {
    REQUIRE(array[0].isNull());
  }

  SECTION("AddFails") {
    array.add(1);
    REQUIRE(0 == array.size());
  }

  SECTION("CreateNestedArrayFails") {
    REQUIRE(array.createNestedArray().isNull());
  }

  SECTION("CreateNestedObjectFails") {
    REQUIRE(array.createNestedObject().isNull());
  }

  SECTION("PrintToWritesBrackets") {
    char memoryPool[32];
    serializeJson(array, memoryPool, sizeof(memoryPool));
    REQUIRE_THAT(memoryPool, Equals("null"));
  }
}
