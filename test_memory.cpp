#include "catch_amalgamated.hpp"

#include <sys/resource.h>
#include <thread>
#include <chrono>
#include "library.cpp"

long getMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;
}

TEST_CASE("Dynamic memory allocation in Library", "[memory]") {
    long initialMemory = getMemoryUsage();

    Library library;
    const int largeNumber = 10000;
    for (int i = 0; i < largeNumber; ++i) {
        library.addBook(new Book("Title", "Author", "ISBN"));
    }

    long finalMemory = getMemoryUsage();

    REQUIRE(finalMemory > initialMemory);

    for (int i = 0; i < largeNumber ; ++i) {
        library.removeBook(0);
    }
}