import std;
import cipher;

int main()
{
    // caesar substitution
    constexpr static std::string_view message{ "Hello, world!" };

    // copy example
    {
        // encrypt the message using the caesar algorithm, with a shift of 10
        // positions (a positive shift is to the right). ciphertext should
        // contain "Rovvy, gybvn!"
        auto ciphertext = cipher::caesar(message, 10);

        // decrypt the message using a shift in the opposite direction (a
        // negative shift is to the left). plaintext should contain "Hello,
        // world!"
        auto plaintext = cipher::caesar(ciphertext, -10);

        std::println("message: {}", message);
        std::println("ciphertext: {}", ciphertext);
        std::println("plaintext: {}", plaintext);
    }

    // inplace example
    {
        // apply the encryption to a buffer (inplace)
        std::string buffer{ message };

        cipher::caesar_inplace(buffer, 10);

        // buffer should contain "Rovvy, gybvn!"
        std::println("inplace ciphertext: {}", buffer);

        cipher::caesar_inplace(buffer, -10);

        // buffer should contain "Hello, world!"
        std::println("inplace plaintext: {}", buffer);
    }
}
