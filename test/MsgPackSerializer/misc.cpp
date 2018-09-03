#include <ArduinoJson.h>
#include <catch.hpp>
#include <limits>

template <typename T>
void check(T value, const std::string &expected) {
  DynamicJsonDocument doc;
  doc.to<JsonVariant>().set(value);
  char memoryPool[256] = "";
  size_t returnValue = serializeMsgPack(doc, memoryPool, sizeof(memoryPool));
  REQUIRE(expected == memoryPool);
  REQUIRE(expected.size() == returnValue);
}

TEST_CASE("serializeMsgPack(JsonObjectSubscript)") {
  DynamicJsonDocument doc;
  deserializeJson(doc, "{\"hello\":42}");
  JsonObject obj = doc.as<JsonObject>();
  std::string result;

  serializeMsgPack(obj["hello"], result);

  REQUIRE(result == "*");
}

TEST_CASE("serializeMsgPack(JsonArraySubscript)") {
  DynamicJsonDocument doc;
  deserializeJson(doc, "[42]");
  JsonArray arr = doc.as<JsonArray>();
  std::string result;

  serializeMsgPack(arr[0], result);

  REQUIRE(result == "*");
}

TEST_CASE("serializeMsgPack(JsonVariantSubscript)") {
  DynamicJsonDocument doc;
  deserializeJson(doc, "[42]");
  JsonVariant var = doc.as<JsonVariant>();
  std::string result;

  serializeMsgPack(var[0], result);

  REQUIRE(result == "*");
}
