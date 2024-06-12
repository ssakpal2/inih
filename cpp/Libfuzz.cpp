#include <cstdint>
#include <cstddef>
#include "INIReader.h"

// This function will be called by libFuzzer
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    // Create a temporary buffer with the input data
    const char* buffer = reinterpret_cast<const char*>(data);

    // Create an INIReader instance using the buffer
    INIReader reader(buffer, size);

    // Access some typical methods to ensure code paths are exercised
    reader.Get("section", "name", "default_value");
    reader.GetString("section", "name", "default_value");
    reader.GetInteger("section", "name", 0);
    reader.GetInteger64("section", "name", 0);
    reader.GetUnsigned("section", "name", 0);
    reader.GetUnsigned64("section", "name", 0);
    reader.GetReal("section", "name", 0.0);
    reader.GetBoolean("section", "name", false);
    reader.HasSection("section");
    reader.HasValue("section", "name");

    return 0;
}
