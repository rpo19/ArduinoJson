// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#include <ArduinoJson.h>
#include <catch.hpp>

using namespace Catch::Matchers;

TEST_CASE("JsonObject::invalid()") {
  JsonObject obj;

  SECTION("SubscriptFails") {
    REQUIRE(obj["key"].isNull());
  }

  SECTION("AddFails") {
    obj.set("hello", "world");
    REQUIRE(0 == obj.size());
  }

  SECTION("CreateNestedArrayFails") {
    REQUIRE(obj.createNestedArray("hello").isNull());
  }

  SECTION("CreateNestedObjectFails") {
    REQUIRE(obj.createNestedObject("world").isNull());
  }

  SECTION("serialize to 'null'") {
    char memoryPool[32];
    serializeJson(obj, memoryPool, sizeof(memoryPool));
    REQUIRE_THAT(memoryPool, Equals("null"));
  }
}
