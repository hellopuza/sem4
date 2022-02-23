#include "vec2.h"
#include <cmath>

int main()
{
    vec2 a(1.0F, 2.0F);

    std::cout << a << "\n\n";

    std::cout << a + vec2(1.0F, -1.0F) << "\n";
    std::cout << a - vec2(1.0F, -1.0F) << "\n";
    std::cout << a * vec2(1.0F, -1.0F) << "\n";
    std::cout << a / vec2(1.0F, -1.0F) << "\n\n";

    std::cout << a * 2.0F << "\n";
    std::cout << a / 2.0F << "\n\n";

    std::cout << (a += vec2(1.0F, -1.0F)) << "\n";
    std::cout << (a -= vec2(1.0F, -1.0F)) << "\n";
    std::cout << (a *= vec2(1.0F, -1.0F)) << "\n";
    std::cout << (a /= vec2(1.0F, -1.0F)) << "\n\n";

    std::cout << (a *= 2.0F) << "\n";
    std::cout << (a /= 2.0F) << "\n\n";

    std::cout << -a << "\n\n";

    std::cout << (a == vec2(1.0F, 2.0F)) << "\n";
    std::cout << (a != vec2(1.0F, 1.0F)) << "\n\n";

    std::cout << a.magnitute2() << "\n";
    std::cout << a.magnitute() << "\n\n";

    std::cout << a.normalized() << "\n";
    std::cout << a.rotated(std::atan(1.0F) * 2.0F) << "\n\n";

    return 0;
}