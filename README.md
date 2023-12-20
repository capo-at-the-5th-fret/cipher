# cipher

A simple cipher project used to test CMake modules support. The library contains a handful of common cipher substitution algorithms such as caesar, rot13, affine and atbash. The doctest library is used for testing.

```cpp

import std;
import cipher;

int main()
{
    const std::string_view message{ "Hello, world!" };

    // encrypt the message using the caesar algorithm, with a shift of 10 positions (to the right). ciphertext should contain "Rovvy, gybvn!"
    auto ciphertext = cipher::caesar(message, 10);

    // decrypt the message using a shift in the opposite direction (a negative shift is to the left). plaintext should contain "Hello, world!"
    auto plaintext = cipher::caesar(ciphertext, -10);

    std::println("message: {}", message);
    std::println("ciphertext: {}", ciphertext);
    std::println("plaintext: {}", plaintext);
}

```

Requires CMake 3.28 and C++23 (import std) to compile.
